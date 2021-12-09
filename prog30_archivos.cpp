# include <stdio.h>
# include <conio.h>
# include <String.h>
# include <fstream> // Paso 1 para manejo de archivos

using namespace std;
char falso[2];

// Definir su estructura
char mat[10];
char nom[21];
char ap[21];
char am[21];
char car[21];
int prom;
//mat       nom   ap    am     car  prom
//A01366001 Juan  Perez Lopez  ITC   85

bool existe_mat(){
	char busca_mat[10];
	ifstream arch;
	arch.open("alumnos.txt",ios::in);
	while (!arch.eof()){
		arch >>busca_mat >>nom >>ap >>am >>car >>prom;
		if (strcmp(busca_mat,mat)==0){
			arch.close();
			return(true);
		}
	}
	arch.close();
	return(false);
}

void altas(){
	do{
        printf("Indica la matr%ccula   : ",161); gets(mat);
        if (strlen(mat)!=9){
			printf("Error, la matr%ccula debe tener 9 caracteres ...\n");
			getche();
		}
	} while (strlen(mat) !=9);
	strupr(mat);
	if (existe_mat()){
		printf("Error, la matr%ccula se duplica en el archivo ...\n",161);
		getche();
	}
	else
	{
		do{
			printf("Indica el nombre      : "); gets(nom);
			if ((strlen(nom)<1) || (strlen(nom)>20)){
				printf("Error, el nombre debe tener al menos un caracter y m%cximo 20 ...\n",160);
				getche();
			}
		} while ((strlen(nom)<1) || (strlen(nom)>20));

		do{
			printf("Indica el Ap. Paterno : "); gets(ap);
			if ((strlen(ap)<1) || (strlen(ap)>20)){
				printf("Error, el Ap. Paterno debe tener al menos un caracter y m%cximo 20 ...\n",160);
				getche();
			}
		} while ((strlen(ap)<1) || (strlen(ap)>20));

		do{
			printf("Indica el Ap. Materno : "); gets(am);
			if ((strlen(am)<1) || (strlen(am)>20)){
				printf("Error, el Ap. Materno debe tener al menos un caracter y m%cximo 20 ...\n",160);
				getche();
			}
		} while ((strlen(am)<1) || (strlen(am)>20));

		do{
			printf("Indica la carrera     : "); gets(car);
			if ((strlen(car)<2) || (strlen(car)>4)){
				printf("Error, la carrera debe tener al menos dos caracteres y m%cximo 4 ...\n",160);
				getche();
			}
		} while ((strlen(car)<1) || (strlen(car)>20));
		strupr(car);

		do{
			printf("Indica el promedio    : "); scanf("%d",&prom); gets(falso);
			if ((prom<1) || (prom>100)){
				printf("Error, promedio fuera de rango entre 1 y 100 ...\n");
				getche();
			}
		} while ((prom<1) || (prom>100));

		// Cambia los espacios por guiones bajos "_"
		for (int i=0;i<strlen(nom);i++) if (nom[i]==' ') nom[i]='_';
		for (int i=0;i<strlen(ap);i++) if (ap[i]==' ') ap[i]='_';
		for (int i=0;i<strlen(am);i++) if (am[i]==' ') am[i]='_';
		for (int i=0;i<strlen(car);i++) if (car[i]==' ') car[i]='_';
		// Se graba el registro
		ofstream arch;
		arch.open("alumnos.txt",ios::app);
		arch <<mat <<" " <<nom <<" " <<ap <<" " <<am <<" " <<car <<" " <<prom <<"\n";
		arch.close();
		printf("Registro Grabado Existosamente\n");
		getche();
	} // Valida que no se duplique la matrícula
}

void consulta(){
	do{
        printf("Indica la matr%ccula   : ",161); gets(mat);
        if (strlen(mat)!=9){
			printf("Error, la matr%ccula debe tener 9 caracteres ...\n");
			getche();
		}
	} while (strlen(mat) !=9);
	strupr(mat);
	if (!existe_mat()){
		printf("Error, matr%ccula inexistente en el archivo ...\n",161);
		getche();
	}
	else{
		for (int i=0;i<strlen(nom);i++) if (nom[i]=='_') nom[i]=' ';
		for (int i=0;i<strlen(ap);i++) if (ap[i]=='_') ap[i]=' ';
		for (int i=0;i<strlen(am);i++) if (am[i]=='_') am[i]=' ';
		for (int i=0;i<strlen(car);i++) if (car[i]=='_') car[i]=' ';
		printf("Nombre      : %s\n",nom);
		printf("Ap. Paterno : %s\n",ap);
		printf("Ap. Materno : %s\n",am);
		printf("Carrera     : %s\n",car);
		printf("Promedio    : %d\n",prom);
		getche();
	}
}

