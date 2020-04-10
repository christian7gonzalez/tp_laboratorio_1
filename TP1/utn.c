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

/*La funcion sumar pide 2 argumentos, realiza la suma y la guarda en una variable local
 sum, y retorna el valor de la operacion.
 * */
int sumar(int num1, int num2)
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
int retar(int num1,int num2)
{
	int resta;
	resta = num1 - num2;
	return resta;
}

/*La funcion multiplicar pide 2 argumentos, realiza la multiplizacion y la guarda en una variable local
 *multiplicacion, y retorna el valor de la operacion.*/
int multiplicar (int num1, int num2)
{
	int multiplicacion;
	multiplicacion = num1 * num2;
	return multiplicacion;
}

/*La funcion dividir pide 3 parametros, una es la direccion de memoria
 *se verifica que sea una direccion de memoria y que el 2 argumento sea distinto de 0
 *si cumple guarda el resultado en el puntero retorna 0, sino retorna errorHub -1. */
int dividir (int num1, int num2, float* pDireccionDeVariable)
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
int factorial(int num, double* pDireccionFactorial)
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


void titulo(void) //Titulo de mi programa, es solo estetica.
{
	printf("**********************************************************************************************************************\n----CALCULADORA----\n**********************************************************************************************************************\n");
}

/*-- valorMenu() --Permite ver el menu, validar que el valor esté entre 1 - 5 y retornar la opción elegida del menu,
esta funcion lo realice para no tener tantos printf en el main.*/
int valorMenu(int num1, int num2)
{
	int bufferMenu;
	titulo();
	printf("\n1. Ingresar 1er (A = %d)\n2. Ingresar 2do operando (B = %d)\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n\n-Opcion: ", num1, num2);
	//fflush(stdin);
	scanf("%d",&bufferMenu);
	while(bufferMenu<1 || bufferMenu>5)
	{
		system("cls");
		titulo();
		printf("\n1. Ingresar 1er (A = %d)\n2. Ingresar 2do operando (B = %d)\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n\n-Opcion: ", num1, num2);
		printf("\n\n\aERROR - Valor invalido - Reintente! \n");
		system("PAUSE");
		system("cls");
		titulo();
		printf("\n1. Ingresar 1er (A = %d)\n2. Ingresar 2do operando (B = %d)\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n\n-Opcion: ", num1, num2);
		fflush(stdin);
		scanf("%d",&bufferMenu);
	}
	return bufferMenu;
}


void imprimirArray(int array[], int len)
{
	for(int i=0; i<len ;i++)
	{
		printf("%d",array[i]);
	}
}

int promedioArray(int array[], int len, float* pPromedioResultado)
{
	int pro = 0;
	int retorno=-1;
	if (pPromedioResultado != NULL && len>0 && array != NULL)
	{
		for (int i=0; i<len;i++)
		{
			pro += array[i];
		}
		*pPromedioResultado = (float)pro/len;
		retorno = 0;
	}
	return retorno;
}

void ordenarArray(int array[], int len)
{
	int aux;
	do
	{
		for(int i=0; i<len;i++)
		{
			// 3 5 8 1 2  3 5 1 2 8
			if(array[i]>array[i+1])
			{
				aux = array[i+1];
				array[i+1]=array[i];
				array[i]=aux;
			}
		}
		len--;
	}while(len>0);

}
