#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int flag = 0;
    do{
        option = getValidInt("\nMenu:\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleado\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir\n","tiene que ser un numero\n",1,10);
        switch(option)
        {
            case 1:
                if(flag == 0)
                {
                    controller_loadFromText("data.csv",listaEmpleados);
                    flag = 1;
                }
                else
                    printMensaje();
                break;
            case 2:
                if(flag == 0)
                {
                     controller_loadFromBinary("data.bin" ,listaEmpleados);
                     flag = 1;
                }
                else
                    printMensaje();
                break;
            case 3:
                if(flag == 1)
                    controller_addEmployee(listaEmpleados);
                else
                    printError();
                break;
            case 4:
                if(flag == 1)
                    controller_editEmployee(listaEmpleados);
                else
                    printError();
                break;
            case 5:
                if(flag == 1)
                    controller_removeEmployee(listaEmpleados);
                else
                    printError();
                break;
            case 6:
                if(flag == 1)
                    controller_ListEmployee(listaEmpleados);
                else
                    printError();
                break;
            case 7:
                if(flag == 1)
                    controller_sortEmployee(listaEmpleados);
                else
                    printError();
                break;
            case 8:
                if(flag == 1)
                {
                    printf("Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
                    controller_saveAsText("data.csv",listaEmpleados);
                    controller_saveAsBinary("data.bin",listaEmpleados);
                    flag = 0;
                }
                else
                    printError();
                break;
            case 9:
                if(flag == 1)
                {
                    printf("Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
                    controller_saveAsBinary("data.bin",listaEmpleados);
                    controller_saveAsText("data.csv",listaEmpleados);
                    flag = 0;
                }
                else
                    printError();
                break;
            case 10:
                printf("salir\n");
                break;
        }
        system("pause");
        system("cls");
    }while(option != 10);

    return 0;
}
