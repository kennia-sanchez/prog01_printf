//  Usando el constructor por parámetros

# include <stdio.h>
# include <conio.h>
# include <String.h>

class Persona{
	public:
		char nom[21], ap[21], am[21], car[5];
		int prom;
	public:
		Persona(char pnom[21], char pap[21], char pam[21], char pcar[5], int pprom){
			strcpy(nom,pnom);
			strcpy(ap,pap);
			strcpy(am,pam);
			strcpy(car,pcar);
			prom=pprom;
		}
		
		void muestra(){
			printf("Nombre      : %s\n",nom);
			printf("Ap. Paterno : %s\n",ap);
			printf("AP. Mtaerno : %s\n",am);
			printf("Carrera     : %s\n",car);
			printf("Promedio    : %d\n",prom);
			getche();
		}
};

main(){
	Persona p1("Juan","Gracia","Reyes","ITC",88);
	p1.muestra();
	Persona p2("Jose","Diaz","Lopez","IMA",89);
	p2.muestra();
}
