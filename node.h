#ifndef H_GL_NODE
#define H_GL_NODE
#include "data.h"
typedef struct Node_t {
    Data_segment * p_data;
	struct Node_t * p_next;
	
} Node_t;

Node_t* creatNode(void);
Node_t* creatNode2(Data_segment*);
void printNode(Node_t *);
void freeNode(Node_t *);

#endif



