#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define InicioArranjo 1
#define MaxTam 5 

typedef int Apontador;

typedef struct {
    int resposta; 
} TipoItem;

typedef struct {
    TipoItem Item[MaxTam];
    Apontador Primeiro;
    Apontador Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista) {
    Lista->Primeiro = InicioArranjo;
    Lista->Ultimo = Lista->Primeiro;
}

int Vazia(TipoLista Lista) {
    return (Lista->Primeiro == Lista->Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista) {
    if (Lista->Ultimo - 1 >= MaxTam) {
        printf("\nA lista está cheia!\n");
    } else {
        Lista->Item[Lista->Ultimo - 1] = x;
        Lista->Ultimo = Lista->Ultimo + 1;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    TipoLista listaRespostas;
    TipoItem respostaAtual;
    FLVazia(&listaRespostas); 

    const char* perguntas[5] = {
        "Telefonou para a vítima?",
        "Esteve no local do crime?",
        "Mora perto da vítima?",
        "Devia para a vítima?",
        "Já trabalhou com a vítima?"
    };

    int i;
    char respostaChar;
    int contagemPositiva = 0; 

    printf("--- INTERROGATÓRIO ---\n");
    printf("Responda às perguntas com 'S' (Sim) ou 'N' (Não).\n\n");

    for (i = 0; i < 5; i++) {
        printf("%s ", perguntas[i]);
        
        while (scanf(" %c", &respostaChar) != 1 || (respostaChar != 'S' && respostaChar != 's' && respostaChar != 'N' && respostaChar != 'n')) {
            printf("Resposta inválida. Por favor, digite S ou N: ");
            while (getchar() != '\n'); 
        }

        if (respostaChar == 'S' || respostaChar == 's') {
            respostaAtual.resposta = 1; 
            contagemPositiva++;         
        } else {
            respostaAtual.resposta = 0; 
        }
        
        Insere(respostaAtual, &listaRespostas);
    }

    printf("\n--- CLASSIFICAÇÃO ---\n");
    printf("O suspeito respondeu 'Sim' a %d pergunta(s).\n", contagemPositiva);

    switch (contagemPositiva) {
        case 0:
        case 1:
            printf("Classificação: Inocente\n");
            break;
        case 2:
            printf("Classificação: Suspeita\n");
            break;
        case 3:
        case 4:
            printf("Classificação: Cúmplice\n");
            break;
        case 5:
            printf("Classificação: Assassino\n");
            break;
    }

    printf("\nPrograma encerrado.\n");
    
    return 0;
}
