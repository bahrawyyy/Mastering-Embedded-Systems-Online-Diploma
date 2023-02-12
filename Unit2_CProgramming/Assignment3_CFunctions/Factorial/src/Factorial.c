// Online C compiler to run C program online
#include <stdio.h>


int factorial(int n){
    if((n==0) || (n==1)){
        return 1;
    }else{
        return n*factorial(n-1);
    }
}

int main(){
    int n;
    printf("Enter a positive integer : ");
    fflush(stdout),fflush(stdin);
    scanf("%d",&n);
    if(n<0){
        printf("Negative Numbers are not allowed");
    }else{
        printf("Factorial of %d = %d",n,factorial(n));
    }
    return 0;
}
