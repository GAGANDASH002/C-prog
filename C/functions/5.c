
#include<stdio.h>
int avg();


int main(){
    int n1,n2,n3;
    printf("enter three numbers\n");
    scanf("%d%d%d",&n1,&n2,&n3);
    avg();
    printf("the average is %d",avg());
}

int avg(){   
    int a,b,c,sum;
    sum=a+b+c;
    return sum/3;
}