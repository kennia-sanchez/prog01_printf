# include <stdio.h>
# include <conio.h>
# include <String.h>

char cad[21]; //Caben 20 caracteres, el adicional es para el fin de cadena
int x;

main(){
    strcpy(cad,"Juanito"); //Copia una cadena a otra
	printf("La cadena es : %s\n",cad);
	
	if (strcmp(cad,"Juanito")==0){ //Compara dos cadenas, 0 igules, otro valor son diferentes
		printf("Cadenas iguales\n");
	}
	strcpy(cad,"bbb");
	x=strcmp(cad,"bbb");
	printf("X=%d, comparando con bbb\n",x);
	x=strcmp(cad,"aaa");
	printf("X=%d, comparando con aaa\n",x);
	x=strcmp(cad,"ccc");
	printf("X=%d, comparando con ccc\n",x);
	x=strcmp(cad,"BBB");
	printf("X=%d, comparando con BBB\n",x);
	// Conclusión si la primera cadena es mayor que la segunda, me da un valor 1
	// Pero si la primera cade¿na es menor que la segunda -1
	// Si las cadenas son iguales 0
	getche();
}
