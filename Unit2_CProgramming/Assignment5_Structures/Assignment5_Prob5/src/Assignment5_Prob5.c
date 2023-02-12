// Online C compiler to run C program online
#include <stdio.h>


#define getArea(radius) radius*radius*3.14


int main() {


    double radius=0;
    printf("Enter radius : ");
    fflush(stdin),fflush(stdout);
    scanf("%lf",&radius);
    printf("Area = %lf",getArea(radius));

    return 0;
}
