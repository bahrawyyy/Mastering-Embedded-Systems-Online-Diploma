/*
 ============================================================================
 Name        : Prob1_SumDigits.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int SumDigits(int num){
	int digit = 0;
	while(num!=0){
		digit += (num % 10);
		num /= 10;
		SumDigits(num);
	}
	return digit;
}

int main(void) {
	printf("%d\t",SumDigits(123));
	printf("%d\t",SumDigits(4565));
	return 0;
}
