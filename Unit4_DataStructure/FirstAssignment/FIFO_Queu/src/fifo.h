/*
 * fifo.h
 *
 *  Created on: Mar 6, 2023
 *      Author: Abdallah
 */

#ifndef FIFO_H_
#define FIFO_H_

#include <stdio.h>
#include <stdint.h>

// USER Configurations (Generic) Important
// Specify how many bytes (uint8_t, uint16_t, ...)

#define Element_type uint8_t
// Create buffer (Same type)
#define width1 5
Element_type uart_buff[width1];


// FIFO data types
typedef struct{
	unsigned int length;
	unsigned int count;
	Element_type* base;
	Element_type* head;
	Element_type* tail;   // Circular
}FIFO_Buf_t;

typedef enum{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_null
}FIFO_Buf_Status;


// APIS
FIFO_Buf_Status FIFO_init(FIFO_Buf_t* fifo, Element_type* buf, uint32_t length);
FIFO_Buf_Status FIFO_enqeue(FIFO_Buf_t* fifo, Element_type item);
FIFO_Buf_Status FIFO_deqeue(FIFO_Buf_t* fifo, Element_type* item);
FIFO_Buf_Status FIFO_isFull(FIFO_Buf_t* fifo);
void FIFO_Print(FIFO_Buf_t* fifo);


#endif /* FIFO_H_ */
