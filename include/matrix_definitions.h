#ifndef MATRIX_DEFINITIONS_HEADER
#define MATRIX_DEFINITIONS_HEADER

// matrix size struct
typedef struct Matrix_size 
{
    int rows_num;
    int cols_num;
} Matrix_size, *Matrix_size_p;

// matrix struct
typedef struct Matrix
{
    Matrix_size_p size;
    double ** data;
} Matrix, *Matrix_p;

#endif