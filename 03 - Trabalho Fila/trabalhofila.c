#include <stdio.h>
#include <stdlib.h>

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
    Apontador Frente;
    Apontador Tras;
} TipoFila;

TipoFila Fila;
int tamanho = 0;

/* Inicializa a fila */
void FFVazia(TipoFila *Fila)
{
    Fila->Frente = 1;
    Fila->Tras = 1;
    tamanho = 0;
}

/* Verifica se a fila está vazia */
int Vazia(TipoFila Fila)
{
    return (tamanho == 0);
}

/* Enfileira um elemento */
void Enfileira(TipoItem x, TipoFila *Fila)
{
    if (tamanho == MaxTam)
    {
        printf("\nERRO: Fila cheia!\n");
        return;
    }

    Fila->Item[Fila->Tras - 1] = x;
    Fila->Tras = (Fila->Tras % MaxTam) + 1;
    tamanho++;
}

/* Imprime a fila */
void Imprime(TipoFila Fila)
{
    int i, aux;

    if (Vazia(Fila))
    {
        printf("\nFila vazia!\n");
        return;
    }

    aux = Fila.Frente - 1;

    for (i = 0; i < tamanho; i++)
    {
        printf("Codigo: %d | Idade: %d\n",
               Fila.Item[aux].cod,
               Fila.Item[aux].idade);

        aux++;
        if (aux == MaxTam)
            aux = 0;
    }
}

/* Procura um elemento pelo código */
void ProcuraCodigo(TipoFila Fila, int codigo)
{
    int i, aux;

    if (Vazia(Fila))
    {
        printf("\nFila vazia!\n");
        return;
    }

    aux = Fila.Frente - 1;

    for (i = 0; i < tamanho; i++)
    {
        if (Fila.Item[aux].cod == codigo)
        {
            printf("\nElemento encontrado!\n");
            printf("Codigo: %d | Idade: %d\n",
                   Fila.Item[aux].cod,
                   Fila.Item[aux].idade);
            return;
        }

        aux++;
        if (aux == MaxTam)
            aux = 0;
    }

    printf("\nCodigo nao encontrado na fila.\n");
}

/* Desenfileira (versão alternativa) */
TipoItem Desenfileira(TipoFila *Fila)
{
    TipoItem removido;

    if (Vazia(*Fila))
    {
        printf("\nERRO: Fila vazia!\n");
        removido.cod = -1;
        removido.idade = -1;
        return removido;
    }

    removido = Fila->Item[Fila->Frente - 1];
    Fila->Frente = (Fila->Frente % MaxTam) + 1;
    tamanho--;

    return removido;
}

/* Retorna o tamanho da fila */
int TamanhoFila()
{
    return tamanho;
}

/* Programa principal */
int main()
{
    int opcao, codigo;
    TipoItem x;

    FFVazia(&Fila);

    do
    {
        printf("\nMENU\n");
        printf("1 - Enfileirar\n");
        printf("2 - Imprimir fila\n");
        printf("3 - Procurar por codigo\n");
        printf("4 - Desenfileirar\n");
        printf("5 - Tamanho da fila\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Codigo: ");
            scanf("%d", &x.cod);
            printf("Idade: ");
            scanf("%d", &x.idade);
            Enfileira(x, &Fila);
            break;

        case 2:
            Imprime(Fila);
            break;

        case 3:
            printf("Digite o codigo: ");
            scanf("%d", &codigo);
            ProcuraCodigo(Fila, codigo);
            break;

        case 4:
            x = Desenfileira(&Fila);
            if (x.cod != -1)
                printf("Removido -> Codigo: %d | Idade: %d\n", x.cod, x.idade);
            break;

        case 5:
            printf("Tamanho da fila: %d\n", TamanhoFila());
            break;

        case 0:
            printf("Programa encerrado.\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }
        system("pause");
        system("cls");

    } while (opcao != 0);

    return 0;
}
