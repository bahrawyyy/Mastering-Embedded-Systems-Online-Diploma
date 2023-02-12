// Online C compiler to run C program online
#include <stdio.h>


struct Sstudent{
  char name[50];
  int roll;
  float marks;
};


int main() {

    struct Sstudent Students[10];
    // Write C code here
    printf("Enter information of students : \n");
    int i;
    for(i=0;i<10;i++){
        printf("For roll number %d\n",i+1);
        Students[i].roll = i+1;
        printf("Enter name : ");
        fflush(stdin),fflush(stdout);
        scanf("%s",Students[i].name);
        printf("Enter marks : ");
        fflush(stdin),fflush(stdout);
        scanf("%f",&Students[i].marks);
    }
    printf("Displaying information of students : \n");
    for(i=0;i<10;i++){
        printf("Information For roll number %d\n",i+1);
        printf("Name : %s\n",Students[i].name);
        printf("Marks : %.2f\n",Students[i].marks);
    }


    return 0;
}
