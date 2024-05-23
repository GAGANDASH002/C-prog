#include<stdio.h>


int compare(int a,int b)
{
    if (a == b) 
    {
        printf("Both numbers are equal");
    } 
    else if (a > b) 
    {
        printf("First number %d is greater than the second number %d\n", a, b);
    } 
    
    else 
    {
        printf("Second number %d is greater than the first number %d\n", b, a);
    }
}
int main()
{
    int x,y;
    printf("Enter the first integer");
    scanf("%d",&x);
    printf("Enter the second integer");
    scanf("%d",&y);
    compare(x,y);
}
