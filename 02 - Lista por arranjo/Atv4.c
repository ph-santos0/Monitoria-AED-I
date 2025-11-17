#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define InicioArranjo 1
#define MaxTam 100

typedef int Apontador;

typedef struct
{
    int nota;
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
    return (Lista->Primeiro == Lista->Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista)
{
    if (Lista->Ultimo - 1 >= MaxTam)
    {
        printf("\nERRO: A lista esta cheia! (Tamanho Maximo: %d)\n", MaxTam);
    }
    else
    {
        Lista->Item[Lista->Ultimo - 1] = x;
        Lista->Ultimo = Lista->Ultimo + 1;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    TipoLista listaDeNotas;
    TipoItem itemAtual;
    int notaInput;
    int i;

    int quantidade = 0;
    int soma = 0;
    double media = 0.0;
    int acimaDaMedia = 0;
    int abaixoDeSete = 0;

    FLVazia(&listaDeNotas);

    printf("--- Entrada de Notas ---\n");
    printf("Digite as notas (limite de %d). Digite -1 para parar.\n\n", MaxTam);

    while (1)
    {
        printf("Digite a nota: ");
        scanf("%d", &notaInput);

        if (notaInput == -1)
        {
            break;
        }

        if (listaDeNotas.Ultimo - 1 >= MaxTam)
        {
            printf("\nA lista esta cheia! Nao e possivel adicionar mais notas.\n");
            printf("Encerrando a leitura de dados...\n");
            break;
        }

        itemAtual.nota = notaInput;
        Insere(itemAtual, &listaDeNotas);
    }

    printf("\n--- Processamento dos Dados ---\n");

    if (Vazia(listaDeNotas))
    {
        printf("Nenhum valor foi lido.\n");
        printf("\n8. Programa encerrado.\n");
        return 0;
    }

    quantidade = listaDeNotas.Ultimo - listaDeNotas.Primeiro;
    printf("\n1. Quantidade de valores lidos: %d\n", quantidade);

    printf("2. Valores na ordem informada: ");
    for (i = listaDeNotas.Primeiro - 1; i < listaDeNotas.Ultimo - 1; i++)
    {
        printf("%d ", listaDeNotas.Item[i].nota);
    }
    printf("\n");

    printf("3. Valores na ordem inversa:\n");
    for (i = listaDeNotas.Ultimo - 2; i >= listaDeNotas.Primeiro - 1; i--)
    {
        printf("%d\n", listaDeNotas.Item[i].nota);
    }

    for (i = listaDeNotas.Primeiro - 1; i < listaDeNotas.Ultimo - 1; i++)
    {
        soma += listaDeNotas.Item[i].nota;
    }

    if (quantidade > 0)
    {
        media = (double)soma / quantidade;
    }

    printf("\n4. Soma dos valores: %d\n", soma);
    printf("5. Media dos valores: %.2f\n", media);

    for (i = listaDeNotas.Primeiro - 1; i < listaDeNotas.Ultimo - 1; i++)
    {
        if (listaDeNotas.Item[i].nota > media)
        {
            acimaDaMedia++;
        }
        if (listaDeNotas.Item[i].nota < 7)
        {
            abaixoDeSete++;
        }
    }

    printf("6. Quantidade de valores acima da media: %d\n", acimaDaMedia);
    printf("7. Quantidade de valores abaixo de sete: %d\n", abaixoDeSete);

    printf("\n8. Programa encerrado. Obrigado!\n");

    return 0;
}