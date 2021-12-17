#ifndef  h_arbre
#define  h_arbre
//fichier header
#include "main.h"

typedef Node* Arbre;

//les prototypes des fonctions.
void affiche_arbre(Arbre arbre);
Node* creation_node_arbre(char val, int occ);
void freeArbre(struct Node *arbre);
void fusionDesDeuxMin(struct Liste_Node **huffLiset);
Liste_Node* huffman(struct List_Node* liste);
Liste_Node *huffList(struct Liste *liste, int i);
void afficheHuffmanListe(struct Liste_Node *huffListe);
Liste_Node *creationNodeListe(struct Node *arbre, int i);
void envoi(struct Liste_Node** t_ref, Node *nouv_donnee, int i);

#endif











