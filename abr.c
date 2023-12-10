
#include "liste_chainee.h"
#include "abr.h"

// __________________________________________________ INITIALISATION __________________________________________________

Tree* TreeCreation(char* key, int value, int res) {
    Tree* abr = NULL;

/**
 * Alloue dynamiquement de la place pour l'arbre de la hashmap
 */
    abr = malloc(sizeof(Tree));
    if (abr == NULL) {
      exit(1);
    }

/**
 * Initialisation des noeuds, de la valeur et des chainons contenus dans l'arbre
 */
    abr->value = res;
    abr->pleft = NULL;
    abr->pright = NULL;
    abr->cell = NodeCreation(key,value);
    //verif
    return abr;
}

// ______________________________________________________ ADD __________________________________________________

Tree* TreeAdd(Tree* abr,char * key, int value, int res, int* verif){

/**
 * Si l'arbre est nul alors on le crée
 */

    if(abr==NULL){
        *verif = 1;
        return TreeCreation(key,value,res);
    }
    else if(res > abr->value){
        abr->pright =TreeAdd(abr->pright,key,value,res, verif);
    }
    else if(res < abr->value){
        abr->pleft =TreeAdd(abr->pleft,key,value,res, verif);
    }
    else{
    	//verifier existence de la clé
    	if((abr->cell) == NULL){
    		*verif = 0;
        	return NULL;
		}
/**
 * la valeur de hachage existe deja alors on va ajouter la clé et sa valeur dans la liste chainée du noeud 
 */
		abr->cell= NodeInsert(abr->cell,key,value,verif);
    }
    *verif = 1;
    return abr;
}


// ______________________________________________________ GET __________________________________________________

int* TreeGet(Tree* abr,char * key, int res){

    if(abr==NULL){
        return NULL;
    }
    else if(res > abr->value){
        return TreeGet(abr->pright,key,res);
    }
    else if(res < abr->value){
        return TreeGet(abr->pleft,key,res);
    }
/**
 * On va cherche la clé dans la liste chainée du noeud 
 */
    else{
        return NodeGet(abr->cell,key);
    };
    return NULL;
}

// _____________________________________________________ REMOVE __________________________________________________

/**
 * On cherche le plus petit noeud du sous arbre droit du noeud pour pouvoir supprimer le noeud en question
 */

Tree* TreeGetMin(Tree* abr, int* verif) {
	Tree* curr = abr;

	if (abr == NULL){
		*verif = 0;
		return NULL;
	}
	while (curr && curr->pleft) {
		curr = curr->pleft;
	}
	return curr;
}


Tree* TreeRemoveNode(Tree* abr, int res, int* verif) {
    if (abr == NULL) {
    	*verif = 0;
        return NULL;
    }

    if (abr->pleft == NULL) {
      Tree* temp = abr->pright;
      free(abr);
      *verif = 1;
      return temp;
    } 

    else if (abr->pright == NULL) {
      Tree* temp = abr->pleft;
      free(abr);
      *verif = 1;
      return temp;
    }
/**
 * On va prendre le plus petit noeud du sous arbre droit pour remplacer les valeurs du noeud a supprimer par celles-ci -> TreeRemoveNode
 */
    Tree* temp = TreeGetMin(abr->pright, verif);
    abr->value = temp->value;
    abr->cell = temp->cell;
    abr->pright = TreeRemoveNode(abr->pright, temp->value, verif);
    *verif = 1;
    return abr;
  }


Tree* TreeRemove(Tree* abr,char * key, int res, int* verif){

    if(abr==NULL){
    	*verif = 0;
        return abr;
    }
    else if(res > abr->value){
        abr->pright = TreeRemove(abr->pright,key,res,verif);
    }
    else if(res < abr->value){
        abr->pleft = TreeRemove(abr->pleft,key,res, verif);
    }
    else{
    	if((abr->cell) == NULL){
    		*verif = 0;
        	return NULL;
		}
/**
 * s'il y a seulement une cle-valeur dans le noeud 
 */
        if(abr->cell->pNext == NULL){
            abr = TreeRemoveNode(abr,res,verif);
        }
/**
 * s'il y a plusieurs cle-valeur dans le noeud 
 */
        else{
            abr->cell = NodeRemove(abr->cell,key,verif);
        }
    }
    return abr;
}


// _____________________________________________________ UPDATE __________________________________________________

int TreeUpdate(Tree* abr,char* key, int value,int res){
    if(abr==NULL){
        return 0;
    }
    else if(res > abr->value){
        TreeUpdate(abr->pright,key,value,res);
    }
    else if(res < abr->value){
        TreeUpdate(abr->pleft,key,value,res);
    }
    else{
        if(NodeUpdate(abr->cell, key, value) == 0){
        	return 0;
        }
        else{
        	return 1;
        }
    }
    return 0;
}

// _____________________________________________________ FREE __________________________________________________

/**
 * Parcours suffixe pour supprimer tous les noeuds de l'arbre
 */

int TreeFree(Tree* abr) {
    if (abr == NULL) {
        return 1;
    }
    TreeFree(abr->pleft);
    TreeFree(abr->pright);
    NodeFree(abr->cell);
    free(abr);
    return 1;
}

