// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

// Not recursevly
void reverseString(char str[]){
    int i;
    for(i = strlen(str); i >= 0;i--){
        printf("%c",str[i]);
    }
}

// Recursively
void printChar(char str[],int length){
    static int i = 0;    // Initialized only once
    i = length;          // Make a copy to be used
    while(i>0){
        printf("%c",str[i-1]);
        i--;             // Decrementing size
        printChar(str,i);
    }
}

int main(){
    char str[100];
    printf("Enter a sentence : ");   // Ahmed
    fflush(stdin),fflush(stdout);
    gets(str);                       // 01234  len = 5
    printChar(str,strlen(str));
    return 0;
}
