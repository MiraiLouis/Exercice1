#include "main.h"

int calculMoyenne(struct logement *tableau, int k)
{
	int compteur;
	int res=0;
	for (compteur=2;compteur<k+2;compteur++){
		res=res+tableau[compteur].distance;}
	return res/k;
}
