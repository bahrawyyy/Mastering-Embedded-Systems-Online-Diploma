/*
 ============================================================================
 Name        : Prob6_UniqueNumXOR.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int uniqueNum(int arr[], int n){
	int result = 0;
	for(int i=0;i<n;i++){
		result ^= arr[i];    // XORing number with itself return 0
	}
	return result;
}

int main(void) {
	int arr[] = {4,2,5,2,5,7,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("%d",uniqueNum(arr,size));
	return 0;
}
