# include <stdio.h>
# include <conio.h>
# include <String.h>

int x;
float y;
char z[100];
int a;

main(){
	x=10;
	y=125.3;
	strcpy(z,"Hola");
	a=20;
	printf("x=%d\n",x);
	printf("La direcci%cn de almacenamiento de X es : %d\n",162,&x);
	printf("y=%f\n",y);
	printf("La direcci%cn de almacenamiento de y es : %d\n",162,&y);
	printf("z=%s\n",z);
	printf("La direcci%cn de almacenamiento de z es : %d\n",162,&z);
	printf("a=%d\n",a);
	printf("La direcci%cn de almacenamiento de a es : %d\n",162,&a);
	getche();
}
