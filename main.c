#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "list.h"
#include "algorithms.h"


int alea(int n, int m){
	return (int)(n + (m-n)*((float)(rand()) / (float)(RAND_MAX)));
	//produit des nombres aléatoires entre n et m.
	//RAND_MAX = 16 * ((2^31) - 1)=34 359 738 352   
}

char menu(){
	char c;
	printf ("\n ******************************************\n");
	printf ("\n ******** Algorithmes de placement ********");
	printf ("\n ******************************************");
	printf ("\n selectionner l'agorithme de placement que vous voulez simuler :");
	printf ("\n 1 : pour le First Fit ");
	printf ("\n 2 : pour le Best Fit ");
	printf ("\n 3 : pour le Worst Fit ");
	printf ("\n Votre choix :  ");	
	return getchar();
	
}


void simule_algos(char c, int a, int b, List_t * MyList){
	int i, MaxEvents;
	MaxEvents=10;	// nombre d'événements qui se produisent (Arrivée ou départ) 
	for(i=0; i<MaxEvents; i++) 
	{
		if (alea(0,2)!=1){ // arrivée d'un processus (2 fois plus que le départ)
			printf("\n ===> Arrivée processus");
				Data_segment * D=creatData('P',i,-1,alea(a,b));
				 printData(D);
		switch  (c){ 
			case '1' : first_fit(MyList,D);
					break;
			case '2' : best_fit(MyList,D);
					break;
			case '3' :	worst_fit(MyList,D);
					break;
			default  : printf("Le numéro %c ne correspond à aucun algorithme\n",c);
						exit(-1);
		}

	printList(MyList);
		} 
		else{// depart d'un processus
		printf("\n <=== depart processus");
	
		//list_delete_node(MyList,getNode(MyList,alea(1,conterProcess(MyList))));
		// Ceci est équivant à écrire
			int nbrprocess=conterProcess(MyList);
printf("\n nbrprocess=%d", nbrprocess);
		int num_p= alea(1, nbrprocess);
printf("\n num_p=%d", num_p);
		Node_t* N=getNode(MyList, num_p);
printNode(N);
		delete_process(MyList,N);	
		mergeHoles(MyList); // suppression des trous qui se suivent.
		printList(MyList);
		}
	}
}

int main (){
	
	int a=5, b=40;
	/*********** Initialisation du seed ******/	
	//srand( time(NULL)); // On initialise le seed par le temps si 
	//on veut à chaque fois une séquence des nombres aléatoires  
	//différente à chaque exécution.

	srand(123232342); //utiliser le même seed pour engendrer 
					//la meme séquence de nombres  aléatoires

	List_t* Memoire= list_create();
	
	list_insert_node(Memoire,creatNode2(creatData('T',-1,0,100)) );
		// La mémoire est vide. Elle est représentée par un trou de taille 100.
	char c=menu();	
 	simule_algos(c,a,b,Memoire);
	return 0;
}
