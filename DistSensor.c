#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "pic18f4321-Config.h"
#include "LCD.h"
#define _XTAL_FREQ 8000000

void main(void) {
    ADCON1 = 0x0F;
    OSCCON = 0x70;
    
    double timer = 0;
    double dist = 0;
    
    TRISC = 0x00;
    TRISBbits.TRISB0 = 0;
    TRISBbits.TRISB1 = 1;
    TRISD = 0x00;

    LCD_init();
    __delay_ms(50);

    T1CON = 0x31;

    while(1) {
        TMR1H = 0x00;
        TMR1L = 0x00;
        PIR1bits.TMR1IF = 0;

        PORTCbits.RC0 = 0;

        timer = 0;
        dist = 0;

        PORTBbits.RB0 = 0;
        __delay_ms(10);

        for (int i = 0; i < 8; i++) {
            PORTBbits.RB0 = 1;
            __delay_us(25);
            PORTBbits.RB0 = 0;
        }

        T1CONbits.TMR1ON = 1;

        while (!PORTBbits.RB1);

        while (PORTBbits.RB1);

        T1CONbits.TMR1ON = 0;

        timer = TMR1;
        dist = (double) timer / 58;
        LCD_cursor_set(2, 1);
        LCD_write_string("Distance: ");
        LCD_write_variable(dist, 3);
        

        if (dist > 0 && dist <= 50) {
            LCD_cursor_set(1, 1);
            LCD_write_string("Target Detected ");
            PORTCbits.RC0 = 1;
            __delay_ms(1000);
            PORTCbits.RC0 = 0;
        }
    }
}
