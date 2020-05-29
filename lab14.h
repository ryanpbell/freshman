#include <stdio.h>
#include <stdlib.h>

typedef struct studstruct{
    int age;
    int ID;
}Student;

typedef struct studdatabase{
    int sizeOfDB;
    Student** array;
}StudentDB;

Student** readRecord(FILE*);
StudentDB createDatabase(Student**,int);
Student* findStudentByID(StudentDB,int);
void freeDatabase(StudentDB);
