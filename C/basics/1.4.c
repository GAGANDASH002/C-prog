#include<stdio.h>
#include <stdio.h>
typedef struct complex
{
float real;
float imag;
} complex;
complex add(complex,complex);
complex multiply(complex,complex);
int main()
{
complex c1, c2, c, m;
printf("\nFor 1st complex number \n");
printf("\nEnter real and imaginary part respectively:");
scanf("%f %f", &c1.real, &c1.imag);
printf("\n\nFor 2nd complex number \n");
printf("\nEnter real and imaginary part respectively:");
scanf("%f %f", &c2.real, &c2.imag);
int n;
printf("MENU\n");
printf("1. Adddition\n");
printf("2. Multiplication\n");
printf("Enter ur choice:\n");
scanf("%d",&n);
switch(n)
{
    case 1:
    {
        c = add(c1, c2);
        printf("Sum = %.1f + %.1fi", c.real, c.imag);

        break;
    }
    case 2:
    {
      printf("PRODUCT = %.1f + %.1fi", c.real, c.imag);
      break;  
    }
    default:printf("Exit");
}

printf("\n\nSum = %.1f + %.1fi", c.real, c.imag);
return 0;
}
complex add(complex x, complex y)
{
complex temp;
temp.real = x.real + y.real;
temp.imag = x.imag + y.imag;
return(temp);
}
complex multiply( complex a, complex b)
{
    complex mul;
    mul.real = a.real * b.real - a.imag * b.imag;
    mul.imag = a.real * b.imag + b.real * a.imag;
    return(mul);

}