#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED
#include "fecha.h"

fecha_t* crear_fecha()
{
    fecha_t* nuevaFecha = malloc(sizeof(fecha_t));

    printf("ingrese el dia: ");
    fflush(stdin);
    scanf("%d",&nuevaFecha->dia);

    printf("ingrese el mes: ");
    fflush(stdin);
    scanf("%d",&nuevaFecha->mes);

    printf("ingrese el anio: ");
    fflush(stdin);
    scanf("%d",&nuevaFecha->anio);

    system("pause");
    system("cls");

    return nuevaFecha;
}

void imprimir_f(fecha_t* fecha)
{
    printf("\ndia:%d\tmes:%d\tanio:%d\n",fecha->dia,fecha->mes,fecha->anio);
}

#endif // FUNCION_H_INCLUDED
