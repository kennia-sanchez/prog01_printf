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

char vmat[10], vnom[21];
int vcalif;

char falso[2];

void inserta_inicio(char pmat[10], char pnom[21], int pcalif){
	nuevo= new Nodo;
	strcpy(nuevo->mat,pmat);
	strcpy(nuevo->nom,pnom);
	nuevo->calif=pcalif;
	nuevo->next=NULL;
	
	if (primero==NULL){
		primero=nuevo;
		ultimo=nuevo;
		actual=nuevo;
	}
	else{
		nuevo->next=primero;
		primero=nuevo;
	}
}

void inserta_final(char pmat[10], char pnom[21], int pcalif){
	nuevo= new Nodo;
	strcpy(nuevo->mat,pmat);
	strcpy(nuevo->nom,pnom);
	nuevo->calif=pcalif;
	nuevo->next=NULL;

	if (primero==NULL){
		primero=nuevo;
		ultimo=nuevo;
		actual=nuevo;
	}
	else{
		ultimo->next=nuevo;
		ultimo=nuevo;
	}
}

void inserta_posicion(char pmat[10], char pnom[21], int pcalif){
	char xmat[10];
	printf("Indica la matr%ccula despu%cs de la que quieres insertar el nodo : ",161,130);
	gets(xmat);

	bool existe;
	if (primero==NULL){
		printf("La lista est%c vac%ca\n",160,161);
		getche();
	}
	else{
		actual=primero;
		existe=false;
		while (actual!=NULL){
			if (strcmp(xmat,actual->mat)==0){
				existe=true;
				break;
			}
			actual=actual->next;
		}
		if (!existe){
			printf("Error, matr%ccula inexistente en la lista ...\n",161);
			getche();
		}
		else{
			nuevo=new Nodo;
			strcpy(nuevo->mat,pmat);
			strcpy(nuevo->nom,pnom);
			nuevo->calif=pcalif;
			nuevo->next=actual->next;
			actual->next=nuevo;
		}
	}

}

void pide_datos(int op){
	printf("Indica la matr%ccula    : ",161); gets(vmat);
	printf("Indica el nombre       : "); gets(vnom);
	printf("Indica la calificaci%cn : ",162); scanf("%d",&vcalif); gets(falso);
	if (op==1){
		inserta_inicio(vmat,vnom,vcalif);
	}
	if (op==2){
        inserta_final(vmat,vnom,vcalif);
	}
	if (op==4){
		inserta_posicion(vmat,vnom,vcalif);
	}
}

void consulta_nodo(){
	bool existe;
	if (primero==NULL){
		printf("La lista est%c vac%ca\n",160,161);
		getche();
	}
	else{
		printf("Indica la matr%ccula a buscar : ",161);
		gets(vmat);
		actual=primero;
		existe=false;
		while (actual!=NULL){
			if (strcmp(vmat,actual->mat)==0){
				existe=true;
				break;
			}
			actual=actual->next;
		}
		if (!existe){
			printf("Error, nodo inexistente en la lista ...\n");
			getche();
		}
		else{
			printf("Nombre       : %s\n",actual->nom);
			printf("Calificaci%cn : %d\n",162,actual->calif);
			getche();
		}
	}
}

void mostrar_lista(){
	if (primero==NULL){
		printf("La lista est%c vac%ca\n",160,161);
	}
	actual=primero;
	while (actual!=NULL){
		printf("%10s  %21s  %3d\n",actual->mat,actual->nom,actual->calif);
		actual=actual->next;
	}
	getche();
}

void borrar_nodo(){
	Nodo *anterior;
	bool existe;
	printf("Indica el nodo a eliminar : ");
	gets(vmat);
	actual=primero;
	existe=false;
	anterior=NULL;
	while (actual!=NULL){
		if (strcmp(vmat,actual->mat)==0){
			existe=true;
			break;
		}
		anterior=actual;
		actual=actual->next;
	}
	if (!existe){
		printf("Error, nodo inexistente en la lista ...\n");
		getche();
	}
	else{
		if (primero==actual){
			primero=primero->next;
			delete(actual);
		}
		else{
			if (actual==ultimo){
				ultimo=anterior;
			}
			anterior->next=actual->next;
			delete(actual);
		}
	}
}

void menu(){
	int op=0;
	while (op!=7){
		printf("1) Insertar nodo al inicio\n");
		printf("2) Insertar nodo al final\n");
		printf("3) Consultar un nodo\n");
		printf("4) Insertar nodo en una posici%cn\n",162);
		printf("5) Borrar un nodo\n");
		printf("6) Mostrar lista enlazada\n");
		printf("7) Terminar\n");
		printf("Indica la opci%cn deseada : ",162);
		scanf("%d",&op); gets(falso);
		if ((op==1) || (op==2) || (op==4)){
			pide_datos(op);
		}
		if (op==3){
			consulta_nodo();
		}
		if (op==5){
			borrar_nodo();
		}
		if (op==6){
			mostrar_lista();
		}
	}
}

main(){
	menu();
}
