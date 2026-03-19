#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ------------------------------------------------------------
// Definições
// ------------------------------------------------------------

#define MAX_ITENS 10

// Struct que representa um item da mochila
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Vetor de itens (lista estática)
Item mochila[MAX_ITENS];

// Controla quantidade atual de itens
int totalItens = 0;

// ------------------------------------------------------------
// PROTÓTIPOS (IMPORTANTE - evita erro de compilação)
// ------------------------------------------------------------

void inserirItem();
void removerItem();
void listarItens();
void buscarItem();

// ------------------------------------------------------------
// Função: Inserir item
// ------------------------------------------------------------
void inserirItem() {

    if (totalItens == MAX_ITENS) {
        printf("Mochila cheia!\n");
        return;
    }

    Item novo;

    printf("Nome do item: ");
    scanf(" %[^\n]", novo.nome);

    printf("Tipo (arma, municao, cura...): ");
    scanf(" %[^\n]", novo.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[totalItens] = novo;
    totalItens++;

    printf("Item cadastrado com sucesso!\n");

    listarItens(); // exibe após operação
}

// ------------------------------------------------------------
// Função: Remover item
// ------------------------------------------------------------
void removerItem() {

    char nomeBusca[30];
    int pos = -1;

    printf("Digite o nome do item para remover: ");
    scanf(" %[^\n]", nomeBusca);

    // Busca sequencial
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Item nao encontrado!\n");
        return;
    }

    // Desloca elementos
    for (int i = pos; i < totalItens - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    totalItens--;

    printf("Item removido com sucesso!\n");

    listarItens();
}

// ------------------------------------------------------------
// Função: Listar itens
// ------------------------------------------------------------
void listarItens() {

    if (totalItens == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    printf("\n--- ITENS NA MOCHILA ---\n");

    for (int i = 0; i < totalItens; i++) {
        printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade);
    }
}

// ------------------------------------------------------------
// Função: Buscar item (busca sequencial)
// ------------------------------------------------------------
void buscarItem() {

    char nomeBusca[30];
    int encontrado = 0;

    printf("Digite o nome do item para buscar: ");
    scanf(" %[^\n]", nomeBusca);

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {

            printf("\nItem encontrado!\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Item nao encontrado.\n");
    }
}

// ------------------------------------------------------------
// MENU PRINCIPAL
// ------------------------------------------------------------
int main() {

    int opcao;

    do {
        printf("\n===== INVENTARIO =====\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("Escolha: ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem();
                break;
            case 2:
                removerItem();
                break;
            case 3:
                listarItens();
                break;
            case 4:
                buscarItem();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}