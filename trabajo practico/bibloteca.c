#include <stdio.h>
#include <stdlib.h>
int menuOpcion (char mensaje[])
{
    int opcion;
    printf("%s",mensaje);
    printf("elija una opcion\n");
    scanf("%d",&opcion);
    return opcion;

}
float ingresarDato (float x)
{
    printf("ingrese un numero\n");
    scanf("%f",&x);
    return x;
}
float suma(float x ,float y)
{
    float resultado;
    resultado =x+y;
    return resultado;
}
float resta (float x , float y)
{
    float resultado;
    resultado =x-y;
    return resultado;
}
float multiplicacion (float x , float y)
{
    float resultado;
    resultado =x*y;
    return resultado;
}
float division (float x , float y)
{
    float resultado;
    resultado = x/y;
    return resultado;

}
int factorial(int x)
{
    int respuesta;
    if(x == 1)
    {
        return 1;
    }
    respuesta = x * factorial(x-1);
    return respuesta;
}
int respuestaMensaje(float respuesta , char mensaje[])
{
    printf("%s %f\n", mensaje , respuesta);
    return 0;
}
/*int respuestafactorial(float respuesta1 ,float respuesta2 ,char mensaje1[] , char mensaje2[])
{
    printf("%s %f %s %f\n", mensaje1 , respuesta1 , mensaje2 , respuesta2);
    return 0;
}*/
