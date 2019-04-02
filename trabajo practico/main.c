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
    float a;
    float b;
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
            a=ingresarDato(a);
            break;
            case 2:
            b=ingresarDato(b);
            break;
            case 3:
            resSuma = suma( a , b);
            resResta = resta ( a , b );
            resMultiplicacion = multiplicacion ( a , b );
            if(b != 0)
            {
                resDivision = division ( a , b );
            }
            if(a > 0)
            {
                resFactorialA = factorial( a );
            }
            if(b > 0)
            {
                resFactorialB = factorial( b );
            }
            break;
            case 4:
            respuestaMensaje( resSuma ,"El resultado de A+B es:");
            respuestaMensaje( resResta ,"El resultado de A-B es:");
            respuestaMensaje( resMultiplicacion ,"El resultado de A*B es:");
            if(b == 0)
            {
                printf("No es posible dividir por cero\n");
            }
            else
            {
                respuestaMensaje( resDivision ,"El resultado de A/B es:");
            }
            if(a > 0)
            {
                respuestaMensaje(resFactorialA,"El factorial de A es:");
            }
            else
            {
                printf("no existe el factorial de A menor a 1\n");
            }
            if(b > 0)
            {
                respuestaMensaje(resFactorialB,"El factorial de B es:");
            }
            else
            {
                printf("no existe el factorial de B menor a 1\n");
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
