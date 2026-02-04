#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 20

// 8. Crie um programa que simule uma fila de atendimento:

// Cada pessoa tem um número
//	A fila suporta até 20 pessoas

typedef struct
{
    int cod[MAXTAM];
    int inicio;
    int final;
    int qtd;
} Tipofila;

void FFVazia(Tipofila *F)
{
    F->inicio = 0;
    F->final = F->inicio;
    F->qtd = 0;
}

// adicionar cliente

void enfileirar(Tipofila *F)
{
    if (F->qtd == MAXTAM)
    {
        printf("Fila cheia!\n");
    }
    int cod;

    printf("Digite o codigo do cliente (-1 para parar):");
    scanf("%d", &cod);

    while (cod != -1 && F->qtd < MAXTAM)
    {
        F->cod[F->final] = cod;
        F->final = (F->final + 1) % MAXTAM;
        F->qtd++;

        printf("Digite o numero do cliente (-1 para parar): ");
        scanf("%d", &cod);
    }
}

// atender cliente

void atendercliente(Tipofila *F)
{
    if(F->qtd==0)
    {
        printf("Fila vazia!");
        return;
    }

    printf("Cliente atendido: %d",F->cod[F->inicio]);
    F->inicio=(F->inicio+1) % MAXTAM;
    F->qtd--;
}

void proximo(Tipofila *F)
{
    if(F->qtd==0){
        printf("Fila vazia!");
        return;
    }
    else
    {
    printf("Proximo cliente a ser atendido: %d",F->cod[F->inicio]);
    }
}

int main()
{
    Tipofila fila;
    FFVazia(&fila);
    int op;
    do
    {
        printf("\nFila de atendimento\n");
        printf("1-Adicionar cliente\n");
        printf("2-Atender cliente\n");
        printf("3-Mostrar proximo cliente\n");
        printf("4-Encerrar atendimento\n");
        scanf("%d",&op);

        switch (op)
        {
        case 1:
            enfileirar(&fila);
            break;
        case 2:
            atendercliente(&fila);
            break;
        case 3:
        proximo(&fila);
        break;
        case 4:
            printf("Atendimento finalizado!");
            break;
        }
    } while (op != 4);
    return 0;
}
