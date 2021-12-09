# include <stdio.h>
# include <conio.h>

int cal; // Calificación esté entre 0 y 100, incluidos

main(){
	printf("Indica la calificaci%cn : ",162); scanf("%d",&cal);
	if ((cal<0)||(cal>100)){
		printf("Error, calificaci%cn fuera de rango entre 0 y 100 ...",162);
	}
	else{
		printf("Calificaci%cn valida",162);
	}
	printf("\nV%cctor Ma%c%cn",161,164,162);
	getche();
}
