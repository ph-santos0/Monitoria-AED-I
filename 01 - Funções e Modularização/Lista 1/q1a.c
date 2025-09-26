#include <stdio.h>

// Variáveis globais
float nota1, nota2;

void lerNotas() {
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
}

int main() {
    float media;
    lerNotas();
    media = (nota1 + nota2) / 2.0;
    printf("Media aritmetica = %.2f\n", media);
    return 0;
}
