#ifndef H_GL_ANNEXE
#define H_GL_ANNEXE
#include<stdio.h>
#include<stdlib.h>
#include "list.h"

int mergeHoles(List_t * L); //Fusionne deux trous successives.

int conterProcess(List_t *);
// compte le nombre de processus dans la liste.

Node_t* getNode(List_t* L, int p);
 //return le processus indice p se trouvant dans la liste

Node_t * getAdrNode(List_t*L, char tp, int dep); // retourne le noeud qui correspond aux critères. Son type==tp et son déplacement>=dep;

int delete_process(List_t* L, Node_t *nd);
// simule le départ d'un process on remplacement le process par un trou
#endif