void listado_general(){
	ifstream arch;
	arch.open("alumnos.txt",ios::in);
	while (!arch.eof()){
		arch >>mat >>nom >>ap >>am >>car >>prom;
		for (int i=0;i<strlen(nom);i++) if (nom[i]=='_') nom[i]=' ';
		for (int i=0;i<strlen(ap);i++) if (ap[i]=='_') ap[i]=' ';
		for (int i=0;i<strlen(am);i++) if (am[i]=='_') am[i]=' ';
		for (int i=0;i<strlen(car);i++) if (car[i]=='_') car[i]=' ';
		if (!arch.eof()){
			printf("%s  %s  %s  %s  %s  %d\n",mat,nom,ap,am,car,prom);
		}
	}
	arch.close();
	getche();
}

void lista_carrera(){
	char car_busca[21];
	float suma, cont_registros, prom_carrera;
	do{
		printf("Indica la carrera     : "); gets(car_busca);
		if ((strlen(car_busca)<2) || (strlen(car_busca)>4)){
			printf("Error, la carrera debe tener al menos dos caracteres y m%cximo 4 ...\n",160);
			getche();
		}
	} while ((strlen(car_busca)<1) || (strlen(car_busca)>4));
	strupr(car_busca);
	ifstream arch;
	arch.open("alumnos.txt",ios::in);
	suma=0;
	cont_registros=0;
	while (!arch.eof()){
		arch >>mat >>nom >>ap >>am >>car >>prom;
		for (int i=0;i<strlen(nom);i++) if (nom[i]=='_') nom[i]=' ';
		for (int i=0;i<strlen(ap);i++) if (ap[i]=='_') ap[i]=' ';
		for (int i=0;i<strlen(am);i++) if (am[i]=='_') am[i]=' ';
		for (int i=0;i<strlen(car);i++) if (car[i]=='_') car[i]=' ';
		if ((!arch.eof()) && (strcmp(car,car_busca)==0)){
			printf("%s  %s  %s  %s  %s  %d\n",mat,nom,ap,am,car,prom);
			suma=suma+prom;
			cont_registros++;
		}
	}
	if (cont_registros>0){
		prom_carrera=suma/cont_registros;
		printf("---------------------------------------\n");
		printf("El promedio de la carrera es : %.2f\n",prom_carrera);
	}
	else{
		printf("Error, no hay alumnos registrados con esa carrera ...\n");
	}
	arch.close();
	getche();
}

void lista_promedio(){
	int prom_ini, prom_fin;
	int cont_registros;
	printf("Indica el promedio inicial : "); scanf("%d",&prom_ini);
	printf("Indica el promedio final   : "); scanf("%d",&prom_fin);
	ifstream arch;
	arch.open("alumnos.txt",ios::in);
	cont_registros=0;
	while (!arch.eof()){
		arch >>mat >>nom >>ap >>am >>car >>prom;
		if ((!arch.eof()) && (prom>=prom_ini) && (prom<=prom_fin)){
			printf("%s  %s  %s  %s  %s  %d\n",mat,nom,ap,am,car,prom);
			cont_registros++;
		}
	}
	if (cont_registros==0){
		printf("Error, no hay alumnos en ese rango de promedios ...\n");
	}
	arch.close();
	getche();
}

void menu(){
	int op;
	do{
		printf("1) Alta de alumnos\n");
		printf("2) Consulta de alumnos\n");
		printf("3) Listado General\n");
		printf("4) Listado por carrera\n");
		printf("5) Por promedio\n");
		printf("6) Terminar\n");
		printf("Indica la opci%cn deseada : ",162);
		scanf("%d",&op); gets(falso);
		if ((op<1) || (op>6)){
			printf("Error, opci%cn fuera de rango entre 1 y 6 ...\n",162);
			getche();
		}
		else{
			switch (op){
				case 1:altas(); break;
				case 2:consulta(); break;
				case 3:listado_general(); break;
				case 4:lista_carrera(); break;
				case 5:lista_promedio(); break;
			}
		}
	} while (op!=6);
}

main(){
	menu();
}
