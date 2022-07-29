#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int** malloc2d(int n_lines, int n_columns);
void initialize2d(int** ptr, int n_lines, int n_columns, double prob);
void free2d(int** ptr, int n_lines);
void iterate(int** ptr, int** ptr_new, int n_lines, int n_columns);
void show(int** ptr, int n_lines, int n_columns);
int sum(int** ptr, int i, int j, int n_lines, int n_columns);

int main(int argc, char** argv)
{
    int n_lines, n_columns, n_iterations, frames;
    double prob;
    int** ptr;
    int** ptr_new;
    if (argc > 1)
    {
        if (argv[1][0] == '-')
        {
            if (argv[1][1] == 'r')
            //read from existing file
            {
                if (argc != 5)
                {
                    printf("Incorrect number of parameters. Please enter after -r:\n");
                    printf("the file name, number of iterations, FPS (frames per second).\n");
                    exit(1);
                }
                char* file_name = argv[2];
                n_iterations = atoi(argv[3]);
                frames = atoi(argv[4]);
                FILE* f = fopen(file_name, "r");
                if (f == NULL)
                {
                    printf("No such file.\n");
                    exit(1);
                }
                fscanf(f, "%d %d", &n_lines, &n_columns);
                ptr = malloc2d(n_lines, n_columns);
                ptr_new = malloc2d(n_lines, n_columns);
                for (int i=0; i<n_lines; i++)
                {
                    for (int j=0; j<n_columns; j++)
                    {
                        fscanf(f, "%d", *(ptr+i)+j);
                    }
                }
                fclose(f);
            }
            else if (argv[1][1] == 'n')
            //create new game
            {
                if (argc != 7)
                {
                    printf("Incorrect number of parameters. Please enter in order: after -n:\n");
                    printf("number of lines, number of columns, number of iterations,\n");
                    printf("FPS (frames per second), probability of initial life.\n");
                    exit(1);
                }
                n_lines = atoi(argv[2]);
                n_columns = atoi(argv[3]);
                n_iterations = atoi(argv[4]);
                frames = atoi(argv[5]);
                prob = atof(argv[6]);
                srand(time(NULL));
                ptr = malloc2d(n_lines, n_columns);
                initialize2d(ptr, n_lines, n_columns, prob);
                ptr_new = malloc2d(n_lines, n_columns);
                printf("Gameboard initialized.\n");
            }
            else
            {
                printf("Please specify the option in the first parameter:\n");
                printf("-r for reading from a file, -n for creating a new life game.\n");
                exit(1);
            }
        }
        else
        {
            printf("Please specify the option in the first parameter:\n");
            printf("-r for reading from a file, -n for creating a new life game.\n");
            exit(1);
        }
    }
    else
    {
        printf("Please specify the option in the first parameter:\n");
        printf("-r for reading from a file, -n for creating a new life game.\n");
        exit(1);
    }
    printf("Game starts in 3 seconds...\n");
    printf("(terminal will be cleared)\n");
    sleep(3);
    show(ptr, n_lines, n_columns);
    int** tmp;
    for (int i=0; i<n_iterations; i++)
    {
        usleep(1000000/frames);
        iterate(ptr, ptr_new, n_lines, n_columns);
        tmp = ptr_new;
        ptr_new = ptr;
        ptr = tmp;
        show(ptr, n_lines, n_columns);
    }
    FILE* f = fopen("result.txt", "w");
    fprintf(f, "%d %d\n", n_lines, n_columns);
    for (int i=0; i<n_lines; i++)
    {
        for (int j=0; j<n_columns; j++)
        {
            fprintf(f, "%d\n", ptr[i][j]);
        }
    }
    free2d(ptr, n_lines);
    free2d(ptr_new, n_lines);
    return 0;
}

int** malloc2d(int n_lines, int n_columns)
//dynamic allocation of memory for a 2-D array
{
    int** ptr = (int**)malloc(sizeof(int*)*n_lines);
    for (int i=0; i<n_lines; i++)
    {
        *(ptr+i) = (int*)malloc(sizeof(int)*n_columns);
    }
    return ptr;
}

void initialize2d(int** ptr, int n_lines, int n_columns, double prob)
//initialize the 2-D array
{
    for (int i=0; i<n_lines; i++)
    {
        for (int j=0; j<n_columns; j++)
        {
            double n = (double)rand()/RAND_MAX;
            if (n < prob)
            {
                ptr[i][j] = 1;
            }
            else
            {
                ptr[i][j] = 0;
            }
        }
    }
}

