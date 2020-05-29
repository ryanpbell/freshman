#include "lab13.h"


/*
This function reads a given file and returns an array of Student pointers with age and ID values
from the file.
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
		
		int i = 0;
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
This function compares the void pointer values a and b. returns a positive number if a is greater
than b, returns a negative number if b is greater than a, and returns 0 if a and b are the same.
Input:
a: the first number being compared
b: the second number being compared
Output:
returns the different between a and b, positive if a is greater, negative if b is greater and 0
if they are the same.
*/
int comparison(void* a, void* b)
{
	return (*(int *)a - *(int *)b);
}


/*
This function searches for a target ID in the given array arr and returns the place of the 
Student object in the array.
Input:
arr: the current array of void objects
low: the lower part of the binary search
high: the higher part of the binary search
target: the ID that the function is searching for
Output:
returns the place of the given target and returns -1 if the target ID is not in the array
*/
int binarySearch(void** arr, int low, int high, void* target)
{
	if (low > high)
	{
		return -1;
	}
	
	int mid = (low + high)/2;
	int comp = comparison(&((Student*)target)->ID, &((Student**)arr)[mid]->ID);
	
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
This function frees all allocated memory of the given Student array arr
Input:
arr: the Student array that will be freed.
size: the size of the array
Output:
frees all allocated memory in the array
*/
void (freeArr(Student** arr, int size)
{
	int i;
	for (i=0; i<size; i++)
	{
		free(&(arr)[i]);
	}
	free(arr);
}




















