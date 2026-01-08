#include <stdio.h>
#include <stdlib.h>

#define MaxTam 3

typedef struct
{
    int modelo;
    float consumo;
} TipoItem;

typedef struct
{
    TipoItem Item[MaxTam];
    int Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista)
{
    Lista->Ultimo = 0;
}

void Insere(TipoItem x, TipoLista *Lista)
{
    if (Lista->Ultimo < MaxTam)
    {
        Lista->Item[Lista->Ultimo] = x;
        Lista->Ultimo++;
    }
}

int main()
{
    TipoLista listaMotos;
    TipoItem moto;
    FLVazia(&listaMotos);
    int i, melhorModelo;
    float maiorConsumo = 0.0;

    printf("--- Cadastro de Motos ---\n");
    for (i = 0; i < MaxTam; i++)
    {
        printf("Moto %d - Digite o modelo (numero inteiro): ", i + 1);
        scanf("%d", &moto.modelo);
        printf("Digite o consumo (km/l): ");
        scanf("%f", &moto.consumo);
        Insere(moto, &listaMotos);
    }

    printf("\n--- Relatorio ---\n");
    for (i = 0; i < listaMotos.Ultimo; i++)
    {
        float litrosNecessarios = 100.0 / listaMotos.Item[i].consumo;
        printf("Modelo: %d | Consumo: %.2f km/l | Litros p/ 100km: %.2f\n",
               listaMotos.Item[i].modelo, listaMotos.Item[i].consumo, litrosNecessarios);

        if (listaMotos.Item[i].consumo > maiorConsumo)
        {
            maiorConsumo = listaMotos.Item[i].consumo;
            melhorModelo = listaMotos.Item[i].modelo;
        }
    }

    printf("\nMotocicleta mais economica: Modelo %d (%.2f km/l)\n", melhorModelo, maiorConsumo);
    return 0;
}
