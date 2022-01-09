#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "huffman.h"


void print_arbre(Arbre arbre)
{
    if (arbre != NULL)
    {
        printf("(%c = %i) ", arbre->donnee, arbre->occurrence);
        print_arbre(arbre->gauche);
        print_arbre(arbre->droite);
    }
}

// Création de l'arbre :
Noeud *creation_noeud_arbre(char val, int occ)
{
    Noeud *arbre = (Noeud *)malloc(sizeof(Noeud));
    Arbre->donnee = val;
    arbre->occ = occ;
    arbre->gauche = NULL;
    arbre->droite = NULL;
    return arbre;
}

/* Libération de la mémoire */
void freeArbre(struct Noeud *arbre)
{
    if (!arbre)
        return;

    freeArbre(arbre->gauche);
    freeArbre(arbre->droite);

    free(arbre);
}

//creation de liste
Liste_Noeud *creationNoeudListe(struct Noeud *arbre, int i)
{
    struct Liste_Noeud *nouv_elem;
    nouv_elem = (Liste_Noeud *)malloc(sizeof(Liste_Noeud));
    nouv_elem->donnee = arbre;
    nouv_elem->suivant = NULL;
    nouv_elem->i = i;
    return nouv_elem;
}

Liste_Noeud *huffListe(struct Liste *liste, int i)
{
    if (liste == NULL)
    {
        return NULL;
    }

    Liste_Noeud *huffmanListe;

    huffmanListe = creationNœudListe(creation_nœud_arbre(liste->c, liste->occ), i);
    liste = liste->suivant;
    huffmanListe->suivant = huffListe(liste, i + 1);

    return huffmanListe;
}


//afficher la liste
void afficheHuffmanListe(struct Liste_Noeud *huffListe)
{
    while (huffListe)
    {
        printf("%c = %d, id = %d\n", huffListe->donnee->donnee, huffListe->donnee->occ,
               huffListe->i);
        huffListe = huffListe->suivant;
    }
}

//envoi de la liste
void envoi(struct Liste_Noeud **t_ref, Noeud *nouv_donnee, int i)
{
    struct Liste_Noeud *nouv_noeud = (struct Liste_Noeud *)malloc(sizeof(struct Liste_Noeud));

    nouv_noeud->donnee = nouv_donnee;
    nouv_noeud->i = i;

    nouv_noeud->suivant = (*t_ref);

    (*t_ref) = nouv_noeud;
}

//Fusionnez les deux premiers éléments minimum du tableau
void fusionDesDeuxMin(struct Liste_Noeud **huffListe)
{
    if (!huffListe || !(*huffListe)->suivant)
    {
        return;
    }

    struct Liste_Noeud *temp = *huffListe;

    struct Liste_Noeud *min1 = *huffListe;
    struct Liste_Noeud *min2 = (*huffListe)->suivant;

    int max_i = 0;

    while (temp)
    {
        if (max_i < temp->i)
        {
            max_i = temp->i;
        }

        if (temp->donnee->oc > 0)
        {
            if (temp->donnee->occ < min1->donnee->occ)
            {
                min2 = min1;
                min1 = temp;
            }

            else if (temp->donnee->occ <= min2->donnee->occ && temp != min1)
            {
                min2 = temp;
            }
        }

        temp = temp->suivant;
    }

 

    Noeud *arbre = creation_noeud_arbre('\0', min1->donnee->occ + min2->donnee->occ);
    arbre->gauche = min1->donnee;
    arbre->droite = min2->donnee;

    envoi(huffListe, arbre, max_i + 1);

    supprNoeud(huffListe, min1->i);
    supprNoeud(huffListe, min2->i);
}

Liste_Nœud *huffman(struct Liste_Noeud *liste)
{
    while (liste->suivant)
    {
       fusionDesDeuxMin(&liste); //la huffman liste
        
    }

    fusionDesDeuxMin(&liste);

    return liste;
}
