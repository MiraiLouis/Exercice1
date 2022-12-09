void affichage(struct logement *tableau, int k)
{
	int compteur;
	for (compteur=2;compteur<k+2;compteur++){
		printf("%d\n",tableau[compteur].distance);}
}

int calculMoyenne(struct logement *tableau, int k)
{
	int compteur;
	int res=0;
	for (compteur=2;compteur<k+2;compteur++){
		res=res+tableau[compteur].distance;}
	return res/k;
}

int calculDistance(int x, int val) {
return abs(x-val);
}

int calculDistance2(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8, int y1, int y2, int y3, int y4, int y5, int y6, int y7, int y8){
return sqrt(pow((x1-y1),2)+pow((x2-y2),2)+pow((x3-y3),2)+pow((x4-y4),2)+pow((x5-y5),2)+pow((x6-y6),2)+pow((x7-y7),2)+pow((x8-y8),2));
}

void swap (struct logement *A, struct logement *B)
{	struct logement temp = *A;
	*A = *B;
	*B = temp;
}

void randomize (struct logement *tableau, int n )
{
    srand ( time(NULL) );
    for (int i = n+1; i > 0; i--)
    {
        int j = rand() % (i+1);
        if (j!=1 && j!=0){
        swap(&tableau[i],&tableau[j]);}
    }
}

void triTab(struct logement *tableau, int n)
{		
	int i,j;
	struct logement temp;
	for (i=1;i<n;i++)
	{
		temp=tableau[i];
		j=i-1;
		while (j>=0 && tableau[j].distance>temp.distance)
		{
			tableau[j+1]=tableau[j];
			j=j-1;
		}
		tableau[j+1]=temp;
	}
}

///////////////////////////////////////////////

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
int compteur=0; //Compteur de la boucle for

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
			distance=calculDistance2(x1, x2, x3, x4, x5, x6, x7, x8, accomodates2, bedrooms2, bathrooms2, beds2, price2, min_nights2, max_nights2, number_of_reviews2);
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

int main() {
	struct logement logement;
	lecture(&(logement));
	return 0;
	}

