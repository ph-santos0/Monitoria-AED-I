#include <stdio.h>
#include <stdlib.h>

#define InicioArranjo 1
#define MaxTam 50

typedef int Apontador;

typedef struct
{
    float nota;
} TipoItem;

typedef struct
{
    TipoItem Item[MaxTam];
    Apontador Primeiro;
    Apontador Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista)
{
    Lista->Primeiro = InicioArranjo;
    Lista->Ultimo = Lista->Primeiro;
}

int Vazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista)
{
    if (Lista->Ultimo - 1 >= MaxTam)
    {
        printf("Lista cheia\n");
    }
    else
    {
        Lista->Item[Lista->Ultimo - 1] = x;
        Lista->Ultimo++;
    }
}

void Retira(Apontador p, TipoLista *Lista)
{
    int i;
    if (Vazia(*Lista) || p < 0 || p >= Lista->Ultimo - 1)
    {
        printf("Erro na remocao\n");
        return;
    }
    for (i = p; i < Lista->Ultimo - 2; i++)
    {
        Lista->Item[i] = Lista->Item[i + 1];
    }
    Lista->Ultimo--;
}

void CalcularEstatisticas(TipoLista Lista)
{
    if (Vazia(Lista))
    {
        printf("Lista vazia\n");
        return;
    }
    float soma = 0, maior = Lista.Item[0].nota, menor = Lista.Item[0].nota;
    int i;

    for (i = 0; i < Lista.Ultimo - 1; i++)
    {
        float val = Lista.Item[i].nota;
        soma += val;
        if (val > maior)
            maior = val;
        if (val < menor)
            menor = val;
    }

    printf("Media: %.2f\n", soma / (Lista.Ultimo - 1));
    printf("Maior: %.2f\n", maior);
    printf("Menor: %.2f\n", menor);
}

int main()
{
    TipoLista lista;
    TipoItem item;
    int op, pos;

    FLVazia(&lista);

    do
    {
        printf("\n1-Inserir 2-Remover (pos) 3-Estatisticas 0-Sair: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Nota: ");
            scanf("%f", &item.nota);
            Insere(item, &lista);
            break;
        case 2:
            printf("Posicao (0 a %d): ", lista.Ultimo - 2);
            scanf("%d", &pos);
            Retira(pos, &lista);
            break;
        case 3:
            CalcularEstatisticas(lista);
            break;
        }
    } while (op != 0);

    return 0;
}