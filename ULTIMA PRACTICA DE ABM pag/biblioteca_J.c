#ifndef _LISTH_
#define _LISTH_

void getString(char* mensaje,char* cadena)
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",cadena);
}

int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&auxiliar);
    return auxiliar;
}

long int getLongInt(char* mensaje)
{
    long int auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%ld",&auxiliar);
    return auxiliar;
}

#endif
