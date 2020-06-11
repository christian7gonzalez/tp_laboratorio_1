#define PATH_LEN 15

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parse_PathBin(char* path,char* path2);
int parse_saveText(FILE* pFile , LinkedList* pArrayListEmployee);
int parse_saveBinary(FILE* pFile , LinkedList* pArrayListEmployee);
