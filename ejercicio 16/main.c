#include <stdio.h>
#include <stdlib.h>

#define FIL 4
#define COL 4

int main()
{
    int matriz [FIL][COL],
        i,j,r = 1;

    for(i=0;i<FIL;i++)
    {
        for(j=0;j<COL;j++)
        {
            matriz[i][j] = r++;
        }
    }

    for(i=0;i<COL;i++)
    {
        printf("%d\t",matriz[1][i]);
    }


}
