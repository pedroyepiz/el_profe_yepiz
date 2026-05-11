#include "karely_ruiz.h"
//*** PROTOTIPOS DE FUNCIONES  ******

int msges();
void menu();
Ts_alum add_reg ();
void buscar (Ts_alum vec_reg[], int m);
void imprimir(Ts_alum v[], int m);
Ts_alum add_aut();
void imp_reg(Ts_alum reg);
void eliminar (Ts_alum vec_reg[], int m);
void crea_arch(const char nombre[],Ts_alum v[], int m);
void  lee_arch(const char nombre[]);

//****  main principal  *********
int main()
{
   srand(time(NULL));
   menu();

	return 0;
}
//  *** DESARROLLO DE LAS FUNCIONES  ******
//*********************
int msges()
{ int op;
  system ("CLS");
  printf ("   M  E   N   U \n");
  printf("1.- AGREGAR REGISTO (MANUAL) \n");
  printf("2.- AGREGAR REGISTRO (AUTOM) \n");
  printf("3.- IMPRIMIR TODO  \n");
  printf("4.- BUSCAR  \n");
  printf("5.- ORDENAR \n");
  printf("6.- ELIMINAR \n");
  printf("7.- CREA ARCHIVO \n");
  printf("8.- LEE ARCHIVO \n");
  printf("20.- SALIR  \n");
  op = my_int(1,20,"ESCOGE UNA OPCION: ");
  return op;
}
//****************
void menu()
{
  Ts_alum reg, vec_reg[1000];
  char nombre[30];
  int vect[N]; //DECLARAR EL VECTOR QUE SE UTILZARA EN TODO EL PROGRAMA
  int i,j,op;
  i=0;
  do{
      op=msges();
      switch (op)
      {
        case 1:
              for (j = 0; j< 10 ; j++)
              {
                vec_reg[i]=add_reg();
                i++;
              }
              break;
        case 2:
           for (j = 0; j< 10 ; j++)
              {
               
                  vec_reg[i]=add_aut();
                  i++;
               }
              break;
        case 3:
               imprimir(vec_reg,i);
               break;
        case 4:
              buscar(vec_reg,i);
              break;
         case 5:
              burbuja_seleccion(vec_reg,i);
              break;      
          case 6:
              eliminar (vec_reg,i);
              break; 
          case 7:
              system("CLS");
              printf ("DAME EL NOMBRE DEL ARCHIVO CON TODO Y EXTENSION ");
              my_fgets(nombre,30);
              crea_arch (nombre,vec_reg,i ); 
              break;
          case 8:
              system("CLS");
              printf ("DAME EL NOMBRE DEL ARCHIVO CON TODO Y EXTENSION ");
              my_fgets(nombre,30);
              lee_arch (nombre); 
              break; 
          
      }

    }while (op != 20);


}

//*********************
Ts_alum add_reg ()
{
  Ts_alum reg;
   reg.status = 1;
   
   reg.matri = my_int(300000,399999, "MATRICULA");
   printf ("NOMBRE : ");
   my_fgets(reg.nombre.nombre,30);
   printf ("APELLIDO PATERNO: ");
   my_fgets(reg.nombre.appat,30);
   printf ("APELLIDO MATERNO: ");
   my_fgets(reg.nombre.apmat,30);
   reg.edad=my_int(15,75,"EDAD: ");
   reg.sexo = my_int(1,2,"SEXO: 1.- HOMBRE  2.- MUJER ");
   return reg;
}

//*************************
void imp_vect (int vect[],int m)
{
    system ("CLS");
    for (int i=0;i<m;i++)
    {
        printf(" %3d  ----> [ %3d ]\n",i,vect[i]);
    }
    system ("PAUSE");
    
}
//****************************
void buscar (Ts_alum vec_reg[], int m)
{
    int num,pos;
    system ("CLS");
    num = my_int(300000,399000,"QUE MATRICULA BUSCAS? ");
    pos = busq_sec(vec_reg,m,num);
    if (pos == -1)
    {
      printf ("%d REGISTRO NO EXISTE \n",num);
    }
    else
    {
      if (pos == -2)
      {
          printf ("REGISTRO DADO DE BAJA");
      }
      else
      {
         imp_reg(vec_reg [pos]);
       }
    }
    system ("PAUSE");

}

//****************************


//****


//*******************************
void imprimir(Ts_alum v[], int m)
{
  char sex[10];
  system("CLS");
  printf("No  Matricula    Nombre     Ap_Pat       Ap_mat    edad   sexo\n");
  for(int i=0; i<m ;i++)
  {
    if (v[i].status == 1)
    {
      if (v[i].sexo == 1)
      {
        strcpy(sex,"HOMBRE");
      }
      else
      {
        strcpy(sex,"MUJER");
      }
      printf("%3d %7d %-15s %-15s %-15s %4d %-6s\n",i,v[i].matri,v[i].nombre.nombre,
                           v[i].nombre.appat, v[i].nombre.apmat,v[i].edad,sex);
   }
  }

  system("pause");
}



