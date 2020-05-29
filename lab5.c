#include <stdio.h>
#include <stdlib.h>

void** create2DArray(int, int, int);
float getRowSize(void**);
float getColSize(void**, int);
void printTable(void**);
void freeTable(void**);

int main(void)
{
	int row = 5;
	int col = 7;
	
	void **table;
	table = create2DArray(row, col, sizeof(int*));
	
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
			*((int*)*(table+i)+j) = 2;
		}
	}
	
	printTable(table);
	
	freeTable(table);
	
	return 0;
}

/*
this function creates an array with an extra spot for the number or rows and an extra column for the number of columns.
Assigns the value of the number of rows in the space [-1][0] and the number of columns in [x][-1] where x is any of the given rows in the 
array

input:
row: the number of rows.
col: the number of columns.
dtype: The datatype of the elements of the array

output:
the created 2D array
*/
void** create2DArray(int row, int col, int dtype)
{
	int **matrix;
	matrix = malloc(sizeof(float) * (row+1)); //allocates for all of the float number of cloumns plus one for the float num of rows
	if (matrix == NULL)
	{
		printf("Error, malloc failed.");
		return NULL;
	}
	
	for (int i=0; i<row; i++)
	{
		matrix[i] = malloc(dtype*(col+1));
		if (matrix[i] == NULL)
		{
			printf("Error, malloc failed.");
			return NULL;
		}
	}
	
	matrix[0][0] = row;
	printf("%d\n", matrix[0][0]);
	
	for(int j=1; j<row; j++)
	{
		matrix[j][0] = col; //sets the values in the first column to col
	}
	
	matrix = ((int**)matrix+1); //moves the pointer one integer behind in the rows
	*matrix = ((int*)(*matrix)+1); //moves the pointer one integer behind in the columns
	
	return (void**)matrix;
}

/*
This function prints the elements of the 2D array.

input:
array: 2D array of unknown datatype which is being printed

output:
no return, prints the array
*/
void printTable(void** array)
{
	int row =0;
	int col =0;
	col = (int)getColSize(array, 0);
	row = (int)getRowSize(array);
	printf("The number of rows is %d. The number of columns is %d\n", row, col);
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
			printf("%d ", *((int*)array[i]+j) );
		}
		printf("\n");
	}
}

/*
This function finds the number of rows in the array, which is stored in the [-1][0] place

input:
array: 2D array of unknown datatype that has the rowsize stored in [-1][0]

output:
returns the number of rows that is stored
*/
float getRowSize(void** array)
{
	return *((int*)array[-1]+0);
}

/*
This function finds the number of columns in the array, which is stored in the [rownum][-1] position.
The size is stored in each of the positions in the -1 column. returns -1 if rownum is outside of the 
array boundaries

input:
array: The 2D array with the column size stored in the elements in the -1 column
rownum: The row in which should be checked the size of

output:
returns the size of the row at the rownum
*/
float getColSize(void** array, int rownum)
{
	if (rownum < 0 || rownum > getRowSize(array))
		return -1;
	else
		return *((int*)array[rownum]-1);
}

/*
This function frees the 2D array

input:
array: 2D array that is being freed

output:
no return, frees the array
*/
void freeTable(void** array)
{
	for (int i=0; i<getRowSize(array); i++)
	{
		free(array[i]);
	}
	free(array);
}






















