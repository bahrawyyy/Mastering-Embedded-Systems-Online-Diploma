/*
 ============================================================================
 Name        : Assignment1_CBasics_2ndFile.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	// Check if a number is even or odd

	int number;
	printf("Enter an integer you want to check : ");
	fflush(stdout),fflush(stdin);
	scanf("%d",&number);
	if(number%2 == 0){
		printf("%d is even",number);
	}else{
		printf("%d is odd",number);
	}


	// Check vowel or consonant
	char c;
	printf("\n\nEnter an alphabet : ");
	fflush(stdout),fflush(stdin);
	scanf("%c",&c);
	if( c == 'i' || c == 'I' || c == 'o' || c == 'O'|| c == 'u' || c == 'U'|| c == 'e' || c == 'E'|| c == 'a' || c == 'A'){
		printf("%c is a vowel",c);
	}else{
		printf("%c is a consonant",c);
	}

	// Getting the largest among three numbers
	float a1,a2,a3;
	printf("\n\nEnter three numbers : ");
	fflush(stdout),fflush(stdin);
	scanf("%f %f %f",&a1,&a2,&a3);
	if(a1>a2){
		if(a1>a3){
			printf("Largest number = %f",a1);
		}else{
			printf("Largest number = %f",a3);
		}
	}
	else{
		if(a2>a3){
			printf("Largest number = %f",a2);
		}else{
			printf("Largest number = %f",a3);
		}
	}


	// Check if a number is positive or negative

	float num;
	printf("\n\nEnter a number : ");
	fflush(stdout),fflush(stdin);
	scanf("%f",&num);
	if(num>0){
		printf("%f is positive",num);
	}
	else if(num<0){
		printf("%f is negative",num);
	}else{
		printf("You entered a zero");
	}


	// Check whether a character is an alphabet or not

	char Character;
	printf("\n\nEnter a character : ");
	fflush(stdout),fflush(stdin);
	scanf("%c",&Character);
	if((Character >= 65 && Character <= 90)||(Character >= 97 && Character <= 122)){
		printf("%c is an alphabet",Character);
	}else{
		printf("%c is not an alphabet",Character);
	}

	// Sum of numbers from 1 to n
	int nn,sum=0;
	printf("\n\nEnter an integer : ");
	fflush(stdout),fflush(stdin);
	scanf("%d",&nn);
	for(int i=0;i<=nn;i++){
		sum+=i;
	}
	printf("Sum equals : %d",sum);


	// Factorial of a number
	int nummm,factorial = 1;
	printf("\n\nEnter an integer : ");
	fflush(stdout),fflush(stdin);
	scanf("%d",&nummm);
	if(nummm < 0){
		printf("Error ! Factorial of negative Numbers doesn't exist");
	}
	else if(nummm == 0){
		factorial = 1;
		printf("Factorial = %d",factorial);
	}else{
		for(int j=nummm;j>0;j--){
			factorial *= j;
		}
		printf("Factorial = %d",factorial);
	}


	// Simple Calculator
	char op;
	float na,nb;
	printf("\n\nEnter operator either + or - or * or / : ");
	fflush(stdout),fflush(stdin);
	scanf("%c",&op);
	fflush(stdout),fflush(stdin);
	printf("Enter two operands : ");
	scanf("%f %f",&na,&nb);
	switch(op){
	case '+':
		printf("%f %c %f = %f",na,op,nb,na+nb);
		break;
	case '-':
		printf("%f %c %f = %f",na,op,nb,na-nb);
		break;
	case '*':
		printf("%f %c %f = %f",na,op,nb,na*nb);
		break;
	case '/':
		printf("%f %c %f = %f",na,op,nb,na/nb);
		break;
	default:
		printf("Invalid operator");
	}


}
