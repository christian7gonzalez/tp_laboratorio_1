/*
 * Calculadora.c
 *
 *  Created on: 4 abr. 2020
 *      Author: Gonzalez
 *      1 Enunciado
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 *
 */
#include<stdio.h>
#include<stdlib.h>

#include "utn.h"

#define TRUE 0
#define FALSE 1

int main(void)
{
	setbuf(stdout,NULL);
	int menu;//4 byte
	char subMenu; // 1 byte 'b'
	int x=0;
	int y=0;
	char operacion = ' ';
	int flagX= TRUE;
	int flagY= TRUE;
	int flagOperacion=TRUE;
	int errorHub;
	float resultado;
	double factorialA;
	double factorialB;
	double respuestaFacA;
	double respuestaFacB;

	do
	{
		menu= valorMenu(x, y,operacion); //Devuelve la opcion del menu y asigna a menu.
		switch(menu)
		{
			case 1:
				printf("\nIngrese el valor para A: ");
				scanf("%d",&x);
				system("cls");
				flagX=FALSE;
				break;
			case 2:
				printf("\nIngrese el valor para B: ");
				scanf("%d",&y);
				system("cls");
				flagY=FALSE;
				break;
			case 3:
				printf("\n\n--Submenu--\na) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division (A/B)\nd) Calcular la multiplicacion (A*B)\ne) Calcular el factorial (A!) y (B!)\nf) Volver\n\n-Opcion: ");
				fflush(stdin);
				scanf("%c",&subMenu);
				while(subMenu<'a' || subMenu>'f') //entra cuando el valor del submenu no esta entre a y e
				{
					printf("\n\n\aERROR - Valor invalido - Reintente! \n");
					system("PAUSE");
					system("cls");
					titulo();
					printf("\n1. Ingresar 1er (A = %d)\n2. Ingresar 2do operando (B = %d)\n3. Calcular todas las operaciones (%c)\n4. Informar resultados\n5. Salir\n\n-Opcion: %d",x,y,operacion,menu);
					printf("\n\n--Submenu--\na) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division (A/B)\nd) Calcular la multiplicacion (A*B)\ne) Calcular el factorial (A!) y (B!)\nf) Volver\n\n-Opcion: ");
					fflush(stdin);
					scanf("%c",&subMenu);
				}

				switch(subMenu)
				{
					case 'a': operacion = '+'; break;
					case 'b': operacion = '-'; break;
					case 'c': operacion = '/'; break;
					case 'd': operacion = '*'; break;
					case 'e': operacion ='!'; break;
					case 'f': break;
				}
				flagOperacion=FALSE;

				system("cls");
				break;

			case 4:
				if (flagOperacion == FALSE && flagX == FALSE && flagY == FALSE)
				{
					switch(subMenu)
					{
					case 'a':
						resultado = utn_sumar(x,y);
						printf("\n\nEl resultado de A+B es: %.2f\n",resultado);
						system("PAUSE");
						break;
					case 'b':
						resultado = utn_retar(x,y);
						printf("\n\nEl resultado de A-B es: %.2f\n",resultado);
						system("PAUSE");
						break;
					case 'c':
						errorHub = utn_dividir(x,y,&resultado);
						if(errorHub==0)
						{
							printf("\n\nEl resultado de A/B es: %.2f\n",resultado);
							system("PAUSE");
						}
						else
						{
							printf("\n\n\aERROR - No es posible dividir por cero.\n");
							system("PAUSE");
						}
						;break;
					case 'd':
						resultado = utn_multiplicar(x,y);
						printf("\n\nEl resultado de A*B es: %.2f\n",resultado);
						system("PAUSE");
						break;
					case 'e':
						respuestaFacA = utn_factorial(x,&factorialA); respuestaFacB = utn_factorial(y,&factorialB);
						if(respuestaFacA == 0)
						{
							printf("\n\nEl factorial de A = %d es: %.2f.\n",x,factorialA);

						}
						else
						{
							printf("\n\n\aERROR - No se puede realizar el factorial de un numero menor a 0. A es %.2f.\n",factorialA);
							system("PAUSE");
						}
						if(respuestaFacB == 0)
						{
							printf("El factorial de B = %d es: %.2f.\n",y,factorialB);
							system("PAUSE");
						}
						else
						{
							printf("\aERROR - No se puede realizar el factorial de un numero menor a 1. B es %.2f.\n\n",factorialB);
							system("PAUSE");
						}
						break;
					}
				}
				else
				{
					printf("\a\n\nALERTA! - No realizo ninguna operacion o no ingreso valores para A y B.\n");
					system("PAUSE");
				}
				system("cls");
				break;
			case 5: break;
		}
	}while(menu != 5);
	return 0;
}



