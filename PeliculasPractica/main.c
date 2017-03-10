#include <stdio.h>
#include <stdlib.h>
#include "Personas.h"
#include <string.h>;

int main()
{
    ePersona persona;
    ePersona* punteroPersona;

    punteroPersona = &persona;

    strcpy(punteroPersona->nombre, "joel");
    strcpy(punteroPersona->apellido, "mora");
    punteroPersona->edad = 20;

    printf("nombre: %s\n", punteroPersona->nombre);
    printf("apellido: %s\n", punteroPersona->apellido);
    printf("edad: %d", punteroPersona->edad);
}
