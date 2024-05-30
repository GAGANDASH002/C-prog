#include<stdio.h>

int main()
{
    int num,rem,sum=0,ognum;
    printf("enter the number\n");
    scanf("%d",&num);
    num=ognum;
    while(ognum!=0){
        rem=ognum%10;
        sum=sum+rem*rem*rem;
        ognum=num/10;

    }
    if(sum==num){
        printf("its an armstrong number\n");
    }
    else{
        printf("its not an armstrong number\n");
    }
    return 0;
}