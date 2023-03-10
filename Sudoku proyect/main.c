#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "ValideInput.h"


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

int cant_zonas;

typedef struct{
	int n;
	int pista;	
} hola ; 

typedef struct{
	int x;
	int y;
	int disponible;
}region;

region zona14x4[4] = { {0,0}, {0,1} , {1,0},{1,1}};
region zona24x4[4] = { {0,2}, {0,3} , {1,2},{1,3}};
region zona34x4[4] = { {2,0}, {2,1} , {3,0},{3,1}};
region zona44x4[4] = { {2,2}, {2,3} , {3,2},{3,3}};
hola tablero4x4[4][4];
hola tablero9x9[9][9];
void inicializardisponibilidaddecombinacionen0(int nposibilidades, region *ayuda);
//void generar_sudoku_valido(int tipo);

void inicializar_tablero(int tipo);
void mostrar_tablero(int tipo);
int revcolumna( int numero, int fila,int columna, int tipo);
int revfila(int numero, int fila,int columna, int tipo);
void rellenar_azar4x4(int dificultad);
void recorrer_tablero(int *fila, int *columna, int tipo);
int repetir_zona(int tipo,int region, int numero);
int solucion_posible(int tipo);
void generar_sudoku_valido4x4(int zona, int row, int column, int n );
int tablero_lleno(int tipo);
void generarprimerazonaen4x4(int zona,int row, int column, int n);



void inicializardisponibilidaddecombinacionen0(int nposibilidades, region *ayuda){
	int i;
	
	for(i=0;i<nposibilidades;++i){
		ayuda[i].disponible=1;
	}
}
void generarprimerazonaen4x4(int zona,int row, int column,int n){
	
	int tablero_lleno_valido;
	int auxpos,auxnotpos;
	
	auxpos = rand () % 4;
	
	if(revfila(n,zona14x4[auxpos].x,zona14x4[auxpos].y,1) == 1){
		tablero_lleno_valido = 0;
	} else
		if(revcolumna(n,zona14x4[auxpos].x,zona14x4[auxpos].y,1) == 1){
			tablero_lleno_valido = 0;
		} else
			if(repetir_zona(1,zona,n) == 1){
				tablero_lleno_valido = 0;
				n = 1+rand()% +4;
			} else if(zona14x4[auxpos].disponible==0){
				tablero_lleno_valido = 0;
				}else
					tablero_lleno_valido = 1;					
			

	if(tablero_lleno_valido == 1){

		tablero4x4[zona14x4[auxpos].x][zona14x4[auxpos].y].n= n ;
		tablero4x4[zona14x4[auxpos].x][zona14x4[auxpos].y].pista= 1;	
		zona14x4[auxpos].disponible=0;	
		return;
	} else
		generarprimerazonaen4x4(zona,zona14x4[auxpos].x,zona14x4[auxpos].y,n);

}
void generarsegundazonaen4x4(int zona,int row, int column,int n){
	
	int tablero_lleno_valido;
	int auxpos,auxnotpos;
	
	auxpos = rand () % 4;
	
	if(revfila(n,zona24x4[auxpos].x,zona24x4[auxpos].y,1) == 1){
		tablero_lleno_valido = 0;
	} else
		if(revcolumna(n,zona24x4[auxpos].x,zona24x4[auxpos].y,1) == 1){
			tablero_lleno_valido = 0;
		} else
			if(repetir_zona(1,zona,n) == 1){
				tablero_lleno_valido = 0;
				n = 1+rand()% +4;
			} else if(zona24x4[auxpos].disponible==0){
				tablero_lleno_valido = 0;
				}else
					tablero_lleno_valido = 1;					
			

	if(tablero_lleno_valido == 1){
		tablero4x4[zona24x4[auxpos].x][zona24x4[auxpos].y].n= n ;
		tablero4x4[zona24x4[auxpos].x][zona24x4[auxpos].y].pista= 1;	
		zona24x4[auxpos].disponible=0;	
		return;
	} else
		generarsegundazonaen4x4(zona,zona24x4[auxpos].x,zona24x4[auxpos].y,n);

}

void generartercerazonaen4x4(int zona,int row, int column,int n){
	
	int tablero_lleno_valido;
	int auxpos,auxnotpos;

	auxpos = rand () % 4;
	
	if(revfila(n,zona34x4[auxpos].x,zona34x4[auxpos].y,1) == 1){
		tablero_lleno_valido = 0;
	} else
		if(revcolumna(n,zona34x4[auxpos].x,zona34x4[auxpos].y,1) == 1){
			tablero_lleno_valido = 0;
		} else
			if(repetir_zona(1,zona,n) == 1){
				tablero_lleno_valido = 0;
				n = 1+rand()% +4;
			} else if(zona34x4[auxpos].disponible==0){
				tablero_lleno_valido = 0;
				}else
					tablero_lleno_valido = 1;					
			

	if(tablero_lleno_valido == 1){
		tablero4x4[zona34x4[auxpos].x][zona34x4[auxpos].y].n= n ;
		tablero4x4[zona34x4[auxpos].x][zona34x4[auxpos].y].pista= 1;	
		zona34x4[auxpos].disponible=0;	
		return;
	} else
		generartercerazonaen4x4(zona,zona34x4[auxpos].x,zona34x4[auxpos].y,n);

}

