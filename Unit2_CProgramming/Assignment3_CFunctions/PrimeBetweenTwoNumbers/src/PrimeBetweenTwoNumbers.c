/*
 ============================================================================
 Name        : PrimeBetweenTwoNumbers.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


// Online C compiler to run C program online
#include <stdio.h>

int isPrime(int n){
    int counter = 0;
   for(int i=2;i<n;i++){
       if(n % i == 0){
           counter++;
       }
   }
   if(counter == 0){
       return 1;
   }else{
       return 0;
   }
}

void printPrimeNumbers(int x, int y){

    int i;
    printf("Prime numbers between %d and %d are : ",x,y);
    for(i=x;i<=y;i++){
        if(isPrime(i)){
            printf("%d ",i);
        }
    }

}

int main() {
    // Write C code here
    int x,y;
    printf("Enter two numbers(intervals) : ");
    fflush(stdout),fflush(stdin);
    scanf("%d %d",&x,&y);
    printPrimeNumbers(x,y);

    return 0;
}
