/*
 * Funciones.h
 *
 *  Created on: 4 abr. 2020
 *      Author: Gonzalez
 *      Las cabeceras de mis funciones
 */

#ifndef UTN_H_
#define UTN_H_

void titulo();
int valorMenu(int num1, int num2, char operacion);
int utn_sumar(int num1, int num2);
int utn_retar(int num1,int num2);
int utn_multiplicar (int num1, int num2);
int utn_dividir (int num1, int num2, float* pDireccionDeVariable);
int utn_factorial(int num, double* pDireccionFactorial);

#endif /* UTN_H_ */