Ts_alum add_aut()
{
  char apell[30][15]={"HERNANDEZ","GARCIA","MARTINEZ","LOPEZ","GONZALEZ","PEREZ","RODRIGUEZ","SANCHEZ","RAMIREZ","CRUZ","FLORES","GOMEZ","MORALES","VAZQUEZ","REYES","JIMENEZ","TORRES","DIAZ","GUTIERREZ","RUIZ","MENDOZA","AGUILAR","ORTIZ","MORENO","CASTILLO","ROMERO","ALVAREZ","CHAVEZ","RIVERA","JUAREZ"};
  char nom_hom[20][15]={"JUAN","JOSE","ANTONIO","ALEJANDRO","DAVID","CARLOS","LUIS","MIGUEL","ANGEL","FERNANDO","DANIEL","JAVIER","DIEGO","ANDRES","SERGIO","RAUL","EDUARDO","RICARDO","MARIO","ALBERTO"};
  char nom_muj[20][15]={"SOFIA","VALENTINA","CAMILA","MARIA","GUADALUPE","ANA","LAURA","ANDREA","DANIELA","PAULA","ELENA","ROSA","PATRICIA","LUCIA","FERNANDA","CAROLINA","MONICA","GABRIELA","ISABEL","ALEJANDRA"};
  Ts_alum reg;
  reg.status = 1;
  reg.matri = (rand()%20000)+350000;
  strcpy(reg.nombre.appat,apell[rand()%30]);
  strcpy(reg.nombre.apmat,apell[rand()%30]);
  reg.sexo=(rand()%2) + 1;
  reg.edad =(rand()%60) + 15;
  if (reg.sexo== 1)
  {
    strcpy(reg.nombre.nombre,nom_hom[rand()%20]);
  }
  else
  {
    strcpy(reg.nombre.nombre,nom_muj[rand()%20]);
  }
  return reg;
}

//**********************************

void imp_reg(Ts_alum reg)
{

  system ("CLS");
  printf ("DATOS DEL ALUMNO\n\n");
  printf ("MATRICULA        : %d\n",reg.matri);
  printf ("APELLIDO PATERNO : %s\n",reg.nombre.appat);
  printf ("APELLIDO MATERNO : %s\n",reg.nombre.apmat);
  printf ("NOMBRE           : %s\n",reg.nombre.nombre);
  printf ("EDAD             : %d\n",reg.edad);
  if (reg.sexo == 1)
  {
    printf ("SEXO             : HOMBRE\n");
  }
  else
  {
    printf ("SEXO             : MUJER\n");
  }  
 
  
}

//****************************
void eliminar (Ts_alum vec_reg[], int m)
{
    int num,pos,resp;
    system ("CLS");
    num = my_int(300000,399000,"QUE MATRICULA QUIERES ELIMINAR? ");
    pos = busq_sec(vec_reg,m,num);
    if (pos == -1)
    {
      printf ("%d NO EXISTE EL AMUMNO \n",num);
    }
    else
    {
      imp_reg(vec_reg [pos]);
      printf ("QUIERES ELIMINAR EL REGISTRO\n");
      resp =my_int (1,2,"1.- SI     2.- NO");
      if (resp == 1 )
      {
          vec_reg [pos].status  = 0;
      }
      
    }
    system ("PAUSE");

}

//*******
void crea_arch(const char nombre[],Ts_alum v[], int m)
{

   FILE *arch;
   arch = fopen(nombre,"w");
   if (arch)
   {
     //***  esta parte que se modifica para sdar una salida a un 
    // archivo de texto////
      char sex[10];
      fprintf(arch,"No  Matricula    Nombre     Ap_Pat       Ap_mat    edad   sexo\n");
      for(int i=0; i<m ;i++)
      {
        if (v[i].status == 1)
        {
          if (v[i].sexo == 1)
          {
            strcpy(sex,"HOMBRE");
          }
        else
        {
          strcpy(sex,"MUJER");
        }
        fprintf(arch,"%3d %7d %-15s %-15s %-15s %4d %-6s\n",i,v[i].matri,v[i].nombre.nombre,
                           v[i].nombre.appat, v[i].nombre.apmat,v[i].edad,sex);
   }
  }

     //**
     fclose(arch);
   }
   else
   {
    printf (" NO SE PUDO ABRIR EL ARCHIVO \n");
    system ("PAUSE");
   } 
}
//****
void  lee_arch(const char nombre[])
{
   char caracter;
   FILE *arch;
   arch = fopen(nombre,"r");
   if (arch)
   {
     
     while ( ! feof(arch) )
     {
        caracter=fgetc(arch);
        fprintf (stdout,"%c",caracter);
     }
     system ("PAUSE");
     
     
     fclose(arch);
   }
   else
   {
    printf (" NO SE PUDO ABRIR EL ARCHIVO \n");
    system ("PAUSE");
   } 
}
//*****






