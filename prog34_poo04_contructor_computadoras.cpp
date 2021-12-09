# include <stdio.h>
# include <conio.h>
# include <String.h>

class Computadora{
	public:
		char dd[21], ram[21], vel[21], mon[21];
		int precio;

	public:
		Computadora(){
			strcpy(dd,"500 Gb");
			strcpy(ram,"8 Gb");
			strcpy(vel,"Core i3 1.8 GHz");
			strcpy(mon,"14P NO TOUCH");
			precio=14000;
		}
		void muestra(){
			printf("*********************************************\n");
			printf("Disco Duro        : %s\n",dd);
			printf("Memoria RAM       : %s\n",ram);
			printf("Procesador y Vel. : %s\n",vel);
			printf("Monitor           : %s\n",mon);
			printf("Precio            : %d\n",precio);
			printf("*********************************************\n");
			getche();
		}
};

main(){
	Computadora m1, m2, m3;
	m1.muestra();

	strcpy(m2.vel,"Core i5 2.2 GHz");
	m2.precio=17000;
	m2.muestra();
	
	strcpy(m3.vel,"Core i5 2.2 GHz");
	strcpy(m3.ram,"12 Gb");
	m3.precio=18500;
	m3.muestra();
	
}
