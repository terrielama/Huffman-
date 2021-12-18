#include "bit.h"

void fromTextToBit(char *s) 
{
    int i;

  //ouvrir le fichier
    FILE *fp = fopen("data/bin_origin.txt, "w"); 

    if (!fp)
    {
        printf("impossible de créer le fichier de sortie\n");
        exit(EXIT_FAILURE);
    }


    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }

    for (int j = 0; j < len; j++)
    {
        char ch = s[j];
        for (i = 7; i >= 0; --i)
            (ch & 1 << i) ? fputc('1', fp) : fputc('0', fp);
    }
//fermeture
    fclose(fp); 
}
