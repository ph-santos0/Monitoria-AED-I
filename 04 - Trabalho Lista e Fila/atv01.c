#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 3

// 1. Faça um programa que carregue uma lista com os modelos (inteiro) de três motos. Carregue esta mesma lista com o consumo dessas motos correspondente, isto é, quantos quilômetros cada uma faz com um litro de combustível. Calcule e mostre:

typedef struct
{
    int modelo;    // modelo da moto
    float consumo; // consumo de km/L
} TipoItem;

typedef struct
{
    TipoItem Motos[MAXTAM];
    int qtd; // quantidade na lista
} TipoLista; // Tem as motos e a quantidade ja inserida na lista

void FFvazia(TipoLista *L)
{
    L->qtd = 0; // mesma coisa de (*L).qtd ( acessando o conteudo)
} // fazer fila ficar vazia para o computador não pegar lixo de memoria

int ListaCheia(TipoLista *L) // conferir se a lista ta cheia para saber se pode ou não inserir mais motos
{
    if (L->qtd == MAXTAM) // qtd for igual tamanho maximo
        return 1;
    else
        return 0;
}

int inserirmoto(TipoLista *L, TipoItem item)
{
    if (ListaCheia(L))
    {
        printf("Lista cheia, não foi possivel adicionar mais modelos!");
        return 0;
    } // False ou que deu erro

    L->Motos[L->qtd] = item; // insere na primera posição livre na lista (a qtd como indice), exemplo, se a quantidade for igual a 0, sera inserida no indice zero, assim vai passar pro proximo e a qtd passara a ser 1 e assim por diante ate atingir a igualdade com o MAXTAM
    L->qtd++;                // a qtd mostra quantas motos tem na lista
    return 1;                // true ou confirma q deu certo
}

int motoeconomica(TipoLista *L)
{
    int economica = 0;               // para fins de comparação, tipo menor e maior numero
    for (int i = 1; i < L->qtd; i++) // (*L).qtd
    // como atribuimos o primeiro indice a economica ou seja a primeira moto, começa em um e n faz sentido comparar a primeira com ela msm, ent a  principio colocamos como se ela fosse a mais economica
    {
        if (L->Motos[i].consumo > L->Motos[economica].consumo)
        {
            economica = i;
        }
        // acessando na lista e acessando o consumo dentro do item motos(array))
    }
    return L->Motos[economica].modelo; // ao comparar o consumo e descobrir qual é a mais economica, retorna o modelo dela.
}

void Kms(TipoLista *L)
{ // n retorna nada ent é void, calculo rapido para saber quanto elas gastam em 100 km
    float litros = 0;
    for (int i = 0; i < L->qtd; i++)
    {
        litros = 100 / L->Motos[i].consumo;
        printf("\nModelo %d gasta %f litros em 100 km", L->Motos[i].modelo, litros);
    }
}

int main()
{
    TipoLista lista; // armazena espaço na memoria // cria a lista
    TipoItem moto;   // cria a moto que manda pra lista

    FFvazia(&lista); // usando & para mandar o endereço

    // inserir os modelos da moto e o consumod e cada:
    for (int i = 0; i < MAXTAM; i++)
    {
        printf("\nDigite o %d modelo da moto e o seu consumo:", i + 1);
        scanf("%d%f", &moto.modelo, &moto.consumo); // recebendo os dados das motos

        inserirmoto(&lista, moto); // lista para *L e moto para Item
    }

    // a) O modelo da moto mais econômico

    int Modeloecomomico = motoeconomica(&lista);
    printf("\nO modelo mais economico e: %d\n", Modeloecomomico);

    // b)Quantos litros de combustível cada uma moto cadastrada consome para percorrer uma distância de 100 quilômetros.

    Kms(&lista);

    return 0;
}
