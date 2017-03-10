#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_J.c"
#include "funciones.c"

int main()
{
   int MAX = 30;
   Persona* persona = malloc(MAX*sizeof(Persona));
   FILE* file;
   long int* dni;
   char continuar = 's';
   int opcion = 0;

   while(continuar == 's')
   {
       printf("\n1 Agregar persona");
       printf("\n2 Borrar persona");
       printf("\n3 Modificar persona");
       printf("\n4 Leer archivo");
       printf("\n5 Salir");

       opcion = getInt("\n\nQue operacion desea realizar?: ");

       switch(opcion)
       {
       case 1:
           AgregarPersona(persona);
           system("pause");
           system("cls");
        break;

       case 2:
           dni = getLongInt("\ningrese el DNI del usuario a borrar: ");
           if((BorrarPersona(dni))!=0)
           {
                printf("\nUsuario Borrado exitosamente\n\n");
           }
           system("pause");
           system("cls");
        break;

       case 3:
           dni = getInt("\nIngrese el DNI del usuario a modificar: ");
           ModificarPersona(dni);
           system("pause");
           system("cls");
        break;

       case 4:
           LeerArchivo(file);
           system("pause");
           system("cls");
        break;

       case 5:
           printf("\ngracias vuelva prontos\n\n");
           system("pause");
           continuar = 'n';
        break;

       default:
           printf("\nOpcion invalida!\n\n");
           system("pause");
           system("cls");
        break;
       }
   }


}
