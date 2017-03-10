#include <stdio.h>
#include <stdlib.h>
#include "personas.h"
#include "funciones.h"

int main()
{
    FILE* file;
    int MAX = 30;
    long int dniAux;
    char continuar = 's';
    Persona* persona;
    int opcion;

    persona = malloc(MAX*sizeof(persona));

    while(continuar == 's')
    {
        printf("\n1 Agregar persona");
        printf("\n2 Borrar persona");
        printf("\n3 Modificar persona");
        printf("\n4 Leer Archivo");
        printf("\n5 Salir");

        printf("\n\nQue operacion desea realizar: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            AgregarPersona(persona);
            system("cls");
            break;
        case 2:
            printf("\ningrese el dni de la persona a borrar: ");
            fflush(stdin);
            scanf("%ld",&dniAux);

            if((eliminarPersona(dniAux))==1)
                printf("\nPersona eliminada exitosamente\n");
                system("pause");
                system("cls");

            break;
        case 3:
            break;
        case 4:
                LeerArchivo(file);
            break;
        case 5:
            printf("\n\nGracias vuelva prontos!\n\n");
            system("pause");
            system("cls");
            continuar = 'n';
            break;
        default:
            printf("\n\nOpcion invalida!");
            system("pause");
            system("cls");
            break;
        }
    }
}
