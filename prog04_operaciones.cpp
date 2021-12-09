# include <stdio.h>
# include <conio.h>

float x,y,r;

main(){
	x=10;
	y=5;
	r=x+y;
	printf("La suma  de          %8.2f m%cs   %8.2f es: %8.2f\n",x,160,y,r);
	r=x-y;
	printf("La resta de          %8.2f menos %8.2f es: %8.2f\n",x,y,r);
	r=x*y;
	printf("La multiplicaci%cn de %8.2f por   %8.2f es: %8.2f\n",162,x,y,r);
	r=x/y;
	printf("La divisi%cn       de %8.2f entre %8.2f es: %8.2f\n",162,x,y,r);
	getche();
}
