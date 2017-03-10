#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct Persona
{
    char nombre[40];
    char apellido[40];
    int edad;
    long int dni;
}Persona;

void AgregarPersona(Persona* persona);
void GuardarPersona(Persona* persona);
void LeerArchivo(FILE* file);
Persona* BuscarPersona(long int* dni);
int BorrarPersona(long int* dni);
void ModificarPersona(long int* dni);

#endif // PERSONA_H_INCLUDED
