#include <xc.h>
#include <stdio.h>
#include <math.h>
#include "pic18f4321-Config.h"
#include "LCD.h"

#define X_TAL_FREQ 16000000

unsigned int readAN0(void);
unsigned int readAN1(void);
unsigned int readAN2(void);
unsigned int readAN3(void);
unsigned int readAN4(void);
float calcVoltage(unsigned int, float);
void actualVoltage(float, char*);

void main() {
    unsigned int adc[5];
    float voltages[5];
    char buffer[16];
    float vRef = 5.0;

    // Configure ADC
    ADCON1 = 0x0E;
    TRISAbits.TRISA0 = 1;
    TRISAbits.TRISA1 = 1;
    TRISAbits.TRISA2 = 1;
    TRISAbits.TRISA3 = 1;
    TRISAbits.TRISA4 = 1;
    ADCON2 = 0x85;
    ADCON0 = 0x01;

    // Initialize LCD
    LCD_init();
    LCD_clear();

    while (1) {
        // Read ADC values
        adc[0] = readAN0();
        adc[1] = readAN1();
        adc[2] = readAN2();
        adc[3] = readAN3();
        adc[4] = readAN4();

        // Convert to voltages
        for (int i = 0; i < 5; i++) {
            voltages[i] = calcVoltage(adc[i], vRef);
        }

        // Display first 3 voltages on LCD line 1
        LCD_cursor_set(1, 1);
        for (int i = 0; i < 3; i++) {
            actualVoltage(voltages[i], buffer);
            LCD_write_string(buffer);
            if (i < 2) LCD_write_string(" ");
        }

        // Display remaining 2 voltages on LCD line 2
        LCD_cursor_set(2, 1);
        for (int i = 3; i < 5; i++) {
            actualVoltage(voltages[i], buffer);
            LCD_write_string(buffer);
            if (i < 4) LCD_write_string(" ");
        }

        __delay_ms(500);
    }
}

// ADC Channel Read Functions
unsigned int readAN0(void) {
    ADCON0 = 0x01;
    __delay_us(5);
    ADCON0bits.GO = 1;
    while (ADCON0bits.GO);
    return ((unsigned int)(ADRESH << 8) + ADRESL);
}

unsigned int readAN1(void) {
    ADCON0 = 0x05;
    __delay_us(5);
    ADCON0bits.GO = 1;
    while (ADCON0bits.GO);
    return ((unsigned int)(ADRESH << 8) + ADRESL);
}

unsigned int readAN2(void) {
    ADCON0 = 0x09;
    __delay_us(5);
    ADCON0bits.GO = 1;
    while (ADCON0bits.GO);
    return ((unsigned int)(ADRESH << 8) + ADRESL);
}

unsigned int readAN3(void) {
    ADCON0 = 0x0D;
    __delay_us(5);
    ADCON0bits.GO = 1;
    while (ADCON0bits.GO);
    return ((unsigned int)(ADRESH << 8) + ADRESL);
}

unsigned int readAN4(void) {
    ADCON0 = 0x11;
    __delay_us(5);
    ADCON0bits.GO = 1;
    while (ADCON0bits.GO);
    return ((unsigned int)(ADRESH << 8) + ADRESL);
}

// Voltage Calculation Function
float calcVoltage(unsigned int adc, float v_ref) {
    return ((float)adc * v_ref) / 1023.0;
}

// Format Voltage Value for LCD Display
void actualVoltage(float value, char* buffer) {
    int intPart = (int)value;
    int decimalPart = (int)((value - intPart) * 100);
    sprintf(buffer, "%d.%02d", intPart, decimalPart);
}
