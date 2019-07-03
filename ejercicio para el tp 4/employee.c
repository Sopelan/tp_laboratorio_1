#include <stdio.h>
#include <stdlib.h>
#include "bibloteca.h"
#include "LinkedList.h"
#include "employee.h"
#include "controller.h"
void prinTodo(int option)
{
    switch(option)
    {
        case 1:
            printf("tiene que cargarse los archivos\n");
            break;
        case 2:
            printf("ya se cargaron los archivcs\n");
            break;
    }
}
eEmpleado* empleadoNew()
{
    eEmpleado* retorno;
    retorno = (eEmpleado*) calloc(sizeof(eEmpleado),1);
    return retorno;
}
int setId(eEmpleado* empleado , int id)
{
    if(empleado != NULL && id >= 0)
    {
        empleado->id = id;
        return 1;
    }
    return 0;
}
int getId(eEmpleado* empleado , int* id)
{
    if(empleado != NULL)
    {
        *id = empleado->id;
        return 1;
    }
    return 0;
}
int setNombre(eEmpleado* empleado , char* nombre)
{
    if(empleado != NULL)
    {
        strcpy(empleado->nombre , nombre);
        return 1;
    }
    return 0;
}
int getNombre(eEmpleado* empleado , char* nombre)
{
    if(empleado != NULL)
    {
        strcpy(nombre , empleado->nombre);
        return 1;
    }
    return 0;
}
int setEmpleo(eEmpleado* empleado , char* empleo)
{
    if(empleado != NULL)
    {
        strcpy( empleado->empleo , empleo);
        return 1;
    }
    return 0;
}
int getEmpleo(eEmpleado* empleado , char* empleo)
{
    if(empleado != NULL )
    {
        strcpy(empleo , empleado->empleo);
        return 1;
    }
    return 0;
}
int setEdad(eEmpleado* empleado , int edad)
{
    if(empleado != NULL && edad > 0 && edad < 100)
    {
        empleado->edad = edad;
        return 1;
    }
    return 0;
}
int getEdad(eEmpleado* empleado , int* edad)
{
    if(empleado != NULL)
    {
        *edad = empleado->edad;
        return 1;
    }
    return 0;
}
int setHorasTrabajadas(eEmpleado* empleado , int horasTrabajadas)
{
    if(empleado != NULL && horasTrabajadas >= 0)
    {
        empleado->horasTrabajadas = horasTrabajadas;
        return 1;
    }
    return 0;
}
int getHorasTrabajadas(eEmpleado* empleado , int* horasTrabajadas )
{
    if(empleado != NULL)
    {
        *horasTrabajadas = empleado->horasTrabajadas;
        return 1;
    }
    return 0;
}
