#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "personas.h"
#include <string.h>

int BuscarPosicion(EPersonas personas[],int longitud)
{
    int i;
    int estado = -1;
    for(i=0;i<longitud;i++)
    {
        if(personas[i].estado == 0)
        {
            estado = i;
        }
    }
    return estado;
}

void NombreMayuscula(EPersonas persona[])
{
    int i;
    for(i=0;persona.nombre[];i++)
    {
        persona[i] = tolower(persona[i]);
    }

}

#endif // FUNCIONES_H_INCLUDED
