/* Header .h file for CS 2050, 2020 SP, Wed labs. Should NOT be modified or submitted. -- Shizeng */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct studstruct{
    int age;
    struct studstruct *nextPtr;
}Student;

typedef struct linkedlist{
    Student *head, *tail;
}StudentList;

StudentList* initStack();
int pushStack(StudentList*,int);
Student* popStack(StudentList*);
StudentList* initQueue();
int enQueue(StudentList*,int);
Student* deQueue(StudentList*);
void printList(StudentList*);
void freeList(StudentList*);
