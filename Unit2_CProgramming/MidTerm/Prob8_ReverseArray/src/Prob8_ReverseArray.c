/*
 ============================================================================
 Name        : Prob8_ReverseArray.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void reverse(int arr[],int size){
	int i=0;
	for(i=size-1;i>=0;i--){
		printf("%d ",arr[i]);
	}
}

int main(void) {
	int a[5] = {1,2,3,4,5};
	int size;
	size = sizeof(a)/sizeof(a[0]);
	reverse(a,size);
	return 0;
}
