#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <String.h>

struct Nodo{
	int mat;
	char nom[11];
	Nodo *prev, *next;
};

Nodo *actual, *primero, *ultimo, *nuevo;


char falso[2];

void insertar_final(){
	int vmat;
	char vnom[11];
	printf("Indica la matr%ccula : ",161); scanf("%d",&vmat); gets(falso);
	printf("Indica el nombre    : "); gets(vnom);
	nuevo=new Nodo;
	nuevo->mat=vmat;
	strcpy(nuevo->nom,vnom);
	nuevo->prev=NULL;
	nuevo->next=NULL;
	if (primero==NULL){
		primero=nuevo;
		primero->prev=primero;
		primero->next=primero;
		ultimo=primero;
	}
	else{
		ultimo->next=nuevo;
		nuevo->prev=ultimo;
		nuevo->next=primero;
		primero->prev=nuevo;
		ultimo=nuevo;
	}
}

void insertar_inicio(){
	int vmat;
	char vnom[11];
	printf("Indica la matr%ccula : ",161); scanf("%d",&vmat); gets(falso);
	printf("Indica el nombre    : "); gets(vnom);
	nuevo=new Nodo;
	nuevo->mat=vmat;
	strcpy(nuevo->nom,vnom);
	nuevo->prev=NULL;
	nuevo->next=NULL;
	if (primero==NULL){
		primero=nuevo;
		primero->prev=primero;
		primero->next=primero;
		ultimo=primero;
	}
	else{
		primero->prev=nuevo;
		nuevo->next=primero;
		nuevo->prev=ultimo;
		ultimo->next=nuevo;
		primero=nuevo;
	}
}

void lista_primeroaultimo(){
	int tiempo;
	char tecla;
	if (primero==NULL){
		printf("Error, la lista est%c vac%ca ...\n",160,161);
	}
	else{
		actual=primero;
		while (actual!=NULL){
			printf("%d  %s\n",actual->mat,actual->nom);
			actual=actual->next;
			if (actual==primero) printf("--------------------\n");
			if (kbhit()) tecla=getche();
			if (tecla==char(13)){
				printf("Indica el tiempo de servicio en segundos : ");
				scanf("%d",&tiempo);
				Sleep(tiempo*1000);
				tecla='A';
			}
			if (tecla==char(27)) break;
		}
	}
	getche();
}

void lista_ultimoaprimero(){
	char tecla;
	int tiempo;
	if (primero==NULL){
		printf("Error, la lista est%c vac%ca ...\n",160,161);
	}
	else{
		actual=ultimo;
		while (actual!=NULL){
			printf("%d  %s\n",actual->mat,actual->nom);
			actual=actual->prev;
			if (actual==ultimo) printf("--------------------\n");
			if (kbhit()) tecla=getche();
			if (tecla==char(13)){
				printf("Indica el tiempo de servicio en segundos : ");
				scanf("%d",&tiempo);
				Sleep(tiempo*1000);
				tecla='A';
			}
			if (tecla==char(27)) break;
		}
	}
	getche();
}

void agregar_nodointermedio(){
	int vmat, mat_refere;
	char vnom[21];
	bool existe;
	Nodo *auxiliar;
	printf("Indica la matr%ccula : ",161); scanf("%d",&vmat); gets(falso);
	printf("Indica el nombre    : "); gets(vnom);
	nuevo=new Nodo;
	nuevo->mat=vmat;
	strcpy(nuevo->nom,vnom);
	nuevo->prev=NULL;
	nuevo->next=NULL;
	printf("Indica la matr%ccula de referencia (se agregar%c despu%cs de esta) : ",161,160,130);
	scanf("%d",&mat_refere);
	existe=false;
	if (primero==NULL){
		printf("Error, la lista est%c vac%Ca ...\n",160,161);
	}
	else{
		actual=primero;
		while (actual!=NULL){
			if (mat_refere==actual->mat){
				existe=true;
				break;
			}
			actual=actual->next;
		}
		if (!existe){
			printf("Error, matr%ccula inexistente ...\n",161);
		}
		else{
			auxiliar=new Nodo;
			auxiliar=actual->next;
			nuevo->next=actual->next;
			nuevo->prev=actual;
			actual->next=nuevo;
			auxiliar->prev=nuevo;
			printf("Nodo agregado correctamente ...");
		}
	}
	getche();
}

void eliminar_nodo(){
	int vmat;
	bool existe;
	Nodo *auxiliar;
	auxiliar=new Nodo;
	printf("Indica la matr%ccula eliminar : ",161);
	scanf("%d",&vmat);
	existe=false;
	actual=primero;
	while (actual!=NULL){
		if (actual->mat==vmat){
			existe=true;
			break;
		}
		actual=actual->next;
	}
	if (!existe){
		printf("Error, matr%ccula inexistente ...\n",161);
		getche();
	}
	else{
		if (primero==ultimo){
			delete(actual);
			primero=NULL;
			ultimo=NULL;
		}
		else{
			if (actual==primero){
				auxiliar=primero->next;
				auxiliar->prev=ultimo;
				ultimo->next=auxiliar;
				delete(actual);
				primero=auxiliar;
			}
			else{
				if (actual==ultimo){
					auxiliar=actual->prev;
					auxiliar->next=primero;
					delete(actual);
					ultimo=auxiliar;
				}
				else{
					auxiliar=actual->prev;
					auxiliar->next=actual->next;
					auxiliar=actual->next;
					auxiliar->prev=actual->prev;
					delete(actual);
				}
			}
		}
	}
}

void menu(){
	int op=0;
	while (op!=7){
		printf("1) Agregar nodo al final\n");
		printf("2) Agregar nodo al inicio\n");
		printf("3) Agregar nodo intermedio\n");
		printf("4) Eliminar nodo\n");
		printf("5) Lista de primer a %cltimo\n",163);
		printf("6) Lista de %cltimo a primero\n",163);
		printf("7) Terminar\n",163);
		printf("Indica la opci%cn deseada : ",162);
		scanf("%d",&op); gets(falso);
		if (op==1) insertar_final();
		if (op==2) insertar_inicio();
		if (op==3) agregar_nodointermedio();
		if (op==4) eliminar_nodo();
		if (op==5) lista_primeroaultimo();
		if (op==6) lista_ultimoaprimero();
	}
}

main(){
	menu();
}
