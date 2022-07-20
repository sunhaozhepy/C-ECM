#include <stdio.h>
#include <stdlib.h>

int **allocate2DArray(int n, int m)
{

	// Allocation of an array of int
	int i = 0;
	int **array;

	// Allocate of the array of pointers to rows
	array = (int **)malloc((size_t)(n * sizeof(int *)));
	if (!array)
	{
		printf("Memory allocation error !!");
		exit(0);
	}

	// Allocate of the coefficients of the array and initialize them
	*array = (int *)malloc((size_t)(n * m * sizeof(int)));
	if (!(*array))
	{
		printf("Memory allocation error !!");
		exit(0);
	}
	for (i = 0; i < (n * m); i++)
		*((*array) + i) = 0;

	// Set the pointers to the rows
	for (i = 1; i < n; i++)
		*(array + i) = (*(array + i - 1) + m);

	return array;
}

void print2DArray(int **array, int n, int m)
{

	int i, j;
	// Size of the 1D array storing the values of the array

	printf("2D array \n");
	for (i = 0; i < n; i++)
	{

		printf("[");

		for (j = 0; j < m; j++)
			printf(" %i ", *(*(array + i) + j));
		//	printf(" %d " , array[i][j] );

		printf("]\n");
	}
}

void init2DArray(int **array, int n, int m, int val)
{
	int i;
	// Size of the 1D array storing the values of the array
	int size = n * m;
	for (i = 0; i < size; i++)
		*((*array) + i) = val;
}

void free2DArray(int **array)
{
	free(*array);
	free(array);
}