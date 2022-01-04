#ifndef  h_occurences
#define  h_occurences

#include "main.h"

void ecrireOccur(char* filename);
void listeOccur(struct Liste* resultat, char *filename);
Liste *creer_Element(char c, int id, int occur);
Liste *creer_liste(int size);
#endif
