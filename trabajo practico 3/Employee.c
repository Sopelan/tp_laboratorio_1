#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <string.h>
Employee* employee_new()
{
    Employee* empleado = (Employee*) calloc(sizeof(Employee),1);
    return empleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    Employee* retorno = employee_new();
    int sueldoInt = atoi(sueldo);
    int horasTrabajadas = atoi(horasTrabajadasStr);
    int id = atoi(idStr);

    if(retorno != NULL)
    {

        employee_setNombre(retorno,nombreStr);

        employee_setSueldo(retorno,sueldoInt);

        employee_setHorasTrabajadas(retorno,horasTrabajadas);


        employee_setId(retorno,id);


    }
    return retorno;
}
void employee_delete(Employee* retorno)
{
    free(retorno);
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    char auxSueldo[128];
    int aux ;

    if(getStringNumero("Cual es su sueldo\n",auxSueldo))
    {

        aux = atoi(auxSueldo);
        if(aux > 0)
        {
            *sueldo = aux;

            employee_setSueldo(this,*sueldo);
            return 1;
        }
        else
        {
            printf("No puede ser posible ese sueldo\n");
            return 0;
        }
    }
    else
    {
        printf("Tiene que ser numeros\n");
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
    this->id = id;

}
int employee_getId(Employee* this,int* id)
{

}
int employee_getNombre(Employee* this,char* nombre)
{
    if(getString("Cual es tu nombre\n",nombre))
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
    char horas[128];
    if(getStringNumero("Ingrese horas trabajadas\n",horas))
    {
        *horasTrabajadas = atoi(horas);
        if(*horasTrabajadas > 0)
        {
            employee_setHorasTrabajadas(this ,*horasTrabajadas);
            return 1;
        }
        else
        {
            printf("No es posible trabajar esas hora\n");
            return 0;
        }

    }
    else
        printf("Tiene que ser un numero\n");
    return 0;

}
void print(void)
{
    printf("|%5s\t|%20s\t|%15s\t|%10s|\t\n","ID","Nombre","Horas trabajadas","Sueldo");
}
void printEmployee(Employee* aux)
{
    printf("|%5d\t|%20s\t|%15d\t|%10d|\t\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
}
int orderId(LinkedList* pArrayListEmployee, int order)
{
    Employee* auxEmp;
    Employee* aux2Emp;
    Employee* aux;
    int tam;
    int i;
    int j;
    tam = ll_len(pArrayListEmployee);
    switch(order)
    {
        case 1:
            for(i = 0; i < tam - 1 ; i++)
            {
                auxEmp = employee_new();
                auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
                for(j = i + 1 ; j < tam ; j++)
                {
                    aux2Emp = employee_new();
                    aux2Emp = (Employee*) ll_get(pArrayListEmployee,j);
                    if(auxEmp->id > aux2Emp->id)
                    {
                        aux = auxEmp;
                        ll_set(pArrayListEmployee,j,aux);
                        auxEmp = aux2Emp;
                        ll_set(pArrayListEmployee,i,auxEmp);
                    }
                }
            }
            break;
        case 2:
            for(i = 0; i < tam - 1 ; i++)
            {
                auxEmp = employee_new();
                auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
                for(j = i + 1 ; j > tam ; j++)
                {
                    aux2Emp = employee_new();
                    aux2Emp = (Employee*) ll_get(pArrayListEmployee,j);
                    if(auxEmp->id < aux2Emp->id)
                    {


                    }
                }
            }
            break;
    }



}
