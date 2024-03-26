#include <stdio.h>

void inputMatrices(int mat1[2][2], int mat2[2][2])
{
	int i,j;
    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < 2; i++)
    {
        for ( j = 0; j < 2; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter the elements of the second matrix:\n");
    for ( i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }
}

void addMatrices(int mat1[2][2], int mat2[2][2], int res[2][2])
{
	int i,j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subMatrices(int mat1[2][2], int mat2[2][2], int res[2][2])
{
	int i,j;
    for ( i = 0; i < 2; i++)
    {
        for ( j = 0; j < 2; j++)
        {
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiply(int mat1[2][2], int mat2[2][2], int res[2][2])
{
    int p1[2][2], p2[2][2], p3[2][2], p4[2][2], p5[2][2], p6[2][2], p7[2][2];

    // divide matrices into 4 parts
    p1[0][0] = mat1[0][0], p1[0][1] = mat1[0][1], p1[1][0] = mat1[1][0], p1[1][1] = 0;
    p2[0][0] = mat1[0][0], p2[0][1] = 0, p2[1][0] = mat1[1][0], p2[1][1] = mat1[1][1];
    p3[0][0] = 0, p3[0][1] = mat1[0][1], p3[1][0] = mat1[1][1], p3[1][1] = 0;
    p4[0][0] = mat1[0][0], p4[0][1] = 0, p4[1][0] = 0, p4[1][1] = mat1[1][1];

    // calculate the sub-matrices
    addMatrices(mat2, p1, p5);
    addMatrices(p4, p3, p6);
    subMatrices(p2, p3, p7);
    subMatrices(p1, p4, p1);

    // calculate the sub-matrix multiplications
    multiply(p5, p7, p7);
    multiply(p6, p1, p1);
    multiply(p2, p3, p3);
    multiply(p4, p6, p6);
    addMatrices(p1, p6, p6);
    addMatrices(p3, p5, p5);
    subMatrices(p7, p6, p7);
    addMatrices(p5, p7, p5);
    addMatrices(p5, p3, res);
}

void printMatrix(int mat[2][

#include <stdio.h>

void inputMatrices(int mat1[2][2], int mat2[2][2])
{
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)	
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }
}

void addMatrices(int mat1[2][2], int mat2[2][2], int res[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subMatrices(int mat1[2][2], int mat2[2][2], int res[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiply(int mat1[2][2], int mat2[2][2], int res[2][2])
{
    int p1[2][2], p2[2][2], p3[2][2], p4[2][2], p5[2][2], p6[2][2], p7[2][2];

    // divide matrices into 4 parts
    p1[0][0] = mat1[0][0], p1[0][1] = mat1[0][1], p1[1][0] = mat1[1][0], p1[1][1] = 0;
    p2[0][0] = mat1[0][0], p2[0][1] = 0, p2[1][0] = mat1[1][0], p2[1][1] = mat1[1][1];
    p3[0][0] = 0, p3[0][1] = mat1[0][1], p3[1][0] = mat1[1][1], p3[1][1] = 0;
    p4[0][0] = mat1[0][0], p4[0][1] = 0, p4[1][0] = 0, p4[1][1] = mat1[1][1];

    // calculate the sub-matrices
    addMatrices(mat2, p1, p5);
    addMatrices(p4, p3, p6);
    subMatrices(p2, p3, p7);
    subMatrices(p1, p4, p1);

    // calculate the sub-matrix multiplications
    multiply(p5, p7, p7);
    multiply(p6, p1, p1);
    multiply(p2, p3, p3);
    multiply(p4, p6, p6);
    addMatrices(p1, p6, p6);
    addMatrices(p3, p5, p5);
    subMatrices(p7, p6, p7);
    addMatrices(p5, p7, p5);
    addMatrices(p5, p3, res);
}

void printMatrix(int mat[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main()i][
{
    int mat1[2][2], mat2[2][2], res[2][2];

    // input matrices
    inputMatrices(mat1, mat2);

    // perform matrix multiplication
    multiply(mat1, mat2, res);

    // print the result
    printMatrix(res);

    return 0;
}
