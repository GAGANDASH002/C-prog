#include<stdio.h>

void checkVowel()
{
    char *ptr , letter;
    printf("the letter is\n");
    scanf("%c",&letter);
    ptr=&letter;

    if(*ptr=="a"||"e"||"i"||"o"||"u")
    {
        printf("it is a vowel");

    }
    else
    {
        printf("it is a consonant");
    }

    }

    void main(){
        
       
        checkVowel();
}

