#include <stdio.h>

float areaQuadrado(float lado) {
    return lado * lado;
}

int main() {
    float lado;
    printf("Digite o lado do quadrado: ");
    scanf("%f", &lado);
    printf("Area do quadrado = %.2f\n", areaQuadrado(lado));
    return 0;
}
