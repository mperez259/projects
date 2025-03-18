//PWM motor control on PIC18F4321

#include <xc.h>
#include "pic18f4321-Config.h"
#define _XTAL_FREQ 8000000

void pwm_setup(void);

int x = 0;
int dutyCycle;

void interrupt() ISR() {
    if (INTCONbits.INT0IF) {
        INTCONbits.INT0IF = 0;
        if (!PORTBbits.RB0) {
            x += 201;
            if (x == 20) { CCPR1L = 40; delay_ms(500); CCPR1L = (x * PR2) / 100; }
            dutyCycle = (x * PR2) / 100;
            CCPR1L = dutyCycle;
            CCP1CONbits.DC1B = dutyCycle % 4;
        }
    }
}

void main() {
    //setup
    ADCON1 = 0x0F;
    OSCCON = 0x70;
    TRISB = 1;
    INTCON2bits.INTEDG0 = 0;
    INTCONbits.INT0IE = 1;
    INTCONbits.GIE = 1;
    PIR1bits.TMR2IF = 0;
    pwm_setup();
    //begin interrupt
    while (!PIR1bits.TMR2IF);
    while (1);
}

void pwm_setup(void) {
    PR2 = 63;
    CCPR1L = 0;
    CCP1CONbits.DC1B = 0;
    TRISCbits.TRISC2 = 0;
    CCP1CON = 0x0C;
    T2CON = 0x03;
    TMR2 = 0;
    T2CONbits.TMR2ON = 1;
}