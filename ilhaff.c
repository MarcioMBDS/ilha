#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10

// ------------------------------------------------------------
// STRUCTS
// ------------------------------------------------------------

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

typedef struct No {
    Item dados;
    struct No* proximo;
} No;

// ------------------------------------------------------------
// VARIÁVEIS GLOBAIS
// ------------------------------------------------------------

Item mochila[MAX_ITENS];
int totalItens = 0;

No* inicio = NULL;

int comparacoesSeq = 0;
int comparacoesBin = 0;

// ------------------------------------------------------------
// INTERFACE (VISUAL)
// ------------------------------------------------------------

void exibirMenuPrincipal() {
    printf("\n========================================\n");
    printf("   MOCHILA DE SOBREVIVENCIA - CODIGO DA ILHA\n");
    printf("========================================\n");

    printf("Itens na Mochila: %d/%d\n\n", totalItens, MAX_ITENS);

    printf("1. Adicionar Item (Loot)\n");
    printf("2. Remover Item\n");
    printf("3. Listar Itens na Mochila\n");
    printf("4. Buscar Item (Sequencial)\n");
    printf("5. Ordenar Mochila (Vetor)\n");
    printf("6. Buscar Item (Binaria - Vetor)\n");
    printf("7. Usar Lista Encadeada\n");
    printf("0. Sair\n");

    printf("----------------------------------------\n");
    printf("Escolha uma opcao: ");
}

// ------------------------------------------------------------
// FUNÇÕES VETOR
// ------------------------------------------------------------

void inserirItemVetor() {

    if (totalItens == MAX_ITENS) {
        printf("\n[ERRO] Mochila cheia!\n");
        return;
    }

    Item novo;

    printf("\n--- Adicionar Novo Item ---\n");

    printf("Nome do item: ");
    scanf(" %[^\n]", novo.nome);

    printf("Tipo do item: ");
    scanf(" %[^\n]", novo.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[totalItens++] = novo;

    printf("\n[OK] Item adicionado com sucesso!\n");
}

void listarVetor() {

    if (totalItens == 0) {
        printf("\nMochila vazia.\n");
        return;
    }

    printf("\n--- ITENS NA MOCHILA (VETOR) ---\n");

    for (int i = 0; i < totalItens; i++) {
        printf("[%d] Nome: %s | Tipo: %s | Qtd: %d\n",
               i + 1,
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade);
    }
}

void removerItemVetor() {

    char nome[30];
    printf("\nNome do item para remover: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < totalItens; i++) {

        if (strcmp(mochila[i].nome, nome) == 0) {

            for (int j = i; j < totalItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }

            totalItens--;

            printf("\n[OK] Item removido!\n");
            return;
        }
    }

    printf("\n[ERRO] Item nao encontrado!\n");
}

int buscaSequencialVetor(char nome[]) {

    comparacoesSeq = 0;

    for (int i = 0; i < totalItens; i++) {
        comparacoesSeq++;

        if (strcmp(mochila[i].nome, nome) == 0) {
            return i;
        }
    }

    return -1;
}

void ordenarVetor() {

    for (int i = 0; i < totalItens - 1; i++) {
        for (int j = 0; j < totalItens - i - 1; j++) {

            if (strcmp(mochila[j].nome, mochila[j + 1].nome) > 0) {
                Item temp = mochila[j];
                mochila[j] = mochila[j + 1];
                mochila[j + 1] = temp;
            }
        }
    }

    printf("\n[OK] Mochila ordenada!\n");
}

int buscaBinariaVetor(char nome[]) {

    comparacoesBin = 0;

    int inicio = 0;
    int fim = totalItens - 1;

    while (inicio <= fim) {

        int meio = (inicio + fim) / 2;
        comparacoesBin++;

        int cmp = strcmp(mochila[meio].nome, nome);

        if (cmp == 0)
            return meio;
        else if (cmp > 0)
            fim = meio - 1;
        else
            inicio = meio + 1;
    }

    return -1;
}

// ------------------------------------------------------------
// LISTA ENCADEADA
// ------------------------------------------------------------

void inserirLista() {

    No* novo = (No*) malloc(sizeof(No));

    printf("\n--- Inserir (Lista) ---\n");

    printf("Nome: ");
    scanf(" %[^\n]", novo->dados.nome);

    printf("Tipo: ");
    scanf(" %[^\n]", novo->dados.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo->dados.quantidade);

    novo->proximo = inicio;
    inicio = novo;

    printf("\n[OK] Item inserido na lista!\n");
}

void listarLista() {

    if (inicio == NULL) {
        printf("\nLista vazia.\n");
        return;
    }

    No* atual = inicio;

    printf("\n--- ITENS NA LISTA ---\n");

    while (atual != NULL) {
        printf("Nome: %s | Tipo: %s | Qtd: %d\n",
               atual->dados.nome,
               atual->dados.tipo,
               atual->dados.quantidade);

        atual = atual->proximo;
    }
}

void removerLista() {

    char nome[30];
    printf("\nNome para remover: ");
    scanf(" %[^\n]", nome);

    No* atual = inicio;
    No* anterior = NULL;

    while (atual != NULL) {

        if (strcmp(atual->dados.nome, nome) == 0) {

            if (anterior == NULL)
                inicio = atual->proximo;
            else
                anterior->proximo = atual->proximo;

            free(atual);

            printf("\n[OK] Removido da lista!\n");
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    printf("\n[ERRO] Item nao encontrado!\n");
}

int buscaSequencialLista(char nome[]) {

    comparacoesSeq = 0;

    No* atual = inicio;
    int pos = 0;

    while (atual != NULL) {

        comparacoesSeq++;

        if (strcmp(atual->dados.nome, nome) == 0)
            return pos;

        atual = atual->proximo;
        pos++;
    }

    return -1;
}

// ------------------------------------------------------------
// MENU LISTA
// ------------------------------------------------------------

void menuLista() {

    int op;
    char nome[30];

    do {
        printf("\n--- MENU LISTA ENCADEADA ---\n");
        printf("1 Inserir\n2 Remover\n3 Listar\n4 Buscar\n0 Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1: inserirLista(); break;
            case 2: removerLista(); break;
            case 3: listarLista(); break;
            case 4:
                printf("Nome: ");
                scanf(" %[^\n]", nome);
                printf("Pos: %d | Comparacoes: %d\n",
                       buscaSequencialLista(nome), comparacoesSeq);
                break;
        }

    } while (op != 0);
}

// ------------------------------------------------------------
// MAIN
// ------------------------------------------------------------

int main() {

    int op;
    char nome[30];

    do {
        exibirMenuPrincipal();
        scanf("%d", &op);

        switch (op) {

            case 1: inserirItemVetor(); break;
            case 2: removerItemVetor(); break;
            case 3: listarVetor(); break;

            case 4:
                printf("\nNome: ");
                scanf(" %[^\n]", nome);
                printf("Pos: %d | Comparacoes: %d\n",
                       buscaSequencialVetor(nome), comparacoesSeq);
                break;

            case 5: ordenarVetor(); break;

            case 6:
                printf("\nNome: ");
                scanf(" %[^\n]", nome);
                printf("Pos: %d | Comparacoes: %d\n",
                       buscaBinariaVetor(nome), comparacoesBin);
                break;

            case 7: menuLista(); break;

            case 0:
                printf("\nSaindo...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (op != 0);

    return 0;
}