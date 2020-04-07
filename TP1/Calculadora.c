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
#include "funciones.h"

#define TRUE 0
#define FALSE 1

int main(void)
{
	setbuf(stdout,NULL);
	int menu;
	char subMenu;
	int x=0;
	int y=0;
	int flagX= TRUE;
	int flagY= TRUE;
	int flagOperacion=TRUE;
	int errorHub;
	float resultado;
	int resFactorialA;
	int resFactorialB;

	do
	{
		titulo();
		menu= valorMenu(x, y);
		while(menu<1 || menu>5)
		{
			printf("\n\n\aERROR - Valor invalido - Reintente! \n");
			system("PAUSE");
			system("cls");
			titulo();
			menu= valorMenu(x, y);
		}
		//system("cls");
		system("cls");
		titulo();
		printf("\n1. Ingresar 1er (A = %d)\n2. Ingresar 2do operando (B = %d)\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n\n-Opcion: %d",x,y,menu);
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
				printf("\n\n--Submenu--\na) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division (A/B)\nd) Calcular la multiplicacion (A*B)\ne) Calcular el factorial (A!)\n\n-Opcion: ");
				fflush(stdin);
				scanf("%c",&subMenu);
				while(subMenu!='a' && subMenu!='b' && subMenu!='c' && subMenu!='d' && subMenu!='e')
				{
					printf("\n\n\aERROR - Valor invalido - Reintente! \n");
					system("PAUSE");
					system("cls");
					titulo();
					printf("\n1. Ingresar 1er (A = %d)\n2. Ingresar 2do operando (B = %d)\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n\n-Opcion: %d",x,y,menu);
					printf("\n\n--Submenu--\na) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division (A/B)\nd) Calcular la multiplicacion (A*B)\ne) Calcular el factorial (A!)\n\n-Opcion: ");
					fflush(stdin);
					scanf("%c",&subMenu);
				}
				switch(subMenu)
				{
					case 'a': resultado = sumar(x,y); break;
					case 'b': resultado = retar(x,y); break;
					case 'c': errorHub = dividir(x,y,&resultado); break;
					case 'd': resultado = multiplicar(x,y); break;
					case 'e': resFactorialA = factorial(x); resFactorialB = factorial(y); break;

				}
				flagOperacion=FALSE;
				system("cls");
				break;

			case 4:

				if(flagOperacion==FALSE && flagX==FALSE && flagY==FALSE)
				{
					if(errorHub!=0 && subMenu=='c')
					{
						printf("\n\nERROR - No se puede realizar la division, B es Cero.\n");
						system("PAUSE");
					}
					else if(subMenu=='e')
					{
						printf("\n\n--RESPUESTA--\n");
						if(resFactorialA!=0)
						{
							printf("El factorial de A es: %d.\n",resFactorialA);
						}
						else
						{
							printf("\n\n\aERROR - No se puede realiza el factorial de un numero menor a 1. A es igual a %d.\n",x);
						}

						if(resFactorialB!=0)
						{
							printf("El factorial de B es: %d.\n\n",resFactorialB);
						}
						else
						{
							printf("\n\n\aERROR - No se puede realiza el factorial de un numero menor a 1. B es igual a %d.\n\n",y);
						}
						system("PAUSE");
					}
					else{
						printf("\n\n--RESPUESTA--\nEl resultado es: %.2f.\n",resultado);
						system("PAUSE");
					}
				}else
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



