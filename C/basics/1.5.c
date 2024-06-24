#include <stdio.h>
void main() 
{
    int n,count1=0,count2=0;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
 
    int arr[n];
 
    //Take n elements as input from the user
    printf("Enter %d elements in the array: ",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
 
    //Print all the even numbers

    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==0){
            count1++;
    }
    }
 
    //print all the odd numbers
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==1){
            count2++;
    }
    }
    printf("Number of odd numbers are: %d\n",count2);
    printf("Number of even numbers are: %d",count1);
}