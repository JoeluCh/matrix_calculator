#define PRINT_FILLED_DATA FALSE

#include "../include/matrix_calculator.h"

typedef enum MENU_OPTIONS
{
    SUM          = 1,
    SUBSTRACTION = 2,
    EXIT         = 3,
} MENU_OPTIONS;

int main()
{
    printf("---------------------------------\n");
    printf("Matrix calculator \n");
    MENU_OPTIONS selected_option;

    while (TRUE)
    {
        selected_option = request_operation();
        switch(selected_option)
        {
            case SUM:
                Sum_matrices();
            break;

            case SUBSTRACTION:
                Substract_matrices();
            break;

            case EXIT:
                printf("Exiting matrix calculator...\n");
                system("pause");
                return 0;
            default:
                printf("Operation number \"%d\" not supported.", selected_option);
        }      
    }
}

int request_operation()
{
    int option;

    printf("Select the matrix operation to be performed:\n");
    printf("%d. Addition\n", SUM);
    printf("%d. Substraction\n", SUBSTRACTION);
    printf("%d. Exit\n", EXIT);
    printf("Option: ");

    if(scanf("%d", &option) != 1){
        printf("ERROR: Input is not a valid number.");
        system("pause");
        exit(1);
    }

    printf("\n");

    return option;
}

void Sum_matrices()
{
    Join_matrices(TRUE);
}

void Substract_matrices()
{
    Join_matrices(FALSE);
}

void Join_matrices(BOOL is_sum)
{
    if(is_sum){
        printf("Sum of matrices:\n");
    }
    else{
        printf("Substraction of matrices:\n");
    }

    Matrix_size_p size = Request_size();    
    printf("\n");

    printf("Matrix A:\n");
    Matrix_p A = Request_matrix(size);
    printf("\n");

    // create and fill B matrix
    printf("Matrix B:\n");
    Matrix_p B = Request_matrix(size);
    printf("\n");

    Matrix_p C = NULL;

    if(is_sum){
        printf("C = A + B is:\n");
        C = Get_sum(A, B);
    }else{
        printf("C = A - B is:\n");
        C = Get_substraction(A, B);
    }

    //print results
    Print_matrix(C);

    // release memory resources
    free(size);
    free(A);
    free(B);
    free(C);
}

Matrix_size_p Request_size()
{
    // reserve memory for the size struct
    Matrix_size_p size_data = (Matrix_size_p)malloc(sizeof(Matrix_size));

    printf("m? ");
    if(scanf("%d", &(size_data -> rows_num)) != 1){
        printf("ERROR: Input is not a valid number.");
        system("pause");
        exit(1);
    }

    if(size_data -> rows_num <= 0){
        printf("ERROR: Rows number must be greater than zero.");
        system("pause");
        exit(2);
    }

    printf("n? ");
    if(scanf("%d", &(size_data -> cols_num)) != 1){
        printf("ERROR: Input is not a valid number.");
        system("pause");
        exit(1);
    }

    if(size_data -> cols_num <= 0){
        printf("ERROR: Columns number must be greater than zero.");
        system("pause");
        exit(2);
    }

    return size_data;
}

Matrix_p Request_matrix(Matrix_size_p size){
    Matrix_p mat = Create_matrix(size);
    Fill_matrix(mat);

    if(PRINT_FILLED_DATA == TRUE){
        printf("\n");
        Print_matrix(mat);
        printf("\n");
    }

    return mat;
}
