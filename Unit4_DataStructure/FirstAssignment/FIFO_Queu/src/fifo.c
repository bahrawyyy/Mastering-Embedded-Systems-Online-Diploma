/*
 * fifo.c
 *
 *  Created on: Mar 6, 2023
 *      Author: Abdallah
 */

#include "fifo.h"

FIFO_Buf_Status FIFO_init(FIFO_Buf_t* fifo, Element_type* buf, uint32_t length)
{
	if(buf == NULL)
		return FIFO_null;

	fifo->base = buf;
	fifo->head = buf;
	fifo->tail = buf;
	fifo->length = length;
	fifo->count = 0;

	return FIFO_no_error;
}
FIFO_Buf_Status FIFO_enqeue(FIFO_Buf_t* fifo, Element_type item)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	// FIFO is full or not
	if(FIFO_isFull(fifo) == FIFO_full)
		return FIFO_full;
	*(fifo->head) = item;
	fifo->count++;


	// Circular FIFO
	if(fifo->head == (fifo->base + (fifo->length * sizeof(Element_type))))
		fifo->head = fifo->base;
	else
		fifo->head++;

	return FIFO_no_error;
}
FIFO_Buf_Status FIFO_deqeue(FIFO_Buf_t* fifo, Element_type* item)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;

	// Check if is empty
	if(fifo->count == 0)
		return FIFO_empty;

	*item = *(fifo->tail);
	fifo->count--;
	if(fifo->tail == (fifo->base + (fifo->length * sizeof(Element_type))))
		fifo->tail = fifo->base;
	else
		fifo->tail++;

	return FIFO_no_error;

}
FIFO_Buf_Status FIFO_isFull(FIFO_Buf_t* fifo)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;

	if(fifo->count == fifo->length)
		return FIFO_full;

	return FIFO_no_error;

}
void FIFO_Print(FIFO_Buf_t* fifo)
{
	// From tail to head
	Element_type* temp;
	int i;
	if(fifo->count == 0)
	{
		printf("FIFO is Empty");
	}else{
		temp = fifo->tail;
		printf("\n ====== FIFO_Print ========= \n");
		for(i=0;i<fifo->count;i++){
			printf("\t %X \n",*temp);
			temp++;
		}
		printf("========================= \n");

	}
}
