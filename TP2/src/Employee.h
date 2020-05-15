/*
 * Employee.h
 *
 *  Created on: May 11, 2020
 *      Author: HP
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#define ELEMENTS 1000
#define NAME_LEN 51
#define LASTNAME_LEN 51

typedef struct
{
	int id;
	char name[NAME_LEN];
	char lastName[LASTNAME_LEN];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int initEmployees(Employee* list, int len);
int getEmptyIndex(Employee list[], int len);
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);
int averageQuantity(Employee* list, int len);


int addEmployeeDebug(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
#endif /* EMPLOYEE_H_ */
