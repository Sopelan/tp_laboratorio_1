#include <stdio.h>
#include <stdio.h>
#ifndef BIBLOTECA_H_INCLUDED
#define BIBLOTECA_H_INCLUDED
int menuOpcion (char mensaje[]);
float ingresarDato (float numeroX);
float suma(float numeroX ,float numeroY);
float resta (float numeroX , float numeroY );
float multiplicacion (float numeroX , float numeroY );
float division (float numeroX , float numeroY );
int factorial(int numeroX);
int respuestaMensaje(float respuesta , char mensaje[]);
//int respuestafactorial(float respuesta1 , float respuesta2 ,char mensaje1[] , char mensaje2[]);
#include "bibloteca.c"
#endif // BIBLOTECA_H_INCLUDED
