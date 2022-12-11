#include "main.h"

void swap (struct logement *A, struct logement *B)
{	struct logement temp = *A;
	*A = *B;
	*B = temp;
}

