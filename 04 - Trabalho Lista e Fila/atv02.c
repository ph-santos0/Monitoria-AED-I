#include <stdio.h>
#include <stdlib.h>
// 2. Faça um programa que leia um número indeterminado de valores inteiros, correspondentes a notas, encerrando a entrada de dados quando for informado um valor igual a -1 (que não deve ser armazenado). Após esta entrada de dados, faça:

#define MAXTAM 100
typedef struct
{
    int notas[MAXTAM];
    int qtd;
} TipoLista;

void FFvazia(TipoLista *L)
{
    L->qtd = 0;
}

void inserirvalores(TipoLista *L)
{
    int notas = 0;

    // necessario ter dois prints e scan pedindo a mesma coisa pois para iniciar e continuar o while enquando a condição for verdaira!

    printf("Digite as notas: (caso queira encerrar digite -1)");
    scanf("%d", &notas);
    while (notas != -1 && L->qtd < MAXTAM) // encerrando a entrada de dados quando for informado um valor igual a -1 (que não deve ser armazenado) e o L->qtd<MAXTAM) é para continuar caso a qtd seja menor que o valor maximo
    {
        L->notas[L->qtd] = notas; // notas na posição da quantidade recebe os valores digitados
        L->qtd++;

        printf("Digite as notas: (caso queira encerrar digite -1)");
        scanf("%d", &notas);
    }
}

void mostrarvalores(TipoLista *L)
{
    for (int i = 0; i < L->qtd; i++)
    {
        printf("%d ", L->notas[i]);
    }
}

void ordeminversa(TipoLista *L)
{
    for (int i = L->qtd - 1; i >= 0; i--) // o -1 dps da qtd é por conta do indice que inicia no zero!
    {
        printf("%d\n ", L->notas[i]);
    }
}

int soma(TipoLista *L)
{
    int soma = 0;
    for (int i = 0; i < L->qtd; i++)
    {
        soma = soma + L->notas[i]; // nao esquece de colocar a posição pq é um vetor!
    }
    return soma;
}

float media(TipoLista *L, int S)
{
    float media = 0;
    media = (float)S / L->qtd;
    return media;
}

int valoresacimadamedia(TipoLista *L, float media)
{
    int acimamedia = 0;
    for (int i = 0; i < L->qtd; i++)
    {
        if (L->notas[i] > media)
        {
            acimamedia++;
        }
    }
    return acimamedia;
}
int abaixosete(TipoLista *L)
{
    int abaixosete = 0;
    for (int i = 0; i < L->qtd; i++)
    {
        if (L->notas[i] < 7)
        {
            abaixosete++;
        }
    }
    return abaixosete;
}

int main()
{
    TipoLista lista;
    FFvazia(&lista);
    inserirvalores(&lista);
    // a.	Mostre a quantidade de valores que foram lidos;

    printf("Quantidade de valores que foram lidos: %d", lista.qtd);

    // b.	Exiba todos os valores na ordem em que foram informados, um ao lado do outro;
    printf("\nValores:");
    mostrarvalores(&lista);

    // c.	Exiba todos os valores na ordem inversa à que foram informados, um abaixo do outro;
    printf("\nValores na ordem inversa:\n");
    ordeminversa(&lista);

    // d.	Calcule e mostre a soma dos valores;
    printf("Soma:");
    int Soma = soma(&lista); // tomar cuidado usando nome repetido pq o C é case sensitive
    printf("%d\n", Soma);

    // e.	Calcule e mostre a média dos valores;
    
    float Media = media(&lista, Soma);
    printf("Media: %f", media(&lista, Soma));
    // f.	Calcule e mostre a quantidade de valores acima da média calculada;

    printf("\nQuantidade de valores acima da media: %d", valoresacimadamedia(&lista, Media));

    // g.	Calcule e mostre a quantidade de valores abaixo de sete;

    printf("\nQuantidade de valores abaixo de sete: %d ", abaixosete(&lista));

    printf("\nPrograma encerrado!");

    return 0;
}
