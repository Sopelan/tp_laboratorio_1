typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;

int initEmployees(Employee[] , int );
int addEmployee(Employee[] , int );
int findEmployeeById(Employee[] , int , char[]);
int removeEmployee(Employee[], int);
int sortEmployees(Employee[] , int , int );
int printEmployees(Employee[] , int );
int findEmptyPlace(Employee[],int);
int findFullPlace(Employee[],int);
int modifyEmployees(Employee[], int );
#include "arrayEmployees.c"
