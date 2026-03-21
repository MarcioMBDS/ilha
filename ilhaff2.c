#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 20

// ------------------------------------------------------------
// STRUCT
// ------------------------------------------------------------
typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

// ------------------------------------------------------------
Componente itens[MAX];
int total = 0;
int comparacoes = 0;
int ordenadoPorNome = 0;

// ------------------------------------------------------------
// FUNÇÃO AUXILIAR
// ------------------------------------------------------------
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ------------------------------------------------------------
// CADASTRO
// ------------------------------------------------------------
void cadastrar() {

    if (total == MAX) {
        printf("\n[ERRO] Limite atingido!\n");
        return;
    }

    printf("\n--- Coletando Componente ---\n");

    printf("Nome: ");
    fgets(itens[total].nome, 30, stdin);
    itens[total].nome[strcspn(itens[total].nome, "\n")] = 0;

    printf("Tipo: ");
    fgets(itens[total].tipo, 20, stdin);
    itens[total].tipo[strcspn(itens[total].tipo, "\n")] = 0;

    printf("Prioridade (1-10): ");
    scanf("%d", &itens[total].prioridade);
    limparBuffer();

    total++;
    ordenadoPorNome = 0;

    printf("[OK] Componente adicionado!\n");
}

// ------------------------------------------------------------
// MOSTRAR
// ------------------------------------------------------------
void mostrarComponentes() {

    if (total == 0) {
        printf("\n[VAZIO]\n");
        return;
    }

    printf("\n--- COMPONENTES ---\n");

    for (int i = 0; i < total; i++) {
        printf("[%d] %s | %s | Prioridade: %d\n",
               i+1,
               itens[i].nome,
               itens[i].tipo,
               itens[i].prioridade);
    }
}

// ------------------------------------------------------------
// BUBBLE SORT (NOME)
// ------------------------------------------------------------
void bubbleSortNome() {

    comparacoes = 0;

    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {

            comparacoes++;

            if (strcmp(itens[j].nome, itens[j+1].nome) > 0) {
                Componente temp = itens[j];
                itens[j] = itens[j+1];
                itens[j+1] = temp;
            }
        }
    }

    ordenadoPorNome = 1;
}

// ------------------------------------------------------------
// INSERTION SORT (TIPO)
// ------------------------------------------------------------
void insertionSortTipo() {

    comparacoes = 0;

    for (int i = 1; i < total; i++) {

        Componente chave = itens[i];
        int j = i - 1;

        while (j >= 0 && strcmp(itens[j].tipo, chave.tipo) > 0) {
            comparacoes++;
            itens[j + 1] = itens[j];
            j--;
        }

        itens[j + 1] = chave;
    }
}

// ------------------------------------------------------------
// SELECTION SORT (PRIORIDADE)
// ------------------------------------------------------------
void selectionSortPrioridade() {

    comparacoes = 0;

    for (int i = 0; i < total - 1; i++) {

        int menor = i;

        for (int j = i + 1; j < total; j++) {
            comparacoes++;
            if (itens[j].prioridade < itens[menor].prioridade) {
                menor = j;
            }
        }

        if (menor != i) {
            Componente temp = itens[i];
            itens[i] = itens[menor];
            itens[menor] = temp;
        }
    }
}

// ------------------------------------------------------------
// BUSCA BINÁRIA (NOME)
// ------------------------------------------------------------
int buscaBinariaPorNome(char chave[]) {

    if (!ordenadoPorNome) {
        printf("\n[ERRO] Ordene por nome primeiro!\n");
        return -1;
    }

    int ini = 0, fim = total - 1;
    comparacoes = 0;

    while (ini <= fim) {

        int meio = (ini + fim) / 2;
        comparacoes++;

        int cmp = strcmp(itens[meio].nome, chave);

        if (cmp == 0)
            return meio;
        else if (cmp > 0)
            fim = meio - 1;
        else
            ini = meio + 1;
    }

    return -1;
}

// ------------------------------------------------------------
// MEDIR TEMPO
// ------------------------------------------------------------
void medirTempo(void (*funcao)(), char nome[]) {

    clock_t inicio = clock();

    funcao();

    clock_t fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\n[%s]\n", nome);
    printf("Comparacoes: %d\n", comparacoes);
    printf("Tempo: %.6f segundos\n", tempo);
}

// ------------------------------------------------------------
// MENU
// ------------------------------------------------------------
void menu() {

    int op;
    char busca[30];

    do {

        printf("\n=====================================\n");
        printf(" PLANO DE FUGA - CODIGO DA ILHA\n");
        printf("=====================================\n");
        printf("Componentes: %d/%d\n", total, MAX);

        printf("\n1. Adicionar Componente\n");
        printf("2. Listar Componentes\n");
        printf("3. Ordenar por Nome (Bubble)\n");
        printf("4. Ordenar por Tipo (Insertion)\n");
        printf("5. Ordenar por Prioridade (Selection)\n");
        printf("6. Buscar Componente (Binaria)\n");
        printf("0. Sair\n");

        printf("\nEscolha: ");
        scanf("%d", &op);
        limparBuffer();

        switch (op) {

            case 1: cadastrar(); break;

            case 2: mostrarComponentes(); break;

            case 3: medirTempo(bubbleSortNome, "Bubble Sort (Nome)"); break;

            case 4: medirTempo(insertionSortTipo, "Insertion Sort (Tipo)"); break;

            case 5: medirTempo(selectionSortPrioridade, "Selection Sort (Prioridade)"); break;

            case 6:
                printf("Nome: ");
                fgets(busca, 30, stdin);
                busca[strcspn(busca, "\n")] = 0;

                int pos = buscaBinariaPorNome(busca);

                if (pos != -1)
                    printf("[ENCONTRADO] Posicao: %d\n", pos);
                else
                    printf("[NAO ENCONTRADO]\n");

                printf("Comparacoes: %d\n", comparacoes);
                break;

        }

    } while (op != 0);
}

// ------------------------------------------------------------
// MAIN
// ------------------------------------------------------------
int main() {
    menu();
    return 0;
}