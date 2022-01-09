#include "encode.h"

char *getCode(char c, const char *dico)
{
    FILE *f = fopen(dico, "r");

    if (!f)
    {
        printf("impossible de lire.\n");
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    int read = 0;

    int newline = 0;

    char *code = (char *)malloc(sizeof(char));

    while ((read = getline(&line, &len, f)) != -1)
    {      
        if (line[0] == '\n' && c == '\n')
        {
            newline = 1;
            continue;
        }

        if (newline)
        {
            code = line + 3;
            break;
        }
        
        
        
        if (line[0] == c)
        {
            code = line + 4;
           
            break;
        }
    }

    fclose(f);

    return code;
}

void ecrireCode(char *code)
{
    FILE *f = fopen("data/output.txt", "a");

    if (!f)
    {
        printf("Impossible de créer le fichier de sortie.\n");
        exit(EXIT_FAILURE);
    }

    
    code[strlen(code) - 1] = '\0';

    //fprintf(f, "%s", code);
    fputs(code, f);

    fclose(f);
}

void encode(const char *input)
{
    remove("data/output.txt");
    
    FILE *f = fopen(input, "r");

    if (!f)
    {
        printf("Impossible de lire le fichier..\n");
        exit(EXIT_FAILURE);
    }

    char c = 0;
    while ((c = fgetc(f)))
    {
        if (c == EOF)
            break;
            
       ecrireCode(getCode(c, "data/dico.txt"));
    }
