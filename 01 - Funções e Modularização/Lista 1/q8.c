#include <stdio.h>

void aumento(float *X, float Y) {
    *X = *X + (*X * (Y / 100.0));
}

int main() {
    float valor, perc;
    printf("Digite o valor: ");
    scanf("%f", &valor);
    printf("Digite a porcentagem de aumento: ");
    scanf("%f", &perc);

    aumento(&valor, perc);
    printf("Novo valor = %.2f\n", valor);
    return 0;
}
