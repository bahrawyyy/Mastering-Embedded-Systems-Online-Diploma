/*
 * LinkedList.c
 *
 *  Created on: Mar 7, 2023
 *      Author: Abdallah
 */

#include "LinkedList.h"

struct SStudent* gpFirstStudent = NULL;

void AddStudent()
{
    struct SStudent* pNewStudent;
    struct SStudent* pLastStudent;
    char temp_text[40];
	// Check if list is empty
	if(gpFirstStudent == NULL)
	{
	    // Create a new record
	    pNewStudent = (struct SStudent*)malloc(sizeof(struct SStudent));
	    // Assign it to gpfirst
		gpFirstStudent = pNewStudent;
	}else{
	    // List contains record
	    // Navigate until reaching the last element (that points to NULL)
	    pLastStudent = gpFirstStudent;
	    // While not pointing to NULL, stuck in this while and go to the next element
	    while(pLastStudent->pNextStudent)
	    {
	        pLastStudent = pLastStudent->pNextStudent;
	    }
	    // Create a new record
	    pNewStudent = (struct SStudent*)malloc(sizeof(struct SStudent));

	    pLastStudent->pNextStudent = pNewStudent;

	}

	// Fill New record
	DPRINTF("\n Enter the ID : ");
	gets(temp_text);
	pNewStudent->student.ID = atoi(temp_text);

	DPRINTF("\n Enter student full name : ");
	gets(pNewStudent->student.name);

	DPRINTF("\n Enter the height : ");
	gets(temp_text);
	pNewStudent->student.height = atof(temp_text);


	// Set the next pointer of (new_student) to NULL
	pNewStudent->pNextStudent = NULL;

}


int DeleteStudent()
{
    // Get the selected ID from user
    char temp_text[40];
    unsigned int selectedID;
    DPRINTF("\n Enter the student ID to be deleted: ");
    gets(temp_text);
    selectedID = atoi(temp_text);


    // Check if list is not empty
    if(gpFirstStudent)
    {
        struct SStudent* pSelectedStudent = gpFirstStudent;
        struct SStudent* pPreviousStudent = NULL;

        // Compare each node with selected ID
        // Loop on all records
        while(pSelectedStudent)
        {
            if(pSelectedStudent->student.ID == selectedID)
            {
                // The first student isn't the selected one
                if(pPreviousStudent)
                {
                    pPreviousStudent->pNextStudent = pSelectedStudent->pNextStudent;
                    free(pSelectedStudent);
                    return 1;
                }else{  // The selected is the first
                    gpFirstStudent = pSelectedStudent->pNextStudent;
                    free(pSelectedStudent);
                    return 1;
                }
            }
            // Looping
            pPreviousStudent = pSelectedStudent;
            pSelectedStudent = pSelectedStudent->pNextStudent;
        }
    }
    DPRINTF("\n Can't find the Student ID.");
    return 0;
}


void ViewStudents()
{
    struct SStudent* pCurrentStudent = gpFirstStudent;
    int count = 0;
    if(gpFirstStudent == NULL){
        DPRINTF("\n Empty List");
    }else{
        while(pCurrentStudent)
        {
            DPRINTF("\n Record Number : %d",count+1);
            DPRINTF("\n \t ID : %d",pCurrentStudent->student.ID);
            DPRINTF("\n \t Name : %s",pCurrentStudent->student.name);
            DPRINTF("\n \t Height : %f",pCurrentStudent->student.height);

            pCurrentStudent = pCurrentStudent->pNextStudent;
            count++;
        }
    }
}


void DeleteAll()
{
    struct SStudent* pCurrentStudent = gpFirstStudent;
    if(gpFirstStudent == NULL){
        DPRINTF("\n Empty List");
    }else{
        while(pCurrentStudent)
        {
            struct SStudent* pTempStudent = pCurrentStudent;
            pCurrentStudent = pCurrentStudent->pNextStudent;
            free(pTempStudent);
        }
        gpFirstStudent = NULL;
    }
}


