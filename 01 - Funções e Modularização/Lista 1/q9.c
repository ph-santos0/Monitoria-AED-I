#include <stdio.h>

void METADE(float *x) {
    *x = *x / 2.0;
}

int main() {
    float A[4];
    int i;

    for (i = 0; i < 4; i++) {
        printf("Digite o valor A[%d]: ", i);
        scanf("%f", &A[i]);
    }

    for (i = 0; i < 4; i++) {
        METADE(&A[i]);
    }

    printf("\nValores pela metade:\n");
    for (i = 0; i < 4; i++) {
        printf("A[%d] = %.2f\n", i, A[i]);
    }
    return 0;
}
