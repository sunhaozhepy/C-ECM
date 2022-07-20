#include <stdio.h>
#include <stdlib.h>

void exchange(int *x, int *y)
{
	int tampon = *x;
	*x = *y;
	*y = tampon;
}