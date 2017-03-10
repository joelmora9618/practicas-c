#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcion.h"

void main()
{
    fecha_t* fecha1 = crear_fecha(fecha1);

    imprimir_f(fecha1);

    free(fecha1);

    imprimir_f(fecha1);
}
