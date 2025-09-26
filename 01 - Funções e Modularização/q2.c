#include <stdio.h>

int soma(int a, int b) {
    return a + b;
}

int main() {
    int x, y, resultado;
    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &x, &y);

    resultado = soma(x, y) * 5;
    printf("Resultado da soma multiplicada por 5 = %d\n", resultado);
    return 0;
}
