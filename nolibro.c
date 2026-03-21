#include <stdio.h>

#define TAM 10

// -------------------------------
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// -------------------------------
void imprimir(int vetor[]) {
    printf("[ ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]");
}

// -------------------------------
void copiarVetor(int origem[], int destino[]) {
    for (int i = 0; i < TAM; i++) {
        destino[i] = origem[i];
    }
}

// -------------------------------
void bubbleSort(int v[]) {
    for (int i = 0; i < TAM - 1; i++) {
        for (int j = 0; j < TAM - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                trocar(&v[j], &v[j + 1]);
            }
        }
    }
}

// -------------------------------
void insertionSort(int v[]) {
    for (int i = 1; i < TAM; i++) {
        int chave = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = chave;
    }
}

// -------------------------------
void selectionSort(int v[]) {
    for (int i = 0; i < TAM - 1; i++) {
        int menor = i;

        for (int j = i + 1; j < TAM; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }

        if (menor != i) {
            trocar(&v[i], &v[menor]);
        }
    }
}

// -------------------------------
int main() {

    int ordenado[TAM]  = {1,2,3,4,5,6,7,8,9,10};
    int inverso[TAM]   = {10,9,8,7,6,5,4,3,2,1};
    int aleatorio[TAM] = {85,54,76,4,48,43,85,73,55,83};

    int copia[TAM];

    printf("--- GERANDO LISTAS DE ENTRADA ---\n");

    printf("Original - Ordenada   : ");
    imprimir(ordenado);
    printf("\n");

    printf("Original - Inversa    : ");
    imprimir(inverso);
    printf("\n");

    printf("Original - Aleatoria  : ");
    imprimir(aleatorio);
    printf("\n");

    printf("--------------------------------------\n\n");

    // ================= BUBBLE =================
    printf("======== 1. BUBBLE SORT ========\n");

    copiarVetor(ordenado, copia);
    bubbleSort(copia);
    printf("Bubble Sort | Melhor Caso (ja ordenada) : ");
    imprimir(copia);
    printf("\n");

    copiarVetor(inverso, copia);
    bubbleSort(copia);
    printf("Bubble Sort | Pior Caso (ordem inversa) : ");
    imprimir(copia);
    printf("\n");

    copiarVetor(aleatorio, copia);
    bubbleSort(copia);
    printf("Bubble Sort | Caso Medio (aleatoria)    : ");
    imprimir(copia);
    printf("\n\n");

    // ================= INSERTION =================
    printf("======== 2. INSERTION SORT ========\n");

    copiarVetor(ordenado, copia);
    insertionSort(copia);
    printf("Insertion Sort | Melhor Caso (ja ordenada): ");
    imprimir(copia);
    printf("\n");

    copiarVetor(inverso, copia);
    insertionSort(copia);
    printf("Insertion Sort | Pior Caso (ordem inversa): ");
    imprimir(copia);
    printf("\n");

    copiarVetor(aleatorio, copia);
    insertionSort(copia);
    printf("Insertion Sort | Caso Medio (aleatoria)   : ");
    imprimir(copia);
    printf("\n\n");

    // ================= SELECTION =================
    printf("======== 3. SELECTION SORT ========\n");

    copiarVetor(ordenado, copia);
    selectionSort(copia);
    printf("Selection Sort | Melhor Caso (ja ordenada): ");
    imprimir(copia);
    printf("\n");

    copiarVetor(inverso, copia);
    selectionSort(copia);
    printf("Selection Sort | Pior Caso (ordem inversa): ");
    imprimir(copia);
    printf("\n");

    copiarVetor(aleatorio, copia);
    selectionSort(copia);
    printf("Selection Sort | Caso Medio (aleatoria)   : ");
    imprimir(copia);
    printf("\n");

    return 0;
}