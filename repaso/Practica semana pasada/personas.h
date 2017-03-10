#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED

typedef struct Persona{
    char nombre[30];
    char apellido[30];
    int edad;
    long int DNI;
    int estado;

}Persona;

Persona* buscarPersona(long int* dni);

#endif // PERSONAS_H_INCLUDED
