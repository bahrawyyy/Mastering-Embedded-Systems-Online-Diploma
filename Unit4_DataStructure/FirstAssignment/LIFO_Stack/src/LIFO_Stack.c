/*
 ============================================================================
 Name        : LIFO_Stack.c
 Author      : Abdalla Elbahrawy
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "lifo.h"


int main(void) {
	Element_type i,temp=0;
	LIFO_Buf_t UART_LIFO,I2C_LIFO;
	// Static allocation
	LIFO_Init(&UART_LIFO, uart_buff, 5);
	// Dynamic allocation
	Element_type* buffer2 = (Element_type*)malloc(5*sizeof(Element_type));
	LIFO_Init(&I2C_LIFO, buffer2, 5);

	for(i=0;i<5;i++){
		LIFO_Add_Item(&UART_LIFO, i);
		printf("UART_LIFO ADD : %d\n",i);
	}

	for(i=0;i<5;i++){
		LIFO_Get_Item(&UART_LIFO, &temp);
		printf("UART_LIFO Get : %d\n",temp);
	}

	return 0;
}
