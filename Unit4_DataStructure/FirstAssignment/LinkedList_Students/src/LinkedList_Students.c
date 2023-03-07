/*
 ============================================================================
 Name        : LinkedList_Students.c
 Author      : Abdalla Elbahrawy
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "LinkedList.h"

extern struct SStudent* gpFirstStudent;

int main(void) {
    char temp_text[40];
    char index1[5],index2[5];

    while(1)
    {
        DPRINTF("\n =========================");
        DPRINTF("\n\t Choose one of the following options : \n");
        DPRINTF("\n 1: AddStudent  ");
        DPRINTF("\n 2: DeleteStudent  ");
        DPRINTF("\n 3: ViewStudents  ");
        DPRINTF("\n 4: DeleteAll  ");
        DPRINTF("\n 5: GetNthNode  ");
        DPRINTF("\n 6: Get Length Iterative  ");
        DPRINTF("\n 7: Get Length Recursively  ");
        DPRINTF("\n 8: GetNthNode From End  ");
        DPRINTF("\n 9: Get Middle Element  ");
        DPRINTF("\n 10: Detect loop  ");
        DPRINTF("\n 11: Reverse List  ");
        DPRINTF("\n Enter Option Number : ");
        gets(temp_text);
        DPRINTF("\n ==========================");
        switch(atoi(temp_text)){
            case 1:
                AddStudent();
                break;
            case 2:
                DeleteStudent();
                break;
            case 3:
                ViewStudents();
                break;
            case 4:
                DeleteAll();
                break;
            case 5:
            	DPRINTF("\n Enter an index : ");
            	gets(index1);
            	getNthNode(atoi(index1));
            	break;
            case 6:
            	DPRINTF("\n %d", GetLengthIterative());
            	break;
            case 7:
            	DPRINTF("\n %d", GetLengthRecursively(gpFirstStudent));
              	break;
            case 8:
                DPRINTF("\n Enter an index : ");
                gets(index2);
                getNthNodeFromEnd(atoi(index2));
                break;
            case 9:
            	getMiddleElement();
            	break;
            case 10:
            	DetectLoop();
            	break;
            case 11:
            	ReverseList();
            	break;
            default:
                DPRINTF("\n Wrong Option");
                break;


        }
    }

    return 0;
}
