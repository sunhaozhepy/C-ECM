#include <stdio.h>
#include <stdlib.h>

int *allocate1DArray(int n)
{
	int i;
	// Allocation of a 1D array
	int *x = (int *)malloc((size_t)n * sizeof(int));

	if (!x)
	{
		printf("Memory allocation error!");
		exit(0);
	}

	for (i = 0; i < n; i++)
		*(x + i) = 0; // x[0] = 0;

	return x;
}

void free1DArray(int *tab)
{
	free(tab);
}

void print1DArray(int *array, int dim)
{
	int i;
	printf("1D Array: [");

	for (i = 0; i < dim; i++)
		printf(" %i ", *(array + i));

	printf("] \n");
}

void init1DArray(int *array, int dim, int val)
{
	int i;

	for (i = 0; i < dim; i++)
		*(array + i) = val;
}