#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct studstruct{
    int age;
    float priority;
    struct studstruct *previousPtr, *nextPtr;
}Student;

typedef struct linkedlist{
    Student *head, *tail;
    int numOfItems;
}StudentList;

typedef struct queuelist{
    StudentList* list;
}PQueue;

PQueue initPQueue();
Student* createNode(float,int);
int insertPQ(float,int,PQueue);
Student* deleteMin(PQueue);
Student* deleteMax(PQueue);
Student* returnMin(PQueue); // returns but does not delete
Student* returnMax(PQueue); // returns but does not delete
void freePQueue(PQueue); // Free all malloced space
void printPQueue(PQueue);
