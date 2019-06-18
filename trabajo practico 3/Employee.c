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
{
    Employee* retorno = employee_new();
    int sueldoInt = atoi(sueldo);
    int horasTrabajadas = atoi(horasTrabajadasStr);

    if(retorno != NULL)
    {
        if(!employee_getNombre(retorno,nombreStr))
            return NULL;
        if(!employee_getSueldo(retorno,&sueldoInt))
            return NULL;
        if(!employee_getHorasTrabajadas(retorno,&horasTrabajadas))
            return NULL;
        return retorno;
    }
}
void employee_delete(Employee* retorno)
{
    free(retorno);
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    char* auxSueldo;
    int aux ;

    if(getStringNumero("cual es su sueldo\n",&auxSueldo))
    {

        aux = atoi(&auxSueldo);
        if(aux > 0)
        {
            *sueldo = aux;

            employee_setSueldo(this,*sueldo);
            return 1;
        }
        else
        {
            printf("no puede ser posible ese sueldo\n");
            return 0;
        }
    }
    else
    {
        printf("tiene que ser numeros\n");
        return 0;
    }

}
int employee_setSueldo(Employee* this,int sueldo)
{
     this->sueldo = sueldo;
    return 1;

}
int employee_setId(Employee* this,int id)
{


}
int employee_getId(Employee* this,int* id)
{

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
int employee_setNombre(Employee* this,char* nombre)
{
   strcpy(this->nombre , nombre);
   return 1;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    this->horasTrabajadas = horasTrabajadas;
    return 1;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    char* horas;
    if(getStringNumero("ingrese horas trabajadas\n",&horas))
    {
        *horasTrabajadas = atoi(&horas);
        printf("%d",*horasTrabajadas);
        employee_setHorasTrabajadas(this ,*horasTrabajadas);
        return 1;
    }
    return 0;

}
