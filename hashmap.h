#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef HASHMAP_H
#define HASHMAP_H

#include "hashmap.h"
#include "abr.h"

typedef struct HashMap
{
    int size;
    Tree* pRoot;
} HashMap;

int hash(char *list);

HashMap* HMCreate();

int* HMGet(HashMap* map, char* K );

int HMAdd(HashMap* map, char* K, int value);

int HMRemove(HashMap* map, char* K);

int HMUpdate(HashMap* map, char* key, int value);

int HMFree(HashMap* map);

#endif