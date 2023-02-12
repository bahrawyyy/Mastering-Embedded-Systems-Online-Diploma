#include <stdio.h>


int power(int base,int por){
    if(por == 0){
        return 1;
    }else if(por == 1){
        return base;
    }else{
        // If powe is even
        if(por%2 == 0){
            return power(base,por/2)*power(base,por/2);
        // else Odd
        }else{
        return base*power(base,por/2)*power(base,por/2);
        }
    }
}

int main(){
    int base,por;
    printf("Enter base number : ");
    fflush(stdin),fflush(stdout);
    scanf("%d",&base);
    printf("Enter power number (positive int) : ");
    fflush(stdin),fflush(stdout);
    scanf("%d",&por);
    printf("%d^%d = %d",base,por,power(base,por));

    return 0;

}
