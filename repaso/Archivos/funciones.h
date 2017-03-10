#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "personas.h"

void AgregarPersona(Persona* persona)
{

    printf("\ningrese su nombre: ");
    fflush(stdin);
    gets(persona->nombre);

    printf("\ningrese su apellido: ");
    fflush(stdin);
    gets(persona->apellido);

    printf("\ningrese su edad: ");
    fflush(stdin);
    scanf("%d",&persona->edad);

    printf("\ningrese su DNI: ");
    fflush(stdin);
    scanf("%ld",&persona->dni);

    persona->estado = 1;

    return GuardarPelicula(persona);

}

void GuardarPelicula(Persona *persona)
{
    FILE* file;
    if((file=fopen("agenda.dat","ab+"))==NULL)
    {
        printf("\nError al abrir el archivo");
    }

    fwrite(persona,sizeof(Persona),1,file);

    free(persona);

    fclose(file);
}

int BuscarPosicion(Persona persona[], int longitud)
{
    int i,
        estado = -1;

    for(i=0;i<longitud;i++)
    {
        if(persona[i].estado == 0)
        {
            estado = i;
        }
    }

    return estado;
}

void LeerArchivo(FILE* file)
{
    if((file = fopen("agenda.dat","ab+"))==NULL);

    Persona* persona = malloc(sizeof(Persona));

    printf("\n------PERSONAS-------\n\n");

    while(fread(persona,sizeof(Persona),1,file))
    {
        printf("%s\t%s\t\t%d\t%ld\n",persona->nombre,persona->apellido,persona->edad,persona->dni);
    }

    printf("\n");

    fclose(file);
    free(persona);
    system("pause");
    system("cls");

}

#endif // FUNCIONES_H_INCLUDED
