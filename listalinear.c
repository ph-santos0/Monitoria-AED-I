#include <stdio.h>
#include <stdlib.h>
#include <windows.h>  // usar gotoxy
#include <locale.h>

#define InicioArranjo 1
#define MaxTam 5

typedef int Apontador;

typedef struct {
    int cod;
    int idade;
} TipoItem;

typedef struct {
    TipoItem Item[MaxTam];
    Apontador Primeiro;
    Apontador Ultimo;
} TipoLista;

TipoLista Lista;
TipoItem x;
Apontador pos;

/*
void gotoxy(int x, int y){ //Função para centralizar
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}
*/

//---------------------------------------------
// FUNÇÕES DE LISTA
//---------------------------------------------

void FLVazia(TipoLista *Lista) {
    Lista->Primeiro = InicioArranjo;
    Lista->Ultimo = Lista->Primeiro;
}

int Vazia(TipoLista Lista) {
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista) {
    if (Lista->Ultimo - 1 >= MaxTam) {
        printf("\nA lista está cheia!\n");
    } else {
        Lista->Item[Lista->Ultimo - 1] = x;
        Lista->Ultimo = Lista->Ultimo + 1;
    }
}

void Imprime(TipoLista Lista) {
    if (Vazia(Lista)) {
        printf("\nA lista está vazia!\n");
        return;
    }

    int aux;
    for (aux = Lista.Primeiro - 1; aux <= (Lista.Ultimo - 2); aux++) {
        printf("Código: %d\nIdade: %d\n\n", Lista.Item[aux].cod, Lista.Item[aux].idade);
    }
}

void Retira(Apontador pos, TipoLista *Lista, TipoItem *x) {
    int Aux;

    if (Vazia(*Lista) || pos < Lista->Primeiro || pos >= Lista->Ultimo) {
        printf("ERRO: Posição inválida!\n");
    } else {
        *x = Lista->Item[pos - 1];
        printf("O elemento retirado foi o de código %d\n", x->cod);

        for (Aux = pos; Aux < Lista->Ultimo - 1; Aux++) {
            Lista->Item[Aux - 1] = Lista->Item[Aux];
        }

        Lista->Ultimo = Lista->Ultimo - 1;
    }
}

void RetiraPos(Apontador pos, TipoLista *Lista, TipoItem *x) {
    int Aux;

    if (Vazia(*Lista) || pos < Lista->Primeiro - 1 || pos > Lista->Ultimo - 2) {
        printf("ERRO: Posição inválida!\n");
    } else {
        *x = Lista->Item[pos];
        printf("O elemento retirado foi o de código %d\n", x->cod);

        for (Aux = pos; Aux < Lista->Ultimo - 2; Aux++) {
            Lista->Item[Aux] = Lista->Item[Aux + 1];
        }

        Lista->Ultimo = Lista->Ultimo - 1;
    }
}

void Procura(TipoItem x, TipoLista Lista) {
    int i, encontrou = 0;

    for (i = Lista.Primeiro - 1; i <= Lista.Ultimo - 2; i++) {
        if (Lista.Item[i].cod == x.cod) {
            encontrou = 1;
            printf("Código encontrado na posição: %d\n", i + 1);
            break;
        }
    }

    if (!encontrou) {
        printf("Código não encontrado!\n");
    }
}

//---------------------------------------------
// PROGRAMA PRINCIPAL
//---------------------------------------------

int main() {
    int opcao, resposta;
    setlocale(LC_ALL, "");

    FLVazia(&Lista);

    do {
        printf("\n\n====== MENU ======\n");
        printf("0 - Sair\n");
        printf("1 - Esvaziar lista\n");
        printf("2 - Verificar se a lista está vazia\n");
        printf("3 - Inserir elemento na lista\n");
        printf("4 - Imprimir os elementos da lista\n");
        printf("5 - Retirar elemento (antes da posição determinada)\n");
        printf("6 - Retirar elemento (na posição)\n");
        printf("7 - Pesquisar elemento na lista\n");
        printf("==================\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("PROGRAMA ENCERRADO!\n");
                break;

            case 1:
                FLVazia(&Lista);
                printf("\nA lista foi esvaziada.\n");
                break;

            case 2:
                resposta = Vazia(Lista);
                if (resposta == 1)
                    printf("\nA lista está vazia.\n");
                else
                    printf("\nA lista NÃO está vazia.\n");
                break;

            case 3:
                printf("Digite o código: ");
                scanf("%d", &x.cod);
                printf("Digite a idade: ");
                scanf("%d", &x.idade);
                Insere(x, &Lista);
                break;

            case 4:
                Imprime(Lista);
                break;

            case 5:
                printf("Digite a posição: ");
                scanf("%d", &pos);
                Retira(pos, &Lista, &x);
                break;

            case 6:
                printf("Digite a posição: ");
                scanf("%d", &pos);
                RetiraPos(pos, &Lista, &x);
                break;

            case 7:
                printf("Digite o código a pesquisar: ");
                scanf("%d", &x.cod);
                Procura(x, Lista);
                break;

            default:
                printf("\nOpção inválida!\n");
        }

        printf("\nPressione qualquer tecla para continuar...");
        system("pause");
        system("cls");

    } while (opcao != 0);

    return 0;
}

