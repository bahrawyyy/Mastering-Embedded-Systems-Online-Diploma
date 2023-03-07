/*
 * LinkedList.h
 *
 *  Created on: Mar 7, 2023
 *      Author: Abdallah
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


#define DPRINTF(...)      {fflush(stdout); \
						  fflush(stdin); \
						  printf(__VA_ARGS__); \
						  fflush(stdout); \
						  fflush(stdin);}

// Effective data
struct Sdata
{
    int ID;
    char name[40];
    float height;
};


struct SStudent{
    struct Sdata student;
    struct SStudent* pNextStudent;
};


// APIS
void AddStudent();
int DeleteStudent();
void ViewStudents();
void DeleteAll();
struct SStudent* getNthNode(unsigned int index);
int GetLengthIterative();
int GetLengthRecursively();
struct SStudent* getNthNodeFromEnd(unsigned int index);
struct SStudent* getMiddleElement();
int DetectLoop();
void ReverseList();



#endif /* LINKEDLIST_H_ */
