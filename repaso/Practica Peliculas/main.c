#include <stdio.h>
#include <stdlib.h>

int main()
{
         int opcion = 0;
         char continuar = 's';

    while(continuar == 's')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Modificar Pelicula\n");
        printf("5- Salir\n");

    printf("\nQue operacion desea realizar: ");
    fflush(stdin);
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    default:
        printf("\nOpcion no valida!");
        system("pause");
        system("cls");
        break;
    }
    }
}
