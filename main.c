#include <stdio.h>
#include <stdlib.h>
#include "jem_fun.c"
#include "abm_fun.c"
#define tam 20

int main()
{
   char continuar = 's';
   int opcion = 0;
   EAlumno alumnos[tam];
   Inicializar_array(alumnos,tam);

   while(continuar == 's')
   {

       printf("Agregar usuario............1\n");
       printf("Eliminar usuario...........2\n");
       printf("Modificar usuario..........3\n");
       printf("Mostrar usuarios...........4\n");
       printf("Salir......................5\n\n");

       opcion = getInt("Que operacion desea realizar: ?");

       switch(opcion)
       {
       case 1:
            agregarUsuario(alumnos,tam);
            system("pause");
            system("cls");
            break;
        case 2:
            printf("\nopcion 2");
            system("pause");
            system("cls");
            break;
        case 3:
            printf("\nopcion 3");
            system("pause");
            system("cls");
            break;
        case 4:
            MostrarLista(alumnos,tam);
            system("pause");
            system("cls");
            break;
        case 5:
            printf("\nopcion 5");
            system("pause");
            system("cls");
            break;
        default:
            printf("\nError, opcion invalida");
            system("pause");
            system("cls");
            break;
       }
   }
}
