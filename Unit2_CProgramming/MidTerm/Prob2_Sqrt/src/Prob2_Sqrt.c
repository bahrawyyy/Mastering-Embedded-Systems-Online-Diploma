/*
 ============================================================================
 Name        : Prob2_Sqrt.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>


float sqr_root(int n){
	return pow(n,0.5);
}


int main(void) {
	printf("%f",sqr_root(10));
	return 0;
}
