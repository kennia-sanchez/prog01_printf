# include <stdio.h>
# include <conio.h>
# include <Math.h>

int ar[100], n;

void pide_valores(){
	for(int i=0;i<=99;i++){
		printf("Captura el valor de la posici%cn [%d] : ",162,i);
		scanf("%d",&ar[i]);
		if (ar[i]==0){
			n=i;
			break;
		}
	}
}

void mediana(){
	int ar2[100], aux;
	float med;
	for(int i=0;i<=99;i++) ar2[i]=ar[i];
	for(int i=0;i<n;i++) ar2[i]=ar[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if (ar2[i]>ar2[j]){
				aux=ar2[j];
				ar2[j]=ar2[i];
				ar2[i]=aux;
			}
		}
	}
	if (n%2!=0){
		med=ar2[n/2];
	}
	else{
		med=(ar2[n/2] + ar2[n/2-1])/2.0;
	}
	printf("La mediana es : %.2f",med);
	getche();
}

void desviacion_estandar(){
	float prom, suma, de;
	suma=0;
	for (int i=0;i<n;i++) suma=suma+ar[i];
	prom=suma/n;
	suma=0;
	for(int i=0;i<n;i++){
		suma=suma+pow((ar[i]-prom),2);
	}
	de=sqrt(suma/n);
	printf("La desviaci%cn est%cndar es : %.2f",162,160,de);
	getche();
}

void menu(){
	char op;
	do{
		printf("a) Captura de valores\n");
		printf("b) Mediana\n");
		printf("c) Desviaci%cn Est%cndar\n",162,160);
		printf("[ESC] para teminar\n");
		printf("Indica la opci%cn deseada : ",162);
		op=getche();
		printf("\n");
		if (((op<'a') || (op>'c')) && (op!=char(27))){
			printf("Error, opci%cn fuera de rango entre -a- y -c- ...\n");
			getche();
		}
		else{
			switch (op){
				case 'a':pide_valores(); break;
				case 'b':mediana(); break;
				case 'c':desviacion_estandar(); break;
			}
		}
	} while (op!=char(27));
}

main(){
	menu();
}
