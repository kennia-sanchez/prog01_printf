#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <String.h>

struct Nodo{
	int valor;
	Nodo *next;
};

Nodo *primero, *ultimo, *nuevo, *actual, *previo;

void inserta_final(){
	int x;
	printf("Indica el valor del nodo : ");
	scanf("%d",&x);

	nuevo=new Nodo;
	nuevo->valor=x;
	nuevo->next=NULL;
	
	if (primero==NULL){ // Se trata del primero de la lista
	    primero=nuevo;
	    primero->next=primero;
	    ultimo=primero;
	}
	else{
		ultimo->next=nuevo;
		nuevo->next=primero;
		ultimo=nuevo;
	}
}

void inserta_inicio(){
	int x;
	printf("Indica el valor del nodo : ");
	scanf("%d",&x);

	nuevo=new Nodo;
	nuevo->valor=x;
	nuevo->next=NULL;
	
	if (primero==NULL){
		primero=nuevo;
		primero->next=primero;
		ultimo=primero;
	}
	else{
		nuevo->next=primero;
		primero=nuevo;
		ultimo->next=primero;
	}
}

void consulta(){
	int x;
	bool existe;
	printf("Indica el nodo a consultar : ");
	scanf("%d",&x);
	actual=primero;
	existe=false;
	do{
		if (x==actual->valor){
			printf("Nodo existente\n");
			existe=true;
			break;
		}
		actual=actual->next;
	} while (actual!=primero);
	if (!existe){
		printf("Nodo inexistente\n");
	}
	getche();
}

void inserta_posicion(){
	int x, pos;
	bool existe;
	printf("Indica el valor del nodo a insertar            : ");
	scanf("%d",&x);
	printf("Indica despu%cs de que nodo deseas insertarlo : ",130);
	scanf("%d",&pos);
	
	actual=primero;
	existe=false;
	do{
		if (pos==actual->valor){
			existe=true;
			break;
		}
		actual=actual->next;
	} while (actual!=primero);
	if (!existe){
		printf("Nodo de referencia inexistente\n");
	}
	else{
		nuevo=new Nodo;
		nuevo->valor=x;
		nuevo->next=NULL;
		if (actual==ultimo){
			ultimo->next=nuevo;
			nuevo->next=primero;
			ultimo=nuevo;
		}
		else{
			nuevo->next=actual->next;
			actual->next=nuevo;
		}
		printf("El nodo ha sido insertado\n");
	}
	getche();
}

void borra_nodo(){
	int x;
	bool existe;
	printf("Indica el nodo a eliminar : ");
	scanf("%d",&x);
	actual=primero;
	existe=false;
	previo=NULL;
	do{
		if (x==actual->valor){
			existe=true;
			break;
		}
		previo=actual;
		actual=actual->next;
	} while (actual!=primero);
	if (!existe){
		printf("Nodo inexistente\n");
	}
	else{
		if (actual==primero){
			primero=primero->next;
			ultimo->next=primero;
			delete(actual);
		}
		else{
			if (actual==ultimo){
				ultimo=previo;
				ultimo->next=primero;
				delete(actual);
			}
			else{
				previo->next=actual->next;
				delete(actual);
			}
		}
		printf("Nodo eliminado\n");
	}
	getche();
}

void muestra(){
	char tecla;
	int tiempo;
	actual=primero;
	while (actual!=NULL){
		printf("%d\n",actual->valor);
		actual=actual->next;
		if (kbhit())tecla=getche();
		if (char(tecla)==13){ // Petición de servicio
		    printf("Indica el tiempo de servicio : ");
		    scanf("%d",&tiempo);
		    Sleep(tiempo*1000);
		    tecla='A';
		}
		if (char(tecla)==27) break;
	}
	printf("Ciclo terminado\n");
	getche();
}


void menu(){
	int op=0;
	while (op!=7){
		printf("1) Insertar nodo al final\n");
		printf("2) Insertar nodo al inicio\n");
		printf("3) Consultar un nodo\n");
		printf("4) Insertar nodo en una posici%cn\n",162);
		printf("5) Borrar un nodo\n");
		printf("6) Mostrar lista circular\n");
		printf("7) Terminar\n");
		printf("Indica la opci%cn deseada : ",162);
		scanf("%d",&op);
		if (op==1) inserta_final();
		if (op==2) inserta_inicio();
		if (op==3) consulta();
		if (op==4) inserta_posicion();
		if (op==5) borra_nodo();
		if (op==6) muestra();
	}
}

main(){
	menu();
}
