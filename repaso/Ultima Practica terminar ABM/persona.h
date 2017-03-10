#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct Persona
{
    char nombre[30];
    char apellido[30];
    int edad;
    long int dni;

}Persona;

void AgregarPersona(Persona* persona);

void GuardarPersona(Persona* persona);

void LeerArchivo(FILE* file);

Persona* BuscarPersona(long int* dni);

void BorrarPersona(long int* dni);

int ModificarPersona(long int* dni);

#endif // PERSONA_H_INCLUDED
