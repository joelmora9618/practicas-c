#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int MAX = 30;
    int position = 0;
    int long auxDNI = 0;
    ePersona persona[MAX];
    int i,j;
    int flag = 0;
    char continuar = 's';
    int opcion = 0;

    while(continuar == 's')
    {

    printf("*** MENU ***");
    printf("\n\n");
    printf("Elija una opcion\n\n");
    printf("1. Agregar una persona\n");
    printf("2. Borrar una persona\n");
    printf("3. Imprimir lista ordenada por nombre\n");
    printf("4. Imprimir grafico de edades\n");
    printf("5. Salir\n");
    printf("\n\n");

    printf("Que operacion desea realizar?: ");
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:

        position = BuscarEspacio(persona,MAX);

        if(position == -1)
        {
            printf("\nError, memoria insuficiente para almacenar usuario");
            system("pause");
            system("cls");
            break;
        }else
        {
            printf("\nIngrese su DNI: ");
            fflush(stdin);
            scanf("%ld",&persona[position].dni);

            printf("\nIngrese su nombre: ");
            fflush(stdin);
            gets(persona[position].nombre);

            printf("\nIngrese su apellido: ");
            fflush(stdin);
            gets(persona[position].apellido);

            printf("\nIngrese su edad: ");
            fflush(stdin);
            scanf("%d",&persona[position].edad);

            persona[position].estado = 1;
            flag = 1;

        }
        system("pause");
        system("cls");
        break;
    case 2:
            printf("\ningrese el DNI del usuario a borrar: ");
            fflush(stdin);
            scanf("%ld",&auxDNI);

            int pos = BuscarPorDNI(persona,MAX,auxDNI);

            if(pos == -1)
            {
                printf("\nEl usuario ingresado no se encuentra inscripto");
                system("pause");
                system("cls");
                break;
            }else
            {
                persona[pos].estado = 2;
                printf("\nBaja realizada con exito!\n\n");
            }

        system("pause");
        system("cls");
        break;
    case 3:

        if(flag == 0)
        {
            printf("\nNo hay usuarios disponibles");
            system("pause");
            system("cls");
            break;
        }else
        {
            printf("\n\nnombre       apellido       edad       DNI\n\n");

            for(i=0;i<MAX;i++)
            {
                if(persona[i].estado==1)
                {
                    printf("%s          %s         %d        %ld\n",persona[i].nombre,persona[i].apellido,persona[i].edad,persona[i].dni);
                }
            }
        }
        printf("\n\n");
        system("pause");
        system("cls");
        break;
    case 4:

            GraficoDeEdades(persona,MAX);

        system("pause");
        system("cls");
        break;
    case 5:
        break;
    default:
        continuar = 'n';
        system("pause");
        system("cls");
        break;
    }

    }

}
