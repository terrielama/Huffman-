#include "occurences.h"

void ecrireOccur(char *filename) 
{
    int count[256] = {0};
    FILE *f = fopen(filename, "r");

    if (!f)
    {
        printf("Impossible de lire le fichier\n");
        exit(EXIT_FAILURE);
    }

    int c = 0;
    while ((c = fgetc(f)))
    {
        if (c == EOF)
            break;

        //printf("char = %d\n", c);

        count[c] += 1;
    }

    fclose(f);

    FILE *fp = fopen("data/occur.txt", "w");

    if (!fp)
    {
        printf("Impossible de créer le fichier.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[4096] = {0};

    int first = 1;

    for (int k = 0; k < 256; k++)
    {
        if (first)
        {
            if (count[k] > 0)
            {
                snprintf(buffer, sizeof(buffer), "%c = %d", k, count[k]);
                first = 0;
                //printf("char = %c\n", k);
            }
        }

        else
        {
            if (count[k] > 0)
            {
                snprintf(buffer, sizeof(buffer), "\n%c = %d", k, count[k]);
                //printf("char = %c\n", k);
            }
        }

        int fput = fputs(buffer, fp);
        if (fput == EOF)
        {
            return;
        }

        memset(buffer, '\0', sizeof(buffer));
    }

    fclose(fp);
}

void listeOccur(struct Liste *resultat, char *filename) 
{
    assert(resultat != NULL);

    char *line = NULL;
    size_t len = 0;
    int lire = 0;

    FILE *f = fopen(filename, "r");

    if (!f)
    {
        printf("Impossible de lire le fichier.\n");
        fclose(f);
        exit(EXIT_FAILURE);
    }

    int id = 1;
    //char occur[1024];
    char * temp;
    int co = 4;

    int first_jump = 0;

    while ((lire = getline(&line, &len, f)) != -1)
    {
        if (line[0] == '\n')
        {
            first_jump = 1;
            continue;
        }
        co = 4;
        
        if (first_jump)
        {
            resultat->c = '\n';
            first_jump = 0;
            co = 3;
        }
        else
        {
            resultat->c = line[0];
        }
        
        resultat->id = id;
        resultat->occur = strtol(line + co, &temp, 10);
            

        //resultat->arbre = NULL;

        if (resultat->suivant)
        {
            resultat = resultat->suivant;
        }
        id++;
    }

    //free(occur);

    fclose(f);
}

List *creer_Element(char c, int id, int occur)
{
    struct List *nouvel_el;
    nouvel_el = (List *)malloc(sizeof(List));
    nouvel_el->c = c;
    nouvel_el->id = id;
    nouvel_el->occur = occur;
    //nouvel_el->arbre = NULL;
    nouvel_el->suivant = NULL;
    return nouvel_el;
}

List *creer_liste(int size)
{
    if (size <= 0)
    {
        return NULL;
    }
    else
    {
        List *myel = creer_Element('\0', 0, 0);
        myel->suivant = creer_list(size - 1);
        return myel;
    }
}
