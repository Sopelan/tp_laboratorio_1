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
int employee_pedirSueldo(Employee* this,int* sueldo)
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
    return 1;

}
int employee_getId(Employee* this,int* id)
{
    if(this != NULL)
    {
        *id = this->id;
        return 1;
    }
    return 0;

}
int employee_pedirNombre(Employee* this,char* nombre)
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
int employee_pedirHorasTrabajadas(Employee* this,int* horasTrabajadas)
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
int ordenarPorId(void* emp1,void* emp2)
{
    int ret;
    Employee* aux=(Employee*)emp1;
    Employee* auxEmp=(Employee*)emp2;
    if(aux!=NULL && auxEmp!=NULL)
    {
        int ID1;
        int ID2;
        employee_getId(aux,&ID1);
        employee_getId(auxEmp,&ID2);
       if(ID1>ID2)
           ret=1;
       else if(ID1<ID2)
           ret=-1;
       else
           ret=0;
    }
    return ret;
}

int ordenarPorNombre(void* emp1 , void* emp2)
{
    int ret;
    Employee* aux = (Employee*)emp1;
    Employee* auxEmp = (Employee*)emp2;
    if(aux != NULL && auxEmp != NULL)
    {
        char* nombre1 = (char*)malloc(sizeof(char)*128);
        char* nombre2 = (char*)malloc(sizeof(char)*128);
        employee_getNombre(aux , nombre1);
        employee_getNombre(auxEmp , nombre2);
        ret = stricmp(nombre1 , nombre2);
    }

    return ret;
}
int ordenarPorHoras(void* emp1 ,void* emp2 )
{
    int ret;
    Employee* aux = (Employee*)emp1;
    Employee* auxEmp = (Employee*)emp2;
    if(aux != NULL && auxEmp != NULL)
    {
       int horasTrabajadoras1;
       int horasTrabajadoras2;
       employee_getHorasTrabajadas(aux ,&horasTrabajadoras1);
       employee_getHorasTrabajadas(auxEmp ,&horasTrabajadoras2);
       if(horasTrabajadoras1 > horasTrabajadoras2)
           ret = 1;
       else if(horasTrabajadoras1 < horasTrabajadoras2)
           ret = -1;
       else
           ret = 0;
    }
    return ret;
}
int ordenarPorSueldo(void* emp1,void* emp2)
{
    int ret;
    Employee* aux = (Employee*)emp1;
    Employee* auxEmp = (Employee*)emp2;
    if(aux != NULL && auxEmp != NULL)
    {
       int sueldo1;
       int sueldo2;
       employee_getSueldo(aux , &sueldo1);
       employee_getSueldo(auxEmp , &sueldo2);
       if(sueldo1 > sueldo2)
           ret = 1;
       else if(sueldo1 < sueldo2)
           ret = -1;
       else
           ret = 0;
    }
    return ret;
}
int employee_getNombre(Employee* this,char* nombre)
{
    if(this != NULL)
    {
        strcpy(nombre , this->nombre);
        return 1;
    }
    return 0;

}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        return 1;
    }
    return 0;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    if(this != NULL)
        *sueldo = this->sueldo;
}
void printError(void)
{
    printf("no se han cargado los archivos\n");
}
void printMensaje(void)
{
    printf("ya se cargaron los archivos\n");
}
