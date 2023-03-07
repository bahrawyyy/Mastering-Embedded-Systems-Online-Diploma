/*
 * FIFO_Queu.c
 *
 *  Created on: Mar 6, 2023
 *      Author: Abdallah
 */


#include "fifo.h"

void main()
{
	Element_type i,temp;
	FIFO_Buf_t FIFO_UART;
	if(FIFO_init(&FIFO_UART, uart_buff, 5) == FIFO_no_error)
		printf("FIFO_init --> Done\n");


	for(i=0;i<7;i++)
	{
		printf("FIFO Enqueue (%x) \n",i);
		if(FIFO_enqeue(&FIFO_UART, i) == FIFO_no_error)
				printf("FIFO_Enqueue --> Done\n");
		else
			printf("FIFO_Enqueue --> Failed\n");
	}

	FIFO_Print(&FIFO_UART);

	if(FIFO_deqeue(&FIFO_UART, &temp) == FIFO_no_error)
				printf("FIFO_Dequeue %x --> Done\n",temp);
	if(FIFO_deqeue(&FIFO_UART, &temp) == FIFO_no_error)
				printf("FIFO_Dequeue %x --> Done\n",temp);

	FIFO_Print(&FIFO_UART);

}

