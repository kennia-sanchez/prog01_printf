#include <stdio.h>
#include <conio.h>

// Objeto est�tico con atributes est�ticos

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
