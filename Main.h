#ifndef h_main
#define h_main
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Noeud
{
    int occ;
    char donnee;
    struct Noeud *gauche;
    struct Noeud *droite;
} Noeud;

typedef struct Liste
{
    struct Liste *suivant;
    long occ;
    char c;
    //struct Noeud *arbre;
    int i;
} Liste;

typedef struct Liste_Noeud
{
    struct Noeud*donnee;
    struct Liste_Noeud *suivant;
    int i;
}Liste_Noeud;

#include "bit.h"
#include "occurence.h"
#include "arbre.h"
#include "encode.h"
#include "dictionnaire.h"

char *fichierToString(const char *nomDeFichier);
void afficheListe(struct Liset *liste);
void supprNoeud(struct Liste_Noeud **t_ref, int c);

#endif
