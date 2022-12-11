#include "main.h"

void affichage(struct logement *tableau, int k)
{
	int compteur;
	for (compteur=2;compteur<k+2;compteur++){
		printf("%d\n",tableau[compteur].distance);}
}
