#ifndef  h_arbre
#define  h_arbre
//fichier header
#include "main.h"

typedef Noeud* Arbre;

//les prototypes des fonctions.
void affiche_arbre(Arbre arbre);
Noeud* creation_noeud_arbre(char val, int occ);
void freeArbre(struct Noeud *arbre);
void fusionDesDeuxMin(struct Liste_Noeud **huffLiset);
Liste_Noeud* huffman(struct Liste_Noeud* liste);
Liste_Noeud *huffList(struct Liste *liste, int i);
void afficheHuffmanListe(struct Liste_Noeud *huffListe);
Liste_Noeud *creationNoeudListe(struct Noeud *arbre, int i);
void envoi(struct Liste_Noeud** t_ref, Noeud *nouv_donnee, int i);

#endif











