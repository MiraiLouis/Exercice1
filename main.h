#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define TAILLE_MAX 50

//Structures

struct logement
{
	int id;
	int accomodates;
	int bedrooms;
	int bathrooms;
	int beds;
	int price;
	int minimum_nights;
	int maximum_nights;
	int number_of_reviews;
	int distance;
};

//Fonctions

void affichage(struct logement *tableau, int k);
int calculDistance(int x, int val);
int calculDistance2(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8, int y1, int y2, int y3, int y4, int y5, int y6, int y7, int y8);
int calculMoyenne(struct logement *tableau, int k);
void lecture(struct logement *pointeurLogement);
void randomize (struct logement *tableau, int n );
void swap (struct logement *A, struct logement *B);
void triTab(struct logement *tableau, int n);
