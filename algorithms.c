#include<stdio.h>
#include<stdlib.h>
#include "algorithms.h"


int first_fit(List_t *L, Node_t* DS) {

	Node_t* pt;
	pt = L->p_first;
 	 while (pt != NULL && (pt->p_data->Type=='P' || (pt->p_data->Deplacement < DS->p_data->Deplacement))){
	
	pt = pt->p_next;
	}
	if (pt != NULL)
	{
		DS->p_data->Debut=pt->p_data->Debut;
		pt->p_data->Debut=DS->p_data->Debut;
		pt->p_data->Type=DS->p_data->Type;
		pt->p_data->PID=DS->p_data->PID;
            if(( pt->p_data->Deplacement - DS->p_data->Deplacement) > 0)
                {
			Node_t* Trou =creatNode2(creatData('T',-1,pt->p_data->Debut+ DS->p_data->Deplacement, pt->p_data->Deplacement - DS->p_data->Deplacement));
                Trou->p_next = pt->p_next;
                pt->p_next =Trou;
                pt->p_data->Deplacement=DS->p_data->Deplacement;
                }
            else
                { // ( pt->p_data->Deplacement = DS->p_data->Deplacement)  
                pt->p_data->Debut=DS->p_data->Debut;
                pt->p_data->Type=DS->p_data->Type;
                pt->p_data->PID=DS->p_data->PID;

			}
	
		return 1;
	}

	return 0;

}

int best_fit(List_t *L, Node_t * DS){

	Node_t* pt;
	Node_t *min;
	pt = L->p_first;
  	while (pt != NULL && (pt->p_data->Type=='P' || (pt->p_data->Deplacement < DS->p_data->Deplacement)))
    {
	pt = pt->p_next;
	}
	min=pt;
 while(pt!=NULL)
    {
        if(pt->p_data->Type=='T' && (min->p_data->Deplacement > pt->p_data->Deplacement) &&  (min->p_data->Deplacement >= DS->p_data->Deplacement))
        min=pt;
        pt=pt->p_next;
	}
        if (min != NULL)
            {
              DS->p_data->Debut=min->p_data->Debut;
                min->p_data->Debut=DS->p_data->Debut;
                min->p_data->Type=DS->p_data->Type;
                min->p_data->PID=DS->p_data->PID;
            if(( min->p_data->Deplacement - DS->p_data->Deplacement) > 0)
                {
	Node_t* Trou =creatNode2(creatData('T',-1,min->p_data->Debut+ DS->p_data->Deplacement, min->p_data->Deplacement - DS->p_data->Deplacement));
                    Trou->p_next = min->p_next;
                    min->p_next =Trou;
                    min->p_data->Deplacement=DS->p_data->Deplacement;
                }
            else
            { //  ( pt->p_data->Deplacement = DS->p_data->Deplacement)
                min->p_data->Debut=DS->p_data->Debut;
                min->p_data->Type=DS->p_data->Type;
                min->p_data->PID=DS->p_data->PID;

			}
			return 1;
	}
	return 0;

}

int worst_fit(List_t *L, Node_t * DS){

	Node_t* pt;
	Node_t *max;
	pt = L->p_first;
    	while (pt != NULL && (pt->p_data->Type=='P' || (pt->p_data->Deplacement < DS->p_data->Deplacement)))
	{
	pt = pt->p_next;
	}
	max=pt;
    while(pt!=NULL)
        {
        if(pt->p_data->Type=='T' && (max->p_data->Deplacement <= pt->p_data->Deplacement) &&   (max->p_data->Deplacement >= DS->p_data->Deplacement))
        max=pt;
        pt=pt->p_next;
        }
	if (max != NULL)
	{
       DS->p_data->Debut=max->p_data->Debut;
		max->p_data->Debut=DS->p_data->Debut;
		max->p_data->Type=DS->p_data->Type;
		max->p_data->PID=DS->p_data->PID;
		if(( max->p_data->Deplacement - DS->p_data->Deplacement) > 0)
		{
			Node_t* Trou =creatNode2(creatData('T',-1,max->p_data->Debut+ DS->p_data->Deplacement, max->p_data->Deplacement - DS->p_data->Deplacement));
			Trou->p_next = max->p_next;
			max->p_next =Trou;
			max->p_data->Deplacement=DS->p_data->Deplacement;
		}
		else
		{ 
			max->p_data->Debut=DS->p_data->Debut;
			max->p_data->Type=DS->p_data->Type;
			max->p_data->PID=DS->p_data->PID;

			}
			return 1;
	}
	return 0;

}


