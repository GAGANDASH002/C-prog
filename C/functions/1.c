#include<stdio.h>

int sum(int a,int b);

int main(){
    int a,b;
    printf("enter the numbers to be added\n");
    scanf("%d%d",&a,&b);
    printf("the sum  is %d",sum(a,b));


}

int sum(a,b){
    return a+b;
}