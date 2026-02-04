#include <stdio.h>
#include <stdlib.h>

// 4. Crie um programa que gerencie uma lista de notas de alunos:

#define MAXTAM 10

typedef struct
{
    float notas[MAXTAM];
    int qtd;
} TipoLista;

void FFVazia(TipoLista *L)
{
    L->qtd = 0;
}
// •	Inserir nota

void inserirnotas(TipoLista *L)
{
    float notas = 0;
    printf("Digite as notas: (caso queira encerrar digite -1)");
    scanf("%f", &notas);
    while (notas != -1 && L->qtd < MAXTAM)
    {
        L->notas[L->qtd] = notas;
        L->qtd++;
        printf("Digite as notas: (caso queira encerrar digite -1)");
        scanf("%f", &notas);
    }
}

// •	Remover nota

int removernota(TipoLista *L, float valor)
{
    for (int i = 0; i < L->qtd; i++)
    {
        if (L->notas[i] == valor)
        {                                        // se notas na posição i for igual a valor
            for (int j = i; j < L->qtd - 1; j++) // o último elemento não tem ninguém à direita para copiar por isso a quantidade -1
            {
                L->notas[j] = L->notas[j + 1]; // como estamos removendo um valor, nao pode ficar um buraco, entao temos q andar com os valores
            }
            L->qtd--;
            return 1;
        }
    }
    return 0;
}

// •	Calcular média

float calcularmedia(TipoLista *L)
{
    float soma = 0;
    float media = 0;

    if (L->qtd == 0) // conferir lista vazia antes de fzr a media
    {
        printf("\nLista vazia!");
        return 0;
    }else
    {
        for (int i = 0; i < L->qtd; i++)
        {
            soma = soma + L->notas[i];
        }
        media = soma / L->qtd;
        return media;
    }
    
}

// •	Mostrar maior e menor nota

void maioremenor(TipoLista *L)
{
    if (L->qtd == 0)
    {
        printf("\nLista vazia!");
        return;
    }

    float maior = L->notas[0];       // colocar primeira nota como maior
    float menor = L->notas[0];       // colocar primeira nota como menor
    for (int i = 1; i < L->qtd; i++) // começa em 1 pq ja estamos comparando ao primeiro indice que inicia em zero
    {
        if (maior < L->notas[i])
        {
            maior = L->notas[i];
        }
        if (menor > L->notas[i])
        {
            menor = L->notas[i];
        }
    }
    printf("\nMaior nota: %f", maior);
    printf("\nMenor nota: %f", menor);
}

int main()
{
    TipoLista lista;
    FFVazia(&lista);
    int op;
    float valor;
    do
    {
        printf("\nGerenciador da lista de alunos");
        printf("\n1. Inserir nota");
        printf("\n2. Remover nota");
        printf("\n3. Calcular media");
        printf("\n4. Mostrar maior e menor nota");
        printf("\n0. Para sair");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            inserirnotas(&lista);
            break;

        case 2:

            printf("\nDigite a nota que deseja remover:");
            scanf("%f", &valor);
            if (removernota(&lista, valor))
            {
                printf("\nNota removida com sucesso");
            }
            else
            {
                printf("\nNota nao encontrada ou lista vazia!");
            }
            break;

        case 3:

            printf("Media:%f", calcularmedia(&lista));
            break;

        case 4:

            maioremenor(&lista);
            break;

        case 0:
            printf("\nPrograma encerrado!");
            break;
        }

    } while (op != 0);
}
