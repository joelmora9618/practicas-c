#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#ifndef _LISTH_
#define _LISTH_

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&auxiliar);
    return auxiliar;
}

/**
* \brief Solicita un número al usuario y devuelve el resultado
* \param mensaje es el mensaje a ser mostrado
* \return el numero ingresado por el usuario
*/
long int getLongInt(char* mensaje)
{
    long int auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%ld",&auxiliar);
    return auxiliar;
}

#endif
