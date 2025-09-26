#include <stdio.h>

void lerNotas(float *n1, float *n2) {
    printf("Digite a primeira nota: ");
    scanf("%f", n1);
    printf("Digite a segunda nota: ");
    scanf("%f", n2);
}

int main() {
    float nota1, nota2, media;
    lerNotas(&nota1, &nota2);
    media = (nota1 + nota2) / 2.0;
    printf("Media aritmetica = %.2f\n", media);
    return 0;
}
