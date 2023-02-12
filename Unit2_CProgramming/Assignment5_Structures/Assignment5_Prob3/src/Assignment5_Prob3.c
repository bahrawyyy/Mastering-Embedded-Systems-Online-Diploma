// Online C compiler to run C program online
#include <stdio.h>


struct SComplex{
  double real;
  double imag;
};




int main() {

    struct SComplex Complex1,Complex2,SumComplex;
    // Write C code here
    printf("For 1st Complex Number : \nEnter real and imaginary respectively : ");
    fflush(stdin),fflush(stdout);
    scanf("%lf %lf",&Complex1.real,&Complex1.imag);
    printf("For 2nd Complex Number : \nEnter real and imaginary respectively : ");
    fflush(stdin),fflush(stdout);
    scanf("%lf %lf",&Complex2.real,&Complex2.imag);

    SumComplex.real = Complex1.real + Complex2.real;
    SumComplex.imag = Complex1.imag + Complex2.imag;

    printf("Sum = %.2lf + %.2lfi",SumComplex.real,SumComplex.imag);

    return 0;
}
