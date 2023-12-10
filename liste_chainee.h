#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef LISTE_CHAINEE_H
#define LISTE_CHAINEE_H

#include "liste_chainee.h"

typedef struct Node
{
    char* key;
    int value ;
    struct Node* pNext; 
} Node;



Node* NodeCreation(char* K, int V);

Node* NodeInsert(Node*pliste,char* key, int value, int* verif);

int* NodeGet(Node* pliste, char* a);

Node* NodeRemoveFirst(Node *pliste, int* verif);

Node* NodeRemove(Node *pliste, char* a, int* verif);

int NodeUpdate(Node* pliste,char*K,int V);

int NodeFree(Node* pliste);

#endif

