#include "lab15.h"

// added prototype
Node* createNode(Employee*);


/*
This function creates a node with a given employee pointer as data and NULL left and right
pointers and returns teh created Node.
*/
Node* createNode(Employee* data)
{
	Node* node = malloc(sizeof(Node));
	
	if (node == NULL)
	{
		printf("failed to allocate memory.\n");
		return NULL;
	}
	else
	{
		node->data = data;
		node->right = NULL;
		node->left = NULL;
	}
	
	return node;
}

/*
This function reads the given file and create an array of employee arrays with the data and
returns the array
*/
Employee** readRecord(FILE* fp)
{
	if (fp == NULL)
	{
		printf("failed to allocate memory.\n");
		return NULL;
	}
	else
	{
		int size;
		fscanf(fp, "%d\n", &size);
		
		Employee** arr = malloc(sizeof(Employee*)*size);
		
		if (arr == NULL)
		{
			printf("failed to allocate memory.\n");
			return NULL;
		}
		
		int i=0;
		while (!feof(fp) && i<size)
		{
			*(arr+i) = (Employee *)malloc(sizeof(Employee));
			fscanf(fp, "%d,%f,%d\n", &(arr[i]->ID), &(arr[i]->salary); &(arr[i]->ssn));
			i++;
		}
		
		return (Employee**)arr;
	}
}


/*
This function compares two passed in ssn values. 1 if the first is greater, -1 if the
second is greater and 0 if they are the same
*/
int comparison(void* a, void* b)
{
	int comp = ((Employee*)a)->ssn - ((Employee*)b)->ssn;
	
	if (comp > 0)
		return 1;
	else if (comp < 0)
		return -1;
	else
		return 0;
}


/*
this finction creates a new emplyee object to get stopred in the current Tree at the 
correct spot and returns the changed Node
*/
Node* insertBST(Node* arr, Employee* data)
{
	if (arr)
	{
		int comp = comparison(arr->data, data);
		
		if (comp == -1)
			arr->left = insertBST(arr->left, data);
		else if (comp == 1)
			arr->right = insertBST(arr->right, data);
			
		return arr;
	}
	else
	{
		return createNode(data);
	}
}


/*
This fucntion finds the Employee with the given target as an ssn value and returns the 
Employee
*/
Employee* searchBST(Node* arr, int target)
{
	if (arr == NULL)
	{
		return NULL;
	}
	
	if (arr->data->ssn < target)
		return searchBST(arr->left, target);
	else if (arr->data->ssn > target)
		return searchBST(arr->right, target);
	else
		return arr->data;
}

/*
This function frees all allocated memory in the given tree.
*/
void deleteTree(Node* arr)
{
	if (arr == NULL)
		return;
	else
	{
		deleteTree(arr->left);
		deleteTree(arr->right);
		free(arr);
	}
}































