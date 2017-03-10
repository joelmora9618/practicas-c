#include "persona.h"
#include "biblioteca_J.c"

void AgregarPersona(Persona* persona)
{
    getString("\nIngrese su nombre: ",persona->nombre);
    getString("\nIngrese su apellido: ",persona->apellido);
    persona->edad = getInt("\nIngrese su edad: ");
    persona->dni = getLongInt("\nIngrese su DNI: ");

    return GuardarPersona(persona);
}

void GuardarPersona(Persona* persona)
{
    FILE* file;
    if((file=fopen("agenda.dat","ab+"))==NULL)
    {
        printf("\nError al abrir el archivo");
        return NULL;
    }
    fwrite(persona,sizeof(Persona),1,file);
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
    printf("NOMBRE\tAPELLIDO\tEDAD\tDNI\n\n");

    Persona* persona = malloc(sizeof(Persona));
    while(fread(persona,sizeof(Persona),1,file)!=0)
    {
        printf("%s\t%s\t\t%d\t%ld\n",persona->nombre,persona->apellido,persona->edad,persona->dni);
    }
    printf("\n");
    free(persona);
    fclose(file);
}

Persona* BuscarPersona(long int* dni)
{
    FILE* file;
    int encontrado = 0;
    if((file=fopen("agenda.dat","rb"))==NULL)
    {
        printf("\nError al abrir el archivo");
        return NULL;
    }
    Persona* persona = malloc(sizeof(Persona));
    while(fread(persona,sizeof(Persona),1,file)!=0)
    {
        if(persona->dni==dni)
        {
            encontrado = 1;
            break;
        }
    }
    if(encontrado == 1)
    {
        return persona;
    }
    fclose(file);
    free(persona);
    return NULL;
}

void ModificarPersona(long int* dni)
{
    FILE* file;
    char continuar = 's';
    int opcion;
    if((file=fopen("agenda.dat","rb"))==NULL){printf("\nError al abrir el archivo!");}
    Persona* persona = BuscarPersona(dni);


    if(persona != NULL)
    {
        while(continuar == 's')
        {
            printf("\n1 nombre: %s",persona->nombre);
            printf("\n2 apellido: %s",persona->apellido);
            printf("\n3 edad: %d",persona->edad);
            printf("\n4 DNI:%ld",persona->dni);
            printf("\n5 salir sin guardar");
            printf("\n6 Guardar y salir");

            opcion = getInt("\n\nque atributo desea modificar: ");

            switch(opcion)
            {
            case 1:
                getString("\ningrese su nombre: ",persona->nombre);
                system("cls");
                break;

            case 2:
                getString("\ningrese su apellido: ",persona->apellido);
                system("cls");
                break;

            case 3:
                persona->edad = getInt("\ningrese su edad: ");
                system("cls");
                break;

            case 4:
                persona->dni = getLongInt("\ningrese su DNI: ");
                 system("cls");
                break;

            case 5:
                continuar = 'n';
                break;

            case 6:
                continuar = 'n';
                printf("\n\nUsuario modificado con exito\n\n");
                BorrarPersona(dni);
                GuardarPersona(persona);
                break;

            default:
                printf("\nOpcion invalida!");
                system("pause");
                system("cls");
                break;
            }

        }
        fclose(file);
        free(persona);

    }else
    {
        printf("\nError, usuario no encontrado!");
        system("cls");
    }
}

int BorrarPersona(long int* dni)
{
    FILE *file,
         *fileAux;
    Persona* existe = BuscarPersona(dni);
    Persona persona;

    if(existe!=NULL)
    {
        if((file=fopen("agenda.dat","rb"))==NULL){printf("\nError al abrir el archivo");}
        if((fileAux=fopen("agendaAux.dat","wb+"))==NULL){printf("\nError al abrir el archivo");}

        while(fread(&persona,sizeof(Persona),1,file)!=0)
        {
            if(persona.dni!=dni)
            {
                fwrite(&persona,sizeof(Persona),1,fileAux);
            }
        }

        fclose(file);
        fclose(fileAux);

        if((file=fopen("agenda.dat","wb+"))==NULL){printf("\nError al abrir el archivo");}
        if((fileAux=fopen("agendaAux.dat","rb"))==NULL){printf("\nError al abrir el archivo");}

        while(fread(&persona,sizeof(Persona),1,fileAux)!=0)
        {
            fwrite(&persona,sizeof(Persona),1,file);
        }

        fclose(file);
        fclose(fileAux);
        return 1;

    }else
    {
        printf("\nEl usuario ingresado no existe!\n\n");
        system("pause");
        system("cls");
        return 0;
    }


}

