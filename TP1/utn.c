/*
 * funciones.c
 *
 *  Created on: 4 abr. 2020
 *      Author: Gonzalez
 *
 *      Mis funciones definidas codeadas
 */
#include<stdio.h>
#include<stdlib.h>

/*
 * */
void titulo(void)
{
	printf("**********************************************************************************************************************\n----CALCULADORA----\n**********************************************************************************************************************\n");
}

/*-- valorMenu() --Permite ver el menu, validar que el valor esté entre 1 - 5 y retornar la opción elegida del menu,
esta funcion lo realice para no tener tantos printf en el main.*/
int valorMenu(int num1, int num2, char operacion)
{
	int bufferMenu;
	titulo();
	printf("\n1. Ingresar 1er (A = %d)\n2. Ingresar 2do operando (B = %d)\n3. Calcular todas las operaciones (%c)\n4. Informar resultados\n5. Salir\n\n-Opcion: ", num1, num2,operacion);
	scanf("%d",&bufferMenu);
	while(bufferMenu<1 || bufferMenu>5)
	{
		system("cls");
		titulo();
		printf("\n1. Ingresar 1er (A = %d)\n2. Ingresar 2do operando (B = %d)\n3. Calcular todas las operaciones (%c)\n4. Informar resultados\n5. Salir\n\n-Opcion: ", num1, num2, operacion);
		printf("\n\n\aERROR - Valor invalido - Reintente! \n");
		system("PAUSE");
		system("cls");
		titulo();
		printf("\n1. Ingresar 1er (A = %d)\n2. Ingresar 2do operando (B = %d)\n3. Calcular todas las operaciones (%c)\n4. Informar resultados\n5. Salir\n\n-Opcion: ", num1, num2, operacion);
		fflush(stdin);
		scanf("%d",&bufferMenu);
	}
	return bufferMenu;
}



/*La funcion sumar pide 2 argumentos, realiza la suma y la guarda en una variable local
 sum, y retorna el valor de la operacion.
 * */
int utn_sumar(int num1, int num2)
{
	int sum;
	sum = num1 + num2;
	if (sum>100)
	{
		sum = 100;
	}
	return sum;
}

/*La funcion restar pide 2 argumentos, realiza la resta y la guarda en una variable local
 resta, y retorna el valor de la operacion.
*/
int utn_retar(int num1,int num2)
{
	int resta;
	resta = num1 - num2;
	return resta;
}

/*La funcion multiplicar pide 2 argumentos, realiza la multiplizacion y la guarda en una variable local
 *multiplicacion, y retorna el valor de la operacion.*/
int utn_multiplicar (int num1, int num2)
{
	int multiplicacion;
	multiplicacion = num1 * num2;
	return multiplicacion;
}

/*La funcion dividir pide 3 parametros, una es la direccion de memoria
 *se verifica que sea una direccion de memoria y que el 2 argumento sea distinto de 0
 *si cumple guarda el resultado en el puntero retorna 0, sino retorna errorHub -1. */
int utn_dividir (int num1, int num2, float* pDireccionDeVariable)
{
	int errorHub= -1;
	if (pDireccionDeVariable != NULL && num2 != 0)
	{
		*pDireccionDeVariable = (double)num1 /num2;
		errorHub = 0;
	}
	return errorHub;
}

/*La funcion factorial pide 2 argumentos numero y direccion de memoria, valida que sea una direccion de memoria y
 * que el numero sea mayor igual a 0, en caso que el numero sea 0 el resultado es 1, si es mayor realiza el fatorial,
 * en caso que el numero sea menos a 0 retorna -1 error.*/
int utn_factorial(int num, double* pDireccionFactorial)
{
	double fac=1;
	int retorno = -1;
	if (pDireccionFactorial != NULL && num>=0)
	{
		if (num > 0)
		{
			for(int itera=num; itera>0;itera--)
			{
				fac*=itera;
			}
		}
		*pDireccionFactorial = fac;
		retorno = 0;
	}
	return retorno;
}






