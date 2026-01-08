#include <stdio.h>
#include <stdlib.h>

#define MaxTam 10
#define InicioArranjo 1

typedef struct
{
    int valor;
} TipoItem;

typedef struct
{
    TipoItem Item[MaxTam];
    int Primeiro, Ultimo;
} TipoLista;

void AlgoritmoEstatistica(TipoLista Lista, int *maior, int *menor, float *media)
{
    int i, soma = 0;
    if (Lista.Primeiro == Lista.Ultimo)
        return;

    *maior = Lista.Item[0].valor;
    *menor = Lista.Item[0].valor;

    for (i = 0; i < Lista.Ultimo - 1; i++)
    {
        int v = Lista.Item[i].valor;
        soma += v;
        if (v > *maior)
            *maior = v;
        if (v < *menor)
            *menor = v;
    }

    *media = (float)soma / (Lista.Ultimo - 1);
}

int main()
{
    TipoLista lista;
    lista.Primeiro = 1;
    lista.Ultimo = 1;

    lista.Item[0].valor = 10;
    lista.Ultimo++;
    lista.Item[1].valor = 5;
    lista.Ultimo++;
    lista.Item[2].valor = 8;
    lista.Ultimo++;

    int max, min;
    float med;

    AlgoritmoEstatistica(lista, &max, &min, &med);
    printf("Maior: %d, Menor: %d, Media: %.2f\n", max, min, med);
    return 0;
}