#include <stdio.h>

int calcular(int x)
{
    int h = x * x - 16;
    int f;
    if (h >= 0)
    {
        f = h;
    }
    else
    {
        f = 1;
    }

    int g;
    if (f == 0)
    {
        g = x * x + 16;
    }
    if (f > 0)
    {
        g = 0;
    }

    return f + g;
}

int main()
{
    int valor;
    printf("Digite o valor de x:\n");
    scanf("%d", &valor);
    int y = calcular(valor);
    printf("%d", y);
}
