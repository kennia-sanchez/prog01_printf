# include <stdio.h>
# include <conio.h>

int ar[10];

void pide_valores(){
	for (int i=0;i<=9;i++){
		printf("Indica el valor de la posici%cn [%d] : ",162,i);
		scanf("%d",&ar[i]);
		if ((ar[i]<1) || (ar[i]>1000)){
			printf("Error, valor fuera de rango entre 1 y 1000 ...\n");
			getche();
			i--;
		}
	}
}

void promedio(){
	float sum, prom;
	sum=0;
	for (int i=0;i<=9;i++) sum=sum+ar[i];
	prom=sum/10;
	printf("El promedio de los valores es : %.2f",prom);
	getche();
}

void menu(){
	char op;
	do{
		printf("a) Promedio\n");
		printf("b) N%cmero mayor\n",163);
		printf("c) N%cmero menor\n",163);
		printf("d) Lista en secuencia\n");
		printf("e) Lista Inversa\n");
		printf("f) Valor por posici%cn\n",162);
		printf("g) Terminar\n");
		printf("Indica la opci%cn deseada : ",162);
		op=getche(); printf("\n");
		if ((op<'a') || (op>'g')){
			printf("Error, opci%cn fuera de rango entre -a- y -g- ...\n");
			getche();
		}
		else{
			switch (op){
				case 'a': promedio(); break;
			}
		}
	} while (op!='g');
}

main(){
	pide_valores();
	menu();
}
