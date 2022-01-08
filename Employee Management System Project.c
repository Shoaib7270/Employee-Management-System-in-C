#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    char full_name[200];
    int employee_ID;
    float salary;
} Employee;

void addEmployeeDetails(Employee EmployeeDB[], int n);
void findEmployee(Employee EmployeeDB[], int n);
void updateEmployee(Employee EmployeeDB[], int n);
void countEmployees(int n);
void printDB(Employee EmployeeDB[], int n);
void ReadDB(FILE *fpt, Employee EmployeeDB[], int *n);
void WriteDB(FILE *fpt, Employee EmployeeDB[], int n);

int main()
{
    start();
    return 0;
}
void start()
{
    Employee EmployeeDB[200];
    int n = 0, option;
    FILE *fpt;
    fpt = fopen("Employee_data.txt", "r");
    if(fpt!=NULL)
    {
        ReadDB(fpt, EmployeeDB, &n);

        fclose(fpt);
    }
    printf("\n\n\n\t\t\t------------------------------------------------------------\n");
    printf("\t\t\t\t\t  * Employee Database *\n");
    printf("\t\t\t------------------------------------------------------------");

    while(1)
    {
        printf("\n\t\t\t------------- 1. Add Employee Details:         -------------\n");
        printf("\t\t\t------------- 2. Find Employee Record:         -------------\n");
        printf("\t\t\t------------- 3. Update Employee Record:       -------------\n");
        printf("\t\t\t------------- 4. Count Employees:              -------------\n");
        printf("\t\t\t------------- 5. Print the Database:           -------------\n");
        printf("\t\t\t------------- 6. Exit:                         -------------\n");
        printf("\t\t\t------------------------------------------------------------");

        printf("\n\n\t\t\t\t\t\tSelect an option: ");
        scanf("%d", &option);

        if(option==6)
            break;

        switch(option)
        {
        case 1:
            addEmployeeDetails(EmployeeDB, n);
            n++;
            break;
        case 2:
            findEmployee(EmployeeDB, n);
            break;

        case 3:
            updateEmployee(EmployeeDB, n);
            break;
        case 4:
            countEmployees(n);
            break;
        case 5:
            printDB(EmployeeDB, n);
            break;
        }
    }
    fpt = fopen("Employee_data.txt", "w");
    WriteDB(fpt, EmployeeDB, n);
    fclose(fpt);

    return 0;
}


void addEmployeeDetails(Employee EmployeeDB[], int n)
{
    Employee emp;
    int flag, i=0;
    do
    {
        printf(" Enter Employee's-ID: ");
        scanf("%d", &emp.employee_ID);
        flag = 0;
        while(i<n)
        {
            if(EmployeeDB[i].employee_ID == emp.employee_ID)
            {
                printf(" ****ERROR! EMPLOYEE ID ALREADY EXIST****\n");
                printf("\t...PLEASE TRY AGAIN...\n");
                flag = 1;
            }
            i++;
        }
    }
    while(flag!=0);
    getchar();
    printf("Enter Employee's Full Name: ");
    //scanset
    scanf("%[^\n]", emp.full_name);
    printf("Enter Employee's salary: ");
    scanf("%f", &emp.salary);
    EmployeeDB[n] = emp;
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t\t...RECORD HAS BEEN ADDED SUCCESSFULLY...");
    sleep(2);
    system("cls");
}
void findEmployee(Employee EmployeeDB[], int n)
{
    int i, id;
    printf("Enter Employee's-ID to search: ");
    scanf("%d", &id);
    for(i=0; i<n; i++)
    {
        if(EmployeeDB[i].employee_ID == id)
        {
            printf("Employee's Name: %s\n", EmployeeDB[i].full_name);
            printf("Employee's id : %d\n", EmployeeDB[i].employee_ID);
            printf("Employee's Salary : %.3f\n", EmployeeDB[i].salary);
            return;
        }
    }
    printf("RECORD NOT FOUND\n");
}
void updateEmployee(Employee EmployeeDB[], int n)
{
    int id, i, option;
    printf("Enter Employee'S-ID to Update: ");
    scanf("%d", &id);
    for(i=0; i<n; i++)
    {

        if(EmployeeDB[i].employee_ID == id)
        {
            printf("\n 1. Update ID: ");
            printf("\n 2. Update name: ");
            printf("\n 3. Update salary: ");
            printf("\n Select an option: ");
            scanf("%d", &option);
            if(option==1)
            {
                printf("Enter new ID: ");
                getchar();
                scanf("%d", &EmployeeDB[i].employee_ID);
            }
            else if (option==2)
            {
                printf("Enter new name: ");
                getchar();
                scanf("%[^\n]", EmployeeDB[i].full_name);
            }
            else
            {
                printf("Enter new salary: ");
                scanf("%f", &EmployeeDB[i].salary);
            }
            return;

        }
    }
    printf("\n\n\t\t**PLEASE TRY AGAIN WITH VALID ID**\n\n");

}
void countEmployees(int n)
{
    printf("Total Employees present in the system=  %d\n", n);
}
void printDB(Employee EmployeeDB[], int n)
{
    int i;
    printf("-------------------------------------------\n");
    printf(" Employee Name  |  Employee ID  |  Salary\n");
    printf("-------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf("%-20s%-15d%.3f\n", EmployeeDB[i].full_name, EmployeeDB[i].employee_ID, EmployeeDB[i].salary);
    }
}

void ReadDB(FILE *fpt, Employee EmployeeDB[], int *n)
{
    char line[100];
    int i = 0;

    while(!feof(fpt))
    {
        fgets(EmployeeDB[i].full_name, 20, fpt);
        if(feof(fpt))
            break;
        fscanf(fpt, "%d%f\n", &EmployeeDB[i].employee_ID, &EmployeeDB[i].salary);
        i++;
    }
    *n = i;
}

void WriteDB(FILE *fpt, Employee EmployeeDB[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        fprintf(fpt, "%-20s\t%d\t%.3f\n", EmployeeDB[i].full_name, EmployeeDB[i].employee_ID, EmployeeDB[i].salary);
    }
}
