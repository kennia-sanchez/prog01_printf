// Base 10,000
// 1,000 por auto vendido
// Si vende de 11 a 19, entonces 5,000
// Si vende 20 o más entonces otros 5,000

// 7 Autos = 10,000 + 7,000 = 17,000
// 17 Autos = 10,000 + 17,000 + 5,000 = 32,000
// 27 Autos = 10,000 + 27,000 + 5,000 + 5,000 = 47,000

# include <stdio.h>
# include <conio.h>

int cpv, c11, c20, av, sal_tot;

main(){
	printf("Indique la cantidad de autos vendidos : "); scanf("%d",&av);
	sal_tot=10000;
	sal_tot=sal_tot+(av*1000);
	if ((av>=11) && (av<=19)){
		sal_tot=sal_tot+5000;
	}
	if (av>=20){
		sal_tot=sal_tot+10000;
	}
	
	printf("El salario total a pagar es : %d",sal_tot);
	getche();
}
