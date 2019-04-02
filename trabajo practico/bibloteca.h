#include <stdio.h>
#include <stdio.h>
#ifndef BIBLOTECA_H_INCLUDED
#define BIBLOTECA_H_INCLUDED
int menuOpcion (char mensaje[]);
float ingresarDato (float x);
float suma(float x ,float y);
float resta (float x , float y );
float multiplicacion (float x , float y );
float division (float x , float y );
int factorial(int x);
int respuestaMensaje(float respuesta , char mensaje[]);
//int respuestafactorial(float respuesta1 , float respuesta2 ,char mensaje1[] , char mensaje2[]);
#include "bibloteca.c"
#endif // BIBLOTECA_H_INCLUDED
