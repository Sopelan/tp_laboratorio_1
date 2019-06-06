#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "bibloteca.h"
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}
float getfloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}
char getchart(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}
char getNumeroAleatorio(int desde , int hasta , int iniciar )
{
    if(iniciar)
        srand(time(NULL));
    return desde+(rand()%(hasta + 1 - desde));
}
int soloNumeros(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9' )
            return 0;
        i++;
    }
    return 1;
}
int soloLetras(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] < 'a' || str[i] > 'z' ) && (str[i] < 'A' || str[i] > 'Z' ))
            return 0;
        i++;
    }
    return 1;
}
int alfanumericos(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] < 'a' || str[i] > 'z' ) && (str[i] < 'A' || str[i] > 'Z' ) && (str[i] < '0' || str[i] > '9' ) )
            return 0;
        i++;
    }
    return 1;
}
int telefono(char str[])
{
    int i = 0;
    int contadorDeGuiones = 0;
    while(str[i] != '\0')
    {
        if((str[i] < '0' || str[i] > '9')&&(str[i] != '-'))
            return 0;
        if(str[i] == '-')
            contadorDeGuiones++;
        i++;
    }
    if(contadorDeGuiones == 1 && i == 9)
    {
        return 1;
    }
    return 0;
}
void getString(char mensaje[] , char input[] )
{
    printf("%s" , mensaje );
    gets(input);
}
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(soloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int getStringNumero(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(soloNumeros(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
void cleanStdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    int input;
    char inputAux[128];
    while(1)
    {
        if(!getStringNumero(requestMessage,inputAux))
        {
            printf("%s",errorMessage);
            break;
        }
        input = atoi(inputAux);
        if(input >= lowLimit && input <= hiLimit)
        {
            return input;
        }
        else
        {
            printf("tiene que estar entre %d y %d\n",lowLimit,hiLimit);
            break;
        }
    }

}
void getValidString(char requestMessage[],char errorMessage[], char input[])
{
    while(1)
    {
        if(!getStringLetras(requestMessage,input))
        {
            printf("%s",errorMessage);
            continue;
        }
        else
        {
            break;
        }
    }
}
