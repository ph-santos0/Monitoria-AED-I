#include <stdio.h>

#define MAX_TOTAL 32 // limite máximo do vetor

// Estrutura da fila
typedef struct
{
    int dados[MAX_TOTAL];
    int frente;
    int tras;
    int tamanho;
    int capacidade; // capacidade atual
} Fila;

// Inicializa a fila
void iniciar(Fila *f)
{
    f->frente = 0;
    f->tras = 0;
    f->tamanho = 0;
    f->capacidade = 4; // capacidade inicial
}

// Verifica se a fila está vazia
int vazia(Fila f)
{
    return f.tamanho == 0;
}

// Dobra a capacidade da fila
void dobrarCapacidade(Fila *f)
{
    if (f->capacidade * 2 <= MAX_TOTAL)
    {
        f->capacidade *= 2;
        printf("\nCapacidade da fila aumentada para %d.\n", f->capacidade);
    }
    else
    {
        printf("\nCapacidade maxima atingida (%d).\n", MAX_TOTAL);
    }
}

// Enfileirar
void enfileirar(Fila *f, int valor)
{
    if (f->tamanho == f->capacidade)
    {
        dobrarCapacidade(f);
    }

    if (f->tamanho == f->capacidade)
    {
        printf("\nErro: fila cheia!\n");
        return;
    }

    f->dados[f->tras] = valor;
    f->tras = (f->tras + 1) % MAX_TOTAL;
    f->tamanho++;
}

// Mostrar fila
void mostrar(Fila f)
{
    if (vazia(f))
    {
        printf("\nFila vazia!\n");
        return;
    }

    printf("\nTamanho da fila: %d\nCapacidade da fila: %d\nElementos: ",
           f.tamanho, f.capacidade);

    int pos = f.frente;
    for (int i = 0; i < f.tamanho; i++)
    {
        printf("%d ", f.dados[pos]);
        pos = (pos + 1) % MAX_TOTAL;
    }
    printf("\n");
}

int main()
{
    Fila fila;
    iniciar(&fila);

    int opcao, valor;

    do
    {
        printf("\n1 - Inserir elementos");
        printf("\n2 - Mostrar fila");
        printf("\n3 - Ver capacidade atual");
        printf("\n0 - Sair");
        printf("\nEscolha: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            
            while (fila.tamanho < MAX_TOTAL)
            {
                printf("\nDigite um valor ou digite -1 para sair: ");
                scanf("%d", &valor);

                if (valor == -1)
                    break;

                enfileirar(&fila, valor);
            }

            if (fila.tamanho == MAX_TOTAL)
            {
                printf("\nA fila atingiu o tamanho maximo absoluto!\n");
            }
        }
        else if (opcao == 2)
        {
            mostrar(fila);
        }
        else if (opcao == 3)
        {
            printf("\nCapacidade atual: %d\nMaxima: %d\n",
                   fila.capacidade, MAX_TOTAL);
        }

    } while (opcao != 0);

    printf("\nPrograma encerrado.\n");
    return 0;
}
