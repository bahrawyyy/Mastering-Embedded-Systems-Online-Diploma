/*
 * lifo.c
 *
 *  Created on: Mar 6, 2023
 *      Author: Abdallah
 */

#include "lifo.h"

LIFO_Status LIFO_Init(LIFO_Buf_t *lifo_buf, Element_type *buf, unsigned int length)
{
	if(buf == NULL)
		return LIFO_Null;
	lifo_buf->base = buf;
	lifo_buf->head = buf;
	lifo_buf->length = length;
	lifo_buf->count = 0;
	return LIFO_no_error;
}


LIFO_Status LIFO_Add_Item(LIFO_Buf_t *lifo_buf, Element_type item)
{
	// Check if LIFO is valid
	if(!lifo_buf->base || !lifo_buf->head)
		return LIFO_Null;

	// Check if LIFO is full
	// if(lifo_buf->head >= lifo_buf->base + (lifo_buf->length *4))
	if(lifo_buf->count == lifo_buf->length)
		return LIFO_full;

	// Adding
	*(lifo_buf->head) = item;
	lifo_buf->head++;
	lifo_buf->count++;
	return LIFO_no_error;

}

LIFO_Status LIFO_Get_Item(LIFO_Buf_t *lifo_buf, Element_type* item)
{
	// Check if LIFO is valid
	if(!lifo_buf->base || !lifo_buf->head)
		return LIFO_Null;

	// Check if LIFO is empty
	if(lifo_buf->count == 0)
		return LIFO_empty;


	// We are already one step ahead using head
	lifo_buf->head--;
	*item = *(lifo_buf->head);
	lifo_buf->count--;

	return LIFO_no_error;
}

