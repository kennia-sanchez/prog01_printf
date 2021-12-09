#include <stdio.h>
#include <conio.h>
#include <String.h>

struct Nodo{
	char mat[10];
	char nom[21];
	int calif;
	Nodo *next;
};

Nodo *primero, *ultimo, *actual, *nuevo;

// Esta función inserta al final de la lista enlazada
void inserta_final(char pmat[10], char pnom[21],int pcalif){
	nuevo=new Nodo;
	strcpy(nuevo->mat,pmat);
	strcpy(nuevo->nom,pnom);
	nuevo->calif=pcalif;
	nuevo->next=NULL;
	
	if (primero==NULL){
		primero=nuevo;
		ultimo=nuevo;
		actual=ultimo;
	}
	else{
		ultimo->next=nuevo;
		ultimo=nuevo;
	}
}

void muestra(){
	actual=primero;
	while (actual!=NULL){
		printf("Matricula : %s\n",actual->mat);
		printf("Nombre    : %s\n",actual->nom);
		printf("Califica  : %d\n",actual->calif);
		printf("--------------------------\n");
		actual=actual->next;
	}
}

main(){
	inserta_final("A01366001","Juan",75);
	inserta_final("A01366002","Bernardo",85);
	inserta_final("A01366003","Carlos",78);
	inserta_final("A01366004","Daniel",69);
	muestra();
	getche();
}
