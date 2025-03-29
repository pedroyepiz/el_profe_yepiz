//  PEDRO NUÑEZ YEPIZ
//  PROGRAMA EN C QUE UTILIZA CADENAS Y  UNA FUNCION PARA LEER CADENAS  SIRVE COMO EJEMPLO
//  PARA LA IMPLEMENTACION EN LO SIGUIENTES EJERCICIOS QUE SE USEN CADENAS

//***************************************************************************************
//    LIBRERIAS
//**************************************************************************************

#include "henry.h"

//****************************************************************
/// Constantes
//***************
#define TAM 50

//****************************************************************************
// PROTOTIPOS DE FUNCIONES
//****************************************************************************

int msges();
void menu();
void llenar_vector(int vect[], int m);
void imprimir_vector(int vect[], int m);
void llena_matriz(int mat[][4], int m);
void imprime_matriz(int mat[][4], int m);
void vector_cadenas(char vect_str[][30], int m);
void imprimir_cadenas(char vect_str[][30], int m);

//****************************************************************************
// MAIN PRINCIPAL  ...  funcion principal
//****************************************************************************

int main()
{
  srand(time(NULL));  //SEMILLA 

  menu();
  return 0;
}

//****************************************************************************
// desarrollo de las funciones en el mismo orden de como listamos los prototipos
//****************************************************************************

// ************ FUNCION PARA LEER CADENAS USANDO fgets  y poner el nulo*******
// Función personalizada para leer cadenas de forma segura

//************************************************
int msges()
{
  int op;
  system("CLS");
  printf("   M  E   N   U \n");
  printf("1.- LLENA VECTOR \n");
  printf("2.- IMPRIMIR VECTOR \n");
  printf("3.- \n");
  printf("4.- \n");
  printf("5.- \n");
  printf("6.- \n");
  printf("0.- SALIR  \n");
  printf("ESCOGE UNA OPCION: ");
  scanf("%d", &op);
  return op;
}
//****************
void menu()
{
  int vect[10];
  int band= 0;
  int op;
  do
  {
    op = msges();
    switch (op)
    {
    case 1:
      llenar_vector(vect, 10);
      band = 1;
      break;
    case 2:
      if (band)
      {
           imprimir_vector(vect,10);
        }
      else
      {
          system ("CLS");
          printf ("LLENA EL VECTOR PRIMERO");
          system ("PAUSE");
      }
      break;
    case 3:
      
      break;
    case 4:
      
      break;
    case 5:
      
      break;
       case 6:
      
      break;
    }

  } while (op != 0);
}

// llenar vector numeros aleatorios

void llenar_vector(int vect[], int m)
{
  int num,rango;
    rango = (40-10)+1;
    for (int i=0; i < m; i++)
    {
        num = (rand()%rango)+10;

        vect[i]= num;
    }

}

//IMPRIMIR VECTOR

void imprimir_vector(int vect[], int m)
{
  
    system ("CLS");
    for (int i=0; i < m; i++)
    {
        
      printf(" %d --> [ %d ] \n",i,vect[i]);
        
    }
    system ("PAUSE");

}

















