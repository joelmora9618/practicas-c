#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int MAX = 30;
    EPersonas persona[MAX];

   int opcion = 0;
   int posicion = 0;
   int Flag = 0;
   int i,j;
   long int auxDni;

   char continuar = 's';

   while(continuar == 's')
   {

    printf("\n      ษอออออออออออออออออออออออออออออออออออออออออออออออออป");
    printf("\n      ฐ                      ABM                        ฐ");
    printf("\n      ฬอออออออออออออออออออออออออออออออออออออออออออออออออน");
    printf("\n      ฐ                                                 ฐ");
    printf("\n      ฐ         1.- Agregar Persona                     ฐ");
    printf("\n      ฐ                                                 ฐ");
    printf("\n      ฐ         2.- Borrar Persona                      ฐ");
    printf("\n      ฐ                                                 ฐ");
    printf("\n      ฐ         3.- Imprimir lista ordenada por nombre  ฐ");
    printf("\n      ฐ                                                 ฐ");
    printf("\n      ฐ         4.- Imprimir grafico de edades          ฐ");
    printf("\n      ฐ                                                 ฐ");
    printf("\n      ฐ         5.- Salir                               ฐ");
    printf("\n      ฐ                                                 ฐ");
    printf("\n      ศอออออออออออออออออออออออออออออออออออออออออออออออออผ");

    printf("\n\nQue operacion desea realizar?: ");
    fflush(stdin);
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
        posicion = BuscarPosicion(persona,MAX);

        if(posicion == -1)
        {
            printf("\nError, Almacenamiento insuficiente");
            system("pause");
            system("cls");
            break;
        }else
        {
            printf("\n---------ALTA--------");

            printf("\ningrese su nombre: ");
            fflush(stdin);
            NombreMayuscula(persona[posicion]);
            gets(persona[posicion].nombre);

            printf("\ningrese su apellido: ");
            fflush(stdin);
            gets(persona[posicion].apellido);

            printf("\ningrese su edad: ");
            fflush(stdin);
            scanf("%d", &persona[posicion].edad);

            printf("\ningrese su dni: ");
            fflush(stdin);
            scanf("%ld",&persona[posicion].dni);

            persona[posicion].estado = 1;
            Flag = 1;
        }
        system("pause");
        system("cls");
        break;

    case 2:

        if(Flag == 0)
        {
            printf("\naun no se ah realizado ningun alta!");
            system("pause");
            system("cls");
            break;
        }else
        {
            printf("ingrese el dni de la persona a borrar: ");
            fflush(stdin);
            scanf("%ld",&auxDni);

            for(i=0;i<MAX;i++)
            {
                if(persona[i].dni == auxDni)
                {
                    printf("\nBaja realizada con exito!\n");
                    persona[i].estado = 2;
                }
            }

             system("pause");
             system("cls");
        }
        break;

    case 3:

        if(Flag == 0)
        {
            printf("\naun no ah realizado ningun alta!");
            system("pause");
            system("cls");
            break;
        }else
        {
            printf("\n     nombre      apellido       edad        dni");
            for(i=0;i<MAX;i++)
            {
                if(persona[i].estado==1)
                {
                    printf("\n     %s        %s           %d         %ld\n", persona[i].nombre, persona[i].apellido, persona[i].edad,
                           persona[i].dni);
                }
            }
        }
        system("pause");
        system("cls");
        break;

    case 4:
        break;

    case 5:
        continuar = 'n';
        system("pause");
        break;

    default:
        printf("\n\nOperacion incorrecta!!");
        system("pause");
        system("cls");
        break;
    }

   }
}
