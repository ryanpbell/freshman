#include <stdio.h>
#include <stdlib.h>

typedef struct studstruct{
    int age;
    int ID;
}Student;

Student** readRecord(FILE*);
int comparison(void*,void*);
int binarySearch(void**,int,int,void*);
void freeArr(Student**,int);
