// Placas 	char[8]
// Marca    char[21]
// Tipo     char[21]
// Modelos  int // Año del vehículo
// Precio   float

# include <stdio.h>
# include <conio.h>
# include <String.h>
# include <fstream>
using namespace std;

// para que se borre la basura 
char falso[2];

class Archivo{
	public:
		char placas[8], marca[21], tipo[21];
		int modelo;
		float precio;
	public:
		Archivo(){
			//Vacío
		}
		// con parametros
		Archivo(char pplacas[8], char pmarca[21], char ptipo[21], int pmodelo, float pprecio){
			strcpy(placas,pplacas);
			strcpy(marca,pmarca);
			strcpy(tipo,ptipo);
			modelo=pmodelo;
			precio=pprecio;
		}
		
		void muestra(){
			printf("Placas : %s\n",placas);
			printf("Marca  : %s\n",marca);
			printf("Tipo   : %s\n",tipo);
			printf("Modelo : %d\n",modelo);
			printf("Precio : %.2f",precio);
			getche();
		}
		
		void grabar(){
			ofstream arch;
			arch.open("autos.txt",ios::app);
			arch <<placas <<" " <<marca <<" " <<tipo <<" " <<modelo <<" " <<precio <<"\n";
			arch.close();
		}
		// Valida que no se repitan las placas
		bool existe_placas(char busca_placas[8]){
			ifstream arch;
			arch.open("autos.txt",ios::in);
			while (!arch.eof()){
				arch >>placas >>marca >>tipo >>modelo >>precio;
				if (strcmp(busca_placas,placas)==0){
					arch.close();
					return true;
				}
			}
			arch.close();
			return false;
		}
		// Muestra todos los elementos que hay en el archivo
		void listados(char tipo_reporte[8], char pmarca[21], int precio_ini, int precio_fin){
			ifstream arch;
			arch.open("autos.txt",ios::in);
			while (!arch.eof()){
				arch >>placas >>marca >>tipo >>modelo >>precio;
				if (!arch.eof()){
					if (strcmp(tipo_reporte,"General")==0){
						printf("%s  %20s  %20s  %4d  %10.2f\n",placas,marca,tipo,modelo,precio);
					}
					if ((strcmp(tipo_reporte,"Marca")==0) && (strcmp(pmarca,marca)==0)){
						printf("%s  %20s  %20s  %4d  %10.2f\n",placas,marca,tipo,modelo,precio);
					}
				}
			} // Termina ciclo
			arch.close();
			getche();
		} // Termina método
};

void altas(){
	char placas[8], marca[21], tipo[21];
	int modelo;
	float precio;
	for (int i=0;i<=45;i++) printf("\n");
	printf("*******************************************\n");
	printf("***********  ALTAS DE AUTOS  **************\n");
	printf("*******************************************\n");
	printf("Indica las placas : "); gets(placas);
	Archivo obj;
	if (obj.existe_placas(placas)){
		printf("Error, las placas se duplican en la base de datos ...\n");
		getche();
	}
	else{
		printf("Marca             : "); gets(marca);
		printf("Tipo              : "); gets(tipo);
		printf("A%co modelo        : ",164); scanf("%d",&modelo);
		printf("Precio de venta   : "); scanf("%f",&precio);
		Archivo obj(placas,marca,tipo,modelo,precio);
		obj.grabar();
		printf("El registro ha sido grabado correctamente [ENTER] para continuar\n");
		getche();
	}
}

void consultas(){
	char placas[8];
	for (int i=0;i<=45;i++) printf("\n");
	printf("*******************************************\n");
	printf("******** CONSULTAS DE AUTOS  **************\n");
	printf("*******************************************\n");
	printf("Indica las placas : "); gets(placas);
	Archivo obj;
	if (!obj.existe_placas(placas)){
		printf("Error, placas inexistentes en la base de datos ...\n");
		getche();
	}
	else{
		obj.muestra();
	}
}

void menu(){
	int op=0;
	char marca[21];
	while (op!=6){
		for (int i=0;i<=45;i++) printf("\n");
		printf("*******************************************\n");
		printf("***********  MENU PRINCIPAL  **************\n");
		printf("*******************************************\n");
		printf("1) Altas de autos\n");
		printf("2) Consulta de autos por placas\n");
		printf("3) Listado general de autos\n"); 	//General
		printf("4) Listado por marca\n"); 			//Marca
		printf("5) Listado por rango de precios\n");//Precio
		printf("6) TERMINAR\n");
		printf("Indica la opci%cn deseada : ",162);
		scanf("%d",&op); gets(falso);
		if ((op<1) || (op>6)){
			printf("Error, opci%cn fuera de rango entre 1 y 6 ...\n",162);
			getche();
		}
		else{
			if (op==1) altas();
			if (op==2) consultas();
			Archivo obj;
			if (op==3) obj.listados("General","",0,0);
			if (op==4){
				printf("Indica la marca : "); gets(marca);
				obj.listados("Marca",marca,0,0);
			}
		}
	} // Termina ciclo del menú
}

main(){
	menu();
}
