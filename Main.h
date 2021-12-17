#ifndef h_main
#define h_main
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Node
{
    int occ;
    char donnee;
    struct Node *gauche;
    struct Node *droite;
} Node;

typedef struct Liste
{
    struct Liste *suivant;
    long occ;
    char c;
    //struct Node *arbre;
    int i;
} Liste;

typedef struct Liste_Node
{
    struct Node*donnee;
    struct Liste_Node *suivant;
    int i;
}Liste_Node;

#include "bit.h"
#include "occurence.h"
#include "arbre.h"
#include "encode.h"
#include "dictionnaire.h"

char *fichierToString(const char *nomDeFichier);
void afficheListe(struct Liset *liste);
void supprNode(struct Liste_Node **t_ref, int c);

#endif
