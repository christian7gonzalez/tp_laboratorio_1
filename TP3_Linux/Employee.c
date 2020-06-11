#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"


static int isValidNombre(char* cadena, int len);



Employee* employee_new(void)
{
	return (Employee*)malloc(sizeof(Employee)*1);
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	int flagOk=0;
	Employee* auxEmployee = NULL;
	auxEmployee = employee_new();
	if(auxEmployee != NULL)
	{
		if(!employee_setNombre(auxEmployee,nombreStr))
		{
			if(!employee_setHorasTrabajadas(auxEmployee,atoi(horasTrabajadasStr)))
			{
				if(!employee_setSueldo(auxEmployee,atoi(sueldoStr)))
				{
					if (!employee_setId(auxEmployee,atoi(idStr)))
					{
						flagOk=1;
					}
				}
			}
		}
	}
	if(flagOk==0)
	{
		employee_delete(auxEmployee);
		auxEmployee = NULL;
	}
	return auxEmployee;
}


void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >=1)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this!=NULL && nombre!=NULL)
	{
		if(!isValidNombre(nombre,128))
		{
			strncpy(this->nombre,nombre,128);
			retorno = 0;
		}
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this!=NULL && nombre!=NULL)
	{
		strncpy(nombre,this->nombre,128);
		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this!=NULL && horasTrabajadas>=0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this!=NULL && horasTrabajadas>=0)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this!=NULL && sueldo>=0)
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this!=NULL && sueldo>=0)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}


/**************************************************************************/
//Validaciones para mis SETERS

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int isValidNombre(char* cadena, int len)
{
	int retorno =-1;
	int i;
	if(cadena!=NULL && len>0)
	{
		for(i=0 ; cadena[i] != '\0' && i < len; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' || cadena[i] > ' ' || cadena[i] > '-'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int employee_ordenarPorNombre(void* valor1,void* valor2)
{
	int retorno=0;
	Employee* Emp1;
	Employee* Emp2;
	Employee* bufferPunteroEmployee;
	char nombre1[NOMBRE_LEN];
	char nombre2[NOMBRE_LEN];
	if(valor1!=NULL && valor2!=NULL)
	{
		//retorno=0;
		Emp1 = (Employee*)valor1;
		Emp2 = (Employee*)valor2;
		if(!employee_getNombre(Emp1,nombre1) &&
				!employee_getNombre(Emp2,nombre2))
		{
			//printf("\nEntro");
			if(strncmp(nombre1,nombre2,sizeof(nombre1))<0)//sizeof(nombre1)
			{
				bufferPunteroEmployee = Emp1;
				Emp1 = Emp2;// bufferPunteroEmployee = Emp1;
				Emp2 = bufferPunteroEmployee;// bufferPunteroEmployee = Emp1;
				retorno =0;
				printf("\nEntro");
			}
			else
			{
				retorno =-1;
			}
		}
	}
	return retorno;
}


int employee_ordenarPorId(void* valor1,void* valor2)
{
	int retorno=0;
	Employee* Emp1;
	Employee* Emp2;
	int id1;
	int id2;
	if(valor1!=NULL && valor2!=NULL)
	{
		//retorno=0;
		Emp1 = (Employee*)valor1;
		Emp2 = (Employee*)valor2;
		if(!employee_getId(Emp1,&id1) &&
				!employee_getId(Emp2,&id2))
		{
			if(id1>id2)
			{
				retorno = 1;
			}
			else
			{
				retorno =-1;
			}
		}
	}
	return retorno;
}


