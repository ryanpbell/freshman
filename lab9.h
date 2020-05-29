/* Header .h file for CS 2050, 2020 SP, Wed labs. Should NOT be modified or submitted. -- Shizeng */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct studstruct{
    int age;
    struct studstruct *nextPtr;
}Student;

Student* initListWithDummyNode();
int insertToHead(Student*,int);
int insertToTail(Student*,int);
void printList(Student*);
void emptyList(Student*);
void freeList(Student*);
