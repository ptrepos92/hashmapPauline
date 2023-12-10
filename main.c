#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "hashmap.h"



// ________________________________________________ AFFICHAGE ________________________________________

void afficherListe(Node*pliste){

    while(pliste != NULL){
        printf(" %s -> %d,", pliste->key, pliste->value);
        pliste = pliste->pNext;
    }
}

void afficherInfixe(Tree* arb) {
  if (arb != NULL) {
    afficherInfixe(arb->pleft);
    printf("\n %d \n", arb->value);
    afficherListe(arb->cell);
    printf("\n");
    afficherInfixe(arb->pright);
  }
}

void display(HashMap* map){
/**
 * Va parcourir l'arbre contenu dans la hashmap en mode Infixe 
 */
    afficherInfixe(map->pRoot);
}

// _________________________________________________ SIZE ___________________________________________

int sizeHM( HashMap* map ){
    return map->size;
}

//__________________________________________________________________________________________________


int main(){
    HashMap* map = HMCreate();
    HMAdd(map,"sss",93810);
    HMAdd(map,"Langonnet",56110);
    HMAdd(map,"rueil",92500);
    display(map);
    printf("____________________________________________ \n");
    HMUpdate(map,"sss", 22222);
    HMUpdate(map,"rueil", 33333);
    HMUpdate(map,"Langonnet", 44444);
    display(map);
    printf("____________________________________________ \n");
    printf("\n%d\n", *HMGet(map,"sss"));
    printf("%d\n", *HMGet(map,"rueil"));
    printf("%d\n", *HMGet(map,"Langonnet"));
    printf("____________________________________________ \n");
    HMRemove(map,"sss");
    display(map);
    printf("____________________________________________ \n");
    printf("%d\n", *HMGet(map,"sss"));
    printf("%d\n", *HMGet(map,"rueil"));
    printf("%d\n", *HMGet(map,"Langonnet"));
    HMFree(map);
    return 0;
}

