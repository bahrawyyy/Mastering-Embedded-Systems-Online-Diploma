/*
 ============================================================================
 Name        : SumHunderedRecurs.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void SumtoNum(int num){
	static int sum = 0;
	if(num<0){
		printf("%d",sum);
		return;
	}
	sum += num;
	SumtoNum(num-1);
}

int main(void) {
	SumtoNum(100);
	return 0;
}
