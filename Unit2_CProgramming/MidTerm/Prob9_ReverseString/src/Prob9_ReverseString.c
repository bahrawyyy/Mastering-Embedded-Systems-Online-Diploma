// To reverse an order of string

// For example --> Abdalla Emad Abdalla Elbahrawy
// The o/p should be --> Elbahrawy Abdalla Emad Abdalla



#include <stdio.h>
#include <string.h>

int main() {
    // Write C code here
    int id1 = 0,j=0,id2 = 0;
    char str[] = "Abdalla Emad Abdalla Elbahrawy";
    int i;
    id2 = strlen(str)-1;
    // Travese the array till a white space is met, and print the string after it
    for(i=strlen(str)-1;i>=0;i--){
        if(str[i] == ' '){
            id1 = i+1;
            for(j=id1;j<=id2;j++){
                printf("%c",str[j]);
            }
            printf(" ");
            id2 = i - 1;
        }
    }
    // Till now we print the whole string except the first part
    // So, we print it separately
    i = 0;
    while(str[i] != ' ')
    {
          printf("%c",str[i]);
          i++;
    }

    return 0;
}
