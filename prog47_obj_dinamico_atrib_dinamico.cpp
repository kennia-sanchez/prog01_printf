#include <stdio.h>
#include <conio.h>

class Ejemplo{
	public:
		int *a;
	public:
		void muestra(){
			printf("el valor del atributo a es  : %d\n",*a);
			printf("La direcci�n del atributo a : %d\n",a);
		}
};

main(){
	int x;
	Ejemplo *obj=new Ejemplo;
	obj->a=new int;
	printf("La direccion de memoria del objeto (obj) es: %d\n",obj);
	obj->muestra();
	*(obj->a)=10;
	printf("El valor de el atributo dinamico a es : %d\n",*(obj->a));
	x=*(obj->a);
	printf("El valor de x es     : %d\n",x);
	printf("La direccion de x es : %d\n",&x);
	obj->muestra();
	getche();
}
/*
Se puede tener la combinaci�n de:
	Atributo est�tico Objeto Est�tico (normal de clases)
	Atributo din�mico Objeto est�tico
	Atributo est�tico Objeto din�mico
	Atributo din�mico Objeto din�mico
*/









