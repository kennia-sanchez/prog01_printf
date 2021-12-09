# include <stdio.h>
# include <conio.h>

char cad[21]; //Caben 20 caracteres, el adicional es para el fin de cadena

main(){
	printf("Indica una palabra : ");
	//scanf("%s",&cad);
	gets(cad);
	printf("La cadena es : %s",cad);
	getche();
}