void free2d(int** ptr, int n_lines)
//deallocation of memory for a given 2-D array
{
    for (int i=0; i<n_lines; i++)
    {
        free(*(ptr+i));
    }
    free(ptr);
}

void iterate(int** ptr, int** ptr_new, int n_lines, int n_columns)
//iterate as the rule stipulates
{
    for (int i=0; i<n_lines; i++)
    {
        for (int j=0; j<n_columns; j++)
        {
            int sum_context = sum(ptr, i, j, n_lines, n_columns);
            if (sum_context == 2)
            {
                ptr_new[i][j] = ptr[i][j];
            }
            else if (sum_context == 3)
            {
                ptr_new[i][j] = 1;
            }
            else
            {
                ptr_new[i][j] = 0;
            }
        }
    }
}

void show(int** ptr, int n_lines, int n_columns)
//show the current status of the array
{
    system("clear");
    for (int i=0; i<n_lines; i++)
    {
        for (int j=0; j<n_columns; j++)
        {
            if (*(*(ptr+i)+j) == 1)
            {
                printf("o");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
    }
}

int sum(int** ptr, int i, int j, int n_lines, int n_columns)
//sum up the eight (or less) neighbouring elements of the current element
{
    int elem1, elem2, elem3, elem4, elem5, elem6, elem7, elem8;
    if (i == 0)
    {
        if (j == 0)
        {
            elem1 = 0;
            elem2 = 0;
            elem3 = 0;
            elem4 = 0;
            elem5 = ptr[i][j+1];
            elem6 = 0;
            elem7 = ptr[i+1][j];
            elem8 = ptr[i+1][j+1];
        }
        else if (j == n_columns - 1)
        {
            elem1 = 0;
            elem2 = 0;
            elem3 = 0;
            elem4 = ptr[i][j-1];
            elem5 = 0;
            elem6 = ptr[i+1][j-1];
            elem7 = ptr[i+1][j];
            elem8 = 0;
        }
        else
        {
            elem1 = 0;
            elem2 = 0;
            elem3 = 0;
            elem4 = ptr[i][j-1];
            elem5 = ptr[i][j+1];
            elem6 = ptr[i+1][j-1];
            elem7 = ptr[i+1][j];
            elem8 = ptr[i+1][j+1];
        }
    }
    else if (i == n_lines - 1)
    {
        if (j == 0)
        {
            elem1 = 0;
            elem2 = ptr[i-1][j];
            elem3 = ptr[i-1][j+1];
            elem4 = 0;
            elem5 = ptr[i][j+1];
            elem6 = 0;
            elem7 = 0;
            elem8 = 0;
        }
        else if (j == n_columns - 1)
        {
            elem1 = ptr[i-1][j-1];
            elem2 = ptr[i-1][j];
            elem3 = 0;
            elem4 = ptr[i][j-1];
            elem5 = 0;
            elem6 = 0;
            elem7 = 0;
            elem8 = 0;
        }
        else
        {
            elem1 = ptr[i-1][j-1];
            elem2 = ptr[i-1][j];
            elem3 = ptr[i-1][j+1];
            elem4 = ptr[i][j-1];
            elem5 = ptr[i][j+1];
            elem6 = 0;
            elem7 = 0;
            elem8 = 0;
        }
    }
    else
    {
        if (j == 0)
        {
            elem1 = 0;
            elem2 = ptr[i-1][j];
            elem3 = ptr[i-1][j+1];
            elem4 = 0;
            elem5 = ptr[i][j+1];
            elem6 = 0;
            elem7 = ptr[i+1][j];
            elem8 = ptr[i+1][j+1];
        }
        else if (j == n_columns - 1)
        {
            elem1 = ptr[i-1][j-1];
            elem2 = ptr[i-1][j];
            elem3 = 0;
            elem4 = ptr[i][j-1];
            elem5 = 0;
            elem6 = ptr[i+1][j-1];
            elem7 = ptr[i+1][j];
            elem8 = 0;
        }
        else
        {
            elem1 = ptr[i-1][j-1];
            elem2 = ptr[i-1][j];
            elem3 = ptr[i-1][j+1];
            elem4 = ptr[i][j-1];
            elem5 = ptr[i][j+1];
            elem6 = ptr[i+1][j-1];
            elem7 = ptr[i+1][j];
            elem8 = ptr[i+1][j+1];
        }
    }
    int sum = elem1 + elem2 + elem3 + elem4 + elem5 + elem6 + elem7 + elem8;
    return sum;
}
