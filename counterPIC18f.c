
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "pic18f4321-Config.h"
#include "LCD.h"
#define _XTAL_FREQ 64000000


        
void main(void) {
    
    LCD_init();
    OSCCONF = 0x70;
	ADCON1 = 0x0F;
    int c = 1;
    int r = 0;
    
    while(1) {
        if (c < 16) {
            c++;
            __delay_ms(100);
        }
        
        if(c == 15 ){
            c = 0;
            r++;
        }
    
    LCD_cursor_set(1,1);
    LCD_write_string("counter: ");
    LCD_write_variable(c, 2);
    
    LCD_cursor_set(2, 1);
    LCD_write_string("round: ");
    LCD_write_variable(r, 2);
    }
    
    return;
}

