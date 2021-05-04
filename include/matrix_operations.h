#ifndef MATRIX_OPERATIONS_HEADER
#define MATRIX_OPERATIONS_HEADER

#include <stdio.h>
#include <stdlib.h>

#include "matrix_definitions.h"
#include "basic_definitions.h"

Matrix_p Create_matrix(Matrix_size_p size);
void Fill_matrix(Matrix_p mat);
void Print_matrix(Matrix_p mat);

// operations
Matrix_p Get_sum(Matrix_p mat_one, Matrix_p mat_two);
Matrix_p Get_substraction(Matrix_p mat_one, Matrix_p mat_two);
Matrix_p Apply_operation(Matrix_p mat_one, Matrix_p mat_two, BOOL is_sum);

#endif