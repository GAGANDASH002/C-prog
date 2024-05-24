#include<stdio.h>
struct employee
{
    char name[10];
    int empid;
    char desig[10];
    float hra;
    float basic;
    float da;
    float gross;
};
int main()
{
    struct employee emp[100];
    int n;
    printf("Enter the number of employees:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the employee id:");
    scanf("%d",&emp[i].empid);
    printf("Enter the employee name:");
    scanf("%s",&emp[i].name);
    printf("Enter the employee designation:");
    scanf("%s",&emp[i].desig);
    printf("Enter the employee hra:");
    scanf("%f",&emp[i].hra);
    printf("Enter the employee basic salary:");
    scanf("%f",&emp[i].basic);
    printf("Enter the employee da:");
    scanf("%f",&emp[i].da);
    }
    for(int i=0;i<n;i++)
    {
        emp[i].gross=(emp[i].hra/100.0)*emp[i].basic+(emp[i].da/100.0)*emp[i].basic+emp[i].basic;
        printf("Employee name :%s\n",emp[i].name);
        printf("Employee id: %d\n",emp[i].empid);
        printf("Employee designation: %s\n",emp[i].desig);
        printf("Employee hra: %.0f\n",emp[i].hra);
        printf("Employee da:%.0f\n",emp[i].da);
        printf("Employee Basic Salary: %.0f\n",emp[i].basic);
        printf("Employee Gross Salary: %.0f\n",emp[i].gross);

    }
}