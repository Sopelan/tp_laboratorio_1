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
float ingresarDato (float numeroX)
{
    printf("ingrese un numero\n");
    scanf("%f",&numeroX);
    return numeroX;
}
float suma(float numeroX ,float numeroY)
{
    float resultado;
    resultado = numeroX+numeroY;
    return resultado;
}
float resta (float numeroX , float numeroY)
{
    float resultado;
    resultado = numeroX-numeroY;
    return resultado;
}
float multiplicacion (float numeroX , float numeroY)
{
    float resultado;
    resultado = numeroX*numeroY;
    return resultado;
}
float division (float numeroX , float numeroY)
{
    float resultado;
    resultado = numeroX/numeroY;
    return resultado;

}
int factorial(int numeroX)
{
    int respuesta;
    if(numeroX == 1)
    {
        return 1;
    }
    respuesta = numeroX * factorial(numeroX-1);
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
