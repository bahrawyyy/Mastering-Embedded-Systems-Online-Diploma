// Online C compiler to run C program online
#include <stdio.h>


struct Sdistance{
  float feet;
  float inch;
};

int main() {
    struct Sdistance distance1,distance2;

    printf("Enter information of 1st distance : \n");
    printf("Enter feet : ");
    fflush(stdin),fflush(stdout);
    scanf("%f",&distance1.feet);
    printf("Enter inch : ");
    fflush(stdin),fflush(stdout);
    scanf("%f",&distance1.inch);
    printf("Enter information of 1st distance : \n");
    printf("Enter feet : ");
    fflush(stdin),fflush(stdout);
    scanf("%f",&distance2.feet);
    printf("Enter inch : ");
    fflush(stdin),fflush(stdout);
    scanf("%f",&distance2.inch);

    float SumFeet=0,SumInches=0,countFeet = 0;

    SumInches = distance1.inch + distance2.inch;
    while(SumInches >= 12){
        countFeet++;
        SumInches -= 12;
    }

    SumFeet = distance1.feet + distance2.feet + countFeet;

    printf("\n\nSum of distances = %.0f'-%0.2f'\n",SumFeet,SumInches);

    return 0;
}
