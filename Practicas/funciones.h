#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "Personas.h"

int BuscarPosicion(EPersona persona[],int longitud)
{
    int estado = 1;
    int i;
    for(i=0;i<longitud;i++)
    {
        if(persona[i].estado == 0)
        {
            estado = i;
        }
    }
    return estado;
}



#endif // FUNCIONES_H_INCLUDED
