#include<stdio.h>

int comp(int a, int b);

int main(){
    int a,b;
     printf("enter two numbers\n");
     scanf("%d%d",&a,&b);
    comp(a,b);
}

int comp(a,b){
    if(a>b){
        printf("%d is greater than %d",a,b);
    }
    else{
        printf("%d is greater than %d",b,a);

    }
}
