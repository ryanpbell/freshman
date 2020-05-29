#include "lab12.h"

//custom prototype
StudentList* initList();


/*
This function initializes a StudentList with NULL head and tail pointers and 0 numOfItems
Input:
none
Output
returns a StudentList with NULL head and tail and numOfItems =0
*/
StudentList* initList()
{
	StudentList* list = malloc(sizeof(StudentList));
	if (list == NULL)
	{
		printf("failed to allocate memory.\n");
		return NULL;
	}
	else
	{
		list->head = list->tail = NULL;
		list->numOfItems = 0;
		
		return list;
	}
}

/*
This function initializes a PQueue with NULL head and tail pointers and 0 numOfItems
Input:
none
Output:
returns a PQueue with an empty StudentList 
*/
PQueue initPQueue()
{
	PQueue q;
	q.list = initList();
	return q;
}


/*
this function creates a node with given priority and age values and returns it
Input:
priority: the given priority value
age: the given age value
Output:
returns a Student node with given priority and age values with NULL next and previous pointers
*/
Student* createNode(float priority, int age)
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
		node->priority = priority;
		node->previousPtr = NULL;
		node->nextPtr = NULL;
		
		return node;
	}
}


/*
This fucntion creates a node with given priority and age values and inserts it into the
given PQueue in the correct place. the head of the PQueue has the highest priority and the
tail has the lowest priority
Input:
priority: the given priority of the new node
age: the given age of the new node
q: the current PQueue that the new node will be inserted into
Output:
returns 1 if the insertion succeeds and -1 if it fails
*/
int insertPQ(float priority, int age, PQueue q)
{
	Student* node = createNode(priority, age);
	if (node == NULL)
	{
		printf("failed to allocate memory.\n");
		return -1;
	}
	else
	{
		if (q.list->tail == NULL)
		{
			q.list->head = q.list->tail = node;
		}
		else
		{
			PQueue place = q;
			if (q.list->tail->priority > node->priority) //the node should be the new tail
			{
				node->previousPtr = q.list->tail;
				q.list->tail->nextPtr = node;
				q.list->tail = node;
				q.list->numOfItems++;
				return 1;
			}
			else if (q.list->head->priority < node->priority)
			{
				node->nextPtr = q.list->head;
				q.list->head->previousPtr = node;
				q.list->head = node;
				q.list->numOfItems++;
				return 1;
			}
			else
			{
				while (place.list->head->nextPtr->priority > node->priority)
				{
					place.list->head = place.list->head->nextPtr;
				}//place.list->head will be equal to the previous node in the Queue
			
				node->previousPtr = place.list->head;
				node->nextPtr = place.list->head->nextPtr;
				place.list->head->nextPtr->previousPtr = node;
				place.list->head->nextPtr = node;
				q.list->numOfItems++;
			}
		}
	}
	return 1;
}


/*
this function pulls out the lowest priority in the current PQueue and returns the pointer
to the removed node
Input:
q: the current PQueue of Student nodes
Output:
returns the pointer to the removed Student node
*/
Student* deleteMin(PQueue q)
{
	if (q.list->tail == NULL)
	{
		printf("the PQueue is empty, can not remove.\n");
		return NULL;
	}
	
	Student* temp = q.list->tail;
	Student* newTail = q.list->tail->previousPtr;
	newTail->nextPtr = NULL;
	q.list->tail = newTail;
	
	temp->previousPtr = NULL;
	
	q.list->numOfItems--;
	
	return temp;
}


/*
this function pulls out the highest priority in the current PQueue and returns the pointer
to the removed node
Input:
q: the current PQueue of Student nodes
Output:
returns the pointer to the removed Student node
*/
Student* deleteMax(PQueue q)
{
	if (q.list->tail == NULL)
	{
		printf("the PQueue is empty, can not remove.\n");
		return NULL;
	}
	
	Student* temp = q.list->head;
	Student* newHead = q.list->head->nextPtr;
	newHead->previousPtr = NULL;
	q.list->head = newHead;
	
	temp->nextPtr = NULL;
	
	q.list->numOfItems--;
	
	return temp;
}


/*
This function returns the pointer to the lowest priority Student node in the given PQueue
Input:
q: the current PQueue of Student nodes
Output:
returns the pointer to the lowest priority Student node
*/
Student* returnMin(PQueue q)
{
	return q.list->tail;
}

/*
This function returns the pointer to the highest priority Student node in the given PQueue
Input:
q: the current PQueue of Student nodes
Output:
returns the pointer to the highest priority Student node
*/
Student* returnMax(PQueue q)
{
	return q.list->head;
}

/*
This function prints the priority and age values of the Student nodes in the current PQueue
Input:
q: the current PQueue of Student nodes
Output:
prints the priority and age values of the Student nodes in the current PQueue
*/
void printPQueue(PQueue q)
{
	Student* temp = q.list->head;
	
	if (q.list->tail == NULL)
	{
		printf("tried to print an empty PQueue.\n");
		return;
	}
	while (temp != NULL)
	{
		printf("%f (%d)\n", temp->priority, temp->age);
		temp = temp->nextPtr;
	}
}


/*
This function frees all allocated memory in the given PQueue 
Input:
q: the current PQueue of Student nodes
Output:
frees all allocated memory in the given PQueue 
*/
void freePQueue(PQueue q)
{
	if (q.list == NULL)
	{
		return;
	}
	Student* tempFree = q.list->head;
	Student* tempHead = q.list->head;
	
	while (tempHead != NULL)
	{
		tempHead = tempHead->nextPtr;
		free(tempFree);
		tempFree = NULL;
		tempFree = tempHead;
	}
	
	free(q.list);
	q.list = NULL;
}







































