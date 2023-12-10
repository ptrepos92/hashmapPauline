

#include "abr.h"
#include "hashmap.h"

int hash(char *list){
/**
 * Fonction de hachage qui va faire le modulo de la somme des codes ASCII de la chaine de caractères list 
 */
    int i = 0, hash = 0;
    for (i = 0 ; list[i] != '\0' ; i++){
        hash += list[i];
    }
    hash %= 100;
    return hash;
}

// _________________________________________________ INITIALISATION ___________________________________________

HashMap* HMCreate(){
    HashMap* n = NULL;

/**
 * Alloue dynamiquement de la place pour la hashmap
 */

    n = malloc(sizeof(HashMap));
    if (n == NULL) {
        exit(1);
    }

/**
 * Initialisation de la taille de la hashmap et de son arbre 
 */
    n->size = 0;
    n->pRoot = NULL;
    return n;
}

// ______________________________________________________ GET __________________________________________________

int* HMGet(HashMap* map, char* K ){
    int res = hash(K);
    if(TreeGet(map->pRoot,K,res) == NULL){
        printf("key not found");
        return NULL;
    }
    else{
        printf("key found, value : ");
        return TreeGet(map->pRoot,K,res);
    }
    }

// ______________________________________________________ ADD __________________________________________________


int HMAdd(HashMap* map, char* K, int value){
/**
 * verif est un pointeur sur un entier qui va me permet de savoir si la fonction ajouter s'est bien passée (1) ou non (0)
 */
	int v;
    int* verif = &v;
    int res = hash(K);
    map->pRoot = TreeAdd(map->pRoot,K,value,res,verif);
    if(verif  == 0){
    	return 0;
    }
    else{
        map->size +=1;
    	return 1;
    }
    return 0;
}

// _____________________________________________________ REMOVE __________________________________________________



int HMRemove(HashMap* map, char* K){
    int v;
	int* verif = &v;
    int res = hash(K);
    map->pRoot = TreeRemove(map->pRoot,K,res, verif);
    if(*verif  == 0){
    	return 0;
    }
    else{
        map->size -=1;
    	return 1;
    }
    return 0;
}

// _____________________________________________________ UPDATE __________________________________________________

int HMUpdate(HashMap* map, char* key, int value){
    int res = hash(key);
    if(TreeUpdate(map->pRoot,key,value,res) == 0){
    	return 0;
    }
    else{
    	return 1;
    }
}

// ______________________________________________________ FREE __________________________________________________

int HMFree(HashMap* map) {
    if (map == NULL) {
        return 1;
    }
    TreeFree(map->pRoot);
    free(map);
    return 1;
}
