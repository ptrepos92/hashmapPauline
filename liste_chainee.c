

#include "liste_chainee.h"

// ___________________________________________________ INITIALISATION __________________________________________________



Node* NodeCreation(char* K, int V){
    Node* n = NULL;

/**
 * Alloue dynamiquement de la place pour un chainon
 */

    n = malloc(sizeof(Node));
    if (n == NULL){
        exit(1);
    }

    char* tmp;
    tmp = malloc(sizeof(strlen(K))+1);
    if (tmp == NULL){
       exit(1);
    }
    // copy key
    strcpy(tmp, K);

    n->key  = tmp;
    n->value = V;

    n->pNext = NULL;
    return n;
}



// ______________________________________________________ ADD __________________________________________________


Node* NodeInsert(Node*pliste,char* key, int value, int* verif){
    Node* n = NodeCreation(key,value);
    if(n==NULL){
        *verif = 0;
        return pliste;
    }

    Node* p = pliste;
    if(p==NULL){
        *verif = 0;
        return pliste;
    }
    while(p->pNext != NULL){
/**
 * on cherche si la clé existe deja avant de l'inserer dans la hashmap
 */
        if(strcmp(p->key,key) == 0){
            *verif = 0;
            return pliste;
        }
        else{
            p = p->pNext;
        }
    }
    p->pNext = n;
    *verif = 1;
    return pliste;

}

// ______________________________________________________ GET __________________________________________________


int* NodeGet(Node* pliste, char* a){
    Node *tmp=pliste;
    /* Tant que l'on n'est pas au bout de la liste */
    while(tmp != NULL)
    {
/**
 * Des que la cle entrée par l'utilisateur est similaire à une de la liste chainee alors ca renvoie un pointeur sur l'adresse de la valeur 
 */
        if (strcmp(tmp->key,a)== 0){
            /* Si l'élément a la valeur recherchée, on renvoie son adresse */
            return &(tmp->value);
        }
        tmp = tmp->pNext;
    }
    return NULL;
}


// _____________________________________________________ REMOVE __________________________________________________


Node* NodeRemoveFirst(Node *pliste, int* verif){
    Node* p = pliste;
    if(pliste == NULL){
        *verif = 0;
        return pliste;
    }
    pliste = pliste->pNext;
    free(p);
    *verif = 1;
    return pliste;
}


Node* NodeRemove(Node *pliste, char* a, int* verif){
    Node* p = pliste;
    Node* p2 = NULL;

    if(pliste == NULL){
        *verif = 0;
        return pliste;
    }
/**
 * si la clé a supprimer est la premiere de la liste chainée alors on deplace le pointeur de la liste au suivant (p->pNext) et on free la cle-valeur
 */
    if (strcmp(p->key,a) == 0){
        return NodeRemoveFirst(pliste, verif);
    }

    while(p->pNext != NULL ){
        
        if (strcmp(p->pNext->key,a)== 0){
            p2 = p->pNext;
            p->pNext = p2->pNext;
            free(p2);
            *verif = 1;
            return pliste;
        }
        p = p->pNext;
    }

    *verif = 0;
    return pliste;
}

// ______________________________________________________ UPDATE __________________________________________________

int NodeUpdate(Node* pliste,char*K,int V){
    Node *p= pliste;
    while(p != NULL){
        if (strcmp(p->key,K)== 0){
            p->value = V;
            return 1;
        }
        p = p->pNext;
    }
    printf("la cle nexiste pas");
    return 0;
}

// ______________________________________________________ FREE __________________________________________________

int NodeFree(Node* pliste) {
    if (pliste == NULL) {
        return 1;
    }
    if (pliste->pNext == NULL) {
        free(pliste);
        return 1;
    } else {
        NodeFree(pliste->pNext);
        free(pliste);
        return 1;
    }
}