void generarcuartazonaen4x4(int zona,int row, int column,int n){
	
	int tablero_lleno_valido;
	int auxpos,auxnotpos;

	auxpos = rand () % 4;
	
	if(revfila(n,zona44x4[auxpos].x,zona44x4[auxpos].y,1) == 1){
		tablero_lleno_valido = 0;
	} else
		if(revcolumna(n,zona44x4[auxpos].x,zona44x4[auxpos].y,1) == 1){
			tablero_lleno_valido = 0;
		} else
			if(repetir_zona(1,zona,n) == 1){
				tablero_lleno_valido = 0;
				n = 1+rand()% +4;
			} else if(zona44x4[auxpos].disponible==0){
				tablero_lleno_valido = 0;
				}else
					tablero_lleno_valido = 1;					
			

	if(tablero_lleno_valido == 1){
		tablero4x4[zona44x4[auxpos].x][zona44x4[auxpos].y].n= n ;
		tablero4x4[zona44x4[auxpos].x][zona44x4[auxpos].y].pista= 1;	
		zona44x4[auxpos].disponible=0;	
		return;
	} else
		generarcuartazonaen4x4(zona,zona44x4[auxpos].x,zona44x4[auxpos].y,n);

}

void generardemaszonas4x4(int zonarellenada)
{
	int i,j;
	switch(zonarellenada){
		
		case 1:
			/*===========================================
								ZONA 2 
			===========================================*/
			/*Igualando la primera columna de la zona 2:
				tablero4x4[0][2]=tablero4x4[1][0]
				tablero4x4[1][2]=tablero4x4[0][0]*/
				
			j=1;
			for(i=0;i<2;++i){
				tablero4x4[i][2] = tablero4x4[j][0];
				--j;
			}
			
			/*Igualando la segunda columna de la zona 2:
				tablero4x4[0][3]=tablero4x4[1][1]
				tablero4x4[1][3]=tablero4x4[0][1]*/
				
			j=1;
			for(i=0;i<2;++i){
				tablero4x4[i][3] = tablero4x4[j][1];
				--j;
			}

			/*===========================================
								ZONA 3 
			===========================================*/
			/*Igualando la primera columna de la zona 3:
				tablero4x4[2][0]=tablero4x4[0][1]
				tablero4x4[3][0]=tablero4x4[1][1]*/
				
			j=0;
			for(i=2;i<4;++i){
				tablero4x4[i][0] = tablero4x4[j][1];
				++j;
			}
			
			/*Igualando la segunda columna de la zona 3:
				tablero4x4[2][1]=tablero4x4[1][0]
				tablero4x4[3][1]=tablero4x4[0][0]*/
				
			j=1;
			for(i=2;i<4;++i){
				tablero4x4[i][1] = tablero4x4[j][0];
				--j;
			}
			/*===========================================
								ZONA 4
			===========================================*/
			/*Igualando la primera columna de la zona 4:
				tablero4x4[2][2]=tablero4x4[3][0]
				tablero4x4[3][2]=tablero4x4[2][0]*/
				
			j=3;
			for(i=2;i<4;++i){
				tablero4x4[i][2] = tablero4x4[j][0];
				--j;
			}
			
			/*Igualando la segunda columna de la zona 4:
				tablero4x4[2][3]=tablero4x4[3][1]
				tablero4x4[3][3]=tablero4x4[2][1]*/
				
			j=3;
			for(i=2;i<4;++i){
				tablero4x4[i][3] = tablero4x4[j][1];
				--j;
			}


			break;
			
		case 2:
			/*===========================================
								ZONA 1 
			===========================================*/
			/*Igualando la primera columna de la zona 1:
				tablero4x4[0][0]=tablero4x4[1][2]
				tablero4x4[1][0]=tablero4x4[0][2]*/
				
			j=1;
			for(i=0;i<2;++i){
				tablero4x4[i][0] = tablero4x4[j][2];
				--j;
			}
			
			/*Igualando la segunda columna de la zona 1:
				tablero4x4[0][1]=tablero4x4[1][3]
				tablero4x4[1][1]=tablero4x4[0][3]*/
				
			j=1;
			for(i=0;i<2;++i){
				tablero4x4[i][1] = tablero4x4[j][3];
				--j;
			}

			/*===========================================
								ZONA 3 
			===========================================*/
			/*Igualando la primera columna de la zona 3:
				tablero4x4[2][0]=tablero4x4[1][3]
				tablero4x4[3][0]=tablero4x4[0][3]*/
				
			j=1;
			for(i=2;i<4;++i){
				tablero4x4[i][0] = tablero4x4[j][3];
				--j;
			}
			
			/*Igualando la segunda columna de la zona 3:
				tablero4x4[2][1]=tablero4x4[0][2]
				tablero4x4[3][1]=tablero4x4[1][2]*/
				
			j=0;
			for(i=2;i<4;++i){
				tablero4x4[i][1] = tablero4x4[j][2];
				++j;
			}
			/*===========================================
								ZONA 4
			===========================================*/
			/*Igualando la primera columna de la zona 4:
				tablero4x4[2][2]=tablero4x4[3][0]
				tablero4x4[3][2]=tablero4x4[2][0]*/
				
			j=3;
			for(i=2;i<4;++i){
				tablero4x4[i][2] = tablero4x4[j][0];
				--j;
			}
			
			/*Igualando la segunda columna de la zona 4:
				tablero4x4[2][3]=tablero4x4[3][1]
				tablero4x4[3][3]=tablero4x4[2][1]*/
				
			j=3;
			for(i=2;i<4;++i){
				tablero4x4[i][3] = tablero4x4[j][1];
				--j;
			}			
			break;
			
		case 3:
			
			/*===========================================
								ZONA 1 
			===========================================*/
			/*Igualando la primera columna de la zona 1:
				tablero4x4[0][0]=tablero4x4[3][1]
				tablero4x4[1][0]=tablero4x4[2][1]*/
				
			j=3;
			for(i=0;i<2;++i){
				tablero4x4[i][0] = tablero4x4[j][1];
				--j;
			}
			
			/*Igualando la segunda columna de la zona 1:
				tablero4x4[0][1]=tablero4x4[2][0]
				tablero4x4[1][1]=tablero4x4[3][0]*/
				
			j=2;
			for(i=0;i<2;++i){
				tablero4x4[i][1] = tablero4x4[j][0];
				++j;
			}

			/*===========================================
								ZONA 2 
			===========================================*/
			/*Igualando la primera columna de la zona 3:
				tablero4x4[0][2]=tablero4x4[2][1]
				tablero4x4[1][2]=tablero4x4[3][1]*/
				
			j=2;
			for(i=0;i<2;++i){
				tablero4x4[i][2] = tablero4x4[j][1];
				++j;
			}
			
			/*Igualando la segunda columna de la zona 3:
				tablero4x4[0][3]=tablero4x4[3][0]
				tablero4x4[1][3]=tablero4x4[2][0]*/
				
			j=3;
			for(i=0;i<2;++i){
				tablero4x4[i][3] = tablero4x4[j][0];
				--j;
			}
			/*===========================================
								ZONA 4
			===========================================*/
			/*Igualando la primera columna de la zona 4:
				tablero4x4[2][2]=tablero4x4[3][0]
				tablero4x4[3][2]=tablero4x4[2][0]*/
				
			j=3;
			for(i=2;i<4;++i){
				tablero4x4[i][2] = tablero4x4[j][0];
				--j;
			}
			
			/*Igualando la segunda columna de la zona 4:
				tablero4x4[2][3]=tablero4x4[3][1]
				tablero4x4[3][3]=tablero4x4[2][1]*/
				
			j=3;
			for(i=2;i<4;++i){
				tablero4x4[i][3] = tablero4x4[j][1];
				--j;
			}						
			break;
			
		case 4:
			/*===========================================
								ZONA 3 
			===========================================*/
			/*Igualando la primera columna de la zona 3:
				tablero4x4[2][0]=tablero4x4[3][2]
				tablero4x4[3][0]=tablero4x4[2][2]*/
				
			j=3;
			for(i=2;i<4;++i){
				tablero4x4[i][0] = tablero4x4[j][2];
				--j;
			}
			
			/*Igualando la segunda columna de la zona 3:
				tablero4x4[2][1]=tablero4x4[3][3]
				tablero4x4[3][1]=tablero4x4[2][3]*/
				
			j=3;
			for(i=2;i<4;++i){
				tablero4x4[i][1] = tablero4x4[j][3];
				--j;
			}

			/*===========================================
								ZONA 1 
			===========================================*/
			/*Igualando la primera columna de la zona 1:
				tablero4x4[0][0]=tablero4x4[2][3]
				tablero4x4[1][0]=tablero4x4[3][3]*/
				
			j=2;
			for(i=0;i<2;++i){
				tablero4x4[i][0] = tablero4x4[j][3];
				++j;
			}
			
			/*Igualando la segunda columna de la zona 1:
				tablero4x4[0][1]=tablero4x4[3][2]
				tablero4x4[1][1]=tablero4x4[2][2]*/
				
			j=3;
			for(i=0;i<2;++i){
				tablero4x4[i][1] = tablero4x4[j][2];
				--j;
			}
			/*===========================================
								ZONA 2
			===========================================*/
			/*Igualando la primera columna de la zona 2:
				tablero4x4[0][2]=tablero4x4[1][0]
				tablero4x4[1][2]=tablero4x4[0][0]*/
				
			j=1;
			for(i=0;i<2;++i){
				tablero4x4[i][2] = tablero4x4[j][0];
				--j;
			}
			
			/*Igualando la segunda columna de la zona 2:
				tablero4x4[0][3]=tablero4x4[1][1]
				tablero4x4[1][3]=tablero4x4[0][1]*/
				
			j=1;
			for(i=0;i<2;++i){
				tablero4x4[i][3] = tablero4x4[j][1];
				--j;
			}				
			break;
	}
}
/*============================================================
        name: inicializar_tablero
        Descripcion: inicializar la matriz del tablero en 0
        parametro: ninguno
==============================================================*/
void inicializar_tablero(int tipo){
	int i,j;
	if(tipo==1)
	{

	for(i = 0; i<4; ++i){
		for(j = 0; j <4 ; ++j){
			tablero4x4[i][j].n=0;
			tablero4x4[i][j].pista=0;
		}
	}
	} else
		{
			for(i = 0; i<9; ++i){
				for(j = 0; j <9 ; ++j){
					tablero9x9[i][j].n=0;
					tablero9x9[i][j].pista=0;
			}
		}
		}
}
/*============================================================
        name: mostrar_tablero 4x4 y 9x9 (
        Descripcion: imprime numeros y tablero
        parametro: 
        -tipo = 1 para 4x4 y 2 para 9x9
==============================================================*/

