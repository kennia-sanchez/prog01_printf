# include <stdio.h>
# include <conio.h>

int ma, mb, mc;
float m2p, flo, cto, vta, ut;
main(){
	printf("Indica la cantidad de tinacos del modelo A : "); scanf("%d",&ma);
	printf("Indica la cantidad de tinacos del modelo B : "); scanf("%d",&mb);
	printf("Indica la cantidad de tinacos del modelo C : "); scanf("%d",&mc);
	
	m2p=(ma*10)+(mb*15)+(mc*20);
	flo=ma+mb+mc;
	cto=(m2p*50)+(flo*20)+(ma*25)+(mb*35)+(mc*45);
	vta=(ma*760)+(mb*1130)+(mc*1490);
	ut=vta-cto;
	
	printf("****************************************************\n");
	printf("Se requieren %8.2f metros cuadrados de pl%cstico\n",m2p,160);
	printf("Se requieren %8.2f flotadores\n",flo);
	printf("Se requieren %8d tapas de 1.0 metro\n",ma);
	printf("Se requieren %8d tapas de 1.5 metros\n",mb);
	printf("Se requieren %8d tapas de 2.0 metros\n",mc);
	printf("****************************************************\n");
	printf("El costo total del material es  : $ %8.2f pesos\n",cto);
	printf("La venta total del pedido es    : $ %8.2f pesos\n",vta);
	printf("****************************************************\n");
	printf("La utilidad total del pedido es : $ %8.2f pesos\n",ut);
	printf("****************************************************\n");
	getche();
}
