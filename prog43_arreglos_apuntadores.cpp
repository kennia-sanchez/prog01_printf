# include <stdio.h>
# include <conio.h>

int ar[10];
int *ap_ar;

main(){
	for (int i=0;i<9;i++) ar[i]=i*100;
	ap_ar=new int[10];
	*ap_ar=ar[2];
	printf("El apuntador del arreglo vale : %d\n",ap_ar);
	printf("Valor posicion 1 : %d\n",*ap_ar);
	getche();
}
