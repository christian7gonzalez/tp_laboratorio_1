#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"

#define LEN_GENERICO 20


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxEmployee;
	if(path != NULL && pArrayListEmployee!=NULL)
	{
		retorno = 0;
		if(ll_len(pArrayListEmployee)>0)
		{
			for(int i=0;i<ll_len(pArrayListEmployee);i++)
			{
				//printf("\n\nEntra");
				auxEmployee = (Employee*)ll_get(pArrayListEmployee,i);
				employee_delete(auxEmployee);
			}
			ll_clear(pArrayListEmployee);
		}

		controller_archivo(path,"r",parser_EmployeeFromText,pArrayListEmployee);//Leo texto
		retorno = 1;
		printf("\n\nLectura completada!\n\n");
	}

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxEmployee;
	//FILE* fp;
	if(path != NULL && pArrayListEmployee!=NULL)
	{
		retorno = 0;
		if(ll_len(pArrayListEmployee)>0)
		{
			for(int i=0;i<ll_len(pArrayListEmployee);i++)
			{
				//printf("\n\nEntra");
				auxEmployee = (Employee*)ll_get(pArrayListEmployee,i);
				employee_delete(auxEmployee);
			}
			ll_clear(pArrayListEmployee);
		}
		controller_archivo(path,"rb",parser_EmployeeFromBinary,pArrayListEmployee);
		printf("\n\nLectura completada!\n\n");
	}
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxEmployee;
	int auxIdInt=1;
	char idParseChar[LEN_GENERICO];
	char nombre[NOMBRE_LEN];
	char horasTrabajadas[LEN_GENERICO];
	char sueldo[LEN_GENERICO];
	if(pArrayListEmployee!=NULL)
	{
		controller_IdMayor(pArrayListEmployee,&auxIdInt);//obtengo id maximo de los Employees
		sprintf(idParseChar, "%d", auxIdInt+1); //parseo a char para utilizar como parametro en employee_newParametros
		retorno =0;
		if(!utn_getNombre(nombre,NOMBRE_LEN,"\nIngrese el nombre del empleado: ","\nError!",2) &&
				!utn_getDescripcion(horasTrabajadas,LEN_GENERICO,"\nIngrese las horas trabajadas del empleado: ","\nError!",2) &&
				!utn_getDescripcion(sueldo,LEN_GENERICO,"\nIngrese el sueldo del empleado: ","\nError!",2))
		{
			auxEmployee = employee_newParametros(idParseChar,nombre,horasTrabajadas,sueldo); //cargar Employee con parametros
			ll_add(pArrayListEmployee,auxEmployee); //Agrego a la lista de empleados
			retorno =1;
		}
		printf("\n\nEmprleado agregado!\n\n");
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxEmployee;
	int auxId;
	int indice;
	char nombre[NOMBRE_LEN];
	char horasTrabajadas[LEN_GENERICO];
	char sueldo[LEN_GENERICO];
	if(pArrayListEmployee!=NULL)
	{
		retorno =0;
		if (!utn_getNumero(&auxId,"\nIngrese el ID del Empleado: ","\nError!",1,3000,2))
		{
			auxEmployee = (Employee*)controller_buscariD(pArrayListEmployee,auxId); //retorno el empleado con el id y el id
			indice = ll_indexOf(pArrayListEmployee,auxEmployee);//obtengo el indice para el seter
			if(!utn_getNombre(nombre,NOMBRE_LEN,"\nIngrese el nombre del empleado: ","\nError!",2) &&
				!utn_getDescripcion(horasTrabajadas,LEN_GENERICO,"\nIngrese las horas trabajadas del empleado: ","\nError!",2) &&
				!utn_getDescripcion(sueldo,LEN_GENERICO,"\nIngrese el sueldo del empleado: ","\nError!",2))
			{
				if(!employee_setNombre(auxEmployee,nombre))
				{
					if(!employee_setHorasTrabajadas(auxEmployee,atoi(horasTrabajadas)))
					{
						if(!employee_setHorasTrabajadas(auxEmployee,atoi(sueldo)))
						{
							ll_set(pArrayListEmployee,indice,auxEmployee);
							printf("\nModificacion realizada con exito!\n\n");
							retorno =1;
						}
					}
				}
			}
		}

	}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	Employee* auxEmployee = NULL;
	int auxId;
	int indice;
	if(pArrayListEmployee!= NULL)
	{
		retorno=0;
		if (!utn_getNumero(&auxId,"\nIngrese el ID del Empleado: ","\nError!",1,3000,2))
		{
			auxEmployee = (Employee*)controller_buscariD(pArrayListEmployee,auxId);
			indice = ll_indexOf(pArrayListEmployee,auxEmployee);
			employee_delete(auxEmployee);
			ll_remove(pArrayListEmployee,indice);
			retorno=1;
		}
	}
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	Employee* auxEmployee;
	int i;
	if(pArrayListEmployee!=NULL)
	{
		retorno = 0;
		printf("\n\nID - Nombre - Horas Trabajadas - Sueldo \n");
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			auxEmployee = (Employee*)ll_get(pArrayListEmployee,i);
			printf("%d - %s - %d - %d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
		}
		retorno = 1;
	}
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int orden;
	if(pArrayListEmployee!=NULL)
	{
		if(!utn_getNumero(&orden,"\nIngrese un orden : DESCENDENTE  [0] ASCENDENTE [1]: ","\nError!",0,1,2))
		{

			ll_sort(pArrayListEmployee,employee_ordenarPorId,orden);
			retorno =1;
		}
	}
	return retorno;
}



/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	FILE* fp;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		controller_archivo(path,"w",parse_saveText,pArrayListEmployee);
		fp= fopen(path,"w");
		if(fp!=NULL)
		{
			parse_saveText(fp,pArrayListEmployee);
			fclose(fp);
			retorno = 1;
		}
		printf("\nEXITO - Datos guardados\n\n");
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	//FILE* fp;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		controller_archivo(path,"wb",parse_saveBinary,pArrayListEmployee);
		printf("\n\nEXITO - Datos guardados\n\n");
		retorno = 0;
	}
    return retorno;
}


int controller_IdMayor(LinkedList* lista,int* id)
{
	int retorno = -1;
	Employee* cadena = NULL;
	int i;
	int flagMaxId = 1;
	if(lista!=NULL && id!=NULL)
	{
		for(i=0;i<ll_len(lista);i++)
		{
			cadena = (Employee*)ll_get(lista,i);
			if(flagMaxId || cadena->id > *id)
			{
				*id = cadena->id;
				flagMaxId = 0;
			}
		}
		retorno = 0;
	}
	return retorno;
}

void* controller_buscariD(LinkedList* lista,int id)
{
	Employee* auxEmployee;
	int i;
	if(lista!=NULL)
	{
		for(i=0;i<ll_len(lista);i++)
		{
			auxEmployee = (Employee*)ll_get(lista,i);
			if(auxEmployee->id == id)
			{
				break;//encontre el id salgo sin modificar auxEmployee
			}
		}
	}
	return auxEmployee;
}

int controller_archivo(char* path, char* modo, int (*pfuncion)(FILE* pFile,LinkedList* lista),LinkedList* lista)
{
	int retorno =-1;
	FILE* pFile;
	if(path!=NULL && modo!=NULL)
	{
		retorno =0;
		pFile = fopen(path,modo);
		if(pFile!=NULL)
		{
			pfuncion(pFile,lista); //parser_EmployeeFromText(pFile,lista);
			fclose(pFile);
			retorno=1;
		}
	}
	return retorno;
}


