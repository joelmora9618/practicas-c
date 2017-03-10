#include "biblioteca_J.h"

void AgregarPersona(Personas* persona)
{
    getString("\ningrese su nombre: ",persona->nombre);
    getString("\ningrese su apellido: ",persona->apellido);
    persona->edad = getInt("\ningrese su edad: ");
    persona->dni = getLongInt("\ningrese su DNI: ");

    return GuardarPersona(persona);
}

void GuardarPersona(Personas* persona)
{
    FILE* file;

    if((file=fopen("agenda.dat","wb"))==NULL){printf("\nError al abrir el archivo\n");}

    fwrite(persona,sizeof(Personas),1,file);

    free(persona);
    fclose(file);
}

void LeerArchivo(FILE* file)
{
    if((file=fopen("agenda.dat","rb"))==NULL){printf("\nError al abrir el archivo");}

    Personas* persona = malloc(sizeof(Personas));

    printf("\n----------AGENDA----------\n\n");

    while(fread(persona,sizeof(Personas),1,file)!=0)
    {
        printf("%s\t%s\t%d\t%ld\n",persona->nombre,persona->apellido,persona->edad,persona->dni);
    }

    fclose(file);
    free(persona);
}
