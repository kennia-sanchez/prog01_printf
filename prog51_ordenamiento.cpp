#include <stdio.h>
#include <conio.h>
#include <String.h>

int arr[10];

void pide_valores(){
	for(int i=0;i<=9;i++){
		printf("Indica valor de posici%cn [%d] : ",162,i); scanf("%d",&arr[i]);
	}
}

void muestra(){
	for(int i=0;i<=9;i++){
		printf("%d, ",arr[i]);
	}
	getche();
}

void ordena(){
	int aux;                        //Nodo aux, posterior;
	                                //actual=primero;
	for (int i=0;i<=9;i++){         //while actual!=NULL{
										//actual=actual->next
		for(int j=i+1;j<=9;j++){        //posterior=actual->next
		                                //while (posterior!=NULL){
			if (arr[i]>arr[j]){         //    if (strcmp(actual->nnom,posterior->nnom)==1){
				aux=arr[i];             //        auxiliar=actual
				arr[i]=arr[j];          //        actual=posterior
				arr[j]=aux;             //        posterior=auxiliar
			}
		}
	}
}

main(){
	pide_valores();
	printf("Los valores NO ordenados son : ");
	muestra();
	ordena();
	printf("\n");
	printf("Los valores ordenados son : ");
	muestra();
}
