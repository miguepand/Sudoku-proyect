#include "ValideInput.h"
#include<conio.h>

#define rojo "\033[31m"
#define blanco "\033[1;37m"
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define TECLA_DERECHA 77
#define TECLA_IZQUIERDA 75
#define ENTER 13

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
 
/*========================================================================
        name function: ValidarNumero();
        
        Descripcion: Valida la entrada de datos. Especificamente es usada
        cuando solo se permite la entrada de numeros enteros (positivos y/o
		negativos).
        
        Parameters:
			-*numero --> Cadena de caracteres donde se guardo la entrada
			de datos 
			-PermiteNegativo --> 0 si no permite, 1 si lo permite.
========================================================================*/
int ValidarNumero(char numero[],int PermiteNegativo)
{
	int i,longitud;
	long int numerovalido1 ;

	longitud=strlen(numero);
	
	printf(rojo);
	for (i=0;i<longitud;++i)
	{
		if ( (!(isdigit(numero[i]))) && ( PermiteNegativo==1 && !((numero[i]=='-') && (i==0))) )
		{
			printf("\a\n\tERROR - ingrese solo numeros.");
			return 0;
		}
		
		if ( (!(isdigit(numero[i]))) && PermiteNegativo==0 )
		{
			printf("\a\n\tERROR - recuerde ingresar solamente numeros (enteros positivos).");
			return 0;
		}
		
		if(numero[i]==32)
		 {
		 	printf("\a\n\tERROR- no ingrese espacios en blanco.");
		 	return 0;
		 }
	}

	if (longitud>10) 
	{
		printf("\a\n\tERROR - cantidad de caracteres permitidos excedidos.\n\n\t");
		return 0;
	} else
		if(longitud<1)
		{
			printf("\a\n\tERROR - debe ingresar al menos un (1) digito.\n\n\t");
			return 0;
		}
	
	return 1;	
}

/*========================================================================
        name function: ValidarEntero();
        
        Descripcion: Recibe la entrada de datos y verifica si cumple
		las validaciones correspondientes de entrada de datos correcta y
		de numero del rango permitido, si existe. Si no cumple, repite.
        
        Parameters:
			-PermiteNegativo --> 0 si no permite, 1 si lo permite.
			-ExisteRango --> 0 si no existe, 1 si existe
			-min --> Rango minimo, en caso de existir
			-max --> Rango maximo, en caso de existir
			-*n --> numero
========================================================================*/
int ValidarEntero(int PermiteNegativo,int ExisteRango, int min,int max,int *n)
{
	int valido1, valido2;
	char entrada[15];

	memset(entrada,0,14); //Reseteamos memoria
	fflush(stdin); 		//Limpieza del buffer de entrada
	scanf("%13[^\n]",entrada);
	
	valido1 = ValidarNumero(entrada,PermiteNegativo);
	
	if(ExisteRango==1 && valido1!=0){
		*n = atoi (entrada);
		
		if(*n<min || *n>max)
		{
			valido2 = 0;
			printf(rojo);
			printf("\a\n\tERROR - Numero fuera del rango.");
			printf(" Rango aceptable esta entre %d-%d. Por favor, intentelo nuevamente.",min,max);
			printf(blanco);
		} else
			valido2 =1;
		
	}
	
	printf(blanco);
	if(valido1==0 || valido2==0){	
		printf("\n\t");
		system("pause");
		return 0;
	} else{
			return 1;
		}
}
/*========================================================================
        name function: ValidarNegativo();
        
        Descripcion: Valida la entrada de datos. Especificamente es usada
        cuando solo se permite la entrada de numeros reales (positivos y/o
		negativos).
        
        Parameters:
			-*valida --> Cadena de caracteres donde se guardo la entrada
			de datos 
			-PermiteNegativo --> 0 si no permite, 1 si lo permite.
========================================================================*/
int ValidarNegativo(char validar[], int PermiteNegativo)
{
	int j,cont=0,cont2=0;
	int longitud;
	
	longitud=strlen(validar);
	
	printf(rojo);
	for(j = 0; j < longitud; j++)
	{
		if(validar[0] =='.') {
			printf("\a\n\tERROR - no ingrese un punto al inicio.\n\n\t");
			return 0; 	
		}
		
		if ((validar[j] =='-') && (PermiteNegativo==0)) {
			printf("\a\n\tERROR - recuerde ingresar solamente numeros reales positivos.\n\n\t");
			return 0; 
		}	
		
		if(validar[j] =='.') cont++;
		if(validar[j] == '-') cont2++;
		
		if(cont > 1 || cont2 > 1){
			printf("\a\n\tERROR - recuerde ingresar solamente un (1) punto decimal.\n\n\t");
			return 0;	
		}
		 
		if(validar[j+1] == '-') return 0;
		if(validar[j] == '.' && !isdigit(validar[j+1])) return 0;
		if(validar[j] =='-' && !isdigit(validar[j+1])) return 0;
		
		if( validar[j]==32){
		 	printf("\a\n\tERROR- no ingrese espacios en blanco.\n\n\t");
		 	return 0;
		}
		
		if(!(isdigit(validar[j]) || ( (PermiteNegativo==1) && (validar[j]== '-' ))  || validar[j] == '.')){	
			printf("\a\n\tERROR - solo debe ingresar numeros reales.\n\n\t");
			return 0;
		} 				
	}
	
	if (longitud>11 ) {
		printf("\a\n\tERROR - cantidad de caracteres permitidos excedidos.\n\n\t");
		return 0;
	} else
		if(longitud==0){
			printf("\a\n\tERROR - debe ingresar al menos un (1) digito.\n\n\t");
			return 0;
		}
	
	return 1;
}



