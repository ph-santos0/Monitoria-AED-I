#include <stdio.h>
#include <stdlib.h>
// 3.Implemente uma lista por arranjo ordenada, mantendo os elementos sempre em ordem crescente.

#define MAXTAM 5

typedef struct
{
    int num[MAXTAM]; // Aqui guarda os numeros
    int qtd;         // pra saber quantos itens ja estão na lista
} TipoLista;

// função para fazer a fila ficar vazia para não pegar lixo de memoria

void FFVazia(TipoLista *L)
{
    L->qtd = 0;
}

int ListaOrdenada(TipoLista *L, int num)
{
    if (L->qtd == MAXTAM)
    {
        printf("Lista cheia!");
        return 0;
    }
    int pos = 0;
    while (pos < L->qtd && num > L->num[pos]) // O "pos" é para percorrer o indice(posição) enquanto ele for menor que a quantidade de itens, e num > L->num[pos] é a comparação de valor, se num(valor) é menor que o valor na posição i soma ++, enquando a condoção for verdadeira continuara percorrendo a lista.
    {
        pos++;
    }

    // deslocar elementos

    for (int i = L->qtd; i > pos; i--) // i começa com o valor do ultimo indice ocupado, enquanto i for maior que a posição, copia o elemento anterior pra posição atual.
    {
        L->num[i] = L->num[i - 1];
    }
    // inserir o numero

    L->num[pos] = num;
    L->qtd++;
    return 1;
}

int main()
{
    TipoLista lista;
    FFVazia(&lista);
    int numero;
    for (int i = 0; i < MAXTAM; i++)
    {
        printf("\nDigite o %d numero:", i + 1);
        scanf("%d", &numero);
        ListaOrdenada(&lista, numero);
    }

    printf("Lista ordenada\n");
    for (int i = 0;i < lista.qtd; i++) // percorre a lista para imprimir
    {
        printf("%d", lista.num[i]);
    }
    return 0;
}
