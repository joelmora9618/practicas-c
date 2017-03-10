#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED

typedef struct
{
    char Nombre[60];
    char Apellido[60];
    int edad;
    long int dni;
    int estado;

}EPersona;

int BuscarPersona(EPersona persona[],int tam);

#endif // PERSONAS_H_INCLUDED
