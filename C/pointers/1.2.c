#include<stdio.h>

int comp(){
    int *a,*b,Num1,Num2;
    printf("enter two numbers");
    scanf("%d%d",&Num1,&Num2);


    a=&Num1;
    b=&Num2;

    if(*a>*b){
        printf("%d is greater than %d",*a,*b);

    }
    else {
         printf("%d is greater than %d",*b,*a);
    }
}

int main(){
    comp();
}