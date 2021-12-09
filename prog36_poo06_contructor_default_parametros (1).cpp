// Usando constructor por default y por parámetros

# include <stdio.h>
# include <conio.h>
# include <String.h>

class Persona{
	public:
		char nom[21], ap[21], am[21], car[5];
		int prom;
	public:
		Persona(){
			strcpy(nom,"Juan");
			strcpy(ap,"Lopez");
			strcpy(am,"Reyes");
			strcpy(car,"ITC");
			prom=90;
		}

		Persona(char pnom[21], char pap[21], char pam[21], char pcar[5], int pprom){
			strcpy(nom,pnom);
			strcpy(ap,pap);
			strcpy(am,pam);
			strcpy(car,pcar);
			prom=pprom;
		}

		void muestra(){
			printf("*********************************\n");
			printf("Nombre      : %s\n",nom);
			printf("Ap. Paterno : %s\n",ap);
			printf("AP. Mtaerno : %s\n",am);
			printf("Carrera     : %s\n",car);
			printf("Promedio    : %d\n",prom);
			printf("*********************************\n");
			getche();
		}
};

main(){
	Persona p1;
	p1.muestra();
	Persona p2("Jose","Garcia","Salinas","IMA",80);
	p2.muestra();
}
