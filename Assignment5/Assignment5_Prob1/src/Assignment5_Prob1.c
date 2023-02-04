// Online C compiler to run C program online
#include <stdio.h>


struct Sinfo{
  char name[50];
  int roll;
  float marks;
};


int main() {

    struct Sinfo Student;
    // Write C code here
    printf("Enter information of student : \n");
    printf("Enter name : ");
    fflush(stdin),fflush(stdout);
    scanf("%s",Student.name);
    printf("Enter roll number : ");
    fflush(stdin),fflush(stdout);
    scanf("%d",&Student.roll);
    printf("Enter marks : ");
    fflush(stdin),fflush(stdout);
    scanf("%f",&Student.marks);

    printf("\n\n\nDisplaying information : \n");
    printf("Name : %s\n",Student.name);
    printf("Roll : %d\n",Student.roll);
    printf("Marks : %f\n",Student.marks);

    return 0;
}
