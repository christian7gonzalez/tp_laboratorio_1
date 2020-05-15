/*
 * Employee.c
 *
 *  Created on: May 11, 2020
 *      Author: Christian Gonzalez
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Employee.h"



/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
 return retorno;
}


/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(Employee array[], int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno = -1;
	int auxIndice;
	if( array != NULL && len > 0 && id >= 0 && name != NULL && lastName != NULL && salary > 0 )
	{
		auxIndice = getEmptyIndex(array,len);
		printf("%d",auxIndice);
		array[auxIndice].id = id;
		strncpy(array[auxIndice].name,name,NAME_LEN);
		strncpy(array[auxIndice].lastName,lastName,LASTNAME_LEN);
		array[auxIndice].salary = salary;
		array[auxIndice].sector = sector;
		array[auxIndice].isEmpty=0;
		retorno = 0;
	}
	return retorno;
}

/** \brief find in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int getEmptyIndex(Employee list[], int len)
{
	int retorno =-1;
	int i;
	if(list != NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 1)
			{
				retorno = i;
				//printf("\nlibre %d",i);
				break;
			}
		}
	}
	return retorno;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id == id && list[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}

	}
	return retorno;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
	int retorno =-1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id == id && list[i].isEmpty == 0)
			{
				list[i].isEmpty = 1;
				retorno =0;
				break;
			}
		}

	}
	return retorno;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
	int retorno = -1;
	int i;
	Employee bufferEntity;
	int flagSwap;
	int auxCompare;
	if(list != NULL && len > 0)
	{
		do{
			flagSwap=0;
			for(i=0;i<len;i++)
			{
				if(list[i].isEmpty || list[i+1].isEmpty)
				{
					continue;
				}
				auxCompare = strncmp(list[i].lastName, list[i+1].lastName,LASTNAME_LEN);
				if((auxCompare < 0 && order==1) || (auxCompare == 0 && order==1 && list[i].sector > list[i+1].sector) ||
				   (auxCompare > 0 && order==0) || (auxCompare == 0 && order==0 && list[i].sector < list[i+1].sector))
				{
					flagSwap = 1;
					bufferEntity = list[i+1];
					list[i+1] = list[i];
					list[i] = bufferEntity;
				}
			}
			len--;
		}while(flagSwap);

		retorno = 0;
	}
	return retorno;
}


/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length)
{
	int retorno = -1;
	int i;
	if(list != NULL && length > 0)
		{
			for(i=0;i<length;i++)
			{
				if(list[i].isEmpty == 0)
				{
					printf("\nID - %d - %s - %s - %d -%.2f",list[i].id,list[i].lastName,list[i].name,list[i].sector,list[i].salary);
				}
			}
		}
	return retorno;
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
int averageQuantity(Employee* list, int len)
{
	int retorno = -1;
	int i;
	int quaEmployees=0;
	int quaSupSalaryAverage=0;
	float salarioTotal=0;
	float average;
	if(list != NULL && len > 0)
		{
			for(i=0;i<len;i++)
			{
				if(list[i].isEmpty == 0)
				{
					quaEmployees++;
					salarioTotal += list[i].salary;
					//printf("\nID - %d - %s - %s - %d -%.2f",list[i].id,list[i].lastName,list[i].name,list[i].sector,list[i].salary);
				}
			}
			average = salarioTotal / quaEmployees;

			for(i=0;i<len;i++)
			{
				if(list[i].isEmpty == 0)
				{
					if(list[i].salary > average)
					{
						quaSupSalaryAverage++;
					}
					//printf("\nID - %d - %s - %s - %d -%.2f",list[i].id,list[i].lastName,list[i].name,list[i].sector,list[i].salary);
				}
			}
			printf("\n\nINFORME:\nThe complete salary from all employees -- %.2f"
					"\nThe average salary -- %.2f"
					"\nThe quantity employees with salary higher to average -- %d",
																salarioTotal,
																average,
																quaSupSalaryAverage);

			retorno = 0;
		}
		return retorno;
}

////////////////////////////////////////////////////////////////////////////////////////////
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployeeDebug(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno = -1;
	int indice;
	Employee bufferEntity;
	if( list != NULL && len > 0 && id >= 0 && name != NULL && lastName != NULL && salary > 0 )
	{
	    indice = getEmptyIndex(list,len);
	    bufferEntity.id = id;
		strncpy(bufferEntity.name,name,NAME_LEN);
		strncpy(bufferEntity.lastName,lastName,LASTNAME_LEN);
		bufferEntity.salary = salary;
		bufferEntity.sector = sector;
		bufferEntity.isEmpty=0;
		list[indice] = bufferEntity;
		retorno = 0;
	}
	return retorno;
}
