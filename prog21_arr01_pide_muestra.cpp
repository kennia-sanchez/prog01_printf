# include <stdio.h>
# include <conio.h>

int arr[5];

void pide_valores(){
	for (int i=0;i<=4;i++){
		printf("Indica el valor de la posici%cn [%d] : ",162,i);
		scanf("%d",&arr[i]);
	}
}

void muestra_valores(){
	for (int i=0;i<=4;i++){
		printf("%d\n",arr[i]);
	}
}

main(){
	pide_valores();
	muestra_valores();
	getche();
}
