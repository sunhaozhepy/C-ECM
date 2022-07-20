void al_prod_mat_vect(int **a, int m, int n, int *x, int *y)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        y[i] = 0;
        for (j = 0; j < n; j++)
        {
            y[i] += a[i][j] * x[j];
        }
    }
}