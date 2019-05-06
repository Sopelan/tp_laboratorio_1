#define LIBRE -2
#define OCUPADO -1
#define QTY 1000
#define QTY 1000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibloteca.h"
#include "arrayEmployees.h"
int main()
{
    Employee person[QTY];
    int salir = 1;
    int opcion;
    char opciones[128];
    initEmployees(person , QTY );
    while(salir == 1)
    {
        printf("1.ALTA\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.SALIR\n");
        while(!getStringNumero("eligir su opcion\n",opciones))
        {
            printf("solo tienen que ser numeros\n");
            system("pause");
            system("cls");
            printf("1.ALTA\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.SALIR\n");
            getStringNumero("eligir su opcion\n",opciones);
        }

        opcion = atoi(opciones);
        switch(opcion)
        {
            case 1:
                printf("alta\n");
                addEmployee(person , QTY );
                break;
            case 2:
                printf("modificar\n");
                modifyEmployees( person, QTY);
                break;
            case 3:
                printf("baja\n");
                removeEmployee(person,QTY);
                break;
            case 4:
                printf("informar\n");
                printEmployees( person, QTY);
                break;
            case 5:
                printf("salir\n");
                salir = 0;
                break;
            default:
                printf("numero incorrecto");
                break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
