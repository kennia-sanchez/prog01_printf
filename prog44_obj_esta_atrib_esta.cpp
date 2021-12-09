#include <stdio.h>
#include <conio.h>

// Objeto estático con atributes estáticos

class Ejemplo{
	public:
		int a;
	public:
		void muestra(){
			printf("El valor de a es : %d",a);
			getche();
		}
};

main(){
	Ejemplo obj;
	obj.a=125;
	obj.muestra();
}
