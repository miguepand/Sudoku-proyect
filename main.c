#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include "ValideInput.h"
#include<ctype.h>

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define TECLA_DERECHA 77
#define TECLA_IZQUIERDA 75
#define ENTER 13

#define verde "\033[;32m"
#define blanco "\033[1;0;37m"
#define rojo "\033[37;31m"
#define cyan "\033[1;36m"
#define azul "\033[1;34m"
#define fazul_verde "\033[5;37;34m"

 struct hola{
	
	int n;
	int pista;
	
}tablero[4][4];

int i,j;

void inicializar_tablero();
void mostrar_tablero();
void rellenar_azar();
int cantnporregion();
int columna( int numero, int fila,int columna);
int fila( int numero, int fila,int columna);
void validarfilacolumna();

/*============================================================
        name: inicializar_tablero
        Descripcion: inicializar la matriz del tablero en 0
        parametro: ninguno
==============================================================*/
void inicializar_tablero(){
	for(i = 0; i<4; ++i){
		for(j = 0; j <4 ; ++j){
			tablero[i][j].n=0;
			tablero[i][j].pista=0;
	
		}
	}
}
/*============================================================
        name: mostrar_tablero
        Descripcion: imprime numeros y tablero
        parametro: ninguno
==============================================================*/

void mostrar_tablero()
{
	int x=70,y=3;
	/*==================================
	Ciclo para imprimir numeros y las 
	filas correspondientes, asi como las 
	columnas. Solo imprime las casillas
	con numeros validos
	==================================*/
	
	for(i=0;i<4;++i){
		for(j=0;j<4;++j){
			
			gotoxy(x,y);
			if(tablero[i][j].n!=0)
			{
				if(tablero[i][j].pista==1){
					printf(verde);
				} else
				printf(blanco);
					//printf(blanco);
				//gotoxy(basex +i, basey +j);
				printf("[%1d]",tablero[i][j].n);
			} else
				{
				//gotoxy(basex +i, basey +j);
				printf("[ ]");
				}
				
			printf(blanco);
			//printf(blanco);
			x+=5;
			}
			y+=2;
			x=70;
		
	}
	
	//gotoxy(0,0);
}

void mostrar_tableroREAL()
{
	/*==================================
	Ciclo para imprimir numeros y las 
	filas correspondientes, asi como las 
	columnas. Solo imprime las casillas
	con numeros validos
	==================================*/
	int basex = 1;
	int basey= 1;
	
	for(i=0;i<4;++i){
		for(j=0;j<4;++j){
			
			if(tablero[i][j].n!=0)
			{
				if(tablero[i][j].pista==1){
					//system("color 92");
					printf(verde);
				} else
					printf(blanco);
				//gotoxy(basex +i, basey +j);
				printf(" %1d ",tablero[i][j].n);
			} else
				{
				//gotoxy(basex +i, basey +j);
				printf("   ");
				}
				
			
			printf(blanco); //printf(blanco);

				if(j ==1) printf("|");
			}
		
		printf("\n");
		if(i==1) 
		       printf(" ----------\n");
		   }
}
/*=============================\n===============================
        name: columna
        Descripcion: busca en todas las columnas (excepto en la
        columna donde se encuentra el numero que se intenta
        ingresar) en la misma fila si hay coincidencias con el
        numero que se intenta ingresar.
        Parametros: 
		*numero --> numero que se intenta ingresar
		*fila --> fila donde se encuentra numero
		*columna --> columna donde se encuentra numero
==============================================================*/

int columna(int numero, int fila,int columna)
{
	int aux=0;
	
	for(i=0;i<3;++i)
	{
		if( (tablero[fila][i].n == numero) && (i!=columna) )
		{
			aux = 1;
		} else
			aux = 0;
			
		if(aux == 1) return 1;
	}
	
	return 0;
}
/*============================================================
        name: fila
        Descripcion: busca en todas las filas (excepto en la
        fila donde se encuentra el numero que se intenta
        ingresar) en la misma columna si hay coincidencias con el
        numero que se intenta ingresar.
        Parametros: 
		*numero --> numero que se intenta ingresar
		*fila --> fila donde se encuentra numero
		*columna --> columna donde se encuentra numero
==============================================================*/
int fila(int numero, int fila,int columna)
{
	int aux=0;
	
	for(i=0;i<3;++i)
	{
		if( (tablero[i][columna].n == numero) && (i!=fila) )
		{
			aux = 1;
		} else
			aux = 0;
			
		if(aux == 1) return 1;
	}
	
	return 0;
}

