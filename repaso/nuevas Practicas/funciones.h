#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "personas.h"

int BuscarEspacio(ePersona persona[], int longitud)
{
    int i;
    int estado = -1;
    for(i=0;i<longitud;i++)
    {
        if(persona[i].estado == 0)
        {
            estado = i;
        }
    }
    return estado;
}

int BuscarPorDNI(ePersona persona[], int longitud,int dni)
{
    int i;
    int value = -1;
    for(i=0;i<longitud;i++)
    {
        if(dni == persona[i].dni)
        {
            value = i;
        }
    }
    return value;
}

void GraficoDeEdades(ePersona persona[], int Longitud)
{

    printf("\n----------GRAFICO DE EDADES----------\n\n");

    int i;
    int menor18 = 0,
        de19a35 = 0,
        masDe35 = 0,
        mayor = 0,
        flag = 0;

    for(i=0;i<Longitud;i++)
    {
        if(persona[i].estado == 1 && persona[i].edad<=18)
        {
            menor18++;
        }
        if(persona[i].estado == 1 && persona[i].edad>18 && persona[i].edad<=35)
        {
            de19a35++;
        }
        if(persona[i].estado == 1 && persona[i].edad>35)
        {
            masDe35++;
        }
    }

    if(menor18 >= de19a35 && menor18 >= masDe35)
    {
        mayor = menor18;
    }else
    {
        if(de19a35 >= menor18 && de19a35 >= masDe35)
        {
            mayor = de19a35;
        }else
        {
            if(masDe35 >= menor18 && masDe35 >= de19a35)
            {
                mayor = masDe35;
            }
        }
    }

    for(i=mayor;i>0;i--)
    {
        if(i <= menor18)
        {
            printf("*");
        }
        if(i <= de19a35)
        {
            flag = 1;
            printf("\t*");
        }
        if(i <= masDe35)
        {
            if(flag == 1)
            {
                printf("\t*");
            }else
            {
                printf("\t\t*");
            }
        }
        printf("\n");
    }
    printf("====================\n");
    printf("X<18\t19a35\tX>35\n");
    printf("%d\t%d\t%d\n\n",menor18,de19a35,masDe35);

}

#endif // FUNCIONES_H_INCLUDED
