#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int MAX = 30;
    int posicion = 0;
    int Flag = 0;
    int i;
    int opcion = 0;

    EPersonas personas[MAX];

    char continuar = 's';


    while(continuar == 's')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n\n");

        printf("\nQue operacion desea realizar?");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:

            posicion = BuscarPosicion(personas,MAX);

            if(posicion==-1)
            {
                printf("\n\nNo hay posiciones disponibles!!");
                system("pause");
                system("cls");
                break;
            }else
            {

                printf("\n\n---------ALTA---------");

                printf("\n\nIngrese su nombre: ");
                fflush(stdin);
                scanf("%s", personas[posicion].Nombre);

                printf("\nIngrese su apellido: ");
                fflush(stdin);
                scanf("%s", personas[posicion].Apellido);

                printf("\nIngrese su edad: ");
                fflush(stdin);
                scanf("%d", &personas[posicion].edad);

                personas[posicion].estado = 1;
                Flag = 1;
            }

            system("pause");
            system("cls");
            break;

        case 2:
            break;
        case 3:

            if(Flag == 0)
            {
                printf("\n\nTodavia no hay personas ingresadas");
                system("pause");
                system("cls");
                break;
            }else
            {
                 int i,j;
                 EPersonas aux;

                for(i=0; i<MAX; i++)
                {
                    for(j=i+1; j<MAX; j++)
                    {
                        if(strcmp(personas[i].Nombre, personas[j].Nombre)>0)
                        {
                            aux = personas[i];
                            personas[i] = personas[j];
                            personas[j] = aux;
                        }
                    }
                }

                printf("\n\n     NOMBRE     APELLIDO     EDAD\n");
                for(i=0;i<MAX;i++)
                {
                    if(personas[i].estado==1)
                    {
                        printf("      %s        %s        %d\n",personas[i].Nombre,personas[i].Apellido,personas[i].edad);
                    }
                }
            }
            system("pause");
            system("cls");
            break;
        case 4:
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
