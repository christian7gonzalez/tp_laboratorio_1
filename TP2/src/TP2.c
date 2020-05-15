/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : TP2 in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Employee.h"


int main(void) {
		setbuf(stdout,NULL);
		Employee arrayEmployees[ELEMENTS];
		int opcion;
		int subOpcion;
		int idAuto = 1;
		int auxIndice;
		int idEmployee;
		int auxOrden;
		//int auxiliarIndice;
		char name[NAME_LEN];
		char lastName[LASTNAME_LEN];
		float salary;
		int sector;


		if(!initEmployees(arrayEmployees,ELEMENTS))//inicializar
		{
			printf("Array inicializado correctamente. \n\n");
		}
/////////////////////////////////////////////////////

		addEmployeeDebug(arrayEmployees,ELEMENTS,idAuto,"Christian","Gonzalez", 36000.22,7);
		idAuto++;
		addEmployeeDebug(arrayEmployees,ELEMENTS,idAuto,"Nancy","Barraza", 39000.22,5);
		idAuto++;
		addEmployeeDebug(arrayEmployees,ELEMENTS,idAuto,"Kevin","Gonzalez", 39080.22,2);
		idAuto++;

/////////////////////////////////////////////////////
		do
		{
			if(!utn_getNumero(	&opcion,
								"\n\n1.ALTAS"
								"\n2.MODIFICAR"
								"\n3.BAJA"
								"\n4.INFORMAR"
								"\n5.EXIT\n\n",
								"\nError opcion invalida",1,5,2) )
			{
				switch(opcion)
				{
				case 1:
					if(!utn_getNombre(name,NAME_LEN,"\nEnter the Name: ","\nERROR",2) &&
						!utn_getNombre(lastName,LASTNAME_LEN,"\nEnter the Last Name: ","\nERROR",2) &&
						!utn_getNumeroFlotante(&salary,"\nEnter the salary: ","\nERROR",0,500000,2) &&
						!utn_getNumero(&sector,"\nEnter the sector","\nERROR",0,1000,2))
					{
						if(!addEmployee(arrayEmployees,ELEMENTS,idAuto,name,lastName,salary,sector))
						{
							idAuto++;
							printf("\nFinished - Successful registration.\n");
						}
					}
					break;
				case 2:
					auxIndice = findEmployeeById(arrayEmployees,ELEMENTS,idEmployee);
					if(!utn_getNumero(&idEmployee,"\nEnter the ID","\nERROR",0,1000,2) &&
							auxIndice!=-1)
					{
						if(!utn_getNumero(&subOpcion,"\nWhat do you modify? [1:Name 2:LastName 3:Salary 4:Sector]","\nERROR",1,4,2))
						{
							switch(subOpcion)
							{
							case 1:
								if(!utn_getNombre(name,NAME_LEN,"\nWrite the Name: ","\nERROR",2))
								{
									strncpy(arrayEmployees[auxIndice].name,name,NAME_LEN);
								}
								break;
							case 2:
								if(!utn_getNombre(lastName,LASTNAME_LEN,"\nWrite the Name: ","\nERROR",2))
								{
									strncpy(arrayEmployees[auxIndice].lastName,lastName,LASTNAME_LEN);
								}
								break;
							case 3:
								if(!utn_getNumeroFlotante(&salary,"\nWhat is the new salary?","\nERROR",0,500000,2))
								{
									arrayEmployees[auxIndice].salary = salary;
								}
								break;
								break;
							case 4:
								if(!utn_getNumero(&sector,"\nWhat is the new sector?","\nERROR",0,1000,2))
								{
									arrayEmployees[auxIndice].sector = sector;
								}
								break;
							}
							printf("\nChange made successfully");
						}
					}
					break;

				case 3:

					if(!utn_getNumero(&idEmployee,"\nEnter the ID","\nERROR",0,1000,2) &&
						findEmployeeById(arrayEmployees,ELEMENTS,idEmployee) != -1)
					{
						if(!removeEmployee(arrayEmployees,ELEMENTS,idEmployee))
						{
							printf("\nRemove successfully");
						}
					}
					break;
				case 4:

					if(!utn_getNumero(&auxOrden,"\nEnter the order [0:Down 1:Up]","\nERROR",0,1,2))
					{
						if(!sortEmployees(arrayEmployees,ELEMENTS,auxOrden) )
						{
							printEmployees(arrayEmployees,ELEMENTS);
							averageQuantity(arrayEmployees,ELEMENTS);
						}

					}
					break;
				}
			}
		}while(opcion != 5);

		return EXIT_SUCCESS;
	}
