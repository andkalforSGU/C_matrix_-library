#include <stdio.h>
#include <stdlib.h>

//------------------------VECTOR-----------------------------

void print_vector(int* V, int size, FILE* output);
int* read_vector(int* V, int size, FILE* input);
int* E_vector(int size);
int* sum_vector(int* V, int* W, int size);
int* mult_num_vector(int* V, int size, int num);
int* mult_vectors(int* V, int* W, int size);
int* mult_vector_matrix(int* V, int** A, int size); 
int* pow_vector(int* V, int size, int num);

//------------------------MATRIX-----------------------------

void print_matrix(int** A, int size, FILE* output);
int** read_matrix(int** A, int size, FILE* input);
int** E_matrix(int size);
int** T_matrix(int** A, int size);
int** sum_matrix(int** A, int** B, int size);
int** mult_num_matrix(int** A, int size, int num);
int** mult_matrix(int** A, int** B, int size);
int** pow_matrix(int** A, int size, int num);

//-----------------------------------------------------------

int main(int argc, char* argv[]) {
    FILE* input = fopen(argv[2], "r");
    FILE* output = fopen(argv[3], "w");

    int size = atoi(argv[1]);

    int* V = (int*)malloc(size*sizeof(int));
    int** A = (int**)malloc(size*sizeof(int*));
    for (int i = 0; i < size; i++) {
        A[i] = (int*)malloc(size*sizeof(int));
    }

    int** B = (int**)malloc(size*sizeof(int*));
    for (int i = 0; i < size; i++) {
        B[i] = (int*)malloc(size*sizeof(int));
    }

//------------Here you can try out the functions-------------

    

//-----------------------------------------------------------

    for (int i = 0; i < size; i++) {
        free(A[i]);
    }
    free(A);
    for (int i = 0; i < size; i++) {
        free(B[i]);
    }
    free(B);
    fclose(output);
    fclose(input);
}

//------------------------VECTOR-----------------------------

void print_vector(int* V, int size, FILE* output) {
    for (int i = 0; i < size; i++) {
        fprintf(output, "%d ", V[i]);
    }
}

//-----------------------------------------------------------

int* read_vector(int* V, int size, FILE* input) {
    for (int i = 0; i < size; i++) {
        fscanf(input, "%d", &(V[i]));
    }

    return V;
}

//-----------------------------------------------------------

int* E_vector(int size) {
    int* V = (int*)malloc(size*sizeof(int));

    for (int i = 0; i < size; i++) {
        V[i] = 1;
    }

    return V;
}

//-----------------------------------------------------------

int* sum_vector(int* V, int* W, int size) {
    int* D = (int*)malloc(size*sizeof(int));

    for (int i = 0; i < size; i++) {
        D[i] = V[i]+W[i];
    }

    return D;
}

//-----------------------------------------------------------

int* mult_num_vector(int* V, int size, int num) {
    for (int i = 0; i < size; i++) {
        V[i] *= num;
    }

    return V;
}

//-----------------------------------------------------------

int* mult_vectors(int* V, int* W, int size) {
    int* D = (int*)malloc(size*sizeof(int));

    for (int i = 0; i < size; i++) {
        D[i] = V[i]*W[i];
    }

    return D;
}

//-----------------------------------------------------------

int* mult_vector_matrix(int* V, int** A, int size) {
    int* W = (int*)calloc(size, sizeof(int));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            W[i] += A[i][j] * V[i];
        }
    }

    return W;
}

//-----------------------------------------------------------

int* pow_vector(int* V, int size, int num) {
    int* W = (int*)malloc(size*sizeof(int));
    for (int i = 0; i < size; i ++) {
        W[i] = V[i];
    }

    for (int i = 0; i < num-1; i++) {
        for (int j = 0; j < size; j++) {
            V[j] *= W[j];
        }
    }

    free(W);

    return V;
}

//------------------------MATRIX-----------------------------

void print_matrix(int** A, int size, FILE* output) {
    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size; j++) {
            fprintf(output, "%d ", A[i][j]);
        }
        fprintf(output, "\n");
    }
}

//-----------------------------------------------------------

int** read_matrix(int** A, int size, FILE* input) {
    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size; j++) {
            fscanf(input, "%d ", &(A[i][j]));
        }
    }

    return A;
}

//-----------------------------------------------------------

int** E_matrix(int size) {
    int** A = (int**)malloc(size*sizeof(int*));
    for (int i = 0; i < size; i++) {
        A[i] = (int*)malloc(size*sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j ++) {
            if (i == j) {
                A[i][j] = 1;
            } else A[i][j] = 0;
        }
    }

    return A;
}

//-----------------------------------------------------------

int** T_matrix(int** A, int size) {
    int swap;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j > i) {
                swap = A[i][j];
                A[i][j] = A[j][i];
                A[j][i] = swap;
            }
        }
    }

    return A;
}

//-----------------------------------------------------------

int** sum_matrix(int** A, int** B, int size) {
    int** C = (int**)malloc(size*sizeof(int*));
    for (int i = 0; i < size; i++) {
        C[i] = (int*)malloc(size*sizeof(int));
    }

    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

//-----------------------------------------------------------

int** mult_num_matrix(int** A, int size, int num) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] *= num;
        }
    }

    return A;
}

//-----------------------------------------------------------

int** mult_matrix(int** A, int** B, int size) {
    int** C = (int**)malloc(size*sizeof(int*));
    for (int i = 0; i < size; i++) {
        C[i] = (int*)calloc(size, sizeof(int));
    }

    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size; j ++) {
            for (int k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

//-----------------------------------------------------------

int** pow_matrix(int** A, int size, int num) {
    int** B = (int**)malloc(size*sizeof(int*));
    int** C = (int**)malloc(size*sizeof(int*));
    for (int i = 0; i < size; i++) {
        B[i] = (int*)malloc(size*sizeof(int));
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j ++) {
            B[i][j] = A[i][j];
        }
    }

    for (int t = 0; t < num-1; t++) {
        for (int i = 0; i < size; i ++) {
            for (int j = 0; j < size; j ++) {
                A[i][j] = 0;
                for (int k = 0; k < size; k++) {
                    A[i][j] += B[i][k] * B[k][j];
                }
            }
        }
    }

    for (int i = 0; i < size; i++) {
        free(B[i]);
    }
    free(B);

    return A;
}

