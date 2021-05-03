#include "../include/matrix_operations.h"

Matrix_p Create_matrix(Matrix_size_p size)
{
    Matrix_p mat_ptr = (Matrix_p)malloc(sizeof(Matrix));

    // generate the copy of the size pointer
    mat_ptr -> size = (Matrix_size_p)malloc(sizeof(Matrix_size));
    mat_ptr -> size -> cols_num = size -> cols_num;
    mat_ptr -> size -> rows_num = size -> rows_num;

    //reserve the memory of the data
    mat_ptr -> data = (double **) malloc(sizeof(double*) * size -> rows_num);

    int i;
    for(i = 0; i < size -> rows_num; i++){
        mat_ptr -> data[i] = (double *) malloc(sizeof(double) * size -> cols_num);
    }

    //return the pointer
    return mat_ptr;
}

void Fill_matrix(Matrix_p mat)
{
    int i = 0, j = 0;

    if(mat == NULL){
        printf("ERROR: mat is null");
        exit(3);
    }

    for(i= 0; i < mat-> size -> rows_num; i++){
        for(j = 0; j < mat-> size -> cols_num; j++){
            printf("[%d][%d]? ", i, j);
            if(scanf("%lf", &(mat->data[i][j])) != 1){
                printf("ERROR: incorrect number read at indexes [%d][%d]", i, j);
            }
        }
    }
}

void Print_matrix(Matrix_p mat)
{
    int i = 0, j = 0;

    if(mat == NULL){
        printf("ERROR: mat is null");
        exit(3);
    }

    printf("\nFilled data: \n");

    for(i= 0; i < mat -> size -> rows_num; i++){
        for(j = 0; j < mat -> size -> cols_num; j++){
            printf("[%d][%d] = %.3f\n", i, j, mat -> data[i][j]);
        }
    }

    printf("\n");
}

//////////////////////////////////////////////////////////////////////////////////////////////
// Matrix Operations
//////////////////////////////////////////////////////////////////////////////////////////////

Matrix_p Get_sum(Matrix_p mat_one, Matrix_p mat_two)
{
    if(mat_one -> size -> cols_num != mat_two -> size -> cols_num ||
       mat_one -> size -> rows_num != mat_two -> size -> rows_num ){
        printf("Size of both matrices must be the same.\n");
        printf("Matrix one size: %d x %d.\n", mat_one -> size -> rows_num, mat_one -> size -> cols_num);
        printf("Matrix two size: %d x %d.\n", mat_two -> size -> rows_num, mat_two -> size -> cols_num);
        exit(4);
    }

    Matrix_p sum = Create_matrix(mat_one -> size);

    int i,j;
    for(i= 0; i < mat_one -> size -> rows_num; i++){
        for(j = 0; j < mat_one -> size -> cols_num; j++){
            sum -> data[i][j] = mat_one -> data[i][j] + mat_two -> data[i][j];
        }
    }

    return sum;
}