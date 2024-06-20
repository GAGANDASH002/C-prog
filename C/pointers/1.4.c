#include<stdio.h>

int sum()
{
    int num , *a,sum=0;
    a=&num;

    for(num=100;num<=200;num++){
        sum=sum+(*a);
    }
    return sum;

}

int average()
{
    int n,*ptr,avg,add;

    ptr=&n;
    

    for(n=100;n<=200;n++)
    {
        add=add+(*ptr);
    }
    
    for(n=100;n<=200;n++)
    {
        
        avg=add/100;
    
    }
}

int main(){
    printf("the sum is %d", sum());
    printf("the average is %d", average());
}

