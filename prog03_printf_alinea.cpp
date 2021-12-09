# include <stdio.h>
# include <conio.h>

int a,b,c,d,f;
float aa,bb,cc,dd,ff;

main(){
	a=10;
	b=1532;
	c=12135;
	d=1;
	f=23;
	printf("Alineando enteros\n");
	printf("%5d\n",a);
	printf("%5d\n",b);
	printf("%5d\n",c);
	printf("%5d\n",d);
	printf("%5d\n",f);
	printf("******************************\n");
	printf("Alineando flotantes\n");
	aa=10.2532;
	bb=1532.1;
	cc=12135.65987814;
	dd=1.14163225;
	ff=23.65;
	printf("%14.8f\n",aa); //%8.2f  XXXXX.XX
	printf("%14.8f\n",bb);
	printf("%14.8f\n",cc);
	printf("%14.8f\n",dd);
	printf("%14.8f\n",ff);
	getche();
}
