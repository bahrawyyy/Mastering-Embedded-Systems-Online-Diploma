/*
 ============================================================================
 Name        : P2_PointersAss.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {
	// Printing all the alphabets using a pointer
	char alpha[26];   // Array of alphabets
	char *ptr = NULL;
	int i;
	// Filling the array with alphabets
	ptr = alpha;
	for(i=0;i<26;i++){
	    *ptr = 'A' + i;
	    ptr++;
	}
	ptr = alpha;
	printf("The alphabets are : \n");
	for(i=0;i<26;i++){
	    printf("%c ",*ptr);
	    ptr++;
	}


	return 0;
}
