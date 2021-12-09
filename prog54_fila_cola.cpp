#include <stdio.h>
#include <conio.h>
#include <String.h>

struct Nodo{
	int valor;
	Nodo *next;
};

Nodo *primero, *ultimo, *nuevo, *actual, *previo;

void inserta_final(){
	int x;
	printf("Indica el valor a insertar : ");
	scanf("%d",&x);
	nuevo=new Nodo;
	nuevo->valor=x;
	nuevo->next=NULL;
	if (primero==NULL){
		primero=nuevo;
		ultimo=nuevo;
	}
	else{
		ultimo->next=nuevo;
		ultimo=nuevo;
	}
}

void retirar_nodo(){
	if (primero==NULL){
		printf("Error, la lista est%c vac%ca ...\n",160,161);
		getche();
	}
	else{
		actual=primero;
		primero=primero->next;
		delete(actual);
	}
}


void muestra(){
	if (primero==NULL){
		printf("Error, la lista est%c vac%ca ...\n",160,161);
		getche();
	}
	else{
		actual=primero;
		while (actual!=NULL){
			printf("%d\n",actual->valor);
			actual=actual->next;
		}
		getche();
	}
}

void menu(){
	int op;
	op=0;
	while (op!=4){
		printf("1) Insertar nodo\n");
		printf("2) Retirar nodo\n");
		printf("3) Mostrar Lista\n");
		printf("4) Terminar\n");
		printf("Indica la opci%cn deseada : ");
		scanf("%d",&op);
		if (op==1) inserta_final();
		if (op==2) retirar_nodo();
		if (op==3) muestra();
	}
}

main(){
	menu();
}
