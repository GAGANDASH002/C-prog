#include<stdio.h>
int main()
{
    int a[100];
    int n;
    printf("enter the number of elements you want to print\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("1.INSEERTION\n");
    printf("2.DELETION\n");
    printf("3.LINEAR SEARCH\n");
    printf("4.TRAVERSE\n");
    int q;
    printf("Enter ur choice: \n");
    scanf("%d",&q);
    switch(q)
    {
        case 1:
        {
             int e;
        printf("enter the number you want to insert\n");
        scanf("%d", &e);
        int p;
        printf("Enter the position in which you want to insert ur valuee\n");
        scanf("%d", &p);
        
        for (int i = n; i >= p-1; i--)
        {
            a[i + 1] = a[i];
        }
        a[p-1] = e;
        n++;
        printf("Updated array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        break;

        }
        case 2:
        {
            int p;
            printf("Enter the position in which you want to delete ur value: ");
            scanf("%d", &p);
            for (int i = p-1; i < n - 1; i++)
            {
                a[i] = a[i + 1];
            }
            n--;
            printf("Updated array: ");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }
            printf("\n");
            break;
        }

       
        case 3:
        {
            int b;
            printf("Enter the element you want to search");
            scanf("%d",&b);
            for(int i=0;i<n;i++)
            {
                if(b==a[i])
                printf("Element found");
                else
                printf("Element not found");
                break;
            }
            break;
        }
        case 4:
        {
            printf("Traversing of a array");
             for(int i=0;i<n;i++)
            {
                printf("%d\t",a[i]);
            }
            break;
        }
    }
}