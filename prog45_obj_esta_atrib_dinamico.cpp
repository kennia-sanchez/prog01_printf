#include <stdio.h>
#include <conio.h>

class Ejemplo{
	public:
		int *a;
	public:
		void muestra(){
			printf("La direccion dememoria es : %d\n",a);
			printf("El valor almacenado es    : %d\n",*a);
			getche();
		}
};

main(){
	Ejemplo obj;
	obj.a=new int;
	*(obj.a)=120;
	obj.muestra();
	// int *a;
	// *a=120;
}
