#include <stdio.h>
const float PI = 3.14159;

float areaCirculo(float raio)
{
    return PI * raio * raio;
}

int main()
{
    float raio;
    printf("Digite o raio do circulo: ");
    scanf("%f", &raio);
    printf("Area do circulo = %.2f\n", areaCirculo(raio));
    return 0;
}
