#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_J.c"
#include "personas.h"
#include "abm_Funciones.c"

int main()
{
    int MAX = 30;
    FILE* file;
    int opcion;
    char continuar = 's';
    Personas* persona = malloc(MAX*sizeof(Personas));

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
            break;

        case 3:
            break;

        case 4:
                LeerArchivo(file);
                system("pause");
                system("cls");
            break;

        case 5:
            printf("\nGracias, vuelva prontos!\n");
            continuar = 'n';
            break;

        default:
            printf("\nOperacion invalida!\n");
            system("pause");
            system("cls");
            break;
        }

}

}
