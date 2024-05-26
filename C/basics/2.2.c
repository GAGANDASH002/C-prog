#include<stdio.h>
int main()
{
    int a[100][100];
    int n;int e;
    printf("enter the number of rows you want to print\n");
    scanf("%d",&n);
    printf("enter the number of columns you want to print\n");
    scanf("%d",&e);
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<e;j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }
    printf("The matrix is:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<e;j++)
        {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    printf("1.to find the non zero numbers\n");
    printf("2.To display the upper triangular matrix\n");
    printf("3.To display the elemnets just above the main diagonal\n");
    int q;
    printf("Enter ur choice: \n");
    scanf("%d",&q);
    switch(q)
    {
        case 1:
        {
            int c=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<e;j++)
                {
                   if(a[i][j]!=0)
                {
                    c++;
                } 
                }
                
            }
            printf("The number of non zero numbers present are %d\n",c);
            break;
        }
        case 2:
        {
            for(int i=0;i<n;i++)
            {
                printf("\n");
                for(int j=0;j<e;j++)
                {
                if(j>=i)
                    printf("%d\t",a[i][j]);
                else
                printf("0");
                }
            }
            printf("\n");
            break;
        }
        case 3:
        {

            printf("The elements  above the main diagonal\n");
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(j>i)
                    printf("%d\n",a[i][j]);
                }
                
            }
            printf("The elemnts below the main diagonal\n");
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i>j)
                    printf("%d\n",a[i][j]);
                }
            }
            break;
        }
    }
}