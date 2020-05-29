#include <stdio.h>
#include <stdlib.h>

typedef struct {    
	int empID, age, ssn;    
	float salary;
} Record;

Record* readRecordFile(FILE*);
int getSize(Record*);
Record* getEmpByAge(Record*,int);
void adjustSalaries(Record*,int,float);
void freeRecordArray(Record*);


int main(void)
{
	FILE *fptr;
	fptr = fopen("employee.csv", "r");
	if (fptr == NULL)
	{
		printf("Failed to open the file.");
		return 0;
	}
	Record *arr;
	arr = (Record*)readRecordFile(fptr);
	
	printf("The size of the array is %d\n\n", getSize((Record*)arr));
	fclose(fptr);
	return 0;
}

/*
This function reads a file with employee statistics and creates an array for the Record structures to be stored
in. The size of the array is hidden in the -1 spot.
Input:
fptr: the file pointer
Output:
an array with the structures of the employees
*/
Record* readRecordFile(FILE* fptr)
{
	if(!feof(fptr))
	{
		int size;
		int i=0;
		
		fscanf(fptr, "%d\n", &size);
		
		int * rec = (int *)malloc(sizeof(Record) * size + sizeof(int));
		
		if (rec == NULL)
		{
			printf("Error, failed to allocate memory");
			return NULL;
		}
		
		*rec = size; //sets the first value of rec to size
		rec++; //hides the size

		for (i =0; i<size; i++)
		{
			if (!feof(fptr))
			{
				fscanf(fptr, "%f,%d,%d,%d\n", &(((Record *)rec+i)->salary), &(((Record *)rec+i)->age), &(((Record *)rec+i)->empID), &(((Record *)rec+i)->ssn));
				
			}
		}

		return (Record *)rec;
	}
	else
		return NULL;
}

/*
This function returns the size of the array of employees which is hidden in the -1 spot
Input:
rec: The array of Records of the employees
Output:
the size of the array which is stored in the -1 position
*/
int getSize(Record* rec)
{
	return *((int*)rec-1);
}

/*
This function returns the pointer to the first employee that is the age given in the input
Input:
rec: array of Records of the employees
age: the target age that the function is looking for
Output:
The pointer to the first instance of that age in the array of employees
*/
Record* getEmpByAge(Record* rec,int age)
{
	for (int i=0; i<getSize(rec); i++)
	{
		if ( (((Record *)rec+i)->age) == age)
		{
			return (Record *)rec+i;
		}
	}
	return NULL;
}

/*
This function adjusts all of the salaries of a given age by a given multiple
Input:
rec: array of Records of the employees
age: the target age whose salraies will be changed
mult: The multiple to multiply the salaries by to change the given salaries
Output:
Does not return anything, just cahnges the values of the salaries
*/
void adjustSalaries(Record* rec,int age,float mult)
{
	for (int i=0; i<getSize(rec); i++)
	{
		if ( (((Record *)rec+i)->age) == age)
		{
			(((Record *)rec+i)->salary) = (((Record *)rec+i)->salary) * mult;
		}
	}
	return;
}

/*
This function frees the array of Records, which starts at eh hidden position -1
Input:
rec: array of Records of the employees
Output:
Does not return, just frees the array
*/
void freeRecordArray(Record* rec)
{
	free((void *)((int *)rec - 1));
	return;
}






























