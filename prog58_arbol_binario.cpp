// Árbol binario
// Insertar un nodo
// Consultar un nodo
// Desplegar el árbol
// Terminar

# include <stdio.h>
# include <conio.h>

struct Nodo{
	int clave;
	char nombre;
	Nodo *h1, *h2;
};

Nodo *raiz, *actual, *nuevo, *padre;

bool busca_nodo(int vcve){
	padre=NULL;
	actual=raiz;
	while (actual!=NULL){
		if (vcve == actual->clave) return(true);
		padre=actual;
		if (vcve < actual->clave) actual=actual->h1;
		else actual=actual->h2;
	}
	return(false);
}

void insertar_nodo(){
	int vcve;
	char vnom;
	printf("Indica la clave  : "); scanf("%d",&vcve);
	if (busca_nodo(vcve)){
		printf("Error, la clave se duplica en el %crbol ...\n");
		getche();
	}
	else{
        printf("Indica el nombre : "); vnom=getche(); printf("\n\n");
        nuevo=new Nodo;
        nuevo->clave=vcve;
        nuevo->nombre=vnom;
		nuevo->h1=NULL;
		nuevo->h2=NULL;
		if (raiz==NULL) raiz=nuevo;
		else{
			if (vcve < padre->clave) padre->h1=nuevo;
			else padre->h2=nuevo;
		}
	}
}

void consulta_nodo(){
	int vcve;
	printf("Indica la clave  : "); scanf("%d",&vcve);
	if (!busca_nodo(vcve)) printf("Error, clave inexistente en el %crbol ...\n");
	else printf("Nombre : %c",actual->nombre);
	getche();
}

int mostrar_arbol(Nodo *arbol, int cont){
	if (arbol==NULL) return(0);
	else{
		mostrar_arbol(arbol->h2,cont+1);
		for(int i=0;i<cont;i++) printf("     ");
		printf("%d%c\n",arbol->clave,arbol->nombre);
		mostrar_arbol(arbol->h1,cont+1);
	}
}

void menu(){
	int op;
	while (op!=4){
		printf("1) Insertar nodo\n");
		printf("2) Consultar nodo\n");
		printf("3) Mostrar %crbol\n",160);
		printf("4) Terminar\n");
		printf("Indica la opci%cn deseada : ");
		scanf("%d",&op);
		if (op==1) insertar_nodo();
		if (op==2) consulta_nodo();
		if (op==3){
			mostrar_arbol(raiz,0);
			getche();
		}
	}
}

main(){
	menu();
}
