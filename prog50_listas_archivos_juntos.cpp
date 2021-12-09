// Archivo
// Matrícula    char    9
// Nombre       char    15
// Ap. Paterno  char    15
// Ap. Materno  char    15
// Carrera      char    4
// Correo       char    40
// Promedio     int     3

#include <stdio.h>
#include <conio.h>
#include <String.h>
#include <fstream>

using namespace std;

char mat[10], nom[16], ap[16], am[16], car[5], cor[41];
int prom;

char falso[2];

struct Nodo{
	char nmat[10], nnom[16], nap[16], nam[16], ncar[5], ncor[41];
	int nprom;
	Nodo *next;
};

Nodo *primero, *actual, *ultimo, *nuevo, *anterior;

void inserta_final(char pmat[10], char pnom[16], char pap[16], char pam[16], char pcar[5], char pcor[5], int pprom){
	nuevo= new Nodo;
	strcpy(nuevo->nmat,pmat);
	strcpy(nuevo->nnom,pnom);
	strcpy(nuevo->nap,pap);
	strcpy(nuevo->nam,pam);
	strcpy(nuevo->ncar,pcar);
	strcpy(nuevo->ncor,pcor);
	nuevo->nprom=pprom;
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

void cargar_archivo(char archivo[21]){
	ifstream arch;
	arch.open(archivo,ios::in);
	while(!arch.eof()){
		arch >>mat >>nom >>ap >>am >>car >>cor >>prom;
		if (!arch.eof()){
			inserta_final(mat, nom, ap, am, car, cor, prom);
		}
	}
	arch.close();
}

void descarga_archivo(char archivo[21]){
	if (primero==NULL){
		printf("Error, la lista est%c vac%ca ...\n",160,161);
		getche();
	}
	ofstream arch;
	arch.open(archivo,ios::out);
	actual=primero;
	while (actual!=NULL){
		arch <<actual->nmat <<" " <<actual->nnom <<" " <<actual->nap <<" " <<actual->nam <<" " <<actual->ncar <<" " <<actual->ncor <<" " <<actual->nprom <<"\n";
		actual=actual->next;
	}
	arch.close();
}

void altas(){
	printf("Indica la matricula   : "); gets(mat);
	printf("Indica el nombre      : "); gets(nom);
	printf("Indica el Ap. Paterno : "); gets(ap);
	printf("Indica el Ap. Materno : "); gets(am);
	printf("Indica la carrera     : "); gets(car);
	printf("Indica el correo      : "); gets(cor);
	printf("Indica el promedio    : "); scanf("%d",&prom); gets(falso);
	inserta_final(mat,nom,ap,am,car,cor,prom);
}

bool busca_nodo(){
	char mat_busca[10];
	printf("Indica la matr%ccula : ",161); gets(mat_busca);
	actual=primero;
	anterior=NULL;
	while (actual!=NULL){
		if (strcmp(actual->nmat,mat_busca)==0){
			return true;
		}
		anterior=actual;
		actual=actual->next;
	}
	return false;
}

void bajas(){
	if (busca_nodo()){
		if (actual==primero){
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
	else{
		printf("Error, matr%ccula inexistente en archivo de alumnos ...\n",161);
		getche();
	}
}

void lista_alumnos(int op){
	char vcar[5];
	if (op==7){
		printf("Indica la carrera a listar : "); gets(vcar);
	}
	printf("Matr%ccula           Nombre      Ap. Paterno      Ap. Materno      Carrera                                    Correo  Promedio\n",161);
	printf("-----------------------------------------------------------------------------------------------------------------------------\n");
	//      123456789  123456789/12345  123456789/12345  123456789/12345         1234  123456789/123456789/123456789/123456789/  123
	actual=primero;
	while (actual!=NULL){
		if ((op==5) || (op==6)){
			printf("%9s  %15s  %15s  %15s        %4s   %40s %3d\n",actual->nmat,actual->nnom,actual->nap,actual->nam,actual->ncar,actual->ncor,actual->nprom);
		}
		if ((op==7)&&(strcmp(vcar,actual->ncar)==0)){
			printf("%9s  %15s  %15s  %15s        %4s   %40s %3d\n",actual->nmat,actual->nnom,actual->nap,actual->nam,actual->ncar,actual->ncor,actual->nprom);
		}
		actual=actual->next;
	}
	getche();
}

void consultas(){
	if (busca_nodo()){
		printf("Nombre      : %s\n",actual->nnom);
		printf("Ap. Paterno : %s\n",actual->nap);
		printf("Ap. Materno : %s\n",actual->nam);
		printf("Carrera     : %s\n",actual->ncar);
		printf("Correo      : %s\n",actual->ncor);
		printf("Promedio    : %d\n",actual->nprom);
		getche();
	}
	else{
		printf("Error, matr%ccula inexistente en archivo de alumnos ...\n");
		getche();
	}
}

void cambios(){
	char vcar[5];
	int vprom;
	if (busca_nodo){
		printf("Carrera actual  : %s\n",actual->ncar);
		printf("Promedio actual : %d\n",actual->nprom);
		printf("Indica la nueva carrera  : "); gets(vcar);
		printf("Indica el nuevo promedio : "); scanf("%d",&vprom); gets(falso);
		strcpy(actual->ncar,vcar);
		actual->nprom=vprom;
		printf("El cambio ha sido realizado ...\n");
		getche();
	}
	else{
		printf("Error, matr%ccula inexistente en archivo de alumnos ...\n");
		getche();
	}
}

void lista_alumnos_nombre(int op){
	Nodo *auxiliar, *posterior;
	actual=primero;
	auxiliar=new Nodo;
	posterior=new Nodo;
	while (actual!=NULL){
		posterior=actual->next;
		while (posterior!=NULL){
			if (strcmp(actual->nnom,posterior->nnom)==1){
				strcpy(auxiliar->nmat,actual->nmat); //auxiliar=actual;
                strcpy(auxiliar->nnom,actual->nnom);
                strcpy(auxiliar->nap,actual->nap);
                strcpy(auxiliar->nam,actual->nam);
                strcpy(auxiliar->ncar,actual->ncar);
                strcpy(auxiliar->ncor,actual->ncor);
                auxiliar->nprom=actual->nprom;
                //----------------------
				strcpy(actual->nmat,posterior->nmat);//actual=posterior;
				strcpy(actual->nnom,posterior->nnom);
				strcpy(actual->nap,posterior->nap);
				strcpy(actual->nam,posterior->nam);
				strcpy(actual->ncar,posterior->ncar);
				strcpy(actual->ncor,posterior->ncor);
				actual->nprom=posterior->nprom;
				//-----------------------
				strcpy(posterior->nmat,auxiliar->nmat); //posterior=auxiliar;
				strcpy(posterior->nnom,auxiliar->nnom);
				strcpy(posterior->nap,auxiliar->nap);
				strcpy(posterior->nam,auxiliar->nam);
				strcpy(posterior->ncar,auxiliar->ncar);
				strcpy(posterior->ncor,auxiliar->ncor);
				posterior->nprom=auxiliar->nprom;
			}
			posterior=posterior->next;
		}
		actual=actual->next;
	}
	lista_alumnos(op);
	delete(auxiliar);
	delete(posterior);
}

void menup(){
	int op;
	op=-1;
	while (op!=0){
		printf("\n\n\n");
		printf("***** MENU PRINCIPAL *****\n");
		printf("1) Alta de alumnos\n");
		printf("2) Baja de alumnos\n");
		printf("3) Consulta de alumnos\n");
		printf("4) Cambios de alumnos\n"); //cor, car, prom
		printf("5) Lista de alumnos\n");
		printf("6) Lista de alumnos ordenada por nombre\n");
	    printf("7) Lista de alumnos por carrera ordenada por nombre\n");
	    printf("8) Lista de alumnos por promedio ordenada por nombre\n");
	    printf("9) SALVAR ARCHIVO\n");
	    printf("0) Terminar\n");
	    printf("Indica la opci%cn deseada : ",162);
	    scanf("%d",&op); gets(falso);
	    if (op==1) altas();
	    if (op==2) bajas();
	    if (op==3) consultas();
	    if (op==4) cambios();
	    if (op==5) lista_alumnos(op);
	    if ((op==6) || (op==7)){
			descarga_archivo("temporal.txt");
			lista_alumnos_nombre(op);
			primero=NULL;
			cargar_archivo("temporal.txt");
		}
	    if (op==9) descarga_archivo("alumnos.txt");
	} // Termina ciclo del menú
}

main(){
	ofstream arch;
	arch.open("alumnos.txt",ios::app);
	arch.close();
	cargar_archivo("alumnos.txt");
	menup();
	descarga_archivo("alumnos.txt");
}