void mostrar_tablero(int tipo)
{
	int i,j;
	int x=70,y=3;
	
	if(tipo==1){
	
		for(i=0;i<4;++i){
			for(j=0;j<4;++j){
				
				gotoxy(x,y);
				//Imprime en verde los numeros que fueron pistas proporcionadas
				if(tablero4x4[i][j].pista==1){
					printf(verde);
				} else
					printf(blanco);

				printf("%1d",tablero4x4[i][j].n);			
				printf(blanco);
				
				//Al llegar a la columna 1 para imprimir espacio
				if(j==1){
					x+=2;
				} else
					x+=1;
			}
			
			//Al llegar a la fila 1 para imprimir espacio
			if(i==1){
				y+=2;
			} else
				y+=1;
				
			x=70;
		}
		
	} else{
			for(i=0;i<9;++i){
				for(j=0;j<9;++j){
					
					gotoxy(x,y);
					//Imprime en verde los numeros que fueron pistas proporcionadas
					if(tablero9x9[i][j].pista==1){
						printf(verde);
					} else
						printf(blanco);
						
					printf("%1d",tablero9x9[i][j].n);
					printf(blanco);
					
					//Al llegar a la 2da y 5ta columna se imprime un espacio	
					if(j==2 || j==5){
						x+=2;
					} else
						x+=1;
				}
				
				//Al llegar a la 2da y 5ta fila se imprime un espacio
				if(i==2 || i==5){
					y+=2;
				} else
					y+=1;
					
				x=70;
			}
		}
}