struct SStudent* getNthNode(unsigned int index)
{
	int count = 1;
	struct SStudent* pCurrentStudent = gpFirstStudent;
	if(gpFirstStudent == NULL){
		DPRINTF("\n Empty List");
		return 0;
	}else{
		while(pCurrentStudent)
		{
			if(count == index){
				DPRINTF("\n Record Number : %d",count);
				DPRINTF("\n \t ID : %d",pCurrentStudent->student.ID);
	            DPRINTF("\n \t Name : %s",pCurrentStudent->student.name);
	            DPRINTF("\n \t Height : %f",pCurrentStudent->student.height);
				return pCurrentStudent;
			}
			count++;
			pCurrentStudent = pCurrentStudent->pNextStudent;
		}
	}
	printf("Node doesn't exist");
	return 0;
}


int GetLengthIterative()
{
	int count = 0;
	struct SStudent* pCurrentStudent = gpFirstStudent;
	if(gpFirstStudent == NULL){
		DPRINTF("\n Empty List");
		return 0;
	}else{
		while(pCurrentStudent)
		{
			count++;
			pCurrentStudent = pCurrentStudent->pNextStudent;
		}
	}
	// DPRINTF("\n %d",count);
	return count;
}


int GetLengthRecursively(struct SStudent* pCurrent)
{
    if (pCurrent == NULL) {
        DPRINTF("\n Empty List");
        return 0;
    }

    int count = 1; // start count at 1 for the current node

    if (pCurrent->pNextStudent != NULL) {
        count += GetLengthRecursively(pCurrent->pNextStudent);
    }
    return count;
}


struct SStudent* getNthNodeFromEnd(unsigned int index)
{
	if(gpFirstStudent == NULL){
		DPRINTF("\n Empty List");
		return 0;
	}

	// Using length
//	int length = GetLengthIterative();
//	return getNthNode(length-index+1);


	// Using two pointers
	struct SStudent* main_ptr = gpFirstStudent;
	struct SStudent* ref_ptr = gpFirstStudent;

	int count = 1;
	// First move the ref pointer to n from beginning
	while(count<=index){
		ref_ptr = ref_ptr->pNextStudent;
		count++;
	}
	// Moving both pointers until the ref pointer points to null
	// Hence, main pointer points to the required node
	while(ref_ptr)
	{
		main_ptr = main_ptr->pNextStudent;
		ref_ptr = ref_ptr->pNextStudent;
	}
	DPRINTF("\n \t ID : %d",main_ptr->student.ID);
	DPRINTF("\n \t Name : %s",main_ptr->student.name);
	DPRINTF("\n \t Height : %f",main_ptr->student.height);
	return main_ptr;

}


struct SStudent* getMiddleElement()
{
	int length = GetLengthIterative();
	// Even or odd
	if(length % 2 != 0)
	{
		return getNthNode(length/2);
	}else{
		return getNthNode((length/2)+1);
	}
}




int DetectLoop()
{
	// Move one pointer(slow_p) by one and another pointer(fast_p) by two.
	// If these pointers meet at the same node then there is a loop.
	struct SStudent* Fast_ptr = gpFirstStudent;
	struct SStudent* Slow_ptr = gpFirstStudent;

	while(Fast_ptr && Slow_ptr && Slow_ptr->pNextStudent)
	{
		Fast_ptr = Fast_ptr->pNextStudent->pNextStudent;
		Slow_ptr = Slow_ptr->pNextStudent;

		if(Fast_ptr == Slow_ptr){
			printf("There is a loop");
			return 1;
		}
	}
	printf("Not found any loops");
	return 0;
}


void ReverseList()
{
	struct SStudent* Current_ptr = gpFirstStudent;
	struct SStudent* Previous_ptr = NULL;
	struct SStudent* Next_ptr = NULL;

	if(gpFirstStudent == NULL){
		DPRINTF("\n Empty List");
		return;
	}
	// If it has one element
	if((gpFirstStudent->pNextStudent) == NULL){
		DPRINTF("\n The list has a single element");
		return;
	}

	// Traverse the list
	while(Current_ptr)
	{
		Next_ptr = Current_ptr->pNextStudent;
		Current_ptr->pNextStudent = Previous_ptr;
		Previous_ptr = Current_ptr;
		Current_ptr = Next_ptr;
	}

	// Update the head of the node
	gpFirstStudent = Previous_ptr;
}




