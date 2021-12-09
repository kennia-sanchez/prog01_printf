# include <stdio.h>
# include <conio.h>

float x,y,r;

main(){
	printf("Indica el valor de X : "); scanf("%f",&x);
	printf("Indica el valor de Y : "); scanf("%f",&y);
	
	if (y==0){
		printf("Error, no existe la divisi%cn entre CERO ...",162);
	}
	else{
		r=x/y;
		printf("La divisi%cn es: %f",162,r);
	}
	getche();
}
