#include "persona.h"
#include <string.h>
#include "biblioteca_J.c"


void AgregarPersona(Persona* persona)
{
    printf("\nIngrese su nombre: ");
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

    return GuardarPersona(persona);
}

void GuardarPersona(Persona* persona)
{
    FILE* file;
    if((file=fopen("agenda.dat","ab+"))==NULL)
    {
        printf("\nerror al abrir el archivo!");
        return NULL;
    }

    int datos = fwrite(persona,sizeof(Persona),1,file);
    if(datos == 0)
    {
        printf("\nError al guardar el usuario!");
    }else
    {
        printf("\nDatos guardados correctamente!\n\n");
    }

    free(persona);
    fclose(file);
}

void LeerArchivo(FILE* file)
{

    if((file=fopen("agenda.dat","rb"))==NULL)
    {
        printf("\nError al abrir el archivo");
        return NULL;
    }
    printf("\n\n----------AGENDA----------\n\n");

    Persona* persona = malloc(sizeof(Persona));
    while(fread(persona,sizeof(Persona),1,file)!=0)
    {
        printf("%s\t%s\t%d\t%ld\n",persona->nombre,persona->apellido,persona->edad,persona->dni);
    }

    printf("\n");
    system("pause");
    system("cls");
    free(persona);
    fclose(file);

}

void BorrarPersona(long int* dni)
{
    FILE *file, *fileAux;
    Persona* dniP = BuscarPersona(dni);

    if(dniP!=NULL)
    {

    Persona persona;
    if((file=fopen("agenda.dat","rb"))==NULL){printf("\nError al abrir el archivo\n");}
    if((fileAux=fopen("agendaAux.dat","wb+"))==NULL){printf("\nError al abrir el archivo\n");}

    while(fread(&persona,sizeof(Persona),1,file)!=0)
    {
        if(dni != persona.dni)
        {
            fwrite(&persona,sizeof(Persona),1,fileAux);
        }
    }
    fclose(file);
    fclose(fileAux);

    if((file=fopen("agenda.dat","wb+"))==NULL){printf("\nError al abrir el archivo\n");}
    if((fileAux=fopen("agendaAux.dat","rb"))==NULL){printf("\nError al abrir el archivo\n");}

    while(fread(&persona,sizeof(Persona),1,fileAux)!=0)
    {
        fwrite(&persona,sizeof(Persona),1,file);
    }
    printf("\nUsuario borrado con exito!\n\n");

    fclose(file);
    fclose(fileAux);

    }else
    {
        printf("\n\nEl usuario no fue encontrado!\n");
    }

}

int ModificarPersona(long int* dni)
{
    FILE* file;
    int opcion;
    int modificacion = 0;
    char continuar = 's';
    Persona* persona = BuscarPersona(dni);
    if((file=fopen("agenda.dat","rb"))==NULL)
    {
        printf("\nError al abrir el archivo!\n");
    }

    if(persona!=NULL)
    {
        while(continuar == 's')
        {
        printf("\n1 Nombre: %s\n ",persona->nombre);
        printf("\n2 Apellido: %s\n",persona->apellido);
        printf("\n3 Edad: %d",persona->edad);
        printf("\n4 DNI: %ld",persona->dni);
        printf("\n5 Salir (sin guardar)");
        printf("\n6 Guardar y salir");

        printf("\n\nQue atributo desea modificar?: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                    getString("ingrese su nombre: ",persona->nombre);
                break;

            case 2:
                    getString("ingrese su apellido: ",persona->apellido);
                break;

            case 3:
                    persona->edad = getInt("ingrese su edad: ");
                break;

            case 4:
                    persona->dni = getLongInt("ingrese su DNI: ");
                break;

            case 5:
                    continuar = 'n';
                break;

            case 6:
                    continuar = 'n';
                    BorrarPersona(dni);
                    GuardarPersona(persona);
                    modificacion = 1;
                break;

            default:
                printf("\nOpcion invalida!");
                system("pause");
                break;

        }

        }
    }else
    {
        printf("\nError, usuario no encontrado\n\n");
    }
    return modificacion;

}

Persona* BuscarPersona(long int* dni)
{
    FILE* file;
    int encontrado = 0;
    if((file=fopen("agenda.dat","rb"))==NULL)
    {
        printf("\nError al abrir el archivo\n");
        return NULL;
    }
    Persona* persona= malloc(sizeof(Persona));

    while(fread(persona,sizeof(Persona),1,file)!=0)
    {
        if(dni == persona->dni)
        {
            encontrado = 1;
            break;
        }
    }
        fclose(file);

    if(encontrado == 1)
    {
        return persona;
    }
    free(persona);
    return NULL;

}
