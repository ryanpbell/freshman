#include "lab10.h"

//added prototypes
Student* createNode(int);
Student* createNullNode();

/*
This function creates a Student node with a given age value and a NULL nextPtr value.
Input:
age: the given age of the new node
Output:
returns a student node with a NULL nextPtr and a given age.
*/
Student* createNode(int age)
{
	Student* node = malloc(sizeof(Student));
	if (node == NULL)
	{
		printf("failed to allocate memory.\n");
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
This function creates a Student node with a no age value and a NULL nextPtr value.
Input:
none
Output:
returns a student node with a NULL nextPtr and a no age.
*/
Student* createNullNode()
{
	Student* node = malloc(sizeof(Student));
	if (node == NULL)
	{
		printf("failed to allocate memory.\n");
		return NULL;
	}
	else
	{
		node->nextPtr = NULL;
		return node;
	}
}

/*
This function initializes a StudentList that will be a stacked list with a head and tail with no age values
Input:
none
Output:
returns a student list with a head and tail. the head->nextPtr is equal to the tail and the tail->nextPtr is equal to NULL
*/
StudentList* initStack()
{
	StudentList* list = malloc(sizeof(StudentList));
	if (list == NULL)
	{
		printf("failed to allocate memory.\n");
		return NULL;
	}
	else
	{
		Student* head = createNullNode();
		Student* tail = createNullNode();
		
		list->head = head;
		list->tail = tail;
		
		list->head->nextPtr = tail;
		list->tail->nextPtr = NULL;
		
		return list;
	}
}

/*
This function creates a Student node with a given age value and inserts the node at the head of the stack 
and pushes the other nodes. returns 1 if it succeeds and -1 if it doesnt succeed.
Input:
list: the current list of Student nodes
age: the given age of the new node
Output:
returns 1 for successful insertion and -1 for unsuccessful insertion.
*/
int pushStack(StudentList* list, int age)
{
	Student* node = createNode(age);
	if (node == NULL)
	{
		printf("failed to allocate memory.\n");
		return -1;
	}
	else
	{
		node->nextPtr = list->head->nextPtr;
		list->head->nextPtr = node;
		return 1;
	}
}

/*
This function pops out the most recent node in the linked list which is at the head and returns the pointer to 
that node or NULL if it cannot be removed
Input:
list: the current list of Student nodes
Output:
returns the address of the removed node or NULL if it cannot be removed
*/
Student* popStack(StudentList* list)
{
	if (list->head->nextPtr->nextPtr == NULL)
	{
		printf("the list is empty, can not popStack.\n");
		return NULL;
	}
	else
	{
		Student* place = list->head->nextPtr;
		list->head->nextPtr = place->nextPtr;
		place->nextPtr = NULL;
		return place;
	}
}

/*
This function initializes a StudentList that will be a Queue list with a head and tail with no age values
Input:
none
Output:
returns a student list with a head and tail. the head->nextPtr is equal to the tail and the tail->nextPtr is equal to NULL
*/
StudentList* initQueue()
{
	StudentList* list = malloc(sizeof(StudentList));
	if (list == NULL)
	{
		printf("failed to allocate memory.\n");
		return NULL;
	}
	else
	{
		Student* head = createNullNode();
		Student* tail = createNullNode();
		
		list->head = head;
		list->tail = tail;
		
		list->head->nextPtr = tail;
		list->tail->nextPtr = NULL;
		
		return list;
	}
}

/*
This function creates a Student node with a given age value and inserts the node at the head of the stack 
and pushes the other nodes. returns 1 if it succeeds and -1 if it doesnt succeed.
Input:
list: the current list of student nodes
age: the given age of the new node
Output:
returns 1 for successful insertion and -1 for unsuccessful insertion.
*/
int enQueue(StudentList* list, int age)
{
	Student* node = createNode(age);
	if (node == NULL)
	{
		printf("failed to allocate memory.\n");
		return -1;
	}
	else
	{
		node->nextPtr = list->head->nextPtr;
		list->head->nextPtr = node;
		return 1;
	}
}

/*
This function dequeues the earliest Student node out of the list. This node is found at the tail of the list.
This function returns the pointer to the removed node or NULL if it cannot be removed.
Input:
list: the current list of Student nodes
Output:
returns the address to the student node that was removed or NULL if it cannot be removed
*/
Student* deQueue(StudentList* list)
{
	Student* remove = list->head;
	
	while (remove->nextPtr->nextPtr != NULL)
	{
		remove = remove->nextPtr
	} //after the loop, remove is the node that needs to be removed.
	
	if (remove == list->head) //if the list is empty
	{
		printf("The list is empty.\n");
		return NULL;
	}
	else
	{
		Student* before = list->head;
		while (before->nextPtr->nextPtr->nextPtr != NULL)
		{
			before = before->nextPtr;
		} //after the loop, before is the node that is before the node being removed.
		
		Student* place = remove;
		before->nextPtr = place->nextPtr;
		place->nextPtr = NULL;
		return place;
	}
}

/*
this function prints the age values of the given list of Students. It does not print the 
dummy nodes.
Input:
list: the current list of Student nodes 
Output:
prints the age values of the list of Students
*/
void printList(StudentList* list)
{
	Student* temp = list->head;
	
	while(temp->nextPtr->nextPtr != NULL)
	{
		temp = temp->nextPtr;
		printf("%d\n", temp->age);Student
	}
}

/*
this function frees all of the nodes in the given list.
Input:
list: the current list of Student nodes 
Output:
frees all of the allocated memory in the list
*/
void freeList(StudentList* list)
{
	Student* temp = list->head;
	while (temp != NULL)
	{
		list->head = list->head->nextPtr;
		free(temp);
		temp = list->head;
	}
}



















