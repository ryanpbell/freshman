#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct studstruct{
    int age;
    struct studstruct *nextPtr;
}Student;

typedef struct linkedlist{
    Student *head, *tail;
    int numOfItems;
    int numOfOdd;
    int numOfEven;
}StudentList;

typedef struct queuelist{
    StudentList* list;
}Queue;


Queue initQueue();
int enQueue(int, Queue);
Student* deQueue(Queue);
int getQsize(Queue);
int getNumOfEven(Queue);
void printQueue(Queue);
void emptyQueue(Queue);
