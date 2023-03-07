/*
 * lifo.h
 *
 *  Created on: Mar 6, 2023
 *      Author: Abdallah
 */

#ifndef LIFO_H_
#define LIFO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Generic configurations

#define Element_type uint8_t
#define width1 5
Element_type uart_buff[width1];


// Type definitions

typedef struct LIFO_Buf{
	unsigned int length;
	unsigned int count;  // No. of elements
	Element_type* base;
	Element_type* head;
}LIFO_Buf_t;

typedef enum{
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,   // In case of popping
	LIFO_Null     // if doesn't exist
}LIFO_Status;

// APIS
// lifo_buf --> for which items
// buf --> The array that will be used
LIFO_Status LIFO_Init(LIFO_Buf_t *lifo_buf, Element_type *buf, unsigned int length);
LIFO_Status LIFO_Add_Item(LIFO_Buf_t *lifo_buf, Element_type item);
LIFO_Status LIFO_Get_Item(LIFO_Buf_t *lifo_buf, Element_type* item);

#endif /* LIFO_H_ */
