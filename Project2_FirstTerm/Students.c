/*
 * Students.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Abdallah
 */


#include "Students.h"

FIFO_Buf_t *FIFO_DataBase = NULL;
int CoursesNum;

FIFO_Buf_Status FIFO_init()
{
	FIFO_DataBase = malloc(sizeof(FIFO_Buf_t));

	if(FIFO_DataBase == NULL)
		return FIFO_null;

	FIFO_DataBase->base = students;
	FIFO_DataBase->head = students;
	FIFO_DataBase->tail = students;
	FIFO_DataBase->length = Length;
	FIFO_DataBase->count = 0;

	return FIFO_no_error;
}

FIFO_Buf_Status add_student_manually()
{
	char temp_text[40];
	// Check if the FIFO isn't full
	if(FIFO_DataBase->count == FIFO_DataBase->length){
		DPRINTF("DataBase is full !!!\n");
		return FIFO_full;
	}
	// Fill new record
	Element_type student;
	DPRINTF("\nEnter first name : ");
	gets(student.fname);
	DPRINTF("\nEnter last name : ");
	gets(student.lname);
	DPRINTF("\nEnter roll number : ");
	gets(temp_text);
	student.roll = atoi(temp_text);
	DPRINTF("\nEnter GPA : ");
	gets(temp_text);
	student.GPA = atof(temp_text);
	DPRINTF("\nEnter number of courses you are enrolling in : ");
	scanf("%d",&CoursesNum);
	DPRINTF("\nEnter courses id : ");
	int i;
	for(i=0;i<CoursesNum;i++)
		scanf("%d",&student.cid[i]);


	*(FIFO_DataBase->head) = student;
	FIFO_DataBase->count++;

	// Circular FIFO
	if(FIFO_DataBase->head == (FIFO_DataBase->base + (FIFO_DataBase->length * sizeof(Element_type))))
		FIFO_DataBase->head = FIFO_DataBase->base;
	else
		FIFO_DataBase->head++;

	return FIFO_no_error;
}

void find_by_roll()
{
	int roll,counter=0;
	DPRINTF("Enter roll number : ");
	scanf("%d",&roll);
	int i = 0;
	while(i<=FIFO_DataBase->count)
	{
		if(students[i].roll == roll)
		{
			counter++;
			DPRINTF("==================================\n");
			DPRINTF("Roll number : %d",students[i].roll);
			DPRINTF("\nFirst name : %s",students[i].fname);
			DPRINTF("\nLast name : %s",students[i].lname);
			DPRINTF("\nGPA : %f",students[i].GPA);
			int j;
			DPRINTF("\nCourses ID : ");
			for(j=0;j<CoursesNum;j++){
				DPRINTF("%d ",students[i].cid[j]);
			}
			DPRINTF("\n==================================\n");
		}
		i++;
	}
	if(counter == 0)
		DPRINTF("Error ! Roll number : %d not found\n",roll);

}


void find_by_fname()
{
	int counter=0;
	char first[50];
	DPRINTF("Enter first name : ");
	gets(first);
	int i = 0;
	while(i<=FIFO_DataBase->count)
	{
		if(!stricmp(first,students[i].fname))
		{
			counter++;
			DPRINTF("==================================\n");
			DPRINTF("Roll number : %d",students[i].roll);
			DPRINTF("\nFirst name : %s",students[i].fname);
			DPRINTF("\nLast name : %s",students[i].lname);
			DPRINTF("\nGPA : %f",students[i].GPA);
			int j;
			DPRINTF("\nCourses ID : ");
			for(j=0;j<CoursesNum;j++){
				DPRINTF("%d ",students[i].cid[j]);
			}
			DPRINTF("\n==================================\n");
		}
		i++;
	}
	if(counter == 0)
		DPRINTF("Error ! First name : %s not found\n",first);
}


void find_by_course()
{
	int ID,counter=0;
	DPRINTF("Enter course ID : ");
	scanf("%d",&ID);
	int i = 0, j = 0;
	while(i<=FIFO_DataBase->count)
	{
		for(j=0;j<CoursesNum;j++){
			if(ID == students[i].cid[j]){
				counter++;
				DPRINTF("==================================\n");
				DPRINTF("Roll number : %d",students[i].roll);
				DPRINTF("\nFirst name : %s",students[i].fname);
				DPRINTF("\nLast name : %s",students[i].lname);
				DPRINTF("\nGPA : %f",students[i].GPA);
				DPRINTF("\n==================================\n");
			}
		}
		i++;
	}
	if(counter == 0)
		DPRINTF("Error ! Course ID : %d not found\n",ID);
}

