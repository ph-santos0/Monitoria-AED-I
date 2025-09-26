#include <stdio.h>

float maiorSalario(float s1, float s2) {
    if (s1 > s2)
        return s1;
    else
        return s2;
}

int main() {
    float sal1, sal2;
    printf("Digite dois salarios: ");
    scanf("%f %f", &sal1, &sal2);
    printf("Maior salario = %.2f\n", maiorSalario(sal1, sal2));
    return 0;
}
