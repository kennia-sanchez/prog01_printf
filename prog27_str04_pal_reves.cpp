# include <stdio.h>
# include <conio.h>
# include <String.h>

char pal[21];
int x;

main(){
	x=0;
	while ((x<5) || (x>20)){
		printf("Indica la palabra : "); gets(pal);
		x=strlen(pal);
		if ((x<5) || (x>20)){
			printf("Error, la cadena debe tener entre 5 y 20 caracteres ...\n");
			getche();		}
	}
	
	// juanito strlen = 7
	// 0123456
	for(int i=strlen(pal)-1;i>=0;i--){
		printf("%c",pal[i]);
	}
	getche();
}