void find_total()
{
	DPRINTF("Total Number of students : %d\n",FIFO_DataBase->count);
	DPRINTF("You can add up to %d students\n",Length);
	DPRINTF("You can add %d more students\n",Length - (FIFO_DataBase->count));
}


void update_by_roll()
{
	int counter=0;
	int k;
	char option[3];
	int roll;
	DPRINTF("Enter roll number : ");
	scanf("%d",&roll);
	int i = 0;
	while(i<=FIFO_DataBase->count)
	{
		if(roll == students[i].roll)
		{
			counter++;
			DPRINTF("Valid Options\n");
			DPRINTF("1. First Name\n");
			DPRINTF("2. Last Name\n");
			DPRINTF("3. GPA\n");
			DPRINTF("4. Courses ID\n");
			DPRINTF("Enter Option to edit :");
			gets(option);
			switch(atoi(option)){
			case 1:
				gets(students[i].fname);
				break;
			case 2:
				gets(students[i].lname);
				break;
			case 3:
				scanf("%f",&students[i].GPA);
				break;
			case 4:
				for(k=0;k<CoursesNum;k++)
					scanf("%d",&students[i].cid[k]);
				break;
			}

			DPRINTF("\n==================================\n");
			DPRINTF("Roll number : %d",students[i].roll);
			DPRINTF("\nFirst name : %s",students[i].fname);
			DPRINTF("\nLast name : %s",students[i].lname);
			DPRINTF("\nGPA : %f",students[i].GPA);
			int j;
			DPRINTF("\nCourses ID : ");
			for(j=0;j<CoursesNum;j++){
				DPRINTF("%d ",students[i].cid[j]);
			}
			DPRINTF("\n==================================\n");
		}
		i++;
	}
	if(counter == 0)
		DPRINTF("Error ! Roll number : %d not found\n",roll);

}

void show_all_info()
{
	int i = 0;
	while(i<FIFO_DataBase->count)
	{
			DPRINTF("==================================\n");
			DPRINTF("Roll number : %d",students[i].roll);
			DPRINTF("\nFirst name : %s",students[i].fname);
			DPRINTF("\nLast name : %s",students[i].lname);
			DPRINTF("\nGPA : %f",students[i].GPA);
			int j;
			DPRINTF("\nCourses ID : ");
			for(j=0;j<CoursesNum;j++){
				DPRINTF("%d ",students[i].cid[j]);
			}
			DPRINTF("\n==================================\n");
		i++;
	}
}

void delete_by_roll()
{
	int roll,counter=0;
	DPRINTF("Enter roll number : ");
	scanf("%d",&roll);
	int i = 0;
	while(i<=FIFO_DataBase->count)
	{
		if(students[i].roll == roll)
		{
			int k;
			for(k=i;k<FIFO_DataBase->count-1;k++)
			{
				students[i] = students[i+1];   // Shifting left from the index to the last element
			}
			FIFO_DataBase->count--;
			counter++;
			DPRINTF("==================================\n");
			DPRINTF("Student deleted Successfully");
			DPRINTF("\n==================================\n");
		}
		i++;
	}
	if(counter == 0)
		DPRINTF("Error ! Roll number : %d not found\n",roll);
}




FILE_Status add_student_file()
{
	FILE *fp = fopen("Data.txt", "r");
	if (fp == NULL) {
		printf("Failed to open file\n");
		return OPEN_FAILED;
	}

	Element_type student[55];
	int num_students = 0;

	while (fscanf(fp, "%s %s %d %f %d", student[num_students].fname, student[num_students].lname, &student[num_students].roll, &student[num_students].GPA, &student[num_students].courNum) == 5) {
		for (int i = 0; i < student[num_students].courNum; i++) {
			fscanf(fp, "%d", &student[num_students].cid[i]);
		}

		*(FIFO_DataBase->head) = student[num_students];
		FIFO_DataBase->count++;

		// Circular FIFO
		if(FIFO_DataBase->head == (FIFO_DataBase->base + (FIFO_DataBase->length * sizeof(Element_type))))
			FIFO_DataBase->head = FIFO_DataBase->base;
		else
			FIFO_DataBase->head++;

		num_students++;
	}

	fclose(fp);

	// Print out the data to verify it was read correctly
	for (int i = 0; i < num_students; i++) {
	    DPRINTF("%s %s %d %f %d ", student[i].fname, student[i].lname, student[i].roll, student[i].GPA, student[i].courNum);
	    for (int j = 0; j < student[i].courNum; j++) {
	        DPRINTF("%d ", student[i].cid[j]);
	    }
	    DPRINTF("\n");
	}


	return OPEN_SUCCEDD;
}
