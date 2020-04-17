/*
 * funciones.c
 *
 *  Created on: 4 abr. 2020
 *      Author: Gonzalez
 *
 *      Mis funciones definidas codeadas
 */
/**\\EJEMPLO DE COMENTARIO
 * \brief  	Que hace
 *\param	que parametros son
 *\param	que parametros son
 *\return 0 si OK o -1 para indicar un error
 *
 */

#include<stdio.h>
#include<stdlib.h>

/**
 * \brief Imprime un titulo para mi proyecto
 *\param
 *\param
 *\return 0 si OK o -1 para indicar un error
 *
 */
void titulo(void)
{
	printf("**********************************************************************************************************************\n----CALCULADORA----\n**********************************************************************************************************************\n");
}

/**
 * \brief Imprime el menu, el titulo con printf y llamando a la funcion titilo
 *\param num1 toma el valor de x en main, remplaza la mascara en el printf
 *\param num2 toma el valor de y en main, remplaza la mascara en el printf
 *\param operacion que operacion debe realizar, remplaza la mascara en el printf
 *\return bufferMenu del 1 al 5 ok.
 *
 */
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

/**
 * \brief Realiza una suma de 2 numeros
 *\param num1 toma valores enteros int
 *\param num2 toma valores enteros int
 *\return sum se devuelve el valor de la suma(int).
 *
 */
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
/**
 * \brief Realiza la resta de 2 numeros, guarda en variable local resta
 *\param num1 toma valores enteros int
 *\param num2 toma valores enteros int
 *\return resta se devuelve el valor de la resta(int).
 *
 */
int utn_retar(int num1,int num2)
{
	int resta;
	resta = num1 - num2;
	return resta;
}

/**
 * \brief Realiza la multiplicacion de 2 numeros, guarda en variable local multiplicacion
 *\param num1 toma valores enteros int
 *\param num2 toma valores enteros int
 *\return multiplicacion devuelve el valor de la multiplicacion(int).
 *
 */
int utn_multiplicar (int num1, int num2)
{
	int multiplicacion;
	multiplicacion = num1 * num2;
	return multiplicacion;
}
/**
 * \brief Realiza la division de 2 numeros, guarda valor por referencia
 *\param num1 toma valores enteros int, es dividendo
 *\param num2 toma valores enteros int, es divisor
 *\param pDireccionDeVariable es un puntero del tipo double donde se guarda el varlor de la division
 *\return errorHub 0 si es ok y -1 si hay algun error.
 *
 */
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
/**
 * \brief Realiza el factorial de un numero, guarda valor por referencia
 *\param num toma valores enteros int
 *\param pDireccionFactorial es un puntero a la direccion de memoria donde se guarda el varlor del factorial
 *\return errorHub 0 si es ok y -1 si hay algun error.
 *
 */
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






