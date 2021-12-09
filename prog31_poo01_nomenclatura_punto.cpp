# include <stdio.h>
# include <conio.h>
# include <String.h>

class Persona{
	public:
		char nom[21], ap[21], am[21];
		int edad;
	public:
		void muestra(){
			printf("Nombre      : %s\n",nom);
			printf("Ap. Paterno : %s\n",ap);
			printf("Ap. Materno : %s\n",am);
			printf("Edad        : %d\n",edad);
			getche();
		}
};

main(){
	Persona obj1, obj2;
	strcpy(obj1.nom,"Juan");
	strcpy(obj1.ap,"Perez");
	strcpy(obj1.am,"Lopez");
	obj1.edad=10;

	strcpy(obj2.nom,"Dos");
	strcpy(obj2.ap,"Dos");
	strcpy(obj2.am,"Dos");
	obj2.edad=2;

	obj1.muestra();
	printf("-------------------------------\n");
	obj2.muestra();
}