/*============================================================
        name: revcolumna
        Descripcion: busca en todas las columnas (excepto en la
        columna donde se encuentra el numero que se intenta
        ingresar) en la misma fila si hay coincidencias con el
        numero que se intenta ingresar.
        Parametros: 
		-numero --> numero que se intenta ingresar
		-fila --> fila donde se encuentra numero
		-columna --> columna donde se encuentra numero
		-tipo --> 1 para 4x4 y 2 para 9x9
==============================================================*/

int revcolumna( int numero, int fila,int columna, int tipo){
	int i,j,aux=0;
	
	if(tipo==1){
	
	for(i=0;i<4;++i){
		if( (tablero4x4[fila][i].n == numero) && (i!=columna) ){
			aux = 1;
		} else
			aux = 0;
			
		if(aux == 1) return 1;
	}
	} else{
			for(i=0;i<9;++i){
				if( (tablero9x9[fila][i].n == numero) && (i!=columna) ){
					aux = 1;
				} else
					aux = 0;
					
				if(aux == 1) return 1;
			}	
		}
	return 0;
}
/*============================================================
        name: revfila
        Descripcion: busca en todas las filas (excepto en la
        fila donde se encuentra el numero que se intenta
        ingresar) en la misma columna si hay coincidencias con el
        numero que se intenta ingresar.
        Parametros: 
		-numero --> numero que se intenta ingresar
		-fila --> fila donde se encuentra numero
		-columna --> columna donde se encuentra numero
		-tipo --> 1 para 4x4 y 2 para 9x9
==============================================================*/
int revfila(int numero, int fila,int columna, int tipo){
	int i,j,aux=0;
	
	if(tipo==1){
			for(i=0;i<4;++i){
				if( (tablero4x4[i][columna].n == numero) && (i!=fila) ){
					aux = 1;
				} else
					aux = 0;
					
				if(aux == 1) return 1;
			}
		} else{
			for(i=0;i<9;++i){
				if( (tablero9x9[i][columna].n == numero) && (i!=fila) ){
					aux = 1;
				} else
					aux = 0;
					
				if(aux == 1) return 1;
			}
		}

	
	return 0;
}

