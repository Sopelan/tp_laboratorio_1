#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <string.h>
Employee* employee_new()
{
    Employee* empleado = (Employee*) malloc(sizeof(Employee));
    return empleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{    Employee* retorno = employee_new();
    int sueldoInt =  atoi(sueldo);
    int horas = atoi(horasTrabajadasStr);
    if(retorno != NULL)
    {
        employee_getNombre(retorno, nombreStr);
        employee_getSueldo(retorno, &sueldoInt);

        //employee_getHorasTrabajadas(retorno , horas);
        return retorno;

    }
    return NULL;
}
void employee_delete();
int employee_getSueldo(Employee* this,int* sueldo)
{
    char* sueld;
    int sueldoo;
    if(getStringNumero("ingrese su sueldo\n",sueld))
    {
        *sueldo = atoi(sueld);
        employee_setSueldo(this , *sueldo);
        return 1;

    }
    else
        return 0;

}
int employee_setSueldo(Employee* this,int sueldo)
{
    this->sueldo = sueldo;
}
int employee_setId(Employee* this,int id)
{


}
int employee_getId(Employee* this,int* id)
{

}
int employee_setNombre(Employee* this,char* nombre)
{
    strcpy(this->nombre , nombre);
}
int employee_getNombre(Employee* this,char* nombre)
{

    if(getString("cual es tu nombre\n",nombre))
    {
        employee_setNombre(this , nombre);
        return 1;
    }
    return 0;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    this->horasTrabajadas = horasTrabajadas;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

    char* horas;
    if(getStringNumero("ingrese horas trabajadas\n",horas))
    {
        *horasTrabajadas = atoi(horas);
        employee_setHorasTrabajadas(this , *horasTrabajadas);
        return 1;
    }
    return 0;
}
