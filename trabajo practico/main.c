#include <stdio.h>
#include <stdlib.h>
#include "bibloteca.h"
/*1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones*/

int main(void)
{
    float numeroA;
    float numeroB;
    float resSuma;
    float resResta;
    float resMultiplicacion;
    float resDivision;
    float resFactorialA;
    float resFactorialB;
    char mensaje;
    char seguir = 's';
    int opcion;
    do{
        opcion= menuOpcion("1. Ingresar 1er operando \n2. Ingresar 2do operando \n3. Calcular todas las operaciones \n4. Informar resultados \n5. Salir\n");
        switch(opcion)
        {
            case 1:
            numeroA=ingresarDato(numeroA);
            break;
            case 2:
            numeroB=ingresarDato(numeroB);
            break;
            case 3:
            resSuma = suma( numeroA , numeroB);
            resResta = resta ( numeroA , numeroB );
            resMultiplicacion = multiplicacion ( numeroA , numeroB );
            if(numeroB != 0)
            {
                resDivision = division ( numeroA , numeroB );
            }
            if(numeroA > 0)
            {
                resFactorialA = factorial( numeroA );
            }
            if(numeroB > 0)
            {
                resFactorialB = factorial( numeroB );
            }
            break;
            case 4:
            respuestaMensaje( resSuma ,"El resultado de numeroA+numeroB es:");
            respuestaMensaje( resResta ,"El resultado de numeroA-numeroB es:");
            respuestaMensaje( resMultiplicacion ,"El resultado de numeroA*numeroB es:");
            if(numeroB == 0)
            {
                printf("No es posible dividir por cero\n");
            }
            else
            {
                respuestaMensaje( resDivision ,"El resultado de numeroA/numeroB es:");
            }
            if(numeroA > 0)
            {
                respuestaMensaje(resFactorialA,"El factorial de numeroA es:");
            }
            else
            {
                printf("no existe el factorial de numeroA menor a 1\n");
            }
            if(numeroB > 0)
            {
                respuestaMensaje(resFactorialB,"El factorial de numeroB es:");
            }
            else
            {
                printf("no existe el factorial de numeroB menor a 1\n");
            }
            break;
            case 5:
            seguir = 'n';
            break;
            default:
            printf("numero incorrecto");
            break;
        }
        system("pause");
        system("cls");


    }while(seguir == 's');



    return 0;
}
