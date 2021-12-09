# include <stdio.h>
# include <conio.h>
# include <String.h>

class Persona{
	public:
        char nom[21], ap[21], am[21];
		int edad;
		
	public:
		Persona(char pnom[21], char pap[21], char pam[21], int pedad){
			strcpy(nom,pnom);
			strcpy(ap,pap);
			strcpy(am,pam);
			edad=pedad;
		}

		Persona(){
		}

		void muestra(){
			printf("Nombre      : %s\n",nom);
			printf("Ap. Paterno : %s\n",ap);
			printf("Ap. Materno : %s\n",am);
			printf("Edad        : %d\n",edad);
		}
};

class Estudiante : public Persona{
	public:
		char mat[10], car[5];
	public:
		Estudiante(){
		}

		Estudiante(char pnom[21], char pap[21], char pam[21], int pedad, char pmat[10], char pcar[5]){
			strcpy(nom,pnom);
			strcpy(ap,pap);
			strcpy(am,pam);
			edad=pedad;
			strcpy(mat,pmat);
			strcpy(car,pcar);
		}
		
		void muestra_estudiante(){
			muestra();
			printf("Matr%ccula    : %s\n",161,mat);
			printf("Carrera      : %s\n",car);
		}
};

class Deportista : public Estudiante{
	public:
		char deporte[21];
	public:
        Deportista(char pnom[21], char pap[21], char pam[21], int pedad, char pmat[10], char pcar[5], char pdeporte[21]){
			strcpy(nom,pnom);
			strcpy(ap,pap);
			strcpy(am,pam);
			edad=pedad;
			strcpy(mat,pmat);
			strcpy(car,pcar);
			strcpy(deporte,pdeporte);
		}
		void muestra_deporte(){
			muestra_estudiante();
			printf("Deporte      : %s\n",deporte);
		}
};
main(){
	Persona ob1("Luis","Herandez","Fernandez",15);
	ob1.muestra();
	getche();
	
	printf("**************************************\n");
	Estudiante objest("Pancho","Pantera","Chocolate",10,"A01366001","ITC");
	//objest.muestra();
	objest.muestra_estudiante();
	getche();

	printf("**************************************\n");
	Deportista objdep("Lucas","Luna","Lucatero",23,"A01366002","IMT","Atletismo");
	objdep.muestra_deporte();
	getche();
}

