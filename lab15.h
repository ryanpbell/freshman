#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int ID;
    float salary;
    int ssn;
}Employee;

typedef struct node{
 		Employee* data;
 		struct node *left, *right;
}Node;

Employee** readRecord(FILE*);
int comparison(void*,void*);
Node* insertBST(Node*, Employee*);
Employee* searchBST(Node*,int);
void deleteTree(Node*);
