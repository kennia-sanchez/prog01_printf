// Computadoras
// Capacidad Disco Duro
// Capacidad de RAM
// Procesador y velocidad
// Monitor
// Precio

# include <stdio.h>
# include <conio.h>
# include <String.h>

class Computadora{
	public:
		char dd[21], ram[21], vel[21], mon[21];
		int precio;

	public:
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
	Computadora m1;
	strcpy(m1.dd,"500 Gb");
	strcpy(m1.ram,"8 Gb");
	strcpy(m1.vel,"Core i3 1.8 GHz");
	strcpy(m1.mon,"14p No touch");
	m1.precio=14000;
	m1.muestra();

	Computadora m2;
	strcpy(m2.dd,"250 Gb");
	strcpy(m2.ram,"8 Gb");
	strcpy(m2.vel,"Core i5 2.2 GHz");
	strcpy(m2.mon,"14p No touch");
	m2.precio=17000;
	m2.muestra();
}
