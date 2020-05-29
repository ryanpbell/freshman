#include <stdio.h>
#include <stdlib.h>

void* createArray(int, int);
int getArraySize(void*);
void freeArray(void*);
void storeAve(void*);

int main(void)
{    
	int arraySize = 10; // size of array 
	double *arr=0;
	int size=0;
	
	arr = createArray(arraySize, sizeof(double)); //creates an array of arraySize+2
	size = getArraySize(arr); //returns the amount of elements in the array
	
	
	printf("Enter %d values as the values in the array.\n", size); //takes in values from the user
	for (int i=2; i<arraySize+2; i++)
	{
		scanf("%lf", (arr+i));
	}
	
	storeAve(arr); //calculates and stores the average
	
	printf("The size of the array is %d.", (int)(*arr));
	printf(" The average value of the elements is %lf\nThe elements in the array are: ", (double)(*(arr+1)));
	for (int z=2; z<arraySize+2; z++)
	{
		printf("%lf", *(arr+z));
		if (z != arraySize+1)
			printf(", ");
	}
	
	
	freeArray(arr); //frees the allocated memory
	return 0;
}

/*
This function recieves two integers, n and elemSize, as inputs.
It creates an array with size n+2, allocates memory for the array with the given elemSize, and
assigns the first value to n, and the rest to 0.
The first two spaces in the array are for number of elements in the array (n) and for the average value
of the elements in the array.
The array is then returned.
n: the amount of elements in the array
elemSize: use the sizeof() operator when calling to correctly allocate the memory for the array
EX. createArray(10, sizeof(int)); 
*/
void* createArray(int n, int elemSize)
{
	double *arr=0;
	
	arr = malloc((n+2)*elemSize);
	
	if (arr == NULL) //check for successful allocation
	{
		printf("error, could not allocate memory\n");
		return 0;
	}
	
	*arr = n;
	for (int i=1; i<n+2; i++)
	{
		*(double *)(arr+i) = 0;
	}
	
	return arr;
}

/*
This function recieves a void array as input.
This function returns the amount of elements in the array, to do so the function must return
the first value stored in the array, since that value stores the number of elements in the array.
arr: void array with the first value storing the amount of elements in the array.
*/
int getArraySize(void *arr)
{
	return (int)(*(double*)arr);
}

/*
This fuction recieves a void array as input.
This fuction calculates the average value of the elements in the array and stores the average to the 
second value in the array.
The function loops through each element in the array and adds it to sum, size is then found using the 
getArraySize function and the average is calcuated and stored in the second position of the array.
arr: void array with the first two positions in the array being the number of elements and the second 
being the place to store the average value of the elements.
*/
void storeAve(void *arr)
{
	double sum=0;
	double avg=0;
	int size = getArraySize(arr);
	
	for (int i=2; i<size+2; i++)
	{ 
		sum += (*(((double *)arr)+i));
	}
	
	avg = sum/size;
	(*(((double *)arr)+1)) = avg;
}

/*
This function recieves a void array as input.
This function frees the allocated memory for the array by calling free.
array: void array that needs to be freed.
*/
void freeArray(void *array)
{
	free(array);
}




















