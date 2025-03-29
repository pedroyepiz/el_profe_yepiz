#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
//   13 marzo 2025    se agrego tal funcion y se modifico  ...
char *my_gets(char *cadena, int tamano);
int validar(int ri, int rf,const char *msge);


//   AQUI IRIA EL MAIN PERO  EN LOS PROGRAMAS EN LAS LIBRERIAS NO...

char *my_gets(char *cadena, int tamano)
{
  size_t longitud;
  fflush(stdin); //  limpiar buffer
  fgets(cadena, tamano, stdin);
  if (cadena)
  {
    // Eliminar el salto de línea (\Bn) si existe y sustituirlo por el  caracter nulo
    longitud = strlen(cadena);
    if (longitud > 0)
    {
      if (cadena[longitud - 1] == '\n')
      {
        cadena[longitud - 1] = '\0';
      }
    }
    return cadena;
  }
  return NULL; // En caso de error
}

//****************************
int validar(int ri, int rf,const char *msge)
{
  int num;
  char strnum[30];
  do
  {
    printf("%s ENTRE EL %d y %d: ",msge,ri,rf);
    my_gets(strnum,30);
    num = atoi(strnum);
    if (num < ri || num > rf)
    {
      printf ("NO SABES LEER? \n");
    }
  } while (num < ri || num > rf);
  return num;
}



