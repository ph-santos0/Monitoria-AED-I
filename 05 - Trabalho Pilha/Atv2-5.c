#include <stdlib.h>
#include <stdio.h>

#define MaxTam 5

typedef int Apontador;

typedef struct
{
    int cod;
    int idade;
} TipoItem;

typedef struct
{
    TipoItem Item[MaxTam];
    Apontador Topo;
} TipoPilha;

TipoPilha Pilha;
TipoItem x;

void FPVazia(TipoPilha *Pilha)
{
    Pilha->Topo = 0;
}

int Vazia(TipoPilha Pilha)
{
    return (Pilha.Topo == 0);
}

void Empilha(TipoItem x, TipoPilha *Pilha)
{
    if (Pilha->Topo == MaxTam)
        printf("\n ERRO: pilha esta cheia\n");
    else
    {
        Pilha->Topo = Pilha->Topo + 1;
        Pilha->Item[Pilha->Topo - 1] = x;
    }
}

void ImprimeTopoFundo(TipoPilha Pilha)
{
    int aux;
    if (Vazia(Pilha))
    {
        printf("Pilha esta Vazia\n");
    }
    else
    {
        for (aux = Pilha.Topo - 1; aux >= 0; aux = aux - 1)
        {
            printf("Cod: %d\nIdade: %d\n\n", Pilha.Item[aux].cod, Pilha.Item[aux].idade);
        }
    }
}

void ImprimeFundoTopo(TipoPilha Pilha)
{
    int aux;
    if (Vazia(Pilha))
    {
        printf("Pilha esta Vazia\n");
    }
    else
    {
        for (aux = 0; aux <= Pilha.Topo - 1; aux = aux + 1)
        {
            printf("Cod: %d\nIdade: %d\n\n", Pilha.Item[aux].cod, Pilha.Item[aux].idade);
        }
    }
}

void Desempilha(TipoPilha *Pilha, TipoItem *x)
{
    if (Vazia(*Pilha))
    {
        printf("ERRO: Pilha esta Vazia\n");
    }
    else
    {
        *x = Pilha->Item[Pilha->Topo - 1];
        printf("O elemento retirado foi o de codigo %d\n", x->cod);
        Pilha->Topo = Pilha->Topo - 1;
    }
}

int Tamanho(TipoPilha Pilha)
{
    return (Pilha.Topo);
}

void procurarcod(TipoPilha Pilha, int cod) // Questão 2
{
    int achou = 0;
    if (Vazia(Pilha))
    {
        printf("Pilha vazia!");
        return;
    }
    for (int i = Pilha.Topo - 1; i >= 0; i--)
    {
        if (cod == Pilha.Item[i].cod)
        {
            printf("Cod: %d\nIdade: %d\n\n", Pilha.Item[i].cod, Pilha.Item[i].idade);
            achou = 1;
        }
    }

    if (!achou)
    {
        printf("Codigo nao encontrado!\n");
    }
}

void PartePilha(TipoPilha Pilha, TipoPilha *P1, TipoPilha *P2) // Questão 3
{
    int i, metade;

    FPVazia(P1);
    FPVazia(P2);

    metade = Pilha.Topo / 2;

    for (i = 0; i < Pilha.Topo; i++)
    {
        if (i < metade)
            Empilha(Pilha.Item[i], P1);
        else
            Empilha(Pilha.Item[i], P2);
    }

    printf("Pilha dividida em duas!\n");
}

void OrdenaPilha(TipoPilha *Pilha) // Questão 4
{
    TipoItem aux;
    int i, j;

    // Usei o método de ordenação Bubble Sort (Vocês vão aprender em AED 2)
    for (i = 0; i < Pilha->Topo - 1; i++)
    {
        for (j = 0; j < Pilha->Topo - 1 - i; j++)
        {
            if (Pilha->Item[j].cod > Pilha->Item[j + 1].cod)
            {
                aux = Pilha->Item[j];
                Pilha->Item[j] = Pilha->Item[j + 1];
                Pilha->Item[j + 1] = aux;
            }
        }
    }

    printf("Pilha ordenada com sucesso!\n");
}