/*========================================================================
        name function: ValidarSaludo();
        
        Descripcion: Valida la entrada de datos. Especificamente es usada
        cuando solo se permite la entrada de caracteres.
        
        Parameters:
			*saludo --> Cadena de caracteres donde se guardo la entrada
			de datos 
========================================================================*/
int ValidarSaludo(char saludo[1000])
{
	int i;
	printf(rojo);
	
	for (i=0;i<strlen(saludo);++i) {
		if(!( (saludo[i]>=65 && saludo[i]<=90) || (saludo[i]>=97 && saludo[i]<=122) || saludo[i]==32 )){
			
			printf("\a\n\tERROR - ingresa solo letras (mayusculas y/o minusculas) y/o espacios.\n\n");
			return 0;
		}
	}

	return 1;
}


int menu(const char *title, const char *opciones[], int n){
	int selectedoption=1;
	int selected = 0;
	int tecla;
	int i;
	
	do{
		system("cls");
		
		gotoxy(5, 3 + selectedoption );	printf("-->");
		gotoxy(15,2); printf("%s",title);
		
		for( i = 0; i<n ; ++i){
			gotoxy(10, 4+i);
			printf("%s",opciones[i]);
		}
		
		do{
			tecla = getch();
		} while(tecla!=TECLA_ARRIBA && tecla!=TECLA_ABAJO && tecla!=ENTER);
		
	
		switch(tecla){
			case TECLA_ARRIBA:
				
				--selectedoption;
				if(selectedoption<1) selectedoption=n;
				break;
				
			case TECLA_ABAJO:
				
				++selectedoption;	
				if(selectedoption>n) selectedoption=1;	
				break;
				
			case ENTER:
				selected =1;
				break;
		}
		
		gotoxy(5, 4 + selectedoption );	printf("-->");
		} while( selected != 1);
	
	return selectedoption;
}

int menu2(const char *title, const char *opciones[], int n, int tipo){
	int selectedoption=1;
	int selected = 0;
	int tecla;
	int i;
	
	do{
		system("cls");
		printf("\n\n\n");
		mostrar_tablero(tipo);
	
		gotoxy(20, 3 + selectedoption );	printf("-->");
		gotoxy(25,2); printf("%s",title);
		
		for( i = 0; i<n ; ++i){
			gotoxy(25, 4+i);
			printf("%s",opciones[i]);
		}
		
		do{
			tecla = getch();
		} while(tecla!=TECLA_ARRIBA && tecla!=TECLA_ABAJO && tecla!=ENTER);
		
	
		switch(tecla){
			case TECLA_ARRIBA:
				
				--selectedoption;
				if(selectedoption<1) selectedoption=n;
				break;
				
			case TECLA_ABAJO:
				
				++selectedoption;	
				if(selectedoption>n) selectedoption=1;	
				break;
				
			case ENTER:

				printf("\n\npresiono enter");
				selected =1;
				break;
		}
		
		gotoxy(20, 4 + selectedoption );	printf("-->");
		
		} while( selected != 1);
		
	
	return selectedoption;
}