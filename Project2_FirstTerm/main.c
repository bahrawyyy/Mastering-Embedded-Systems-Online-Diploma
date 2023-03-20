/*
 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Abdallah
 */


#include "Students.h"


int main()
{
	int choice = 0;

	if(FIFO_init() == FIFO_no_error){
		DPRINTF("Welcome to Students Management system\n");
	}else{
		DPRINTF("Error");
	}


	while(1)
	{
		DPRINTF("\nChoose the operation to perform \n");
		DPRINTF("1. Add the students Details Manually\n");
		DPRINTF("2. Add the students details from text file\n");
		DPRINTF("3. Find the student details by roll number\n");
		DPRINTF("4. Find the student details by first name\n");
		DPRINTF("5. Find the student details by course ID\n");
		DPRINTF("6. Find the total number of students\n");
		DPRINTF("7. Delete the student details by roll number\n");
		DPRINTF("8. Update the student details by roll number\n");
		DPRINTF("9. Show all information\n");
		DPRINTF("10. To Exit\n");
		DPRINTF("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			add_student_manually();
			break;
		case 2:
			add_student_file();
			break;
		case 3:
			find_by_roll();
			break;
		case 4:
			find_by_fname();
			break;
		case 5:
			find_by_course();
			break;
		case 6:
			find_total();
			break;
		case 7:
			delete_by_roll();
			break;
		case 8:
			update_by_roll();
			break;
		case 9:
			show_all_info();
			break;
		case 10:
			return 0;
		}

	}
	return 0;
}
