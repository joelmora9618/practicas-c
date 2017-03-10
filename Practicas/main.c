#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#include <ctype.h>

int main()
{
    int Max = 30;
    EPersona persona[Max];
    int i;
    int opcion;
    char continuar = 's';

    int FlagPers = 0;
    int posiPerson;     //Posici�n de la persona en el array

    while(continuar == 's')
    {

    printf("\n      �������������������������������������������������ͻ");
    printf("\n      �                      ABM                        �");
    printf("\n      �������������������������������������������������͹");
    printf("\n      �                                                 �");
    printf("\n      �         1.- Agregar Persona                     �");
    printf("\n      �                                                 �");
    printf("\n      �         2.- Borrar Persona                      �");
    printf("\n      �                                                 �");
    printf("\n      �         3.- Imprimir lista ordenada por nombre  �");
    printf("\n      �                                                 �");
    printf("\n      �         4.- Imprimir grafico de edades          �");
    printf("\n      �                                                 �");
    printf("\n      �         5.- Salir                               �");
    printf("\n      �                                                 �");
    printf("\n      �������������������������������������������������ͼ");

    printf("\n\n        Que operacion desea realizar: ");
    fflush(stdin);
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
        printf("\n\n        *********ALTA**********\n\n");

            posiPerson = BuscarPosicion(persona,Max);
            if(posiPerson == -1)
            {
                printf("no queda espacio para realizar otra ALTA\n");
                system("pause");
                system("cls");
                break;
            }

        printf("\ningrese su nombre: ");
        fflush(stdin);
        gets(persona[posiPerson].Nombre);

        printf("\ningrese su apellido: ");
        gets(persona[posiPerson].Apellido);

        printf("\ningrese su edad: ");
        scanf("%d",&persona[posiPerson].edad);

        printf("\ningrese su DNI: ");
        scanf("%ld",&persona[posiPerson].dni);

        persona[posiPerson].estado = 1;
        FlagPers = 1;

        system("pause");
        system("cls");
        break;
    case 2:
        break;
    case 3:

                if(FlagPers == 0)
                {
                    printf("\nno hay datos ingresados!!");
                    system("pause");
                    system("cls");
                    break;
                }

                printf("\n\n        *********LISTAR*********\n\n");
                 printf("Nombre    Apellido    Edad    DNI \n\n");
                  for(i=0; i<Max;i++)
                  {
                      if (persona[i].estado==0)
                      {
                          continue;
                      }

                    printf("%s    %s    %8d     \t%8ld",persona[i].Nombre,persona[i].Apellido,persona[i].edad,persona[i].dni);
                }
                system("pause");
                system("cls");

        break;
    case 4:
        break;
    case 5:
        continuar = 'n';
        break;
    default:
        printf("\n        opcion invalida!!\n\n");
        system("pause");
        system("cls");
        break;
    }

    }
    return 0;
}
