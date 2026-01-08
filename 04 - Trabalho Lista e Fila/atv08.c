#include <stdio.h>
#include <stdlib.h>

#define MaxTam 20

typedef struct
{
    int numero;
} TipoItem;

typedef struct
{
    TipoItem Item[MaxTam];
    int Frente, Tras;
    int Tamanho;
} TipoFila;

void FFVazia(TipoFila *Fila)
{
    Fila->Frente = 1;
    Fila->Tras = 1;
    Fila->Tamanho = 0;
}

void Enfileira(TipoItem x, TipoFila *Fila)
{
    if (Fila->Tamanho == MaxTam)
    {
        printf("Fila cheia\n");
        return;
    }
    Fila->Item[Fila->Tras - 1] = x;
    Fila->Tras = (Fila->Tras % MaxTam) + 1;
    Fila->Tamanho++;
    printf("Cliente %d entrou na fila\n", x.numero);
}

void Atender(TipoFila *Fila)
{
    if (Fila->Tamanho == 0)
    {
        printf("Ninguem na fila\n");
        return;
    }
    TipoItem x = Fila->Item[Fila->Frente - 1];
    Fila->Frente = (Fila->Frente % MaxTam) + 1;
    Fila->Tamanho--;
    printf("Atendendo cliente %d\n", x.numero);
}

void Proximo(TipoFila Fila)
{
    if (Fila.Tamanho == 0)
    {
        printf("Ninguem na fila\n");
    }
    else
    {
        printf("Proximo a ser atendido: %d\n", Fila.Item[Fila.Frente - 1].numero);
    }
}

int main()
{
    TipoFila fila;
    TipoItem cliente;
    int op;
    FFVazia(&fila);

    do
    {
        printf("\n1-Novo Cliente 2-Atender 3-Ver Proximo 0-Sair: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Numero do cliente: ");
            scanf("%d", &cliente.numero);
            Enfileira(cliente, &fila);
            break;
        case 2:
            Atender(&fila);
            break;
        case 3:
            Proximo(fila);
            break;
        }
    } while (op != 0);

    return 0;
}