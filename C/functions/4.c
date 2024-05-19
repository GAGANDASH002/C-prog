#include<stdio.h>

int ispalindrome(int num);

int main(){
    int number;
    printf("enter the number");
    scanf("%d",&number);
     if (isPalindrome(number))
        printf("%d is a palindrome.", number);
    else
        printf("%d is not a palindrome.", number);

}

int ispalindrome(int num){
    
    int reversed=0, original,i,remainder;
    
     original=num;
     while(num>0){
        remainder=num%10;
        reversed=reversed*10+remainder;
        num=num/10;
    }
    if(original==reversed){
        printf("palindrome");
    }
    else{
        printf("not palindrome");
    }

}


