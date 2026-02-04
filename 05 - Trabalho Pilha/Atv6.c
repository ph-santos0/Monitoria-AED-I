#include <stdio.h>
#include <stdlib.h>

#define MaxTam 6

typedef int Apontador;

typedef struct
{
    int Item[MaxTam];
    Apontador Topo;
} TipoPilha;

void FPVazia(TipoPilha *Pilha)
{
    Pilha->Topo = 0;
}

int Vazia(TipoPilha Pilha)
{
    return (Pilha.Topo == 0);
}

void Empilha(int x, TipoPilha *Pilha)
{
    if (Pilha->Topo == MaxTam)
        printf("\nERRO: pilha esta cheia\n");
    else
    {
        Pilha->Topo = Pilha->Topo + 1;
        Pilha->Item[Pilha->Topo - 1] = x;
    }
}

void ImprimeTopoFundo(TipoPilha Pilha, char nome[])
{
    int aux;

    printf("\nPilha %s:\n", nome);

    if (Vazia(Pilha))
    {
        printf("Pilha esta vazia\n");
    }
    else
    {
        for (aux = Pilha.Topo - 1; aux >= 0; aux--)
        {
            printf("%d\n", Pilha.Item[aux]);
        }
    }
}

int main()
{
    TipoPilha PilhaPar, PilhaImpar;
    int num, cont = 0;
    int opcao = 1;

    FPVazia(&PilhaPar);
    FPVazia(&PilhaImpar);

    printf("Digite ate 12 numeros inteiros.\n");

    while (cont < 12 && opcao == 1)
    {
        printf("\nDigite um numero: ");
        scanf("%d", &num);

        if (num % 2 == 0)
            Empilha(num, &PilhaPar);
        else
            Empilha(num, &PilhaImpar);

        cont++;

        if (cont < 12)
        {
            printf("\nDeseja continuar? (1-Sim / 0-Nao): ");
            scanf("%d", &opcao);
        }
    }

    ImprimeTopoFundo(PilhaPar, "PAR");
    ImprimeTopoFundo(PilhaImpar, "IMPAR");
    
    return 0;
}
