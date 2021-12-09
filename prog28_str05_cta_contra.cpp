# include <stdio.h>
# include <conio.h>
# include <String.h>

char cta[16], contra[16];
int x;

void pide_cuenta(){
	do{
		printf("Indica la cuenta     : ");
		gets(cta);
		x=strlen(cta);
		if ((x<5) || (x>15)){
			printf("Error, la cuenta debe tener entre 5 y 15 caracteres ...\n");
			getche();
		}
	} while ((x<5) || (x>15));
}

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
		printf("\n");
		x=strlen(contra);
		if ((x<5) || (x>15)){
			printf("Error, la contrase%ca debe tener entre 5 y 15 caracteres ...\n",164);
			getche();
		}
	} while ((x<5) || (x>15));
}

main(){
	do{
		pide_cuenta();
		pide_contra();
		x=strcmp(cta,"A00517129");
		if (x!=0){
			printf("Error, cuenta incorrecta ...\n");
			getche();
		}
		else{
			x=strcmp(contra,"100300");
			if (x!=0){
				printf("Error, contrase%ca incorrecta ...\n",164);
				getche();
			}
			else{
				printf("Accesos Permitido !!!\n");
				getche();
				break;
			}
		}
	} while (true);
}
