#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* s1 = "hola como andas";
    char* s2 = "hola";
    int count = 2;
    int length = 0;
    int length_from;
    char* s3;
    char* s4 = "bien";
    int len_s4 = strlen(s4);
    int len_s2 = strlen(s2);
    char* ins = s1;

    printf("%s\n",s1);

    while(count--)
    {
        ins = strstr(s1,s2);
        length_from = ins - s1;
        s3 = strncpy(s3,s1,length_from)+length_from;
        s3 = strcpy(s3,s4)+len_s4;
        s1 += length_from +len_s2;
    }

        while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }

    printf("%s",s1);


}
