#include<stdio.h>
 
int fib(n);

int main(){
    int n=4;
    int result=fib(n);
    printf("fibonacci of %d is %d",n,result);
    return 0;
}

int fib(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return fib(n-1) + fib(n-2);
    }
}