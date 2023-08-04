/*
 * main.c
 *
 *  Created on: May 4, 2023
 *      Author: Abdallah
 */



#define F_CPU 16000000UL

#include "../HAL/Lcd/Lcd.h"
#include <util/delay.h>
#include "../MCAL/ADC/ADC.h"


// Reading lm35 real value


// LDR intensity as a percent
// With custom character


#define BLANK 	0
#define Celsius	1


int main()
{
	DIO_ES_tInit();
	Lcd_ES_tInit();
	ADC_init();
	u8 Blank[] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
	u8 customChar_Celsius[8] = {0x1C, 0x14, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00};


	Lcd_CreateCustomCharacter(Blank,BLANK);
	Lcd_CreateCustomCharacter(customChar_Celsius,Celsius);


	u16 Lm_read;
	u8 Ldr_Percent,Dashes_Num;

	lcd_ES_tclear();
	Lcd_ES_tsendString("Lm35 : ");
//	Lcd_ES_tsendString("Ldr Out : ");

	u8 i;


    while (1)
    {
    	Lcd_ES_tsendString("   ");
    	LCD_ES_tGoTo(0, 10);


    	// Ldr Application
//    	Ldr_Percent = (u8)((ADC_read(ADC7)/1024.0)*100);
//    	Lcd_ES_tdisplayNum(Ldr_Percent);
//    	Lcd_ES_tsendChar('%');
//    	LCD_ES_tGoTo(1, 0);
//    	Lcd_ES_tsendString("                ");
//    	LCD_ES_tGoTo(1, 0);
//    	Dashes_Num = (Ldr_Percent * 16)/100;
//    	for(i=0;i<Dashes_Num;i++)
//    	{
//    		Lcd_ES_tsendChar(BLANK);
//    	}


    	// Lm35 Application
    	Lm_read = (u16)(ADC_read(ADC0) * 0.488);
    	Lcd_ES_tdisplayNum(Lm_read);
   	Lcd_ES_tsendChar(Celsius);
    	Lcd_ES_tsendChar('C');

    	_delay_ms(500);

    }

    return 0;
}
