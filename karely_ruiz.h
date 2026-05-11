//  propietario :  PEDRO NUÑEZ YEPIZ
// FECHA.  13 DE MARZO 2026 ULTIMA MODF: 20 MARZO  
//  V 1.1
// AGREGO.  FUNCION my_fgets  y my_int
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dos.h>
#define N 15
#define N2 20
#define SALTO printf("\n");
// DEFINICION DE TIPOS DE DATOS
typedef struct _nom{
  char nombre[30];
  char appat[30];
  char apmat[30];
}Ts_nom;
//****
typedef struct _talum{
  int status; //0.INACTIVO   1  ACTIVO
  int matri; // pk   campo llave
  Ts_nom nombre;
  int edad; 
  int sexo; //1.  M  o 2.- H  
}Ts_alum;

//PROTOTIPOS
void my_fgets(char string[],int tam);
int my_int(int ri, int rf, const char msge[]);
int busq_sec(Ts_alum vect[],int m, int num);
void burbuja_seleccion (Ts_alum vect[],int m);

/*
AQUI IRIA EL MAIN SI FUERA UN PROGRAMA PERO
ESTA ES UNA LIBRERIA POR ESO
DEBE ESTAR DESACTIVADO O 
NO SE PONE...

int main ()
{
	
}
*/
//DESARROLLO DE LAS FUNCIONES EN EL MISMO ORDEN
//QUE LOS PROTOTIPOS
//*******************************************************
//my_fgets  ES UNA FUNCION QUE SIRVE PARA LEE L CADESN
//EN LAS VERSIONES MAS NUEVAS DE C,  Y QUETA EL SALTO DEL RENGLO
//Y LO SUSTITUYE POR EL CARACTER NULO
//********************************************************
void my_fgets(char string[],int tam)
{
  int i=0 ;
  fflush(stdin);
  fgets(string,tam,stdin);
  while (string[i] != '\0')
  {
    i++;
  }
  string[i-1]='\0';
}
//*********************************************************
  //  FUNCION QUE SIRVE PARA VALIDAR UN MNUMERO ENTERO,
//*****************************************************
int my_int(int ri, int rf, const char msge[])
{
  int num;
  char my_num[30];
  do{
    printf ("%s",msge);
    my_fgets(my_num,30);
    num = atoi(my_num);
  }while(num < ri || num > rf);
  
  return num;  // REGRESA  EL VALOR YA VALIDADO
}

//********
int busq_sec(Ts_alum vect[],int m, int num)
{
    for (int i = 0;i < m;i++)
    {
        if (num == vect[i].matri)
        {
          if (vect[i].status != 0)
          {     
            return i; // si lo encontro y esta activo
          }
          else
          {
            return -2;  //  si lo encontro pero status es 0
          }
        }
    }
    return -1; // no lo encontro
}

//****
void burbuja_seleccion (Ts_alum vect[],int m)
{
    int i,j;
    Ts_alum temp;
    for (i = 0; i < m-1; i++)
    {
      for(j= i+1;j<m;j++)
      {
          if (vect[j].matri < vect[i].matri)
          {
              temp = vect[j];
              vect[j]=vect[i];
              vect[i]=temp;
          }
      }
    }


}