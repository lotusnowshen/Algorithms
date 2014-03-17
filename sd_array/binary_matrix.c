#include <stdio.h>
#include <string.h>
#include <assert.h>

#define M 10
#define N 9

struct Matrix
{
    int A[M][N];
    int m;
    int n;
};

void init_matrix(struct Matrix *p_matrix, int m, int n)
{
    memset(p_matrix->A, 0, sizeof(struct Matrix));
    p_matrix->m = m;
    p_matrix->n = n;
}

void input_matrix(struct Matrix *p_matrix)
{
    int i, j;
    for(i = 0; i != p_matrix->m; ++i)
    {
        for(j=0; j != p_matrix->n; ++j)
        {
            scanf("%d", &(p_matrix->A[i][j]));
        }
    }

}

void debug_matrix(struct Matrix *p_matrix)
{

    int i, j;
    for(i = 0; i != p_matrix->m; ++i)
    {
        for(j=0; j != p_matrix->n; ++j)
        {
            printf("%d ", p_matrix->A[i][j]);
        }
        printf("\n");
    }
}

int find_matrix(struct Matrix *p_matrix, int key, int *m, int *n)
{
    int found = 0;
    assert(p_matrix);
    int rows = p_matrix->m;
    int cols = p_matrix->n;
    int row = 0;
    int col = cols-1;
    while(row < rows && col >= 0)
    {
        if(p_matrix->A[row][col] == key)
        {
            found = 1;
            *m = row;
            *n = col;
            break;
        }
        else if (p_matrix->A[row][col] > key)
        {
            --col;
        }else
        {
            ++row;
        }
    }
    return found;
}

int main(void)
{
    freopen("in.txt", "r", stdin);
    struct Matrix mat;
    int m, n;
    init_matrix(&mat, 4, 4);
    input_matrix(&mat);
    debug_matrix(&mat);
    int found = find_matrix(&mat, 7, &m, &n);

    printf("%d %d %d",found, m, n);
    return 0;
}
