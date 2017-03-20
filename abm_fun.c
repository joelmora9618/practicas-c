#include "jem_fun.h"

void agregarUsuario (EAlumno alumnos[], int longitud)
{
    int posicion = BuscarPosicion(alumnos,longitud);

    if(posicion != -1)
    {
        alumnos[posicion].dni_alumno = getInt("ingrese su DNI: ");
        getString("ingrese nombre: ", alumnos[posicion].nombre);
        getString("ingrese apellido: ", alumnos[posicion].apellido);
        alumnos[posicion].edad = getInt("ingrese su edad: ");
        getString("ingrese sexo: ", alumnos[posicion].sexo);
        getString("ingrese divicion: ", alumnos[posicion].divicion);
        alumnos[posicion].estado = 1;

        printf("\nUsuario agregado exitosamente!\n\n");
    }
    else
    {
        printf("\n\nError, Espacio insuficiente!\n");
    }
}

int BuscarPosicion(EAlumno alumnos[], int longitud)
{
    int posicion = -1,
        i;
    for(i=0;i<longitud;i++)
    {
        if(alumnos[i].estado == 0)
        {
           return posicion = i;
        }
    }
    return posicion;
}

void MostrarLista(EAlumno alumnos[], int longitud)
{
    printf("\nDNI\t\tNOMBRE\tAPELLIDO\tEDAD\tSEXO\tDIVICION\n\n");
    int i;
    for(i=0;i<longitud;i++)
    {
        if(alumnos[i].estado == 1)
        {
            printf("%d\t%s\t%s\t\t%d\t%s\t%s\n", alumnos[i].dni_alumno,alumnos[i].nombre, alumnos[i].apellido,
                   alumnos[i].edad, alumnos[i].sexo, alumnos[i].divicion);
        }
    }
}

