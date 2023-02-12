/*
 ============================================================================
 Name        : String_EX1_EX2_EX3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	// Get a frequency of a character
	char str[100];
	char ch;
	int count=0;
	printf("Enter a string : ");
	fflush(stdout),fflush(stdin);
	gets(str);
	printf("Enter a char to find frequency : ");
	fflush(stdout),fflush(stdin);
	scanf("%c",&ch);
	int i;
	for(i=0;i<strlen(str);i++){
		if(str[i] == ch)
			count++;
	}
	printf("Frequency of %c = %d",ch,count);


	// Reverse a string
	printf("\n\n\n");
	char sstr[100],reverse[100];
	printf("Enter a string : ");
	fflush(stdout),fflush(stdin);
	gets(sstr);
	int k;
	for(k=0;k<strlen(sstr);k++){
		reverse[k] = sstr[strlen(sstr) - 1 - k];
	}
	reverse[k] = 0;
	printf("%s",reverse);



	// Calculate the length manually
	printf("\n\n\n");
	char sentence[100];
	int counter=0;
	fflush(stdout),fflush(stdin);
	printf("Enter a string : ");
	fflush(stdout),fflush(stdin);
	gets(sentence);
	int j=0;
	while(sentence[j]!=0){
		counter++;
		j++;
	}
	printf("Length of string : %d",counter);














	return 0;
}
