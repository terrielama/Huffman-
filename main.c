#include "main.h"

int main(int argc, char *argv[])
{


    (void)argc;

    char *filename = argv[1];

    ecrireOccur(filename);

    char *st;
    st = fileToString(filename);
    fromTextToBit(st);
    free(st);

    FILE *f = fopen("data/occur.txt", "r");
    int compteur = 0;
    int first = 0;
    for (char c = getc(f); c != EOF; c = getc(f))
    {
        if (!first && c == '\n')
        {
            first = 1;
            continue;
        }

        first = 1;


        if (c == '\n')
        {
            compteur++;
        }
    }
    counter++;

    //printf("compteur = %d\n", compteur);

    fclose(f);

    Liste *resultat = creer_liste(compteur);
    listeOccur(resultat, "data/occur.txt");

    //printListe(resultat);

    Liste_Noeud *huffmanListe = huffListe(resultat, 1);
    printf("\n");



    Noeud *huffArbre = (huffman(huffmanListe))->data;

    //print_tree(huffTree);

    char code[256] = {0};

    remove("data/dico.txt");
    getDico(huffTree, code);

    encode(filename);
}

char *fileToString(const char *filename)
{
    char *s;
    int length;
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        return NULL; // tu ne peux plus rien faire tout va crash
    }

    if (fseek(f, 0, SEEK_END) < 0 || (length = ftell(f)) < 0 || fseek(f, 0, SEEK_SET) < 0)
    {
        fclose(f);
        return NULL; // tu ne peux plus rien faire tout va crash
    }
    s = malloc((length + 1) * sizeof(*s));
    if (s == NULL)
    {
        fclose(f);
        return NULL; // tu ne peux plus rien faire tout va crash
    }
    s[length] = '\0';
    if ((unsigned long)length != fread(s, 1, length, f))
    {
        free(s);
        fclose(f);
        return NULL; // tu ne peux plus rien faire tout va crash
    }
    fclose(f);

    return s;
}

void printListe(struct Liste *liste) //Print a linked list
{
    while (liste != NULL)
    {
        if (liste)
        {
            printf("%c = %ld,\n", liste->c, liste->occur);
        }

        if (!liste->suivant)
        {
            break;
        }

        liste = liste->suivant;
    }
}

void supprNoeud(struct Liste_Noeud **ref, int key)
{
    if (!*ref)
    {
        return;
    }

    struct Liste_Noeud *temp = *ref;
    struct Liste_Noeud *prev = NULL;

    if (temp != NULL && temp->id == key)
    {
        *ref = temp->suivant;
        free(temp);
        temp = NULL;
        return;
    }
    //Trouver la clé à supprimer
    while (temp != NULL && temp->id != key)
    {
        prev = temp;
        temp = temp->suivant;
    }

    // si la clé n'est pas présente
    if (temp == NULL)
        return;

    // suppr Noeud
    prev->suivant = temp->suivant;

    free(temp);
    temp = NULL;
}
