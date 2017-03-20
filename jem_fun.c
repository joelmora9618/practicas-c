#include "alumnos.c"

int getInt(char* mensaje)
{
    int num = 0;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&num);
    return num;
}

void Inicializar_array(EAlumno alumno[], int longitud)
{
    int i;
    for(i=0; i<longitud;i++)
    {
        alumno[i].estado = 0;
    }
}

void getString(char* mensaje, char* cadena)
{
    printf("%s", mensaje);
    fflush(stdin);
    gets(cadena);
}
