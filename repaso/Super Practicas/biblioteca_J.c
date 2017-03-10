#ifndef _LISTH_
#define _LISTH_

void getString(char* mensaje, char* input)
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",input);
}

int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

long int getLongInt(char* mensaje)
{
    long int auxiliar;
    printf("%s",mensaje);
    scanf("%ld",&auxiliar);
    return auxiliar;
}

#endif
