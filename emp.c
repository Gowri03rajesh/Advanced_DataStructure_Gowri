#include<stdio.h>
struct Employee
{
int emp_id;
char name[50];
float salary;
};
int main()
{
struct Employee emp[3];
int i;
printf("enter details of 3 employee:\n");
for(i=0;i<3;i++)
{
printf("\n employee %d:\n",i+1);
printf("enter employee ID:");
scanf("%d",&emp[i].emp_id);
printf("enter name:");
scanf(emp[i].name, sizeof(emp[i].name), stdin);
printf("enter salary:");
scanf("%f",&emp[i].salary);

}
printf("\n---employee datails---\n");
for(i=0;i<3;i++)
{
printf("\nemployee %d\n",i+1);
printf("employee ID:%d\n",emp[i].emp_id);
printf("name :%s\n",emp[i].name);
printf("salary :%2f\n",emp[i].salary);
}
return 0;
}
