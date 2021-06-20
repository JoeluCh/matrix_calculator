#ifndef _MATRIX_CALCULATOR_H_
#define _MATRIX_CALCULATOR_H_

#include "matrix_operations.h"

// menu operation request
int request_operation(void);

// available operations
Matrix_p Join_matrices(BOOL);
Matrix_p Sum_matrices(void);
Matrix_p Substract_matrices(void);
Matrix_p Scale_matrix(void);


// auxiliar functions to request size and data from a given matrix
Matrix_size_p Request_size(void);
Matrix_p Request_matrix(Matrix_size_p);

#endif