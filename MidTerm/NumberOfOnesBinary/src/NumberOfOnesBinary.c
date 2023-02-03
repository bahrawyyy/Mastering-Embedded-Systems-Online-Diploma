/*
 ============================================================================
 Name        : NumberOfOnesBinary.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void decimal_to_binary(int n){
    int arr[40];
    int i=0;
    printf("%d as binary : ",n);
    while(n>0){
        arr[i] = n % 2;
        n /= 2;
        i++;
    }
    // Printing them in a reversed order
    int count=0;
    int j;
    for(j=i-1;j>=0;j--){
        printf("%d",arr[j]);
        if(arr[j] == 1)
        	count++;
    }
    printf("\nNumber of ones : %d",count);

}

int main(void) {
	decimal_to_binary(15);
	return EXIT_SUCCESS;
}
