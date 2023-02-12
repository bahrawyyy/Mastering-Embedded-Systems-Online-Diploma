/*
 ============================================================================
 Name        : Arrays_EX3_EX4_EX5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {


	// Transpose of Array
	int r,c;
	int j,i;
	printf("Enter number of rows and columns : ");
	fflush(stdout),fflush(stdin);
	scanf("%d %d",&r,&c);
	float Array[r][c];
	// Inserting Elements
	printf("Insert the elements : \n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("Array[%d][%d] : ",i,j);
			fflush(stdout),fflush(stdin);
			scanf("%f",&Array[i][j]);
		}
	}
	// Printing the elements
	printf("\n\nThe Array You entered : \n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%f\t\t",Array[i][j]);
		}
		printf("\n");
	}
	// Transpose the array
	float ArrayT[c][r];
	printf("\n\nThe Transposed array : \n");
	for(i=0;i<c;i++){
		for(j=0;j<r;j++){
			ArrayT[i][j] = Array[j][i];
		}
	}
	for(i=0;i<c;i++){
		for(j=0;j<r;j++){
			printf("%f\t\t",ArrayT[i][j]);
		}
		printf("\n");
	}



	// Insert an element in Array
	printf("\n\n\n");
	int n;
	printf("Enter no. of element : ");
	fflush(stdout),fflush(stdin);
	scanf("%d",&n);
	float Arrayn[n];
	printf("Enter Elements : ");
	int ij;
	for(ij=0;ij<n;ij++){
		fflush(stdout),fflush(stdin);
		scanf("%f",&Arrayn[ij]);
	}
	for(ij=0;ij<n;ij++){
		printf("%f\t",Arrayn[ij]);
	}
	fflush(stdout),fflush(stdin);
	printf("\nEnter the element : ");
	fflush(stdout),fflush(stdin);
	float elementx;
	int index;
	float Arrayx[n+1];
	scanf("%f",&elementx);
	printf("Enter the Location : ");
	fflush(stdout),fflush(stdin);
	scanf("%d",&index);
	int loc = index-1;
	for(ij=0;ij<n+1;ij++){
		if(ij<loc){
			Arrayx[ij] = Arrayn[ij];
		}else if(ij == loc){
			Arrayx[ij] = elementx;
		}else{
			Arrayx[ij] = Arrayn[ij-1];
		}
	}
	for(ij=0;ij<n+1;ij++){
		printf("%f\t",Arrayx[ij]);
	}




	// Search an element in the array
	printf("\n\n\n");
	int size,k;
	float elm;
	printf("Enter no. of elements : ");
	fflush(stdout),fflush(stdin);
	scanf("%d",&size);
	float element[size];
	for(k=0;k<size;k++){
		scanf("%f",&element[k]);
	}
	printf("Enter the element to be searched : ");
	fflush(stdout),fflush(stdin);
	scanf("%f",&elm);
	for(k=0;k<size;k++){
		if(elm == element[k]){
			break;
		}
	}
	if(k == size){
		printf("Not found");
	}else{
		printf("Number found at location : %d",k+1);
	}



	return EXIT_SUCCESS;
}
