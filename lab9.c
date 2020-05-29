#include "lab9.h"

//added prototypes
Student* createNode(int age);
Student* createDummy();

/*
this function creates a node with an age value that is given and returns it.
Input:
age: integer value for the age of the Student node
Output:
returns the created node with an age value of the given age and a nextPtr as NULL
*/
Student* createNode(int age)
{
	Student* node = malloc(sizeof(Student));
	if (node == NULL)
	{
		printf("failed to allocate memory\n");
		return NULL;
	}
	else
	{
		node->age = age;
		node->nextPtr = NULL;
		return node;
	}
}

/*
this function creates a dummy node with no age value.
Input:
none
Output:
returns the created dummy node with no age value and a nextPtr as NULL
*/
Student* createDummy()
{
	Student* node = malloc(sizeof(Student));
	if (node == NULL)
	{
		printf("failed to allocate memory\n");
		return NULL;
	}
	else
	{
		node->nextPtr = NULL;
		return node;
	}
}

/*
this function creates an empty list with only a dummy head and a dummy tail.
Input:
none
Output:
returns a Student list with only a dummy head and a dummy tail.
*/
Student* initListWithDummyNode()
{
	Student* head = createDummy();
	Student* tail = createDummy();
	
	head->nextPtr = tail;
	tail->nextPtr = NULL;
	
	return head;
}

/*
this function creates a new node with a given age value and inserts it in the first position
of the list (after the dummy head). returns 1 if it succeeded and 0 if it failed
Input:
list: the current list of Students which the new node will be inserted into
age: the given age value of the new node
Output:
returns 0 if the insertion failed and returns 1 if the insertion succeeded
*/
int insertToHead(Student* list, int age)
{
	Student* newHead = createNode(age);
	if (newHead == NULL)
	{
		printf("failed to allocate memory\n");
		return 0;
	}
	else
	{	
		newHead->nextPtr = list->nextPtr; 
		list->nextPtr = newHead;
		return 1;
	}
}

/*
this function creates a new node with a given age value and inserts it in the last position in 
the list (before the dummy tail). returns 1 if it succeeded and 0 if it failed.
Input:
list: the current list of Students which the new node will be inserted into
age: the given age value of the new node
Output:
returns 0 if the insertion failed and returns 1 if the insertion succeeded
*/
int insertToTail(Student* list, int age)
{
	Student* newTail = createNode(age);
	if (newTail == NULL)
	{
		printf("failed to allocate memory\n");
		return 0;
	}
	
	Student* temp = list;
	while (temp->nextPtr->nextPtr != NULL)
	{
		temp = temp->nextPtr;
	}
	
	newTail->nextPtr = temp->nextPtr;
	temp->nextPtr = newTail;
	
	return 1;
}

/*
this function prints the age values of the given list of Students. It does not print the 
dummy nodes.
Input:
list: the current list of Student nodes with a dummy head and a dummy tail
Output:
prints the age values of the list of Students
*/
void printList(Student* list)
{
	Student* temp = list;
	
	while(temp->nextPtr->nextPtr != NULL)
	{
		temp = temp->nextPtr;
		printf("%d\n", temp->age);
	}
}

/*
this function frees all memory of the real nodes in the given list.
Input: 
list: the current list of Student nodes with a dummy head and a dummy tail
Output:
after freeing the real nodes the list will only contain dummy head and dummy tail nodes
*/
void emptyList(Student* list)
{
	Student* temp = list;
	Student* temp2 = list;
	
	temp = temp->nextPtr; //skip the dummy head
	temp2 = temp2->nextPtr; //skip the dummy head
	
	while (temp->nextPtr != NULL)
	{
		temp2 = temp2->nextPtr;
		free(temp);
		temp = temp2;
	} //temp and temp2 are pointing to the dummy tail after the while
	
	list->nextPtr = temp; //dummy head's nextPtr equal to the dummy tail
}

/*
this function frees all of the nodes in the given list.
Input:
list: the current list of Student nodes with a dummy head and a dummy tail
Output:
frees all of the allocated memory in the list
*/
void freeList(Student* list)
{
	Student* temp = list;
	while (temp != NULL)
	{
		list = list->nextPtr;
		free(temp);
		temp = list;
	}
}



































