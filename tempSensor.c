#include <xc.h>
#include "LCD.h"
#include "pic18f4321-Config.h"

#define _XTAL_FREQ 4000000
#define SENSOR_PORT PORTCbits.RC1  
#define SENSOR_DIR TRISCbits.TRISC1  

void initiate_sensor();
char fetch_byte();
void display_readings(char humMajor, char tempMajor);
char validate_data(char humMajor, char humMinor, char tempMajor, char tempMinor, char checkSum);

void main(void) {
    char majorHumidity, minorHumidity, majorTemperature, minorTemperature, checksum;

    OSCCON = 0x60;  
    ADCON1 = 0x0F;  
    LCD_init();     
    LCD_clear();    

    LCD_cursor_set(1, 1);
    LCD_write_string("Hum: ");
    LCD_cursor_set(2, 1);
    LCD_write_string("Temp: ");

    while (1) {
        
        initiate_sensor();

        
        while (SENSOR_PORT);    // Wait for signal to go low
        while (!SENSOR_PORT);   // Wait for signal to go high
        while (SENSOR_PORT);    // Wait for signal to go low again

        
        majorHumidity = fetch_byte();
        minorHumidity = fetch_byte();
        majorTemperature = fetch_byte();
        minorTemperature = fetch_byte();
        checksum = fetch_byte();

        
        if (validate_data(majorHumidity, minorHumidity, majorTemperature, minorTemperature, checksum)) {
            display_readings(majorHumidity, majorTemperature);
        } else {
            LCD_clear();
            LCD_cursor_set(1, 1);
            LCD_write_string("Checksum Error");
        }

        __delay_ms(2000);  
    }
}

// initiate communication with the DHT11
void initiate_sensor() {
    SENSOR_DIR = 0;       
    LATCbits.LATC1 = 0;   
    __delay_ms(18);       
    LATCbits.LATC1 = 1;   
    __delay_us(25);       
    SENSOR_DIR = 1;      
}

//  read a single byte from the DHT11
char fetch_byte() {
    char receivedData = 0;

    for (int bitCount = 0; bitCount < 8; bitCount++) {
        while (!SENSOR_PORT);  
        __delay_us(35);        
        receivedData <<= 1;   
        if (SENSOR_PORT) {     
            receivedData |= 1;
        }
        while (SENSOR_PORT);   
    }

    return receivedData;
}

// validate the checksum from the DHT11
char validate_data(char humMajor, char humMinor, char tempMajor, char tempMinor, char checkSum) {
    return (checkSum == (humMajor + humMinor + tempMajor + tempMinor));
}


void display_readings(char humMajor, char tempMajor) {
    LCD_cursor_set(1, 6);  
    LCD_write_variable(humMajor, 0);
    LCD_write_string(" %");

    LCD_cursor_set(2, 6);  
    LCD_write_variable(tempMajor, 0);
    LCD_write_string(" C");
}
