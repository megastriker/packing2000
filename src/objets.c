/****************************************/
/* FONCTIONS OPERATIONS OBJETS/LISTES	*/
/****************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../headers/objets.h"
#include"../headers/boite.h"

/*Initialisation de liste d'objets, renvoi pointeur nouvelle liste*/
Liste_objet initialiser_liste(){
	Liste_objet *ptr;
	ptr=malloc(sizeof(Liste));
	ptr->nb_objets=0;
	ptr->objets=NULL;
	return *ptr;
}

/*Receptions objets pour liste depuis generateur*/
void reception_objets(Liste_objet* a){
	int i=0;
	char tmp_char[50];
	scanf("%d",&a->nb_objets);
	a->objets=malloc(sizeof(objet)*a->nb_objets);
	while(scanf("%s",tmp_char) > 0){
		if(i>=a->nb_objets){printf("Trop d'objets\n"); break;}
		scanf("%d",&a->objets[i].largeur);
		scanf("%d",&a->objets[i].hauteur);
		strcpy(a->objets[i].nom,tmp_char);
		//a->objets[i].x=-1;
		//a->objets[i].y=-1;	
		i++;
	}
}

/*Ajout objet a liste, N°Liste/nom/largeur/hauteur/posX/posY*/
void ajouter_objet(Liste_objet* a, char *nom ,int l, int h, int x, int y){
	a->nb_objets++;
	a->objets=realloc(a->objets, sizeof(objet)*a->nb_objets);
	a->objets[a->nb_objets-1].largeur=l;
	a->objets[a->nb_objets-1].hauteur=h;
	strcpy(a->objets[a->nb_objets-1].nom,nom);
	//a->objets[a->nb_objets-1].x=x;
	//a->objets[a->nb_objets-1].y=y;
}

/*Ajout objet a liste, objet, N°Liste (Simplification de ajouter_objet)*/
void ajouter_objet_struct(Liste_objet* a, objet* obj){
	ajouter_objet(a, obj->nom, obj->largeur, obj->hauteur, 0,0);	
}

/*Supp objets*/
void supprimer_objet(Liste_objet* a, char *nom){
	int i;
	for(i=0;i<a->nb_objets;i++){
		if(strcmp(a->objets[i].nom,nom)){
			printf("TEST1\n");
			free(&a->objets[i]);
			printf("TEST2\n");
			a->objets[i]=a->objets[a->nb_objets-1];
			printf("TEST3\n");
			a->nb_objets--;
			printf("TEST4\n");
			a->objets=realloc(a->objets, sizeof(objet)*a->nb_objets);
		}
	}
}

/*Initiliser listeA */
Liste initialiser_listeA(int nb_objets){
	Liste tmp;
	tmp.nb_objets=0;
	tmp.surface=0;
	tmp.surface_perdue=9999999;
	tmp.objets=malloc(sizeof(int)*nb_objets);
	tmp.orientation=malloc(sizeof(int)*nb_objets);
	int i;
	for(i=0; i<nb_objets;i++){
		tmp.objets[i]=0;
		tmp.orientation[i]=0;
	}
	return tmp;
}

/*Copie listeA vers une nouvelle liste*/
Liste dupliquer_listeA(Liste* A, int nb_objets_total){
	Liste tmp;
	tmp.objets=malloc(sizeof(int)*nb_objets_total);
	tmp.orientation=malloc(sizeof(int)*nb_objets_total);
	tmp.nb_objets=A->nb_objets;
	tmp.surface=A->surface;
	tmp.surface_perdue=A->surface_perdue;
	int i;
	for(i=0;i<nb_objets_total;i++){
		tmp.objets[i]=A->objets[i];
		tmp.orientation[i]=A->orientation[i];
	}
	return tmp;
}

/*Supprimer listeA*/
void supprimer_listeA(Liste* A){
	free(A->objets);
	free(A->orientation);
	A->objets=NULL;
	A->orientation=NULL;
}

/*Retablit listeP*/
void retablir_liste(Liste *A, int nb_objets_total, int surface_init, int couche){
	int i, j=0;
	for(i=0; i <= nb_objets_total; i++){
		if(A->objets[i] == couche){
			A->objets[i]=0;
			j++;
		}
	}
	A->nb_objets-=j;
	A->surface = surface_init;
}
	
	
	
