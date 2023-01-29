/*
 ============================================================================
 Name        : Asssignemnt2_Arrays_Strings.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {


	// C program to find sum of two matrix of order 2*2
	float Matrix1[2][2],Matrix2[2][2];
	int i,j;
	printf("First Array : \n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("Matrix1[%d][%d] : ",i,j);
			fflush(stdin),fflush(stdout);
			scanf("%f",&Matrix1[i][j]);
		}
	}
	printf("Second Array : \n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("Matrix2[%d][%d] : ",i,j);
			fflush(stdin),fflush(stdout);
			scanf("%f",&Matrix2[i][j]);
			Matrix1[i][j] += Matrix2[i][j];
		}
	}
	printf("Summation Array : \n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%f  ",Matrix1[i][j]);
		}
		printf("\n");
	}




	// Avreage using arrays
	printf("\n\n\n\n");
	int n;
	float sum = 0;
	printf("Enter no. of elements : ");
	fflush(stdin),fflush(stdout);
	scanf("%d",&n);
	float array[n];
	for(int k=1;k<=n;k++){
		printf("Enter element no.%d : ",k);
		fflush(stdin),fflush(stdout);
		scanf("%f",&array[k-1]);
		sum += array[k-1];
	}
	printf("Average equals : %f",sum/n);





//	// Using continue if the user enters a zero
//	int j;
//	float number,multiply=1;
//	for(j=1;j<=4;j++){
//		printf("Enter element no. %d : ",j);
//		fflush(stdin),fflush(stdout);
//		scanf("%f",&number);
//		if(number == 0)
//			continue;
//		multiply *= number;
//	}
//	printf("Multiplication equals : %f\n",multiply);
//
//
//	// Calculate the average of n numbers and exclude the negative and end the program
//	int n,i;
//	float num=0,sum=0;
//	printf("Enter no. of elements : ");
//	fflush(stdin),fflush(stdout);
//	scanf("%d",&n);
//	for(i=1;i<=n;i++){
//		printf("Enter element no. %d : ",i);
//		fflush(stdin),fflush(stdout);
//		scanf("%f",&num);
//		if(num<0){
//			num = 0;
//			break;
//		}
//		sum += num;
//	}
//	printf("Average equals : %f",sum/(i-1));
}
