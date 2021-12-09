# include <stdio.h>
# include <conio.h>

int a,r;
float j;
int *p, *q;

main(){
	a=10;
	p=new int;
	*p=a;
	q=&a;
	printf("El valor de a es : %d\n",*p);
	printf("Cual sera el valor de p?? : %d\n",p);
	
	printf("El valor de a es : %d\n",*p);
	printf("El valor a en el apuntador q = %d\n",*q);
	r=*p+*q;
	printf("r=%d\n",r);
	getche();
	delete p;
}
