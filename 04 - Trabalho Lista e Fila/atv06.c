#include <stdio.h>
#include <stdlib.h>

#define MaxTam 10

typedef struct
{
    int valor;
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
        return;
    Fila->Item[Fila->Tras - 1] = x;
    Fila->Tras = (Fila->Tras % MaxTam) + 1;
    Fila->Tamanho++;
}

TipoItem Desenfileira(TipoFila *Fila)
{
    TipoItem x = {0};
    if (Fila->Tamanho == 0)
        return x;
    x = Fila->Item[Fila->Frente - 1];
    Fila->Frente = (Fila->Frente % MaxTam) + 1;
    Fila->Tamanho--;
    return x;
}

void IntercalaFilas(TipoFila *f1, TipoFila *f2, TipoFila *res)
{
    while (f1->Tamanho > 0 || f2->Tamanho > 0)
    {
        if (f1->Tamanho > 0)
            Enfileira(Desenfileira(f1), res);
        if (f2->Tamanho > 0)
            Enfileira(Desenfileira(f2), res);
    }
}

int main()
{
    TipoFila f1, f2, f3;
    TipoItem x;

    FFVazia(&f1);
    FFVazia(&f2);
    FFVazia(&f3);

    x.valor = 1;
    Enfileira(x, &f1);
    x.valor = 3;
    Enfileira(x, &f1);
    x.valor = 2;
    Enfileira(x, &f2);
    x.valor = 4;
    Enfileira(x, &f2);

    IntercalaFilas(&f1, &f2, &f3);

    printf("Fila Intercalada: ");
    while (f3.Tamanho > 0)
    {
        printf("%d ", Desenfileira(&f3).valor);
    }
    return 0;
}