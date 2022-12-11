#include "main.h"

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
