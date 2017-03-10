#include <stdio.h>
#include <stdlib.h>

#define FIL  5
#define COL  3

int main()
{
    int matriz[FIL][COL];
    char nombres[5][40];
    int tiempos[5] = {0,0,0,0,0};
    int tmax = 0,
        tmin = 9999;
    int imax = 0,
        imin = 0;
    int min3 = 9999,
        imin3 = 0;
    int min4 = 9999,
        imin4 = 0;
    int i,j;

    for(i=0;i<FIL;i++)
    {
        printf("\ningrese el nombre del piloto numero %d: ",i+1);
        fflush(stdin);
        scanf("%s",nombres[i]);
        for(j=0;j<COL;j++)
        {
            printf("tiempo en la vuelta %d : ",j+1);
            fflush(stdin);
            scanf("%d",&matriz[i][j]);
        }
        system("cls");
    }

    printf("\nPILOTO\t\tvuelta 1\tvuelta 2\tvuelta 3\ttotal\n\n");

	for (i=0;i<FIL;i++)
	{
	    printf("%s\t\t",nombres[i]);
		for (j=0;j<COL;j++)
		{
			printf("%d min\t\t",matriz[i][j]);
			tiempos[i] = tiempos[i] + matriz[i][j];
		}
		if(matriz[i][2]<min3)
        {
            min3 = matriz[i][2];
            imin3 = i;
        }

		if(tiempos[i]<tmin)
        {
            tmin = tiempos[i];
            imin = i;
        }
        printf("%d",tiempos[i]);
        printf("\n\n");
	}

	for(i=0;i<=3;i++)
    {
        if(matriz[3][i]<min4)
        {
            min4 = matriz[3][i];
            imin4 = i+1;
        }
    }

    printf("\n\n1) tiempo del piloto numero 5 en la vuelta 3 es de %d minutos",matriz[4][2]);
    printf("\n2) el ganador es %s con un tiempo de: %d minutos",nombres[imin],tmin);
    printf("\n3) el piloto %s realizo el menor tiempo en la vuelta 3, con %d minutos",nombres[imin3],min3);
    printf("\n4) el mejor tiempo del piloto numero 4 (%s)  fue en la vuelta numero %d con %d minutos\n\n",nombres[3],imin4,min4);

	return 0;
}
