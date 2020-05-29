# include <stdio.h>
# include <stdlib.h>

//prototype
void countGrades(int arr[], int size, int BBoundary, int CBoundary, int* NoOfAs, int* NoOfBs, int* NoOfCs);

int main(void){

    int array[30] = {57,99,53,58,46,46,92,72,43,82,42,90,70,65,88,53,59,75,43,45,66,69,63,93,77,98,99,40,88,49};
    int size = sizeof(array)/sizeof(array[0]);
    int BBoundary = 80, CBoundary = 60;
	
	//these store the values for the amount of As, Bs, and Cs
	int As=0;
	int Bs=0; 
	int Cs=0;
	
	//these are pinters to the abover values so I can pass by reference in countGrades
	int* NoOfAs;
	int* NoOfBs;
	int* NoOfCs;

	//assigns the pointer to the counter integer
	NoOfAs = &As;
	NoOfBs = &Bs;
	NoOfCs = &Cs;
	
	//calls countgrades which will change the values of As, Bs, and Cs
	countGrades(array, size, BBoundary, CBoundary, NoOfAs, NoOfBs, NoOfCs);
	
	printf("%d students got A, %d students got B, and %d students got C.\n", *NoOfAs, *NoOfBs, *NoOfCs);
	
    return 0;
}


//inserts the amount of grades above the BBoundary to NoOfAs, above the CBoundary to NoOfBs, and below the CBoundary to NoOfCs
void countGrades(int arr[], int size, int BBoundary, int CBoundary, int* NoOfAs, int* NoOfBs, int* NoOfCs)
{
	for (int i=0; i<size; i++)
	{
		if (arr[i] >= BBoundary)
			*NoOfAs += 1;
		else if (arr[i] >= CBoundary)
			*NoOfBs += 1;
		else 
			*NoOfCs += 1;
	}
}