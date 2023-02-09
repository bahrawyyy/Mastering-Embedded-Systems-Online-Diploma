/*
 ============================================================================
 Name        : P3_PointersAss.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

int main(void) {
	char arr[25];
	printf("Enter a string : ");
	fflush(stdin),fflush(stdout);
	scanf("%s",arr);
	// The pointer points to the last char
	char *ptr = &arr[strlen(arr)-1];
	printf("Reverse of string is : ");
	int i;
	// The direction of the loop desn't matter
	// As nothing depends on it
	for(i=0;i<strlen(arr);i++){
	    printf("%c",*ptr);
	    ptr--;
	}
	return 0;
}