/*============================================================
        name function: repetir_zona
        Descripcion: Valida en cada zona 4x4 de la matriz tablero
        si el numero que se intenta ingresar ya existe previamente.
        Parameters:
		*region --> zona 4x4 evaluada 
		*numero --> numero que se intenta ingresar
==============================================================*/
int repetir_zona(int region, int numero)
{
	switch(region)
	{
		case 1:
			for(i=0;i<2;++i)
			{
				for(j=0;j<2;++j)
				{
					if(tablero[i][j].n==numero) return 1;
				}
			}
			break;
			
		case 2:
			for(i=0;i<2;++i)
			{
				for(j=2;j<4;++j)
				{
					if(tablero[i][j].n==numero) return 1;
				}
			}
			break;	
		case 3:
			for(i=2;i<4;++i)
			{
				for(j=0;j<2;++j)
				{
					if(tablero[i][j].n==numero) return 1;
				}
			}
			break;			
			
		case 4:
			for(i=2;i<4;++i)
			{
				for(j=2;j<4;++j)
				{
					if(tablero[i][j].n==numero) return 1;
				}
			}
			break;	
	}
	
	return 0;
	
}

/*============================================================
        name function: rellenar_azar
        
        Descripcion: Rellena al azar la matriz con "pistas"
        para que el usuario pueda guiarse. Esto se realiza
        bajo las siguientes condiciones:
       		*No se repita el numero en la zona 4x4
        	*No se coloque el numero en una casilla donde
        	ya se encuentra un numero
        	*El numero no se repita en la fila, columna
        
        Estas condiciones son evaluadas con las siguientes 
        funciones:
        	repetir_zona();
        	columna();
        	fila();
        
        Parameters:
			*region --> zona 4x4 evaluada 
			*numero --> numero que se intenta ingresar
==============================================================*/
void rellenar_azar()
{
	int cant_n;
	int fila_random;
	int columna_random;
	int n_random;
	int error=2;
	int auxfilar=7,auxcolumnar=7,aux=7;
	
	/* ========== Region 1 =========== */
	
	cant_n = 1 + rand() % 2;
	
	for(j=1;j<=cant_n;++j){
		
		fila_random =  rand() % 2;
		columna_random =  rand() % 2;
		aux = 1 + rand () % 4;
		
		while((fila_random==auxfilar && columna_random==auxcolumnar)
		|| (columna(aux,fila_random,columna_random) ==1)
		|| (fila(aux,fila_random,columna_random) ==1)
		|| (repetir_zona(1,aux)==1))
		{
			fila_random =  rand() % 2;
			columna_random =  rand() % 2;
			aux = 1 + rand () % 4;
		}
		
		tablero[fila_random][columna_random].n= aux ;
		tablero[fila_random][columna_random].pista= 1;
		auxfilar=fila_random;
		auxcolumnar=columna_random;
	}
	
	/* ========== Region 2 =========== */
	
	cant_n = 1 + rand() % 2;
	for(j=1;j<=cant_n;++j){
		
		fila_random =  rand() % 2;
		columna_random = 2 + rand() % 2;
		aux = 1 + rand () % 4;
		
		while((fila_random==auxfilar && columna_random==auxcolumnar)
		|| (columna(aux,fila_random,columna_random) ==1)
		|| (fila(aux,fila_random,columna_random) ==1)
		|| (repetir_zona(2,aux)==1))
		{
			fila_random =  rand() % 2;
			columna_random = 2 + rand() % 2;
			aux = 1 + rand () % 4;
		}
		
		tablero[fila_random][columna_random].n= aux ;
		tablero[fila_random][columna_random].pista= 1;
		auxfilar=fila_random;
		auxcolumnar=columna_random;
	}
	
	/* ========== Region 3 =========== */
	
	cant_n = 1 + rand() % 2;
	for(j=1;j<=cant_n;++j){
		
		fila_random =  2 + rand() % 2;
		columna_random = rand() % 2;
		aux = 1 + rand () % 4;
		
		while((fila_random==auxfilar && columna_random==auxcolumnar)
		|| (columna(
		aux,fila_random,columna_random) ==1)
		|| (fila(aux,fila_random,columna_random) ==1)
		|| (repetir_zona(3,aux)==1))
		{
			fila_random =  2 + rand() % 2;
			columna_random = rand() % 2;
			aux = 1 + rand () % 4;
		}
		
		tablero[fila_random][columna_random].n= aux ;
		tablero[fila_random][columna_random].pista= 1;
		auxfilar=fila_random;
		auxcolumnar=columna_random;
	}

	/* ========== Region 4 =========== */
	
	cant_n = 1 + rand() % 2;
	for(j=1;j<=cant_n;++j){
		
		fila_random =  2 + rand() % 2;
		columna_random = 2 + rand() % 2;
		aux = 1 + rand () % 4;
		
		while((fila_random==auxfilar && columna_random==auxcolumnar)
		|| (columna(aux,fila_random,columna_random) ==1)
		|| (fila(aux,fila_random,columna_random) ==1)
		|| (repetir_zona(4,aux)==1))
		{
			fila_random =  2 + rand() % 2;
			columna_random = 2 + rand() % 2;
			aux = 1 + rand () % 4;
		}
		
		tablero[fila_random][columna_random].n= aux ;
		tablero[fila_random][columna_random].pista= 1;
		auxfilar=fila_random;
		auxcolumnar=columna_random;
	}
}

