# include <stdio.h>
# include <conio.h>

int val;

main(){
	printf("Indica el valor : ");
	scanf("%d",&val);
	
	if (val>100){
		printf("El valor es mayor que 100");
	}
	else{
		if (val<100){
			printf("El valor es menor que 100");
		}
		else{
			printf("El valor es igual a 100");
		}
	}
	getche();
}
