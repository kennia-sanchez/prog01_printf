# include <stdio.h>
# include <conio.h>

int bic, lla, fre, mar, asi, vta_tot, dto_por;
float dto_pesos, vta_final;

main(){
	printf("Indica la cantidad de bicicletas vendidas : "); scanf("%d",&bic);
	printf("Indica la cantidad de llantas    vendidas : "); scanf("%d",&lla);
	printf("Indica la cantidad de frenos     vendidos : "); scanf("%d",&fre);
	printf("Indica la cantidad de marcos     vendidos : "); scanf("%d",&mar);
	printf("Indica la cantidad de asientos   vendidos : "); scanf("%d",&asi);
	
	vta_tot=(bic*1200)+(lla*250)+(fre*150)+(mar*600)+(asi*200);
	
	if (vta_tot<1000){
		dto_por=0;
	}
	if ((vta_tot>=1000) && (vta_tot<3000)){
		dto_por=10;
	}
	if ((vta_tot>=3000) && (vta_tot<6000)){
		dto_por=15;
	}
	if (vta_tot>=6000){
		dto_por=20;
	}

	dto_pesos=(vta_tot*dto_por)/100;
	vta_final=vta_tot-dto_pesos;
	
	printf("*****************************************************\n");
	printf("La venta total del pedido es  : $ %5d\n",vta_tot);
	printf("El descuento en porcentaje es :   %5d %c\n",dto_por,37);
	printf("El descuento en pesos es      : $ %8.2f\n",dto_pesos);
	printf("*****************************************************\n");
	printf("La venta final es             : $ %8.2f\n",vta_final);
	printf("*****************************************************\n");
	getche();
}

// 1 lla, 1 fre , 1 asi = 600
// 1 Bic, 1 lla, 1 fre, 1 asi 1200+250+150+200=1800
// 2 Bic, 1 lla, 1 fre, 1 mar 1 asi,  2400+250+150+600+200=3600
// 3 Bic, 1 lla, 1 fre, 3 mar 1 asi,  3600+250+150+1800+200=6000
