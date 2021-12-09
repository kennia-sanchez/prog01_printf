# include <stdio.h>
# include <conio.h>

int pide_x(){
	int x;
	printf("Indica el valor de X : "); scanf("%d",&x);
	return(x);
}

int pide_y(){
	int y;
	printf("Indica el valor de Y : "); scanf("%d",&y);
	return(y);
}

void suma(){
	int r;
	r=pide_x()+pide_y();
	printf("La suma es : %d\n",r);
	getche();
}

void division(){
	float r, x, y;
	x=pide_x();
	do{
		y=pide_y();
		if (y==0){
			printf("Error, no existe la divisi%cn entre CERO ...\n",162);
			getche();
		}
	} while (y==0);
	r=x/y;
	printf("La divisi%cn es : %.2f",162,r);
	getche();
}

void factorial(){
	int f, n;
	n=pide_x();
	f=1;
	for (int i=1;i<=n;i++) f=f*i;
	printf("El factorial es : %d\n",f);
	getche();
}

void menu(){ // Void es para las funciones que no regresan valor
	int op;
	do{
		printf("1)Suma\n");
		printf("2)Resta\n");
		printf("3)Multiplicaci%cn\n",162);
		printf("4)Divisi%cn\n",162);
		printf("5)Potencia\n");
		printf("6)Factorial\n");
		printf("7)Primo o no primo\n");
		printf("8)Terminar\n");
		printf("Indica la opci%cn deseada : ",162); scanf("%d",&op);
		if ((op<1) || (op>8)){
			printf("Error, opci%cn fuera de rango entre 1 y 8 ...\n",162);
			getche();
		}
		else{
			switch(op){
				case 1: suma(); break;
				case 4: division(); break;
				case 6: factorial(); break;
			}
		}
	} while(op!=8);
}

main(){
	menu();
}
