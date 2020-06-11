/*
 * Controller.h
 *
 *  Created on: 7 jun. 2020
 *      Author: chgonzalez
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "Employee.h"
#include "LinkedList.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

int controller_IdMayor(LinkedList* lista,int* id);
void* controller_buscariD(LinkedList* lista,int id);
int controller_archivo(char* path, char* modo, int (*pfuncion)(FILE* pFile,LinkedList* lista),LinkedList* lista);



#endif /* CONTROLLER_H_ */
