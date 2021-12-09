# include <stdio.h>
# include <conio.h>

int n,x,divi;

main(){
	do{
		printf("Indica el valor de N : "); scanf("%d",&n);
		if ((n<1) || (n>1000)){
			printf("Error, valor fuera de rango entre 1 y 1000 ...\n");
			getche();
		}
	} while ((n<1) || (n>1000));
	
	divi=0;
	x=2;
	while (x<n){
		if (n%x==0){
			divi++; // += Python
		}
		x++;
	}
	if (divi==0){
		printf("El valor dado es primo");
	}
 	else{
		printf("El valor dado NO es primo");
	}
	getche();
}
