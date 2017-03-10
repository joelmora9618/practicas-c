#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

typedef struct
{
    int id;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[300];
    int puntaje;
    char linkImagen[300];
    int estado;
}eMovie;

#endif // MOVIE_H_INCLUDED
