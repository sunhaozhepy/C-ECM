#include <stdio.h>
#include <stdlib.h>

void exchange(int *, int *);
int *allocate1DArray(int n);
void free1DArray(int *tab);
void print1DArray(int *array, int dim);
void init1DArray(int *array, int dim, int val);
void al_prod_mat_vect(int **a, int n, int m, int *x, int *y);
int **allocate2DArray(int n, int m);
void print2DArray(int **array, int n, int m);
void init2DArray(int **array, int n, int m, int val);
void free2DArray(int **array);

int main(void)
{

	/*  Exercice 1  */

	int a = 5;
	int b = 3;

	printf("\n\n\n\n\n\n*************   EXERCICE 1   *************\n\n");

	printf("a= %i; b=%i\n", a, b);
	exchange(&a, &b);
	printf("a= %i; b=%i\n", a, b);

	/*  Exercice 2  */

	int c = 5;
	int val = 99;

	printf("\n\n\n\n\n\n*************   EXERCICE 2   *************\n\n");

	int *table = allocate1DArray(c);
	print1DArray(table, c);
	init1DArray(table, c, val);
	print1DArray(table, c);
	free1DArray(table);

	/*  Exercice 3  */

	int d = 3;
	int e = 4;

	printf("\n\n\n\n\n\n*************   EXERCICE 3   *************\n\n");

	int **matrix = allocate2DArray(d, e);
	print2DArray(matrix, d, e);
	init2DArray(matrix, d, e, val);
	print2DArray(matrix, d, e);

	//free2DArray(matrix);*/

	printf("\n\n\n\n\n\n*************   EXERCICE 4   *************\n\n");

	/*	int* table1 = allocate1DArray( e );
			int* table2 = allocate1DArray( d );
				print1DArray(table1 , e);
					init1DArray(table1 , e , val);
			al_prod_mat_vect(matrix,d,e,table1,table2);
			print1DArray(table2 , d);*/

	return 1;
}