int tablero_lleno()
{
	int aux = 0;
	for(i = 0;i<4;++i){
		for(j=0;j<4;++j){
				if(tablero[i][j].n!=0) aux+=1;
			}
	}
			
	if(aux>=16){
		return 1;
	} else
		return 0;
}
void recorrer_tablero(int *fila, int *columna){
	
	int selected = 0;
	int x=70,y=3,nrecorridos=0;
	/**fila=0;
	*columna=0;*/
	int tecla;
	mostrar_tablero();
	//gotoxy(x,y);
	do{
		system("cls");

		mostrar_tablero();
		
		gotoxy(x,y);
		printf(fazul_verde);
		if(tablero[*fila-1][*columna-1].n!=0)
		{
			//printf()
			printf("[%1d]",tablero[*fila-1][*columna-1].n);
		} else
			printf("[X]",tablero[*fila-1][*columna-1].n);
		
		printf(blanco);
		//printf(fazul_verde);
		//printf("[%1d]",tablero[*fila][*columna].n);
		
		do
		{
			tecla = getch();
		} while(tecla!=TECLA_ARRIBA && tecla!=TECLA_IZQUIERDA && tecla!=TECLA_DERECHA 
		
		&& tecla!=TECLA_ABAJO && tecla!=ENTER);
		

		switch(tecla)
		{
			case TECLA_ARRIBA:
				*fila=*fila-1;
				//--*fila;
				y-=2;
				if(*fila<1) 
				{
					y = 9;
					*fila=4;
				}
				break;
				
			case TECLA_ABAJO:
				*fila=*fila+1;
				//++*fila;
				y+=2;
				
				if(*fila>4)
				{
					y =3;
					*fila=1;
				 } 
				break;
				
			case TECLA_IZQUIERDA:
				*columna=*columna-1;
			//	--*columna;
				x-=5;
				if(*columna<1) 
				{
					x = 85;
					*columna=4;
				}
				break;
				
			case TECLA_DERECHA:
				*columna=*columna+1;
				x+=5;
				if(*columna>4) 
				{
					x = 70;
					*columna=1;	
				}
				break;
				
			case ENTER:
				selected =1;
		}
		
			
		++nrecorridos;
	} while (selected!=1);
	
	printf(blanco);
	
}
int main(int argc, char *argv[]) {
	
	printf(blanco);
	srand(time(NULL));
	int r1=1, r2=1,n;
	int op,op2,op3,aux=0,auxnumero,error;
	int  valido;
	
	const char *title1 = "MENU PRINCIPAL";
	const char *options1[] = {"INGRESAR JUGADOR", "JUGAR", "SALIR"};
	int n1=3;
	
	const char *title2 = "MENU PARA JUGAR";
	const char *options2[] = {"INGRESAR NUMERO", "BORRAR NUMERO", "RECOMENZAR JUEGO",
	"COMPROBAR SOLUCION","VOLVER AL MENU PRINCIPAL"};
	int n2=5;
	
		const char *title3 = "MENU RECOMENZAR JUEGO";
	const char *options3[] = {"RESETEAR ACTUAL TABLERO", "GENERAR NUEVO TABLERO", 
	"VOLVER AL MENU PARA JUGAR"};
	int n3=3;
	
	menuprincipal:
	
	do
	{
		
	system("cls");
	
	op = menu(title1,options1,n1);
	
	system("cls");
	
	switch(op)
	{
		case 1:
			printf("\n\nAun no disponible.\n\n");
			printf("\n\n");
			system("pause");
			break;
			
		case 2:
			
			aux=0;
			for(i = 0;i<4;++i){
				for(j=0;j<4;++j){
					if(tablero[i][j].n==0) aux+=1;
				}
			}
			
			if(aux>=16) rellenar_azar();
				
			mostrar_tablero();
			
			menujugar:
				r1=r2=1;
				system("cls");
				mostrar_tablero();
			
			op2 = menu2(title2,options2,n2);
			
			system("cls");
			mostrar_tablero(tablero);
			
			switch(op2)
			{
				case 1:
					system("cls");
					
					
					recorrer_tablero(&r1, &r2);
					//printf(blanco);
					//validarfilacolumna(&r1,&r2);
										
					if(tablero[r1-1][r2-1].n!=0){
						printf(rojo);
						printf("\n\t\aERROR - Ya esa casilla posee un numero.");
						printf("\n\tVuelva a ingresar otra vez.");
						printf("\n\t");
						printf(blanco);
						system("pause");
						goto menujugar;
					}
					
					system("cls");
				//	mostrar_tablero(tablero);
					
					do
					{
						system("cls");
						mostrar_tablero();
						printf("\nDigite el numero (1-4) que quiere ");
						printf("ingresar en la casilla(%d,%d): ",r1,r2);
						valido = ValidarEntero(0,1,1,4,&auxnumero);
					} while (valido==0);

					
					tablero[r1-1][r2-1].n = auxnumero;
				
					goto menujugar;
				
				case 2:
					
					system("cls");
					mostrar_tablero();
					recorrer_tablero(&r1, &r2);
					//validarfilacolumna(&r1,&r2);
			
					if(tablero[r1-1][r2-1].n==0){
						printf(rojo);
						printf("\n\t\aERROR - la casilla esta vacia. ",r1,r2);
						printf("\n\tVuelva a intentar.\n\t");
						printf(blanco);
						system("pause");
					} else
						if(tablero[r1-1][r2-1].pista==1)
						{
							printf(rojo);
							printf("\n\t\aERROR - la casilla posee una pista ",r1,r2);
							printf("proporcionada. ");
							printf("\n\tVuelva a intentar.\n\t");
							printf(blanco);
							system("pause");
						} else
							tablero[r1-1][r2-1].n=0;
					
					goto menujugar;
						
				case 3:
					
					menurecomenzar:
					system("cls");
					op3 = menu2(title3,options3,n3);
					
					system("cls");
					
					switch(op3){
						
						case 1:
							
							for(i = 0;i<4;++i){
								for(j=0;j<4;++j){
									if(tablero[i][j].pista==0) tablero[i][j].n=0;
								}
							}
							
							mostrar_tablero(tablero);
							printf(verde);
							printf("\n\tTablero tactual reseteado.");
							printf("\n\t");
							printf(blanco);
							system("pause");
							goto menurecomenzar;
							
						case 2:
							
							for(i = 0;i<4;++i){
								for(j=0;j<4;++j){
									tablero[i][j].n=0;
								}
							}
							
							rellenar_azar(tablero);
							mostrar_tablero(tablero);
							printf(verde);
							printf("\n\tTablero totalmente nuevo generado.");
							printf("\n\t");
							printf(blanco);
							system("pause");
							goto menurecomenzar;
							
						case 3:
							
							printf("\n\t");
							system("pause");
							goto menujugar;
					}
				
				case 4:
					
					if(tablero_lleno()==0){
						printf(rojo);
						printf("\n\tEl tablero debe estar lleno para comprobar");
						printf(" si todo esta correcto");

						
					} else
						{
							error = 0;
							for(i=0;i<4;++i){
								for(j=0;j<4;++j){
									
									if(fila(tablero[i][j].n,i,j)==1 
									&& tablero[i][j].pista==0){
										error+=1;
									}
									
									if(columna(tablero[i][j].n,i,j)==1 
									&& tablero[i][j].pista==0){
										error+=1;
									}
								}
							}
							
							if(error>0) 
							{
								printf(rojo);
								printf("\n\n\t\aDERROTA - se ha equivocado.");	
							} else
								{
									printf(verde);
									printf("\n\n\t\aVICTORIA - todo esta correcto!");
								}
								
							printf(blanco);
						}
	
					printf("\n\n\t");
					printf(blanco);
					system("pause");
					goto menujugar;
					
				case 5:
					goto menuprincipal;	
			}
			
		case 3:
			printf("\n\nGracias por jugar.\n\n");
			break;
	}
	
	} while (op!=3);
	
	return 0;
	
}