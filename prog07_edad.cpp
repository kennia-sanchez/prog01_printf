# include <stdio.h>
# include <conio.h>

int edad;

main(){
	printf("Indica la edad de la persona : ");
	scanf("%d",&edad);
	
	if (edad>=18){
		printf("La persona es mayor de edad");
	}
	else{
		printf("La persona NO es mayor de edad");
	}
	getche();
}
