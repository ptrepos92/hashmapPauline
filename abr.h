#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#ifndef ABR_H
#define ABR_H

#include "abr.h"
#include "liste_chainee.h"


typedef struct Tree
{
    int value;
    struct Tree* pleft;
    struct Tree* pright;
    struct Node* cell;
} Tree;


Tree* TreeCreation(char* key, int value, int res);

Tree* TreeAdd(Tree* abr,char * key, int value, int res, int* verif);

int* TreeGet(Tree* abr,char * key, int res);

Tree* TreeGetMin(Tree* abr,int* verif);

Tree* TreeRemoveNode(Tree* abr, int res,int* verif) ;

Tree* TreeRemove(Tree* abr,char * key, int res,int* verif);

Tree* TreeAdd(Tree* abr,char * key, int value, int res, int* verif);

int TreeUpdate(Tree* abr,char* key, int value,int res);

int TreeFree(Tree* abr);

#endif
