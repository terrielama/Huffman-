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
Node *creation_noeud_arbre(char val, int occ)
{
    Node *arbre = (Noeud *)malloc(sizeof(Noeud));
    Arbre->donnee = val;
    arbre->occ = occ;
    arbre->gauche = NULL;
    arbre->droite = NULL;
    return arbre;
}

/* Libération de la mémoire */
void freeArbre(struct Node *arbre)
{
    if (!arbre)
        return;

    freeArbre(arbre->gauche);
    freeArbre(arbre->droite);

    free(arbre);
}

//creation de liste
Liste_Node *creationNodeListe(struct Node *arbre, int i)
{
    struct Liste_Node *nouv_elem;
    nouv_elem = (Liste_Node *)malloc(sizeof(Liste_Node));
    nouv_elem->donnee = arbre;
    nouv_elem->suivant = NULL;
    nouv_elem->i = i;
    return nouv_elem;
}

Liste_Node *huffListe(struct Liste *liste, int i)
{
    if (liste == NULL)
    {
        return NULL;
    }

    Liste_Node *huffmanListe;

    huffmanListe = creationNodeLiset(creation_node_arbre(liste->c, liste->occ), i);
    liste = liste->suivant;
    huffmanListe->suivant = huffListe(liste, i + 1);

    return huffmanListe;
}


//afficher la liste
void afficheHuffmanListe(struct Liste_Node *huffListe)
{
    while (huffListe)
    {
        printf("%c = %d, id = %d\n", huffListe->donnee->donnee, huffListe->donnee->occ,
               huffListe->i);
        huffListe = huffListe->suivant;
    }
}

//envoi de la liste
void envoi(struct Liste_Node **t_ref, Node *nouv_donnee, int i)
{
    struct Liste_Node *nouv_node = (struct Liste_Node *)malloc(sizeof(struct Liste_Node));

    nouv_node->donnee = nouv_donnee;
    nouv_node->i = i;

    nouv_node->suivant = (*t_ref);

    (*t_ref) = nouv_node;
}

//Fusionnez les deux premiers éléments minimum du tableau
void fusionDesDeuxMin(struct Liste_Node **huffListe)
{
    if (!huffListe || !(*huffListe)->suivant)
    {
        return;
    }

    struct Liste_Node *temp = *huffListe;

    struct Liste_Node *min1 = *huffListe;
    struct Liste_Node *min2 = (*huffListe)->suivant;

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

 

    Node *arbre = creation_node_arbre('\0', min1->donnee->occ + min2->donnee->occ);
    arbre->gauche = min1->donnee;
    arbre->droite = min2->donnee;

    envoi(huffListe, arbre, max_i + 1);

    supprNode(huffListe, min1->i);
    supprNode(huffListe, min2->i);
}

Liste_Node *huffman(struct Liste_Node *liste)
{
    while (liste->suivant)
    {
       fusionDesDeuxMin(&liste); //la huffman liste
        
    }

    fusionDesDeuxMin(&liste);

    return liste;
}










