# include <stdio.h>
# include <conio.h>
# include <String.h>

class Persona{
	private:
        char nom[21], ap[21], am[21];
	public:
		int edad;
	public:
		Persona(char pnom[21], char pap[21], char pam[21], int edad){
			strcpy(nom,pnom);
			strcpy(ap,pap);
			strcpy(am,pam);
		}

		Persona(){
			strcpy(nom,"Juan");
			strcpy(ap,"Perez");
			strcpy(am,"Lopez");
		}

		void muestra(){
			printf("Nombre      : %s\n",nom);
			printf("Ap. Paterno : %s\n",ap);
			printf("Ap. Materno : %s\n",am);
			printf("Edad        : %d\n",edad);
			printf("**************************************\n");
			getche();
		}
};

main(){
	Persona ob1("Luis","Herandez","Fernandez",15);
	ob1.edad=25;
	ob1.muestra();
}

