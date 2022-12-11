#include "main.h"

void triTab(struct logement *tableau, int n)
{		
	int i,j;
	struct logement temp= {0,0,0,0, 0, 0, 0, 0, 0,0};
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
