# include <stdio.h>
# include <conio.h>
# include <String.h>

// Otras funciones

char cad[21];
int x;

main(){
	printf("Indica una cadena : "); gets(cad);
	x=strcmp(cad,"Juan");
	if (x==0){
		printf("La cadena es igual a Juan\n");
	}
	else{
		printf("La cadena es diferente de Juan\n");
	}
	// strnicmp(cadena1,cadena2,n caracteres);
	x=strnicmp(cad,"Juan",3);
	if (x==0){
		printf("Los primeros 3 cracateres de la cadena son igual a Jua\n");
	}
	else{
		printf("Los primeros 3 caracteres de la cadena son diferentes a Jua\n");
	}
	//strlen(cad); te regresa la longitud de la cadena en caracteres
	x=strlen(cad);
	printf("La cadena tiene %d caracteres\n",x);
	// strupr(cad) // Transforma la cadena a mayúsculas
	strupr(cad);
	printf("La cdena en may%csculas es : %s\n",163,cad);
	strlwr(cad);
	printf("La cdena en min%csculas es : %s\n",163,cad);
	getche();
}
