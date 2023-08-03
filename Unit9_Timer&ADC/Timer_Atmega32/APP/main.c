/*
 * main.c
 *
 *  Created on: May 4, 2023
 *      Author: Abdallah
 */

#define Act_As_Master
//#define Act_As_Slave

#define F_CPU 16000000UL

#include "../HAL/Lcd/Lcd.h"
#include <util/delay.h>
#include "../HAL/KPD/KPD_interface.h"
#include "../MCAL/UART/UART.h"
#include "../MCAL/SPI/SPI.h"
#include "../MCAL/I2C/I2C.h"
#include "../MCAL/TIMER/Timer.h"
#include "../HAL/DC_MOTOR/DC_Motor.h"




int main()
{

	 DC_Motor_Init(DC_MOTOR_0);




	while(1)
	{

		//		DC_Motor_Move(DC_MOTOR_0, DC_MOTOR_CW, 30);

	}


	return 0;


}
