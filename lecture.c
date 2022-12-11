#include "main.h"

void lecture(struct logement *pointeurLogement){
FILE* fichier= NULL;
char logt[TAILLE_MAX] = "";
const char * sep =",";
int i = 0;
int compteur_col = 0;
char * id;
int id2;
char * accomodates;
int accomodates2;
char * bedrooms;
int bedrooms2;
char * bathrooms;
int bathrooms2;
char * beds;
int beds2;
char * price;
int price2;
char * minimum_nights;
int min_nights2;
char * maximum_nights;
int max_nights2;
char * number_of_reviews;
int number_of_reviews2;
int distance = 0;
int x1;
int x2;
int x3;
int x4;
int x5;
int x6;
int x7;
int x8;
int k;

fichier = fopen("airbnb_donnees_propre.csv", "r+");

if (fichier != NULL)
{	printf("\nAccomodates?\n");
	scanf("%d",&x1);  //accomodates du logement à évaluer
	printf("\nBedrooms?\n");
	scanf("%d",&x2);  //bedrooms du logement à évaluer
	printf("\nBathrooms?\n");
	scanf("%d",&x3);  //bathrooms du logement à évaluer
	printf("\nBeds?\n");
	scanf("%d",&x4);  //beds du logement à évaluer
	printf("\nPrice?\n");
	scanf("%d",&x5);  //price du logement à évaluer
	printf("\nMinimum nights?\n");
	scanf("%d",&x6);  //minimum_nights du logement à évaluer
	printf("\nMaximum nights?\n");
	scanf("%d",&x7);  //maximum_nights du logement à évaluer
	printf("\nNumber of reviews?\n");
	scanf("%d",&x8);  //Number of reviews du logement à évaluer
	printf("\n Nombre de logements à comparer?");
	scanf("%d",&k);
	//Initialisation des critères
	int n;
	int z1=0;
	int z2=0;
	int z3=0;
	int z4=0;
	int z5=0;
	int z6=0;
	int z7=0;
	int z8=0;
	printf("\n Nombres de critères à comparer? ");
	scanf("%d",&n);
	if (n>8)
	{
		printf("Trop de critères!");
	}
	else
	{	int k;
		for (k=0;k<n;k++)
		{	
			int x;
			printf("Numéro du critère choisi: ");
			scanf("%d",&x);
			switch(x)
			{
				case 1:
					z1=x1;
					break;
				case 2:
					z2=x2;
					break;
				case 3:
					z3=x3;
					break;
				case 4:
					z4=x4;
					break;
				case 5:
					z5=x5;
					break;
				case 6:
					z6=x6;
					break;
				case 7:
					z7=x7;
					break;
				case 8:
					z8=x8;
					break;
			}
		}
	}
	
	struct logement tableau[7918]; //tableau de struct des logements
	while(fgets(logt, TAILLE_MAX, fichier) != NULL)
	{
		if (i>1) //permet de ne pas prendre la première ligne
		{	
			char * valeurs = strtok (logt, sep);
			id = valeurs;
			id2 = strtol(id,NULL,10);  //on convertit en int les char* de valeurs
			compteur_col = 0;
			while (valeurs != NULL)
			{	//printf ("%s\n", valeurs);
				if (compteur_col == 8)  //permet de ne pas dépasser de colonne
				{
					break;
				}
				valeurs = strtok(NULL, sep);
				if (compteur_col == 0)
				{ 
					accomodates = valeurs;
					accomodates2 = strtol(accomodates,NULL,10);
				}
				if (compteur_col == 1)
				{ 
					bedrooms = valeurs;
					bedrooms2 = strtol(bedrooms,NULL,10);
				}
				if (compteur_col == 2)
				{ 
					bathrooms = valeurs;
					bathrooms2 = strtol(bathrooms,NULL,10);
				}
				if (compteur_col == 3)
				{ 
					beds = valeurs;
					beds2 = strtol(beds,NULL,10);
				}
				if (compteur_col == 4)
				{ 
					price = valeurs;
					price2 = strtol(price,NULL,10);
				}
				if (compteur_col == 5)
				{ 
					minimum_nights = valeurs;
					min_nights2 = strtol(minimum_nights,NULL,10);
				}
				if (compteur_col == 6)
				{ 
					maximum_nights = valeurs;
					max_nights2 = strtol(maximum_nights,NULL,10);
				}
				if (compteur_col == 7)
				{ 
					number_of_reviews = valeurs;
					number_of_reviews2 = strtol(number_of_reviews,NULL,10);
				}
				compteur_col = compteur_col+1;
			}
			//distance=calculDistance(x, price2);
			distance=calculDistance2(z1, z2, z3, z4, z5, z6, z7, z8, accomodates2, bedrooms2, bathrooms2, beds2, price2, min_nights2, max_nights2, number_of_reviews2);
			struct logement logement2 = {id2, accomodates2, bedrooms2, bathrooms2, beds2, price2, min_nights2, max_nights2, number_of_reviews2, distance};
			tableau[i]=logement2;
		}
		i = i+1;
	}
	randomize(tableau, 7917);                //randomize le tableau
	triTab(tableau, k+2);               //trie k éléments du tableau
	printf("\n tri \n");
	affichage(tableau,k);
	printf("\n moyenne: \n");
	int res;
	res=calculMoyenne(tableau,k);
	printf("%d\n",res);
}
else
{
	printf("Erreur fichier");
}
}
