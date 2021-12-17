#ifndef  h_arbre
#define  h_arbre

#include "main.c"

typedef Node* Arbre;

void affiche_arbre(Arbre arbre);
Node* creation_node_arbre(char val, int occ);
void freeArbre(struct Node *arbre);
void mergeTheTwoSmallest(struct Liste_Node **huffListe);
List_Node* huffman(struct Liste_Node* liste);
List_Node *huffListe(struct Liste *liste, int i);
void afficheHuffmanListe(struct Liste_Node *huffListe);
List_Node *creationNodeListe(struct Node *arbre, int i);
void envoi(struct Liste_Node** t_ref, Node *nouv_donnee, int i);

#endif
