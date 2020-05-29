#include "lab14.h"

//custom prototypes
void insertionSort(Student**, int);
int comparison(int, int);
int binarySearch(Student**, int, int, int);Employee""

/*
This function takes a given file pointer fp, and returns an array of Student pointers with given
age and ID values from the file.
Input:
fp: the pointer to the file
Output:
returns an array of Student pointers with age and ID values from the file
*/
Student** readRecord(FILE* fp)
{
	if (fp == NULL)
	{
		printf("could not open file.\n");
		return NULL;
	}
	else
	{
		int size;
		fscanf(fp, "%d\n", &size);
		
		Student** arr = malloc(sizeof(Student*)*size);
		
		if (arr == NULL)
		{
			printf("failed to allocate memory.\n");
			return NULL;
		}
		
		int i=0;
		while (!feof(fp))
		{
			*(arr+i) = (Student *)malloc(sizeof(Student));
			
			fscanf(fp, "%d,%d\n", &(arr[i]->age), &(arr[i]->ID));
			
			i++;
		}
		
		return (Student**)arr;
	}
}


/*
This function sorts the given array of Student pointers in descending order of their ID values
Input:
arr: the current array of Student pointers
size: the size of the array
Output:
the array passed in is now sorted in descending order of ID values
*/
void insertionSort(Student** arr, int size)
{
	int i;
	int j;
	Student* place;
	
	for (i=0; i<size; i++)
	{
		for (j=0; j<size-1; j++)
		{
			if (arr[j]->ID < arr[j+1]->ID)
			{
				place = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = place;
			}
		}
	}
}


/*
This function creates a Student database with a sorted array in descending order of ID values and 
a given size.
Input:
arr: the current array of Student pointers
size: the size of arr
Output:
returns a created StudentDB with a sorted array in descending order of ID values and a given size.
*/
StudentDB createDatabase(Student** arr, int size)
{
	StudentDB data;
	data.sizeOfDB = size;
	
	insertionSort(arr, size);
	data.array = arr;
	
	return data;
}


/*
This function compares 2 integer values.
Input:
a: the first integer value
b: the second integer value
Output:
returns the difference of the 2 int values, positive if a>b, negative if b>a, 0 if a=b
*/
int comparison(int a, int b)
{
	return (a - b);
}


/*
This function returns the position of the Student object with the target ID.
Input:
arr: the current array of Student pointers
low: the bottom of the binary search
high: the top of the binary search
target: the ID value that is being searched for
Output:
returns the position of the target ID in the given array, returns -1 if the target ID cannot be 
found.
*/
int binarySearch(Student** arr, int low, int high, int target)
{
	if (low > high)
	{
		return -1;
	}
	
	int mid = (low + high) / 2;
	int comp = comparison(target, arr[mid]->ID);
	
	if (comp > 0)
	{
		return binarySearch(arr, low, mid-1, target);
	}
	else if (comp < 0)
	{
		return binarySearch(arr, mid+1, high, target);
	}
	else
	{
		return mid;
	}
}


/*
This function returns the Student pointer with the given target ID value
Input:
data: the current Student database
target: the ID value that is being searched for
Output:
returns the pointer to the Student object with the given target vlaue
*/
Student* findStudentByID(StudentDB data, int target)
{
	int place = binarySearch(data.array, 0, data.sizeOfDB, target);
	
	if (place < 0)
	{
		printf("could not find the target ID.\n");
		return NULL;
	}
	
	return (Student *)data.array[place];
}


/*
This function frees all allocated memory in the Student database
Input:
data: the current Student database
Output:
frees the allocated memory in the Student database
*/
void freeDatabase(StudentDB data)
{
	int size = data.sizeOfDB;
	int i;
	for (i=0; i<size; i++)
	{
		free(&(data.array)[i]);
	}
	free(data.array);
}



























