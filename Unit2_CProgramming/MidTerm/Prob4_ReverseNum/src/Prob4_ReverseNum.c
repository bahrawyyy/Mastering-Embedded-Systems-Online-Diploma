/*
 ============================================================================
 Name        : Prob4_ReverseNum.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>

int get_nDigits(int num){
	int digits = 0;
	while(num!=0){
		digits++;
		num/=10;
	}
	return digits;
}

int reverse(int num){
	int reversed_num = 0;
	int num_digits = get_nDigits(num);
	int i,digit=0;
	for(i=num_digits-1;i>=0;i--){
		digit = num % 10;
		reversed_num += digit * pow(10,i);
		num /= 10;
	}
	return reversed_num;
}

int main(void) {
	printf("%d ",reverse(2457));
	printf("%d ",reverse(1057));
	return 0;
}
