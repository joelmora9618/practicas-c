#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "personas.h"

void main(void)
{
    int MAX = 30;
    Persona* persona;
    FILE* file;
    char continuar = 's';
    int opcion;

    persona = malloc(MAX*sizeof(persona));

    while(continuar == 's')
    {

    printf("\n1 Agregar persona");
    printf("\n2 Borrar persona");
    printf("\n3 Modificar persona");
    printf("\n4 Leer datos del archivo");
    printf("\n5 Salir");

    printf("\nQue operacion desea realizar?: ");
    fflush(stdin);
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
            AgregarPersona(persona);
            system("cls");

        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
            LeerArchivo(file);
        break;
    case 5:
        printf("\nGracias, vuelva prontos!\n\n");
        continuar = 'n';
        break;
    default:
        printf("\nOpcion incorrecta!");
        system("pause");
        system("cls");
        break;
    }

    }

}
