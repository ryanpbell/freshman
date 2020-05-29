#include <stdio.h>
#include <stdlib.h>

//prototypes
int* readIntAgeIntoArray(FILE* fptr, int* totalEmp, float* avgAge);
void findMinMax(int* arr, int size, int* min, int* max);
void freeIntArray(int** aptr);

int main(void)
{
	FILE *fptr = fopen("employeeAge.txt", "r"); //opens the file
	int *totalEmp;
	int *minP;
	int *maxP;
	float *avgAge;
	int total=0;
	int min=0;
	int max=0;
	float avg=0;
	int *arr;
	
	//initializes the pointers
	totalEmp = &total;
	minP = &min;
	maxP = &max;
	avgAge = &avg;
	
	arr = readIntAgeIntoArray(fptr, totalEmp, avgAge);
	printf("The total num of employees is %d\nThe avgerage age of the employees is %f\n", total, avg);
	
	findMinMax(arr, total, minP, maxP);
	printf("The smallest age is %d\nThe largest age is %d\n", min, max);
	
	freeIntArray(&arr);
	
	return 0;
}


//given a file, it will return an array of all of the ages of the employees and it 
//will compute the average age and the total number of employees passed by reference
int* readIntAgeIntoArray(FILE* fptr, int* totalEmp, float* avgAge)
{
	int *arr;
	int i=0;
	int sum=0;
	
	fscanf(fptr, "%d", totalEmp);
	
	arr = (int*)malloc((*totalEmp)*sizeof(int)); //allocates memory for arr
	
	
	while (!feof(fptr)) //while it is not the end of the file
	{
		fscanf(fptr, "%d", arr+i);
		sum += *(arr+i);
		i++;
	}
	
	*avgAge = (float)sum/(*totalEmp);
	
	fclose(fptr); //closes the file
	return arr;
}

//calculates the min and max of the arr and passes them by reference. does not return anything
//sets the values stored in the min and max pointers to the min and max ages
void findMinMax(int* arr, int size, int* min, int* max)
{
	*min = *arr;
	*max = *arr;
	for (int i=0; i<size; i++)
	{
		if (*(arr+i) < *min)
			*min = *(arr+i);
		else if (*(arr+i) > *max)
			*max = *(arr+i);
	}
}

//frees the array and sets the pointer passed by reference to NULL
void freeIntArray(int** aptr)
{
	free(*aptr);
	*aptr = NULL;
}























