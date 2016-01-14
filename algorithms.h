#ifndef H_GL_ALGORITHMS
#define H_GL_ALGORITHMS
#include<stdio.h>
#include<stdlib.h>
#include "list.h"
#include "annexe.h"

int mergeHoles(List_t * L); //Fusionne deux trous successives.

int conterProcess(List_t *);
// compte le nombre de processus dans la liste.

Node_t* getNode(List_t* L, int p);
 //return le processus indice p se trouvant dans la liste

int first_fit(List_t *L, Node_t * DS); 
int best_fit(List_t *L, Node_t * DS);
int worst_fit(List_t *L, Node_t * DS);

#endif

