#ifndef MATRIX_CALCULATOR_HEADER
#define MATRIX_CALCULATOR_HEADER

#include "matrix_operations.h"

// menu operation request
int request_operation(void);

// available operations
void Sum_matrices(void);

// auxiliar functions to request size and data from a given matrix
Matrix_size_p Request_size(void);
Matrix_p Request_matrix(Matrix_size_p);

#endif