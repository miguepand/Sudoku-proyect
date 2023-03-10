#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int ValidarNumero(char numero[],int PermiteNegativo);
int ValidarEntero(int PermiteNegativo,int ExisteRango, int min,int max,int *n);
int ValidarNegativo( char validar[], int PermiteNegativo );
int ValidarSaludo(char saludo[1000]);
void gotoxy(int x,int y);
int menu(const char *title, const char *opciones[], int n);
int menu2(const char *title, const char *opciones[], int n,int tipo);
void mostrar_tablero(int tipo);