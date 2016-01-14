
#ifndef H_GL_DATA
#define H_GL_DATA

typedef struct Data_segment {
    
	char Type;
	int PID;
	int Debut;
	int Deplacement;
	// Autres informations 
	// ...
} Data_segment;

Data_segment *  creatData(char _type, int _pid,int _debut, int _deplacement);
void printData(Data_segment*);
void freeData(Data_segment *);
#endif 
