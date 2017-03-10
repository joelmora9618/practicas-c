#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED

typedef struct
{
    char nombre[60];
    char apellido[60];
    int edad;
    int estado;
    long int dni;
}EPersonas;

int BuscarPosicion(EPersonas personas[],int longitud);

void NombreMayuscula(EPersonas persona[]);

#endif // PERSONAS_H_INCLUDED
