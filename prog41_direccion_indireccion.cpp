# include <stdio.h>
# include <conio.h>

int a,b;
int *ap_a, *ap_b;

main(){
	ap_a=&a;
	ap_b=&b;
	a=10;
	b=20;
	
	printf("La direcci%cn de a es : %d\n",162,ap_a);
	printf("La direcci%cn de b es : %d\n",162,ap_b);
	
	printf("Se obtiene los valores a traves de la direcci%cn, OPERADOR DE DIRECCION\n",162);
	printf("El valor de a, desde la memoria es : %d\n",*ap_a);
	printf("El valor de b, desde la memoria es : %d\n",*ap_b);
	printf("\n\n");
	printf("Se obtiene los valores a partir del nombre de la variable, OPERADOR DE INDIRECCION\n");
	printf("El valor de a es : %d\n",a);
	printf("El valor de b es : %d\n",b);
	getche();
}

