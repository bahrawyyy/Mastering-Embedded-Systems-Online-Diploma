/*
 ============================================================================
 Name        : Prob3_PrimeBetweenTwoNum.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int isPrime(int n){
	if(n<=1){
		return 0;
	}
	int i;
	for(i=2;i<n;i++){
		if(n%i == 0){
			return 0;
		}
	}
	return 1;
}

void primtPrimary(int a,int b){
	int i;
	for(i=a;i<=b;i++){
		if(isPrime(i))
			printf("%d ",i);
	}
}

int main(void) {
	primtPrimary(1,20);
	return 0;
}
