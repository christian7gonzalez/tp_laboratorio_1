/*
 * Funciones.h
 *
 *  Created on: 4 abr. 2020
 *      Author: Gonzalez
 *      Las cabeceras de mis funciones
 */

#ifndef UTN_H_
#define UTN_H_
int utn_getNumeroInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
int utn_getChar(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);

int sumar(int num1, int num2);
int retar(int num1,int num2);
int multiplicar (int num1, int num2);
int dividir (int num1, int num2, float* pDireccionDeVariable);
int factorial(int num, double* pDireccionFactorial);

void titulo();
int valorMenu(int num1, int num2);
void imprimirArray(int array[], int len);
void promedioArray(int array[], int len, float* pPromedioResultado);
void ordenarArray(int array[], int len);


#endif /* UTN_H_ */
