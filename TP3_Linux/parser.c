#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"




/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee = NULL;
	int retorno = -1;
	char a[3000];
	char b[3000];
	char c[3000];
	char d[3000];
	if(pFile!=NULL)
	{
		do{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",a,b,c,d)==4) //%s"
			{
				auxEmployee = employee_newParametros(a,b,c,d);
				if(auxEmployee!=NULL)
				{
					//printf("%d - %s - %d - %d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
					ll_add(pArrayListEmployee,auxEmployee);
				}
			}
		}while(feof(pFile)==0);
		retorno = 1;
	}
    return retorno;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee =NULL;
	int fin;
	int retorno =-1;
	int i;
	if(pFile!=NULL)
	{
		//fwrite("\n\nID - Nombre - Horas Trabajadas - Sueldo \n",sizeof(char),1,pFile);
		do//for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			auxEmployee = employee_new();
			fin = fread(auxEmployee,sizeof(Employee),1,pFile);
			if(fin==1)
			{
				ll_add(pArrayListEmployee,auxEmployee);
				i++;
			}
			//printf("%d %s %d %d\n",auxEmployee->id, auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
		}while(feof(pFile)==0);
		//while(i>ll_len(pArrayListEmployee));
		retorno = 1;
	}
    return retorno;
}


int parse_PathBin(char* path,char* path2)
{
	int retorno=-1;
	int i;
	if(path2!=NULL && path!=NULL)
	{
		strncpy(path2,path,PATH_LEN);
		for(i=0;i<strnlen(path,sizeof(path2));i++)
		{
			if(path2[i-1] == '.')
			{
				path2[i]='b';
				path2[i+1]='i';
				path2[i+2]='n';
				path2[i+3]='\0';
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int parse_saveText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	Employee* auxEmployee;
	int i;
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			auxEmployee = (Employee*)ll_get(pArrayListEmployee,i);
			fprintf(pFile,"%d,%s,%d,%d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
			retorno = 0;
		}
	}
	return retorno;
}

int parse_saveBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	Employee* auxEmployee;
	int i;
	//char titulo[]="id,nombre,horasTrabajadas,sueldo";
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		//fprintf(pFile,"%s\n",titulo);
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			auxEmployee = (Employee*)ll_get(pArrayListEmployee,i);
			fwrite(auxEmployee,sizeof(Employee),1,pFile);
		}
		retorno = 0;
	}
	return retorno;
}
