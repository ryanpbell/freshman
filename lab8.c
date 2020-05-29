#include "lab8.h"


/*
This function creates a Student Node with a passed in integer a which will be the age of the 
Student. The pointer to this node gets returned to the calling function.
Input:
a: the integer that will be the age of the created Student 
Output:
return the pointer to the node created
*/
Student* createNode(int a)
{
	Student * new = malloc(sizeof(Student));
	
	if (new == NULL)
	{
		printf("error. failed to allocate memory\n");
		return NULL;
	}
	else
	{
		new->age = a; //sets the age of the Student new to a
	}
	
	return new;
}

/*
This function returns an empty (NULL) list of Students.
Input:
none.
Output:
returns NULL
*/
Student* initList()
{
	return NULL;
}

/*
This function adds a new Node to the head of the list with the given age value a.
it moves any of the current nodes in the list down one and sets the new Nodes nextPtr value
equal to the old first Node in the list.
Input:
list: the current list of Student Nodes where the added Node will go
a: the age value that is assigned to the added Node
Output:
The student list after the new Node has been added
*/
Student* addToHead(Student* list, int a)
{
	Student * newHead = createNode(a);
	
	if (newHead == NULL)
	{
		printf("error. failed to allocate memory\n");
		return NULL;
	}
	else
	{
		newHead->age = a;
		newHead->nextPtr = list;
		return newHead;
	}
}

/*
This function adds a new Node to the tai of the list with the given ages value a.
the Node will be placed at the end of the list.
Input:
list: the current list of Student Nodes where the added Node will go
a: the age value that is assigned to the added Node
Output:
The student list after the new Node has been added
*/
Student* addToTail(Student* list,int a)
{
	Student * newTail = malloc(sizeof(Student));
	
	if (newTail == NULL)
	{
		printf("error. failed to allocate memory\n");
		return NULL;
	}
	else
	{
		newTail->age = a;
		
		Student* place = list;
		
		while(place->nextPtr != NULL)
		{
			place = place->nextPtr;
		}
		
		place->nextPtr = newTail;
	}
	
	return list; //returns the pointer to start the list
}

/*
This function prints the age values of all of the Nodes in the given list from head to 
tail.
Input:
list: The current list of Student Nodes that will have their age printed
Output:
print a comma separated list of all of the Student ages in the list
*/
void printList(Student* list)
{
	if (list == NULL)
		printf("the list is empty\n");
	else
	{
		printf("List values:\n");
		
		while(list->nextPtr != NULL)
		{
			printf("%d, ", list->age);
			list = list->nextPtr;
		}
		printf("%d\n", list->age); //prints the last value for the comma separated list 
	}
	
	return;
}

/*
This function returns the place where the first occurance of the int target is the age
of a student in the list. The place will be 0-based.
Input:
list: the current list of Student Nodes that will be searched for the target age
target: The age that is being searche for in the list
Output:
returns the place of the first occurance of the target age in the list in 0-based form
*/
int searchAge(Student* list, int target)
{
	if (list == NULL)
	{
		printf("the list is empty\n");
		return -1;
	}
	else
	{
		int ans=0;
		
		while(list != NULL)
		{
			if (list->age == target)
			{
				return ans;
			}
			ans++;
			list = list->nextPtr;
		}
	}
	
	return -1;
}

/*
This function frees the allocated memories in the Student Nodes in the list and sets the list 
to NULL and returns it to the calling function
Input:
list: the current list of Student Nodes
Output:
frees all allocated memory, returns the NULL list
*/
Student* freeList(Student* list)
{
	Student * place = list;
	
	while(list != NULL)
	{
		place = list;
		list = list->nextPtr;
		free(place);
	}
	
	list = NULL;
	return list;
}












































