#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
} TipoItem;

typedef struct
{
    TipoItem *Item;
    int Frente, Tras;
    int Tamanho;
    int Capacidade;
} TipoFila;

void Inicializa(TipoFila *Fila)
{
    Fila->Capacidade = 2;
    Fila->Item = (TipoItem *)malloc(Fila->Capacidade * sizeof(TipoItem));
    Fila->Frente = 1;
    Fila->Tras = 1;
    Fila->Tamanho = 0;
}

void Enfileira(TipoItem x, TipoFila *Fila)
{
    if (Fila->Tamanho == Fila->Capacidade)
    {
        printf("Dobrando tamanho de %d para %d...\n", Fila->Capacidade, Fila->Capacidade * 2);
        int novaCapacidade = Fila->Capacidade * 2;
        TipoItem *novoArr = (TipoItem *)malloc(novaCapacidade * sizeof(TipoItem));

        int i, aux = Fila->Frente - 1;
        for (i = 0; i < Fila->Tamanho; i++)
        {
            novoArr[i] = Fila->Item[aux];
            aux = (aux + 1) % Fila->Capacidade;
        }

        free(Fila->Item);
        Fila->Item = novoArr;
        Fila->Capacidade = novaCapacidade;
        Fila->Frente = 1;
        Fila->Tras = Fila->Tamanho + 1;
    }

    Fila->Item[Fila->Tras - 1] = x;
    Fila->Tras = (Fila->Tras % Fila->Capacidade) + 1;
    Fila->Tamanho++;
}

int main()
{
    TipoFila f;
    TipoItem x;
    int i;

    Inicializa(&f);

    for (i = 1; i <= 5; i++)
    {
        x.id = i;
        Enfileira(x, &f);
        printf("Enfileirado: %d\n", i);
    }

    return 0;
}