#include <stdio.h>
#include <stdlib.h>
#include<conio.h> //usar o gotoxy
#include<windows.h> //usar o gotoxy
#include<locale.h>
#define InicioArranjo 1
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
    Apontador Primeiro;
    Apontador Ultimo;
} TipoLista;

TipoLista Lista;
TipoItem x;
Apontador pos;

/*void gotoxy(int x, int y){ //Função para centralizar
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}*/ //para usar função gotoxy


void FLVazia (TipoLista *Lista)
{
    Lista->Primeiro=InicioArranjo;
    Lista->Ultimo=Lista->Primeiro;
}

int Vazia (TipoLista Lista)
{
    return (Lista.Primeiro==Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista)
{
    if (Lista->Ultimo > MaxTam)
        printf("\n A lista esta cheia\n");
    else
    {
        Lista->Item[Lista->Ultimo -1]=x;
        Lista->Ultimo=Lista->Ultimo+1;
    }
}	Continuação de estrutura de dados abstratas - Lista por arranjo

void Imprime (TipoLista Lista)
{
    int aux;
    for (aux=Lista.Primeiro-1;aux<=(Lista.Ultimo-2);aux=aux+1)
    {
        printf("Cod: %d\n Idade: %d\n\n\n", Lista.Item[aux].cod, Lista.Item[aux].idade);
    }
}

void Retira (Apontador pos, TipoLista *Lista, TipoItem *x)
{
    int Aux;
    if (Vazia (*Lista) || pos>=Lista->Ultimo)
    {
        printf("ERRO: Posição não existe\n");
    }
    else
    {
        *x = Lista->Item[pos-1];
        printf("O elemento retirado foi o de codigo %d\n", x->cod);
        Lista->Ultimo=Lista->Ultimo-1;
        for (Aux =pos; Aux < Lista->Ultimo;Aux=Aux+1)
            Lista->Item[Aux-1]=Lista->Item[Aux];
    }
}

void RetiraPos (Apontador pos, TipoLista *Lista, TipoItem *x)
{
    int Aux;
    if (Vazia (*Lista) || pos>=Lista->Ultimo-1)
    {
        printf("ERRO: Posição não existe\n");
    }
    else
    {
        *x = Lista->Item[pos];
        printf("O elemento retirado foi o de codigo %d\n", x->cod);
        Lista->Ultimo=Lista->Ultimo-1;
        for (Aux =pos; Aux < Lista->Ultimo-1;Aux=Aux+1)
            Lista->Item[Aux]=Lista->Item[Aux+1];
    }
}

void Procura(TipoItem x, TipoLista Lista)
{
    int i, encontrou=0;
    for (i=Lista.Primeiro-1; i<=Lista.Ultimo-2;i=i+1)
    {
      if (Lista.Item[i].cod==x.cod)
      {
          encontrou=1;
          printf("Codigo encontrado na posicao:%d\n",i);
          break;
      }
    }
    if (encontrou==0)
    {
        printf("Codigo nao encontrado\n");
    }
}

int main ()
{
    int opcao, resposta;
    setlocale(LC_ALL, ""); //aceitar acentos
    FLVazia(&Lista);
    do
    {

        printf("\n\nMENU\n\n");
        printf("Digite a opcão desejada:\n ");
        printf("0 - Sair\n");
        printf("1 - Esvaziar lista\n");
        printf("2 - Verificar se a lista esta vazia\n");
        printf("3 - Inserir elemento na lista\n");
        printf("4 - Imprimir os elementos da lista\n");
        printf("5 - Retirar elemento da lista antes da posição determinada\n");
        printf("6 - Retirar elemento da lista\n");
        printf("7 - Pesquisar elemento na lista\n");
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
                FLVazia(&Lista);
                printf("\nA LISTA VAZIA\n");
                break;
            }
            case 2:
            {
                resposta=Vazia(Lista);
                if (resposta==1)
                    printf("\n Lista esta vazia\n");
                else
                    printf("\n Lista não esta vazia\n");
                break;
            }
            case 3:
            {
                printf("Digite o codigo\n");
                scanf("%d", &x.cod);
                printf("Digite a idade\n");
                scanf("%d", &x.idade);
                Insere(x, &Lista);
                break;
            }
            case 4:
            {
                Imprime(Lista);
                break;
            }
            case 5:
            {
                printf("Digite a posição\n");
                scanf("%d", &pos);
                Retira(pos, &Lista, &x);
                break;
            }
            case 6:
            {
                printf("Digite a posição\n");
                scanf("%d", &pos);
                RetiraPos(pos, &Lista, &x);
                break;
            }
            case 7:
            {
                printf("Digite o elemento\n");
                scanf("%d", &x.cod);
                Procura(x, Lista);
                break;
            }

            default: printf("\n\nOpcao invalida\n\n");
        } //fim do case
        _getch();
        system("cls");
    } while (opcao != 0);//fim do while
    return(0);
}


