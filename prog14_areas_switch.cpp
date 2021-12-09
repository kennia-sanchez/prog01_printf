# include <stdio.h>
# include <conio.h>

int op;

void cuadrado(){
	int L, area;
	printf("Indica la medida del lado : "); scanf("%d",&L);
	area=L*L;
	printf("El %crea del cuadrado es : %d",160,area);
}

void triangulo(){
	int b, h;
	float area;
	printf("Indica la medida de la base   : "); scanf("%d",&b);
	printf("Indica la medida de la altura : "); scanf("%d",&h);
	area=(b*h)/2;
	printf("El %crea del tri%cngulo es : %f",160,160,area);
}

void circulo(){
	int R;
	float area;
	printf("Indica la medida del radio : "); scanf("%d",&R);
	area=3.1416*R*R;
	printf("El %crea del c%crculo es : %f",160,161,area);
}

main(){
	printf("1) Cuadrado\n");
	printf("2) Tri%cngulo\n",160);
	printf("3) C%crculo\n",161);
	printf("Indica la opci%cn deseada : ",162);
	scanf("%d",&op);
	
	switch(op){
		case 1:cuadrado(); break;
		case 2:triangulo(); break;
		case 3:circulo(); break;
	}
	getche();
}
