/*
 * funciones.c
 *
 *  Created on: 4 abr. 2020
 *      Author: Gonzalez
 *
 *      Mis funciones definidas codeadas
 */

int sumar(int x, int y)
{
	int sum;
	sum = x + y;
	if (sum>100)
	{
		sum = 100;
	}
	return sum;
}

int retar(int x,int y)
{
	int resta;
	resta = x - y;
	return resta;
}

int multiplicar (int x, int y)
{
	int multiplicacion;
	multiplicacion = x*y;
	return multiplicacion;
}

int dividir (int x, int y, float* direccionDeVariable)
{
	float errorHub;
	if (y!=0)
	{
		*direccionDeVariable = (float)x / y;
		errorHub = 0;
	}
	else
	{
		errorHub = 1;
	}
	return errorHub;
}

void titulo()
{
	printf("**********************************************************************************************************************\n----CALCULADORA----\n**********************************************************************************************************************\n");
}
void mostrarMenu()
{
	printf("\n1. Ingresar 1er (A = )\n2. Ingresar 2do operando (B = y)\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n\n-Opcion: ");
}

int valorMenu(int x, int y)
{
	int menu;
	printf("\n1. Ingresar 1er (A = %d)\n2. Ingresar 2do operando (B = %d)\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n\n-Opcion: ",x,y);
	scanf("%d",&menu);
	return menu;
}

int factorial(int num)
{
	int mult=1;
	for(int itera=num; itera>0;itera--)
	{
		mult*=itera;
	}
	return mult;
}
