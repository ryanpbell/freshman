#include "lab11.h"

//custom prototypes
StudentList* initList();
Student* createNode(int);


/*
This function create a Student node with a given age value.
Input:
age: the given age value for the node
Output:
returns a Student node pointer to a node with age value of age and NULL nextPtr
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
This function initializes a StudentList with NULL head and tail values and
0 numOfItems, numOfEven and numOfOdd
Input:
none
Output:
returns a StudentList with no nodes and all values set to 0
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
		list->numOfEven = 0;
		list->numOfOdd = 0;
		
		return list;
	}
}

/*
This function initializes a Queue with NULL head and tail values and
0 numOfItems, numOfEven and numOfOdd
Input:
none
Output:
returns a Queue with no nodes and all values set to 0
*/
Queue initQueue()
{
	Queue q;
	q.list = initList();
	return q;
}


/*
This function creates a Student node with a given age value that 
is inserted at the tail of the given Queue.
Input:
age: the given age value fo the student node
q: the current Queue
Output:
returns 1 if it succeeds and -1 if it fails
*/
int enQueue(int age, Queue q)
{
	Student* node = createNode(age);
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
			q.list->tail->nextPtr = node;
			q.list->tail = node;
		}
	
		q.list->numOfItems++;
	
		if (age % 2 == 0)
		{
			q.list->numOfEven++;
		}
		else
		{
			q.list->numOfOdd++;
		}
	}
	return 1;
}

/*
This function removed the most recent Student node in the given Queue
which is found at the head of the Queue.
Input:
q: the curret Queue
Output
returns the pointer to the removed Student node
*/
Student* deQueue(Queue q)
{
	Student* place = q.list->head;
	q.list->head = place->nextPtr;

	q.list->numOfItems--;
	
	if (place->age % 2 == 0)
	{
		q.list->numOfEven--;
	}
	else
	{
		q.list->numOfOdd--;
	}
	
	return place;
}


/*
This function returns the number of student nodes in the given Queue
Input:
q: the current Queue
Output:
returns the number of Student nodes in the Queue
*/
int getQsize(Queue q)
{
	int size = q.list->numOfItems;
	return size;
}

/*
This function returns the number of even ages of Students in the given Queue
Input:
q: the current Queue
Output:
returns the number of even ages of Students in the Queue
*/
int getNumOfEven(Queue q)
{
	int num = q.list->numOfEven;
	return num;
}

/*
This function prints the age values of the given Queue
Input:
q: the current Queue
Output:
prints the age values of the Students in the given Queue
*/
void printQueue(Queue q)
{
	Student* temp = q.list->head;
	
	while (temp != NULL)
	{
		printf("%d\n", temp->age);
		temp = temp->nextPtr;
	}
}

/*
This function frees all allocated memory in the given Queue
Input:
q: the current Queue
Output:
frees all allocated memory in the Queue
*/
void emptyQueue(Queue q)
{
	Student* temp = q.list->head;
	while (temp != NULL)
	{
		q.list->head = q.list->head->nextPtr;
		free(temp);
		temp = q.list->head;
	}
}



















