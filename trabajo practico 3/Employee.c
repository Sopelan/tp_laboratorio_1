#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
int employee_getSueldo(Employee* this,int* sueldo)
{
    char* sueld;
    if(getStringNumero("ingrese su sueldo\n",sueld))
    {
        sueldo = atoi(sueld);
        return 1;
    }
    else
        return 0;

}
int employee_setSueldo(Employee* this,int sueldo)
{
    this->sueldo = sueldo;
}
