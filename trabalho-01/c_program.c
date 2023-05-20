# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>

/*
Código para alocar uma matriz A NxM e realizar a multiplicação por um vetor x de tamanho M
*/
int** allocate_rows(int n);
int* allocate_columns(int m);


int main(int argc, char *argv[]){
    if (argc != 3) {
        printf("Usage: %s <number of rows> <number of columns>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    int **A;
    int *x, *b;
    int i, j, sum;
    int max_number = 100;

    A = allocate_rows(n);
    x = allocate_columns(m);
    b = allocate_columns(m);

    for (i = 0; i < n; i++) {
        A[i] = allocate_columns(m);
    }


    srand(time(NULL)); // inicializa semente do gerador de números aleatórios

    // Aloca valores aleatórios à matriz
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            A[i][j] = rand() % max_number; // gera número aleatório entre 0 e n
        }
    }

    // Aloca valores aleatórios ao vetor
    for (j = 0; j < m; j++) {
        x[j] = rand() % max_number; // gera número aleatório entre 0 e n
    }

    // printf("\n------------Matriz------------\n");

    // // Imprime matriz
    // for (i = 0; i < n; i++) {
    //     for (j = 0; j < m; j++) {
    //         printf("%d ", A[i][j]);
    //     }
    //     printf("\n");
    // }

    // printf("\n---------Vetor--------------\n");

    // // Imprime vetor
    // for (j = 0; j < m; j++) {
    //     printf("%d ", x[j]);
    //     printf("\n");
    // }




    for (i=0; i<n; i++){
        sum=0;
        for (j=0; j<m; j++){
            // printf("A[%d][%d] = %d, x[%d] = %d \n", i, j, A[i][j], j, x[j]);
            sum += A[i][j]*x[j];
        }
        // printf("b[%d] = %d \n\n", i, sum);
        b[i] = sum;
    }
    // printf("\n---------------Resultado------------------\n");
    // // Imprime resultado
    // for (i = 0; i < n; i++) {
    //     printf("%d ", b[i]);
    //     printf("\n");
    // }

    free(A);
    free(b);
    free(x);

    return 0;

}


int** allocate_rows(int n) {

    int **aux; //variável auxiliar

    aux = (int **) malloc(n * sizeof(int*));

    return aux;

}

int* allocate_columns(int n) {

    int *aux; //variável auxiliar

    aux = (int *) malloc(n * sizeof(int));

    return aux;

}
