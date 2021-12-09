#include <stdio.h>
#include <conio.h>
#include <String.h>

char cad1[16], cad2[16];
int x;

main(){
	printf("Indica la primer  cadena : "); gets(cad1);
	printf("Indica la segunda cadena : "); gets(cad2);
	x=strcmp(cad1,cad2);
	// Si la primer cadena es menor que la segunda meda 	-1
	// Si la primer cadena es mayor que la segunda meda 	1
	// Si las cadenas son iguales me da 					0
	printf("X=%d",x);
	getche();
}
