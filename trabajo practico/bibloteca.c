#include <stdio.h>
#include <stdlib.h>
#include "bibloteca.h"
int menuOpcion (char mensaje[])
{
    int opcion;
    printf("%s",mensaje);
    printf("elija una opcion");
    scanf("%d",opcion);
    return opcion;

}
int ingresarDato (int a)
{
    printf("ingrese un numero");
    scanf("%d",&a);
    return a;
}
int suma(int a ,int b)
{
    float resultado;
    resultado=a+b;
    return resultado;
}
int resta (int a , int b)
{
    float resultado;
    resultado=a-b;
    return resultado;
}
int multiplicacion (int a , int b)
{
    float resultado;
    resultado=a*b;
    return resultado;
}
int division (int a , int b)
{
    float resultado;
    resultado=a/b;
    if(b==0)
    {
        return 0;
    }
    return resultado;
}

//int factorial(int a , float factorial)
