#ifndef H_GL_LIST
#define H_GL_LIST
#include "data.h"
#include "node.h"

typedef struct List_t {
	Node_t * p_first;
	Node_t * p_last;
} List_t;


List_t* list_create( void ); //Cree une liste vide

int list_insert_item(List_t* , Data_segment*); // insert un data segment à l'entete

int list_insert_node(List_t* , Node_t *);// insert un noeud à l'entete

void printList(List_t* L); // affiche les éléments de la liste

int list_delete_node(List_t* L, Node_t * _nd); // détruit un noeud de la liste

int list_insert_before(List_t* list, Data_segment* seg_to_insert, Node_t * _nd);
// insert avant le noeud _nd un nouveau noeud dont les données sont seg_to_insert

//int list_remove_item( List_t* list,	Data_segment* item);
// supprime le noeud dont les données sont item

int sizeList( List_t* );
// retourn la taille de la liste.


#endif
