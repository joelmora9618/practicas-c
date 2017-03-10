#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED

typedef struct
{
    char Nombre[60];
    char Apellido[60];
    int edad;
    int estado;
}EPersonas;

 int BuscarPosicion(EPersonas personas[],int longitud);

#endif // PERSONAS_H_INCLUDED
