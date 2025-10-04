#include <stdio.h>
#include <math.h>

float num1 = 0, num2 = 0, x = 0;
int flag = 0;

float adicao(float a, float b)
{
    return (a + b);
}

float subtracao(float d, float e)
{
    return (d - e);
}

float mult(float f, float g)
{
    return (f * g);
}

float div(float h, float i)
{
    return (h / i);
}

float verificacao(float num2)
{
    if (num2 != 0)
    {
        x = 1;
        return (x);
    }
    else
    {
        printf("Nao existe divisao por zero\n");
    }
}

int main()
{
    int opcao;
    do
    {
        system("cls");
        printf("\tCalculadora");

        printf("\n1-Entrar com os numeros\n");
        printf("2-Adicao\n");
        printf("3-Subtracao\n");
        printf("4-Multiplicacao\n");
        printf("5-Divis�o\n");
        printf("6-Sair");
        printf("\nDigite a opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Insira o primeiro numero: ");
            scanf("%f", &num1);
            printf("Insira o segundo numero: ");
            scanf("%f", &num2);
            flag = 1;
            break;
        case 2:
            if (flag == 1)
            {
                printf("O resultado da soma %0.2f+%0.2f e: %0.2f", num1, num2, adicao(num1, num2));
            }
            else
            {
                printf("Voce nao digitou nenhum numero!\n");
            }
            break;
        case 3:
            if (flag == 1)
            {
                printf("O resultado da subtracao %0.2f-%0.2f e: %0.2f", num1, num2, subtracao(num1, num2));
            }
            else
            {
                printf("Voce nao digitou nenhum numero!\n");
            }
            break;
        case 4:
            if (flag == 1)
            {
                printf("O resultado da multiplicacao %0.2f*%0.2f: %0.2f", num1, num2, mult(num1, num2));
            }
            else
            {
                printf("Voce nao digitou nenhum numero!\n");
            }
            break;
        case 5:
            if (flag == 1)
            {
                verificacao(num2);
                if (x == 1)
                {

                    printf("O resultado da divisao %0.2f/%0.2f: %f", num1, num2, div(num1, num2));
                }
            }
            else
            {
                printf("Voce nao digitou nenhum numero!\n");
            }
            break;

        case 6:
            break;
        }

        if (opcao < 1 || opcao > 6)
        {
            printf("Opcao invalida!\n");
        }
        printf("\n");
        system("pause");
    } while (opcao != 6);
}
