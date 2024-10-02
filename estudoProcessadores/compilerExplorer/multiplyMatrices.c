#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500  // Defina o tamanho da matriz

void multiply_matrices(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[SIZE][SIZE], mat2[SIZE][SIZE], result[SIZE][SIZE];
    
    // Inicializa matrizes com valores aleatórios
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            mat1[i][j] = rand() % 100;
            mat2[i][j] = rand() % 100;
        }
    }

    clock_t start = clock();
    multiply_matrices(mat1, mat2, result);
    clock_t end = clock();

    printf("Tempo de execução: %lf segundos\n", (double)(end - start) / CLOCKS_PER_SEC);
    
    return 0;
}
