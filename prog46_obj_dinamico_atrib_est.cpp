#include <stdio.h>
#include <conio.h>

class Ejemplo{
	public:
		int a,b,c;
	public:
		void muestra(){
			printf("El valor de a es: %d\n",a);
			printf("El valor de b es: %d\n",b);
			printf("El valor de c es: %d\n",c);
			getche();
		}
};

main(){
	Ejemplo *obj=new Ejemplo;
	printf("La dirección de memoria es : %d\n",obj);
	obj->a=1;
	obj->b=2;
	//obj->c=3;
	obj->muestra();
}
