#include<stdio.h>

int fact(int num);

int main(){
    int num,factorial,i;
    printf("enter the number whose factorial is to be calculated\n");
    scanf("%d",&num);
    factorial=fact(num);
    printf("the factorial is %d",factorial);
}

int fact(num){
    int i,factorial=1;
    for(i=1;i<=num;i++){
        factorial=factorial*i;
    }
    return factorial;

}