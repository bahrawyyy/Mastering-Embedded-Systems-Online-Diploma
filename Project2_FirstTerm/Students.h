/*
 * Students.h
 *
 *  Created on: Mar 20, 2023
 *      Author: Abdallah
 */


#ifndef _Student_H_
#define _Student_H_


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define DPRINTF(...)      {fflush(stdout); \
						  fflush(stdin); \
						  printf(__VA_ARGS__); \
						  fflush(stdout); \
						  fflush(stdin);}



#define Element_type struct Sinfo
#define Length 55

// Student Information
struct Sinfo{
	char fname[50];
	char lname[50];
	int roll;
	float GPA;
	int courNum;
	int cid[10];
}students[Length];


// Queue information
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

typedef enum{
	OPEN_FAILED,
	OPEN_SUCCEDD
}FILE_Status;

// Prototypes
FIFO_Buf_Status FIFO_init();
FIFO_Buf_Status add_student_manually();
FILE_Status add_student_file();         ////////
void find_by_roll();
void find_by_fname();
void find_by_course();
void find_total();
void delete_by_roll();        //////
void update_by_roll();
void show_all_info();


#endif
