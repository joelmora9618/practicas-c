#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "funciones.h"
#include "biblioteca_J.c"

int main()
{
   int MAX = 30;
   FILE* file;
   int opcion;
   long int* dniAux;
   char continuar = 's';
   Persona* persona = malloc(MAX*sizeof(Persona));

   while(continuar == 's')
   {
       printf("\n1 Agregar persona");
       printf("\n2 Borrar persona");
       printf("\n3 Modificar persona");
       printf("\n4 Leer Archivo");
       printf("\n5 Salir");

       printf("\n\nQue operacion desea realizar?: ");
       fflush(stdin);
       scanf("%d",&opcion);

       switch(opcion)
       {
       case 1:
           AgregarPersona(persona);
           system("pause");
           system("cls");
        break;

       case 2:
           printf("\n\nIngrese el dni del usuario a borrar: ");
           fflush(stdin);
           scanf("%ld",&dniAux);
           BorrarPersona(dniAux);
           system("pause");
           free(dniAux);
           system("cls");
        break;

       case 3:
            dniAux = getLongInt("\ningrese el DNI del usuario a borrar: ");
            ModificarPersona(dniAux);
            system("pause");
            system("cls");
        break;

       case 4:
           LeerArchivo(file);
        break;

       case 5:
           printf("\n\nGracias vuelva prontos!\n\n");
           system("pause");
           continuar = 'n';
        break;

       default:
           printf("\n\nOpcion invalida!\n\n");
           system("pause");
           system("cls");
        break;
       }
   }
}
