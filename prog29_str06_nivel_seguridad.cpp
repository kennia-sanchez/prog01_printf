# include <stdio.h>
# include <conio.h>
# include <String.h>

char contra[16];
int x,nivel;

void pide_contra(){
	char letra;
	do {
		printf("Indica la contrase%ca : ",164);
		for (int i=0;i<=14;i++){
			letra=getch();
			if (letra==char(13)){
				contra[i]='\0';
				break;
			}
			else{
				printf("*");
				contra[i]=letra;
			}
		}
		// Verifica el tamano de la contrasena
		printf("\n");
		x=strlen(contra);
		if ((x<5) || (x>15)){
			printf("Error, la contrase%ca debe tener entre 5 y 15 caracteres ...\n",164);
			getche();
		}
	} while ((x<5) || (x>15));
}

main(){
	char letra;
	pide_contra();
	
	int nivel=0;
	bool sw_min, sw_may, sw_num, sw_otr;
	sw_min=false; sw_may=false; sw_num=false; sw_otr=false;
	for(int i=0;i<strlen(contra);i++){
		letra=contra[i];
		if ((letra>='a') && (letra<='z')) sw_min=true;
		if ((letra>='A') && (letra<='Z')) sw_may=true;
		if ((letra>='0') && (letra<='9')) sw_num=true;
		if (!((letra>='a') && (letra<='z')) && !((letra>='A') && (letra<='Z')) && !((letra>='0') && (letra<='9'))){
			sw_otr=true;
		}
	}
	// printf("%d  %d  %d  %d",sw_min, sw_may, sw_num, sw_otr);
	
	if ((sw_min) && (!sw_may) && (!sw_num) && (!sw_otr)) nivel=1;
	if ((sw_min) && (sw_may) && (!sw_num) && (!sw_otr)) nivel=2;
	if ((sw_min) && (!sw_may) && (sw_num) && (!sw_otr)) nivel=3;
	if ((!sw_min) && (sw_may) && (sw_num) && (!sw_otr)) nivel=3;
	if ((sw_min) && (sw_may) && (sw_num) && (!sw_otr)) nivel=4;
	if ((sw_min) && (sw_may) && (sw_num) && (sw_otr)) nivel=5;
	
	printf("El nivel de seguridad de tu contrase%ca es : %d\n",164,nivel);
	getche();
}
