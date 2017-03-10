#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "personas.h"

 int BuscarPosicion(EPersonas personas[],int longitud)
{
    int i;
    int estado = -1;
    for(i=0;i<longitud;i++)
    {
        if(personas[i].estado == 0)
        {
            return i;
        }
    }
    return estado;
}

#endif // FUNCIONES_H_INCLUDED
