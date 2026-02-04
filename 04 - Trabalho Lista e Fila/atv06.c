#include <stdio.h>
#include <stdlib.h>

// 6. Escreva um algoritmo para juntar duas filas em uma única fila, de forma que os valores desta fila sejam intercalados.

#define MAXTAM 10
typedef int apontador;
typedef struct
{
    int item[MAXTAM];
    apontador inicio;
    apontador fim;
    int qtd;
} TipoFila;

void FFvazia(TipoFila *F)
{
    F->inicio = 0;
    F->fim = F->inicio;
    F->qtd = 0;
}

void enfileirar(TipoFila *F, int num)
{
    if (F->qtd == MAXTAM)
    {
        printf("fila cheia!\n");
    }

    F->item[F->fim] = num;          // item na posição final da fila recebe o novo valor pq fila é fifo, primeiro que entra primeiro que sai e so pode adicionar no final
    F->fim = (F->fim + 1) % MAXTAM; // isso faz com que a posição ande, e o mod é pra fzr com que volte para o inicio pq é uma fila circular
    F->qtd++;

    // primeiro verificar se a fila esta cheia
}

void intercalarFilas(TipoFila *A, TipoFila *B, TipoFila *C)
{
    int i;
    int posA = A->inicio; // ponteiros auxiliares pois nao mexemos com o inicio da fila real
    int posB = B->inicio;

    C->inicio = 0;
    C->fim = 0;
    C->qtd = 0;

    for (i = 0; i < A->qtd || i < B->qtd; i++)
    {
        if (i < A->qtd)
        {
            C->item[C->fim] = A->item[posA]; // C recebe o item de A na ultima posição que ele tem disponivel
            C->fim = (C->fim + 1) % MAXTAM;  // pro indice de c caminha pro ultimo e o mod é por conta de ser uma lista circular
            C->qtd++;
            posA = (posA + 1) % MAXTAM; // para avançar leitura da fila
        }
        if (i < B->qtd)
        {
            C->item[C->fim] = B->item[posB]; // C recebe o item de B na ultima posição que ele tem disponivel
            C->fim = (C->fim + 1) % MAXTAM;  // pro indice de c caminha pro ultimo e o mod é por conta de ser uma lista circular
            C->qtd++;
            posB = (posB + 1) % MAXTAM;
        }
    }
}

void imprimirfila(TipoFila *F)
{
    if (F->qtd == 0) // conferir se a fila ta vazia
    {
        printf("\nFila vazia!\n");
        return;
    }

    int pos = F->inicio; // ponteiro para leitura

    for (int i = 0; i < F->qtd; i++) // quantidade de elementos validos
    {
        printf("%d ", F->item[pos]);
        pos = (pos + 1) % MAXTAM; // chega no final do vetor-> volta pro começo
    }
}

int main()
{
    TipoFila filaA;
    TipoFila filaB;
    TipoFila filaC;
    FFvazia(&filaA);
    FFvazia(&filaB);
    FFvazia(&filaC);
    int num;
    for (int i = 0; i < 5; i++)
    {
        printf("Fila A\n");
        printf("Digite o %d valor:", i + 1);
        scanf("%d", &num); 
        enfileirar(&filaA, num);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("\nFila B\n");
        printf("Digite o %d valor:", i + 1);
        scanf("%d", &num);
        enfileirar(&filaB, num);
    }

    intercalarFilas(&filaA, &filaB, &filaC);
    printf("Fila A:\n");
    imprimirfila(&filaA);
    printf("\nFila B:\n");
    imprimirfila(&filaB);
    printf("\nFila intercalada:\n");
    imprimirfila(&filaC);
    return 0;
}
