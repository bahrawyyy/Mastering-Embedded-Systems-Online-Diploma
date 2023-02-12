/*
 ============================================================================
 Name        : Assignment1_CBasics.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	// Write C Program to Print a Sentence

	printf("########## Example 1 ########\n");
	printf("C programming\n");

	// Write C Program to Print a Integer Entered by a User

	printf("\n\n########## Example 2 ########\n");
	int x;
	printf("Enter a number : ");
	fflush(stdout),fflush(stdin);
	scanf("%d",&x);
	printf("You entered : %d",x);

	// Write C Program to Add Two Integers

	printf("\n\n########## Example 3 ########\n");
	int num1,num2;
	printf("Enter two integers : ");
	fflush(stdout),fflush(stdin);
	scanf("%d %d",&num1,&num2);
	printf("Sum equals : %d",num1+num2);


	// Write C Program to Multiply two Floating Point Numbers

	printf("\n\n########## Example 4 ########\n");
	float n1,n2;
	printf("Enter two numbers : ");
	fflush(stdout),fflush(stdin);
	scanf("%f %f",&n1,&n2);
	printf("Multiplication equals : %f",n1*n2);


	// Write C Program to Find ASCII Value of a Character

	printf("\n\n########## Example 5 ########\n");
	char c;
	printf("Enter a character : ");
	fflush(stdout),fflush(stdin);
	scanf("%c",&c);
	printf("The ASCII of %c equals %d",c,c);

	// Write Source Code to Swap Two Numbers

	printf("\n\n########## Example 6 ########\n");
	float a,b;
	printf("Enter Value of a : ");
	fflush(stdout),fflush(stdin);
	scanf("%f",&a);
	printf("Enter Value of b : ");
	fflush(stdout),fflush(stdin);
	scanf("%f",&b);
	float temp = 0;
	temp = a;
	a = b;
	b = temp;
	printf("After Swapping\n a = %f\n b = %f",a,b);

	// Write Source Code to Swap Two Numbers without temp variable

	printf("\n\n########## Example 7 ########\n");
	float xa,xb;
	printf("Enter two numbers : ");
	fflush(stdout),fflush(stdin);
	scanf("%f %f",&xa,&xb);
	xa = xa * xb;
	xb = xa / xb;
	xa = xa / xb;
	printf("After Swapping\n a = %f\n b = %f",xa,xb);

	return 0;
}
