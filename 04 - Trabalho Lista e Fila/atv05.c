#include <stdio.h>
#include <stdlib.h>

// 5.Escreva um algoritmo que forneça o maior, o menor e a média aritmética dos itens inteiro de uma lista.

#define MAXTAM 10
typedef struct
{
    int num[MAXTAM];
    int qtd;
} TipoLista;

void FFvazia(TipoLista *L)
{
    L->qtd = 0; 
} 

void inserirvalores(TipoLista *L)
{
    int num = 0;


    printf("Digite os valores (caso queira encerrar digite -1)");
    scanf("%d", &num);
    while (num != -1 && L->qtd < MAXTAM) 
    {
        L->num[L->qtd] = num; 
        L->qtd++;

        printf("Digite as notas: (caso queira encerrar digite -1)");
        scanf("%d", &num);
    }
}

void maioremenor(TipoLista *L)
{
    if (L->qtd == 0)
    {
        printf("\nLista vazia!");
        return;
    }

    int maior = L->num[0];       
    int menor = L->num[0];       
    for (int i = 1; i < L->qtd; i++) 
    {
        if (maior < L->num[i])
        {
            maior = L->num[i];
        }
        if (menor > L->num[i])
        {
            menor = L->num[i];
        }
    }
    printf("\nMaior: %d", maior);
    printf("\nMenor: %d", menor);
}
float calcularmedia(TipoLista *L)
{
    int soma = 0;
    float media = 0;

    if (L->qtd == 0) // conferir lista vazia antes de fzr a media
    {
        printf("\nLista vazia!");
        return 0;
    }else
    {
        for (int i = 0; i < L->qtd; i++)
        {
            soma = soma + L->num[i];
        }
        media = (float) soma / L->qtd;// Convertemos soma para float antes de dividir
        return media;
    }
    
}
int main()
{
    TipoLista lista;
    FFvazia(&lista);
    inserirvalores(&lista);
    maioremenor(&lista);
    printf("\nmedia:%f",calcularmedia(&lista));

    return 0;
}
