/*
1. Realizar un programa que lea de un archivo .csv los datos de empleados y los guarde de manera dinámica en un arraylist de entidades eEmpleado (id, nombre, empleo,edad,horasTrabajadas).
2. Listar todos los empleados ordenados de manera ascendente por nombre. Nota: Utilizar constructores, Getters y Setter.
*/
#include <stdio.h>
#include <stdlib.h>
#include "bibloteca.h"
#include "LinkedList.h"
#include "employee.h"
#include "controller.h"
int main()
{
    int option;
    LinkedList* newLinkedlist = ll_newLinkedList();
    int flag = 0;
    while(option != 10)
    {
        option = getValidInt("\n1guardar el archivo .csv\n2.listar los empleados\n10.salir","tiene que ser un numero\n",1,10);
        switch(option)
        {
            case 1:
                if(flag == 0)
                {
                    flag = 1;
                }
                else
                {
                    prinTodo(2);
                }
                break;
            case 2:
                if(flag == 1)
                {

                }
                else
                {
                    prinTodo(1);
                }
                 break;
            case 10:
                printf("salir\n");
                break;
            default:
                printf("error de numero\n");
                break;

        }

    }
    system("pause");
    system("cls");
    return 0;
}
