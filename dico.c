
#include "dico.h"

//retourne valeur true
int isLeaf(struct Noeud *arbre)
{
    if (!arbre->droit && !arbre->gauche)
        return 1;
    return 0;
}

void printCode(char *code, char c)
{
    //(void)code;

    char buffer[4096] = {0};

//ouverture
    FILE *f = fopen("data/dico.txt", "a");

    if (!f)
    {
        printf("Unable to create dico file.\n");
        exit(EXIT_FAILURE);
    }

    snprintf(buffer, sizeof(buffer), "%c = %s\n", c, code);
    fputs(buffer, f);

    fclose(f);
}

void getDico(struct Noeud *arbre, char *code)
{
    if (!arbre)
        return;

    if (isLeaf(arbre))
        return printCode(code, arbre->data);

    getDico(arbre->gauche, strcat(code, "0"));
    code[strlen(code) - 1] = '\0';
    getDico(arbre->droit, strcat(code, "1"));
    code[strlen(code) - 1] = '\0';
    //code[strlen(code) - 1] = '\0';

    //memset(code, '\0', 256);
}