void MaiorMenorMediaIdade(TipoPilha Pilha) // Questão 5
{
    int i;
    int maior, menor;
    float media, soma = 0;

    if (Vazia(Pilha))
    {
        printf("Pilha vazia!\n");
        return;
    }

    maior = menor = Pilha.Item[0].idade;

    for (i = 0; i < Pilha.Topo; i++)
    {
        if (Pilha.Item[i].idade > maior)
            maior = Pilha.Item[i].idade;

        if (Pilha.Item[i].idade < menor)
            menor = Pilha.Item[i].idade;

        soma += Pilha.Item[i].idade;
    }

    media = soma / Pilha.Topo;

    printf("Maior idade: %d\n", maior);
    printf("Menor idade: %d\n", menor);
    printf("Media: %.2f\n", media);
}

int main()
{
    int opcao, resposta, cod;

    FPVazia(&Pilha);
    do
    {

        printf("MENU\n\n");

        printf("1 - Esvaziar pilha\n");
        printf("2 - Verificar se a pilha esta vazia\n");
        printf("3 - Inserir elemento na pilha\n");
        printf("4 - Imprimir os elementos da pilha no sentido topo fundo \n");
        printf("5 - Imprimir os elementos da pilha no sentido fundo topo \n");
        printf("6 - Desempilhar elemento da pilha\n");
        printf("7 - Tamanho da Pilha\n");
        printf("8 - Procurar elemento pelo codigo (Questao 2)\n");
        printf("9 - Partir pilha em duas (Questao 3)\n");
        printf("10 - Ordenar pilha pelo codigo (Questao 4)\n");
        printf("11 - Maior, menor e media das idades (Questao 5)\n");
        printf("0 - Sair\n\n");
        printf("Digite a opcao desejada: ");

        scanf("%d", &opcao);
        switch (opcao)
        {
        case 0:
        {
            printf("PROGRAMA ENCERRADO!\n");
            break;
        }
        case 1:
        {
            FPVazia(&Pilha);
            printf("\nA PILHA VAZIA\n");
            break;
        }
        case 2:
        {
            resposta = Vazia(Pilha);
            if (resposta == 1)
                printf("\n PILHA ESTA VAZIA\n");
            else
                printf("\n PILHA NAO ESTA VAZIA\n");
            break;
        }
        case 3:
        {
            printf("Digite o codigo\n");
            scanf("%d", &x.cod);
            printf("Digite a idade\n");
            scanf("%d", &x.idade);
            Empilha(x, &Pilha);
            break;
        }
        case 4:
        {
            ImprimeTopoFundo(Pilha);
            break;
        }
        case 5:
        {
            ImprimeFundoTopo(Pilha);
            break;
        }

        case 6:
        {
            Desempilha(&Pilha, &x);
            break;
        }

        case 7:
        {
            printf("A pilha tem %d elementos\n", Tamanho(Pilha));
            break;
        }
        case 8:
        {
            printf("Digite o codigo que deseja procurar: ");
            scanf("%d", &cod);
            procurarcod(Pilha, cod);
            break;
        }
        case 9:
        {
            TipoPilha Pilha1, Pilha2;
            PartePilha(Pilha, &Pilha1, &Pilha2);

            printf("\nPilha 1:\n");
            ImprimeFundoTopo(Pilha1);

            printf("\nPilha 2:\n");
            ImprimeFundoTopo(Pilha2);
            break;
        }
        case 10:
        {
            OrdenaPilha(&Pilha);
            break;
        }
        case 11:
        {
            MaiorMenorMediaIdade(Pilha);
            break;
        }

        default:
            printf("\n\nOpcao invalida\n\n");
        }

    } while (opcao != 0);
    return (0);
}
