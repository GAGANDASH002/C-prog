#include<stdio.h>

int diff(){
    int *a,*b,num1,num2;
    a=&num1;
    b=&num2;

    return (a-b);
}

int main(){
    int n1,n2;
    printf("enter two numbers");
    scanf("%d%d",&n1,&n2);
    printf("the difference is %d",diff());
}