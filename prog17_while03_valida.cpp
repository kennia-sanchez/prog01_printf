# include <stdio.h>
# include <conio.h>

int x; // Validar que X esté entre 0 y 100

void while01(){
	x=-1;
	while ((x<0) || (x>100)){
		printf("Indica el valor de X : "); scanf("%d",&x);
		if ((x<0) || x>100){
			printf("Error, valor fuera de rango ...\n");
			getche();
		}
	}
	printf("Valor correcto");
	getche();
}

void while02(){
	do {
		printf("Indica el valor de X : "); scanf("%d",&x);
		if ((x<0) || x>100){
			printf("Error, valor fuera de rango ...\n");
			getche();
		}
	} while ((x<0) || (x>100));
	printf("Valor Correcto");
	getche();
}

main(){
	while02();
}