/*============================================================
        name function: repetir_zona
        Descripcion: Valida en cada zona 4x4 de la matriz tablero
        si el numero que se intenta ingresar ya existe previamente.
        Parameters:
        -tipo --> 1 para 4x4 y 2 para 9x9
		-region --> zona 4x4 evaluada 
		-numero --> numero que se intenta ingresar
==============================================================*/
int repetir_zona(int tipo,int region, int numero){
	int i,j;
	
	if(tipo==1){
		
		switch(region)
		{
			case 1:
				
				for(i=0;i<2;++i){
					for(j=0;j<2;++j){
							if(tablero4x4[i][j].n==numero) return 1;
					}
				}
				break;
				
			case 2:
				
				for(i=0;i<2;++i){
					for(j=2;j<4;++j){
						if(tablero4x4[i][j].n==numero) return 1;
					}
				}
				break;	
			case 3:
				
				for(i=2;i<4;++i){
					for(j=0;j<2;++j){
						if(tablero4x4[i][j].n==numero) return 1;
					}
				}
				break;			
				
			case 4:
				
				for(i=2;i<4;++i){
					for(j=2;j<4;++j){
						if(tablero4x4[i][j].n==numero) return 1;
					
					}
				}
				break;		
		}
	} else
		{
			switch(region)
			{
				case 1:
					
					for(i=0;i<3;++i){
						for(j=0;j<3;++j){
								if(tablero9x9[i][j].n==numero) return 1;
						}
					}
					break;
					
				case 2:
					
					for(i=0;i<3;++i){
						for(j=3;j<6;++j){
							if(tablero9x9[i][j].n==numero) return 1;
						}
					}
					break;	
				case 3:
					
					for(i=0;i<3;++i){
						for(j=6;j<9;++j){
							if(tablero9x9[i][j].n==numero) return 1;
						}
					}
					break;			
				case 4:
					
					for(i=3;i<6;++i){
						for(j=0;j<3;++j){
								if(tablero9x9[i][j].n==numero) return 1;
						}
					}
					break;
					
				case 5:
					
					for(i=3;i<6;++i){
						for(j=3;j<6;++j){
							if(tablero9x9[i][j].n==numero) return 1;
						}
					}
					break;	
				case 6:
					
					for(i=3;i<6;++i){
						for(j=6;j<9;++j){
							if(tablero9x9[i][j].n==numero) return 1;
						}
					}
					break;	
					
				case 7:
					
					for(i=6;i<9;++i){
						for(j=0;j<3;++j){
								if(tablero9x9[i][j].n==numero) return 1;
						}
					}
					break;
					
				case 8:
					
					for(i=6;i<9;++i){
						for(j=3;j<6;++j){
							if(tablero9x9[i][j].n==numero) return 1;
						}
					}
					break;	
					
				case 9:
					
					for(i=6;i<9;++i){
						for(j=6;j<9;++j){
							if(tablero9x9[i][j].n==numero) return 1;
						}
					}
					break;		
			}	
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
        	revcolumna();
        	revfila();
        
        Parameters:
			-dificultad --> nivel de dificultad escogido por parte del usuario
==============================================================*/
void rellenar_azar4x4(int dificultad)
{
	int cant_n,k,error=0;
	int fila_random, columna_random, auxfilar=7, auxcolumnar=7;
	int aux;
	int tipo = 1;
	int zona_actual=1;
	
	do{
		switch(dificultad){
			
			case 1:
				cant_n = 2;
				break;
				
			case 2:
				cant_n = 1 + rand() % 2;
				break;
				
			case 3:
				cant_n = 1;
				break;
		}
		
		for(k=0;k<cant_n;++k){
			
			do{
				aux = 1 + rand () % 4;
				
				switch(zona_actual){
					
					case 1:
						fila_random =   rand() % 2;
						columna_random =   rand() % 2;
						break;
						
					case 2:
						fila_random =  rand() % 2;
						columna_random = 2 + rand() % 2;
						break;
						
					case 3:
						fila_random =  2 + rand() % 2;
						columna_random = rand() % 2;
						break;
						
					case 4:
						fila_random =  2 + rand() % 2;
						columna_random = 2 + rand() % 2;
						break;
							
					}
					
					if((fila_random==auxfilar && columna_random==auxcolumnar)
					|| (revcolumna(aux,fila_random,columna_random,1) ==1)
					|| (revfila(aux,fila_random,columna_random,1) ==1)
					|| (repetir_zona(1,zona_actual,aux)==1)){
						error = 1;
					} else{
							error = 0;		
						}
							
			} while( error == 1 );
			
			tablero4x4[fila_random][columna_random].n= aux ;
			tablero4x4[fila_random][columna_random].pista= 1;
			auxfilar=fila_random;
			auxcolumnar=columna_random;
		}
		
		++zona_actual;
		
	} while(zona_actual<=4);
}

/*============================================================
        name function: rellenar_azar
        
        Descripcion: Rellena al azar la matriz con "pistas"
        para que el usuario pueda guiarse. Esto se realiza
        bajo las siguientes condiciones:
       		*No se repita el numero en la zona 9x9
        	*No se coloque el numero en una casilla donde
        	ya se encuentra un numero
        	*El numero no se repita en la fila, columna
        
        Estas condiciones son evaluadas con las siguientes 
        funciones:
        	repetir_zona();
        	revcolumna();
        	revfila();
        
        Parameters:
			-dificultad --> nivel de dificultad escogido por parte del usuario
==============================================================*/

void rellenar_azar9x9(int dificultad)
{
	int tipo = 2, zona_actual=1;
	int cant_n, aux, k,error=0;
	int fila_random, columna_random, auxfilar=10, auxcolumnar=10;
	
	do{
		switch(dificultad){
			
			case 1:
				
				cant_n = 3 + rand() % 3;
				break;
			case 2:
				
				cant_n = 2 + rand() % 2;
				break;
				
			case 3:
				
				cant_n = 2;
				break;
		}
		
		for(k=0;k<cant_n;++k){
			
			do{
				aux = 1 + rand () % 9;
				
				switch(zona_actual){
					
					case 1:
						
						fila_random =   rand() % 3;
						columna_random =   rand() % 3;
						break;
						
					case 2:
						
						fila_random =  rand() % 3;
						columna_random = 3 + rand() % 3;
						break;
						
					case 3:
						
						fila_random =  rand() % 3;
						columna_random = 6 + rand() % 3;
						break;
						
					case 4:
						
						fila_random =   3 + rand() % 3;
						columna_random =   rand() % 3;
						break;
						
					case 5:
						
						fila_random =  3 + rand() % 3;
						columna_random = 3 + rand() % 3;
						break;
						
					case 6:
						
						fila_random =  3 + rand() % 3;
						columna_random = 6 + rand() % 3;
						break;

					case 7:
						
						fila_random =   6 + rand() % 3;
						columna_random =   rand() % 3;
						break;
						
					case 8:
						
						fila_random =  6 + rand() % 3;
						columna_random = 3 + rand() % 3;
						break;
						
					case 9:
						
						fila_random =  6 + rand() % 3;
						columna_random = 6 + rand() % 3;
						break;
					}
					
					if((fila_random==auxfilar && columna_random==auxcolumnar)
					|| (revcolumna(aux,fila_random,columna_random,2) ==1)
					|| (revfila(aux,fila_random,columna_random,2) ==1)
					|| (repetir_zona(tipo,zona_actual,aux)==1)){
						error = 1;
					} else{
							error = 0;		
						}
							
			} while( error == 1 );
			
			tablero9x9[fila_random][columna_random].n= aux ;
			tablero9x9[fila_random][columna_random].pista= 1;
			auxfilar=fila_random;
			auxcolumnar=columna_random;
		}
		
		++zona_actual;
		
	} while(zona_actual<=9);
}

/*============================================================
        name function: tablero_lleno;
        
        Descripcion: Verifica si el tablero esta lleno
        
        Parameters:
			-tipo --> 1 para tablero 4x4, 2 para tablero 4x4
==============================================================*/

int tablero_lleno(int tipo)
{
	int i,j;
	int aux = 0;
	
	if(tipo==1){
	
		for(i = 0;i<4;++i){
			for(j=0;j<4;++j){
					if(tablero4x4[i][j].n!=0) aux+=1;
				}
		}
				
		if(aux>=16){
			return 1;
		} else
			return 0;
	} else{
		
			for(i = 0;i<9;++i){
				for(j=0;j<9;++j){
						if(tablero9x9[i][j].n!=0) aux+=1;
					}
			}
					
			if(aux>=16){
				return 1;
			} else
				return 0;
		}
	

}

/*============================================================
        name function: recorrer_tablero
        
        Descripcion: Permite al usuario recorrer la matriz del
		tablero del juego actual

        Parameters:
			*fila --> fila actual 
			*columna --> columna actual
			-tipo --> 1 para tablero 4x4 y 2 para tablero 9x9
==============================================================*/
void recorrer_tablero(int *fila, int *columna, int tipo){
	
	int selected = 0;
	int x=70,y=3;
	int tecla;
	
	mostrar_tablero(tipo);
	
	if(tipo==1){
		
		do{
			system("cls");
	
			mostrar_tablero(tipo);
			
			printf(azul);
			gotoxy(x,y);
			
			if(tablero4x4[*fila-1][*columna-1].n!=0){
				printf("%1d",tablero4x4[*fila-1][*columna-1].n);
			} else{
					printf("X");	
				}
			
			do{
				tecla = getch();
			} while(tecla!=TECLA_ARRIBA && tecla!=TECLA_IZQUIERDA && tecla!=TECLA_DERECHA 
			&& tecla!=TECLA_ABAJO && tecla!=ENTER);
			
			switch(tecla){
				case TECLA_ARRIBA:
					
					if(y!=6){
						--*fila;
						--y;			
					} else
						if(y==6){
							--*fila;
							y-=2;
						} 
						
						
					if(*fila<1){
						y=7;
						*fila=4;
					}
					break;
					
				case TECLA_ABAJO:
					
					if(y!=4){
						++*fila;
						++y;			
					} else
						if(y==4){
							++*fila;
							y+=2;
						} 
						
						if(*fila>4){
							y=3;
							*fila=1;
						}
		
					break;
					
				case TECLA_IZQUIERDA:
					
					if(x!=73){
						--*columna;
						--x;			
					} else
						if(x==73){
							--*columna;
							x-=2;
						}
						
					if(*columna<1){
						x=74;
						*columna=4;
					}
		
					break;
					
				case TECLA_DERECHA:
					
					if(x!=71){
						++*columna;
						++x;			
					} else
						if(x==71){
							++*columna;
							x+=2;
						} 
						
						
					if(*columna>4){
						x=70;
						*columna=1;
					}
					break;
					
				case ENTER:
					selected =1;
					break;
			}
			
			Sleep(50);
		} while (selected!=1);
		
	} else{
			do{
				system("cls");
		
				mostrar_tablero(tipo);
				
				printf(azul);
				gotoxy(x,y);
				
				if(tablero9x9[*fila-1][*columna-1].n!=0){
					printf("%1d",tablero9x9[*fila-1][*columna-1].n);
				} else{
						printf("X");	
					}
									
					do
					{
						tecla = getch();
					} while(tecla!=TECLA_ARRIBA && tecla!=TECLA_IZQUIERDA && tecla!=TECLA_DERECHA 
					&& tecla!=TECLA_ABAJO && tecla!=ENTER);
			
				switch(tecla){
					case TECLA_ARRIBA:
						
						if(y!=11 && y!=7){
							--*fila;
							--y;			
						} else
							if(y==11 || y==7){
								--*fila;
								y-=2;
							}
							
						if(*fila<1){
							y=13;
							*fila=9;
						}
						
						break;
						
					case TECLA_ABAJO:
						
						if(y!=5 && y!=9){
							++*fila;
							++y;			
						} else
							if(y==5 || y==9){
								++*fila;
								y+=2;
							}
							
						if(*fila>9){
							y=3;
							*fila=1;
						}
						
						break;
						
					case TECLA_IZQUIERDA:
						
						if(x!=78 && x!=74){
							--*columna;
							--x;			
						} else
							if(x==78 || x==74){
								--*columna;
								x-=2;
							}
							
						if(*columna<1){
							x=80;
							*columna=9;
						}
			
						break;
						
					case TECLA_DERECHA:
						
						if(x!=72 && x!=76){
							++*columna;
							++x;			
						} else
							if(x==72 || x==76){
								++*columna;
								x+=2;
							}
							
						if(*columna>9){
							x=70;
							*columna=1;
						}
			
						break;
						
					case ENTER:
						selected =1;
						break;
				}
					
				Sleep(0);
		} while (selected!=1);
	}
	printf(blanco);
	
}
int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	int i,j,auxfila=7,auxcolumna=7;
	int r1=1, r2=1,n,tipo=1;
	int op,op2,op3,aux=0,auxnumero, zona_random,error,nposibilidades;
	int  valido;
	int level=4;
	int tipo_sudoku,cantnporzona, auxcantnporzona=1;
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
	
	const char *title4 = "MENU DE DIFICULTAD";
	const char *options4[] = {"NIVEL FACIL", "NIVEL NORMAL", 
	"NIVEL DIFICIL"};
	int n4=3;
	
	const char *title5 = "MENU DE TIPO DE SUDOKU";
	const char *options5[] = {"SUDOKU 4X4", "SUDOKU 9X9"};
	int n5=2;
	
	
/*	switch(tipo){
		case 1:
			nposibilidades= cantnporzona=4;
			zona_random = 1 + rand() %4;
			break;
		case 2:
			zona_random = 1 + rand() %9;
			nposibilidades=cantnporzona=9;
			break;
	}
	
	if(tipo==1){
	auxcantnporzona=1;
	switch(zona_random){
		
		case 1:
			printf("\nZONA 1\n");
			inicializardisponibilidaddecombinacionen0(nposibilidades, zona14x4);
			do{
				generarprimerazonaen4x4(1,rand() % 2,rand () % 2,1 + rand () % 4);
				++auxcantnporzona;	
			} while (auxcantnporzona<=cantnporzona);
				generardemaszonas4x4(zona_random);
		break;
		
		case 2:
			printf("\nZONA 2\n");
			inicializardisponibilidaddecombinacionen0(nposibilidades, zona24x4);
			do{
				generarsegundazonaen4x4(2,rand() % 2,rand () % 2,1 + rand () % 4);
				++auxcantnporzona;	
			} while (auxcantnporzona<=cantnporzona);
			generardemaszonas4x4(zona_random);
		break;
		case 3:
			printf("\nZONA 3\n");
			inicializardisponibilidaddecombinacionen0(nposibilidades, zona34x4);
			do{
				generartercerazonaen4x4(3,rand() % 2,rand () % 2,1 + rand () % 4);
				++auxcantnporzona;	
			} while (auxcantnporzona<=cantnporzona);
			generardemaszonas4x4(zona_random);
		break;
		
		case 4:
			printf("\nZONA 4\n");
			inicializardisponibilidaddecombinacionen0(nposibilidades, zona44x4);
			do{
				generarcuartazonaen4x4(4,rand() % 2,rand () % 2,1 + rand () % 4);
				++auxcantnporzona;	
			} while (auxcantnporzona<=cantnporzona);
			generardemaszonas4x4(zona_random);
		break;
		
	}
	}
		system("pause");
	system("cls");
	mostrar_tablero(1);
	
	system("pause");
	system("cls");*/
	//INICION ciclo do-while MENU PRINCIPAL	
	do{
		
		system("cls");
		
		op = menu(title1,options1,n1);
		
		system("cls");
		
		switch(op){
			case 1:
				printf("\n\nAun no disponible.\n\n");
				printf("\n\n");
				system("pause");
				break;
				
			case 2:
				
				aux=0;
				for(i = 0;i<4;++i){
					for(j=0;j<4;++j){
						if(tablero4x4[i][j].n==0) aux+=1;
					}
				}
				
				tipo_sudoku = menu(title5,options5,n5);
				
				if(aux>=16)
				{
					if(level == 4) level = menu(title4,options4,n4);
					
					if(tipo_sudoku == 1){
						rellenar_azar4x4(level);
						tipo=1;
					} else
						if(tipo_sudoku == 2){
							rellenar_azar9x9(level);
							tipo=2;
						}	
				}
				
	switch(tipo){
		case 1:
			nposibilidades= cantnporzona=4;
			zona_random = 1 + rand() %4;
			break;
		case 2:
			zona_random = 1 + rand() %9;
			nposibilidades=cantnporzona=9;
			break;
	}
	
	if(tipo==1){
	auxcantnporzona=1;
	switch(zona_random){
		
		case 1:
			printf("\nZONA 1\n");
			inicializardisponibilidaddecombinacionen0(nposibilidades, zona14x4);
			do{
				generarprimerazonaen4x4(1,rand() % 2,rand () % 2,1 + rand () % 4);
				++auxcantnporzona;	
			} while (auxcantnporzona<=cantnporzona);
				generardemaszonas4x4(zona_random);
		break;
		
		case 2:
			printf("\nZONA 2\n");
			inicializardisponibilidaddecombinacionen0(nposibilidades, zona24x4);
			do{
				generarsegundazonaen4x4(2,rand() % 2,rand () % 2,1 + rand () % 4);
				++auxcantnporzona;	
			} while (auxcantnporzona<=cantnporzona);
			generardemaszonas4x4(zona_random);
		break;
		case 3:
			printf("\nZONA 3\n");
			inicializardisponibilidaddecombinacionen0(nposibilidades, zona34x4);
			do{
				generartercerazonaen4x4(3,rand() % 2,rand () % 2,1 + rand () % 4);
				++auxcantnporzona;	
			} while (auxcantnporzona<=cantnporzona);
			generardemaszonas4x4(zona_random);
		break;
		
		case 4:
			printf("\nZONA 4\n");
			inicializardisponibilidaddecombinacionen0(nposibilidades, zona44x4);
			do{
				generarcuartazonaen4x4(4,rand() % 2,rand () % 2,1 + rand () % 4);
				++auxcantnporzona;	
			} while (auxcantnporzona<=cantnporzona);
			generardemaszonas4x4(zona_random);
		break;
		
	}
	}
				
				
				mostrar_tablero(tipo);
				
				
				menujugar:
				
				//INICIO ciclo do-while MENU JUGAR		
				do{
						
					r1=r2=1;
					system("cls");
					mostrar_tablero(tipo);
				
					op2 = menu2(title2,options2,n2,tipo);
					
					system("cls");
					mostrar_tablero(tipo);
					//mostrar_tablero4x4();
					
					switch(op2)
					{
						case 1:
							
							system("cls");
							recorrer_tablero(&r1, &r2,tipo);
							
							if(tipo==1){
															
								if(tablero4x4[r1-1][r2-1].n!=0){
									printf(rojo);
									printf("\n\t\aERROR - Ya esa casilla posee un numero.");
									printf("\n\t");
									printf(blanco);
									system("pause");
									goto menujugar;
								}
								
								do
								{
									system("cls");
									mostrar_tablero(tipo);
									printf("\nDigite el numero (1-4) que quiere ");
									printf("ingresar en la casilla (%d,%d): ",r1,r2);
									valido = ValidarEntero(0,1,1,4,&auxnumero);
								} while (valido==0);
							} else
								{
									if(tablero9x9[r1-1][r2-1].n!=0){
										printf(rojo);
										printf("\n\t\aERROR - Ya esa casilla posee un numero.");
										printf("\n\t");
										printf(blanco);
										system("pause");
										goto menujugar;
									}	
									do
									{
										system("cls");
										mostrar_tablero(tipo);
										printf("\nDigite el numero (1-9) que quiere ");
										printf("ingresar en la casilla (%d,%d): ",r1,r2);
										valido = ValidarEntero(0,1,1,9,&auxnumero);
									} while (valido==0);									
								}
							system("cls");
							

		
							if(tipo==1){
								tablero4x4[r1-1][r2-1].n = auxnumero;
							} else
								tablero9x9[r1-1][r2-1].n = auxnumero;
							
							break;
						
						case 2:
							
							system("cls");
							mostrar_tablero(tipo);
							recorrer_tablero(&r1, &r2,tipo);
							
							if(tipo==1){
							
								if(tablero4x4[r1-1][r2-1].n==0){
									printf(rojo);
									printf("\n\t\aERROR - la casilla esta vacia. ",r1,r2);
									printf("\n\tVuelva a intentar.\n\t");
									printf(blanco);
									system("pause");
								} else
									if(tablero4x4[r1-1][r2-1].pista==1)
									{
										printf(rojo);
										printf("\n\t\aERROR - la casilla posee una pista ",r1,r2);
										printf("proporcionada. ");
										printf("\n\tVuelva a intentar.\n\t");
										printf(blanco);
										system("pause");
									} else
										tablero4x4[r1-1][r2-1].n=0;
							} else{
								
									if(tablero9x9[r1-1][r2-1].n==0){
										printf(rojo);
										printf("\n\t\aERROR - la casilla esta vacia. ",r1,r2);
										printf("\n\tVuelva a intentar.\n\t");
										printf(blanco);
										system("pause");
									} else
										if(tablero9x9[r1-1][r2-1].pista==1)
										{
											printf(rojo);
											printf("\n\t\aERROR - la casilla posee una pista ",r1,r2);
											printf("proporcionada. ");
											printf("\n\tVuelva a intentar.\n\t");
											printf(blanco);
											system("pause");
										} else
											tablero9x9[r1-1][r2-1].n=0;
								}
							break;
								
						case 3:
							
							menurecomenzar:
								
							//INICIO ciclo do-while MENU PARA RECOMENZAR EL JUEGO	
							do{
								
								system("cls");
								op3 = menu2(title3,options3,n3,tipo);
								
								system("cls");
								
								switch(op3){
									
									case 1:
										
										if(tipo==1){
										
											for(i = 0;i<4;++i){
												for(j=0;j<4;++j){
													if(tablero4x4[i][j].pista==0) tablero4x4[i][j].n=0;
												}
											}
										} else{
											for(i = 0;i<9;++i){
												for(j=0;j<9;++j){
													if(tablero9x9[i][j].pista==0) tablero9x9[i][j].n=0;
												}
											}
										}
										mostrar_tablero(tipo);
										printf(verde);
										printf("\n\tTablero tactual reseteado.");
										printf("\n\t");
										printf(blanco);
										system("pause");
										break;
										
									case 2:
										
										level = menu(title4,options4,n4);
										inicializar_tablero(tipo);
										rellenar_azar4x4(level);
										system("cls");
										mostrar_tablero(tipo);
										printf(verde);
										printf("\n\tTablero totalmente nuevo generado.");
										printf("\n\t");
										printf(blanco);
										system("pause");
										break;
								}
								
							} while(op3!=3); //FIN ciclo do-while MENU PARA RECOMENZAR EL JUEGO	
							break;
							
						case 4:
							
							if(tablero_lleno(tipo)==0){
								printf(rojo);
								printf("\n\tEl tablero debe estar lleno para comprobar");
								printf(" si todo esta correcto");
		
								
							} else
								{
									error = 0;
									if(tipo == 1){
									
										for(i=0;i<4;++i){
											for(j=0;j<4;++j){
												
												if(revfila(tablero4x4[i][j].n,i,j,tipo)==1 
												&& tablero4x4[i][j].pista==0){
													error+=1;
												}
												
												if(revcolumna(tablero4x4[i][j].n,i,j,tipo)==1 
												&& tablero4x4[i][j].pista==0){
													error+=1;
												}
											}
										}
									} else{
											for(i=0;i<9;++i){
												for(j=0;j<9;++j){
													
													if(revfila(tablero9x9[i][j].n,i,j,tipo)==1 
													&& tablero9x9[i][j].pista==0){
														error+=1;
													}
													
													if(revcolumna(tablero9x9[i][j].n,i,j,tipo)==1 
													&& tablero9x9[i][j].pista==0){
														error+=1;
													}
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
							break;
					}
					
				} while (op2!=5); //FIN ciclo do-while menu para jugar	
				
			case 3:
				printf("\n\nGracias por jugar.\n\n");
				break;
		}
		
	} while (op!=3);//FIN ciclo do-while MENU PRINCIPAL
	
	return 0;
	
}
