// Constructor
// Incicializar los atributos de la clase, es decir, asigna valores predeterminados
// a cada uno de los atributos "Los Construye"
// Dos Tipos
// Constructor por default
// El constructor asigna valores predeterminados a los atributos de la clase

//Constructor por parámetros
//Permite que el constructor RECIBA los valores que serán asignados a los atributos
// de la clase

// EJEMPLO1: CONTRUCTOR POR DEFAULT // FORMA SIMPLE

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
			strcpy(ap,"Garcia");
			strcpy(am,"Reyes");
			strcpy(car,"ITC");
			prom=88;
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
	Persona p1;
	p1.muestra();
	Persona p2;
	strcpy(p2.ap,"Hernandez");
	strcpy(p2.am,"Fernandez");
	p2.prom=85;
	p2.muestra();
}
