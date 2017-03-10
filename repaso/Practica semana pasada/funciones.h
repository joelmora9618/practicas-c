#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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
    scanf("%ld",&persona->DNI);

    persona->estado = 1;

    return GuardarPersona(persona);

}

void GuardarPersona(Persona *persona)
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

int eliminarPersona(long int* dni)
{
    FILE* file, *fileAux;
    Persona* persona= buscarPersona(dni);

    if(persona != NULL)
    {
        fileAux=fopen("agendaAux.dat","wb+");
        file=fopen("agenda.dat","rb");
        Persona perso;

        while(fread(&perso,sizeof(Persona),1,file)!=0)
        {
            if(perso.DNI != dni)
            {
                fwrite(&perso,sizeof(Persona),1,fileAux);
            }
        }
        fclose(file);
        fclose(fileAux);

        file=fopen("agenda.dat","wb");
        fileAux=fopen("agendaAux.dat","rb");

        while(fread(&perso,sizeof(Persona),1,fileAux))
        {
            fwrite(&perso,sizeof(Persona),1,file);
        }

        fclose(file);
        fclose(fileAux);

    }
      else
    {
        printf("La persona no fue encontrado\n\n");
    }

    return 1;

}

void LeerArchivo(FILE* file)
{
    if((file = fopen("agenda.dat","ab+"))==NULL);

    Persona* persona = malloc(sizeof(Persona));

    printf("\n------PERSONAS-------\n\n");

    while(fread(persona,sizeof(Persona),1,file)!=0)
    {
        if(persona->estado == 1)
        {
            printf("%s\t\t%s\t%d\t%ld\n",persona->nombre,persona->apellido,persona->edad,persona->DNI);
        }
    }

    printf("\n");

    fclose(file);
    free(persona);
    system("pause");
    system("cls");
}

Persona* buscarPersona(long int* dni)
{
    FILE* file;
    file=fopen("agenda.dat","rb");
    int encontrado = 0;

    if(file==NULL)
    {
        printf("\nError al abrir el archivo");
        return NULL;
    }

    struct Persona* persona = malloc(sizeof(Persona));

    while(fread(persona, sizeof(Persona),1,file)!= 0)
    {
        if(dni == persona->DNI)
        {
            encontrado = 1;
            break;
        }
    }
    fclose(file);
    if(encontrado == 1)
        return persona;

    free(persona);
    return NULL;
}


