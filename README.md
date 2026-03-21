🎒 Mochila de Sobrevivência — Código da Ilha

Projeto desenvolvido em linguagem C com foco no aprendizado de estruturas de dados, algoritmos de busca e ordenação, demonstrando evolução prática ao longo de diferentes versões do sistema — do básico ao nível mestre.

📁 Estrutura do Projeto

📦 ilha
┣ 📜 isla.c
┣ 📜 island.c
┣ 📜 ilhaff.c
┣ 📜 nolibro.c
┣ 📜 ilhaff2.c
┣ 📜 README.md

📄 Descrição dos Arquivos:

----------------------
🔹 isla.c

Primeira versão do sistema de mochila.

Implementa um inventário simples utilizando vetor (lista sequencial).

Funcionalidades:

Inserir item
Remover item
Listar itens
Buscar item por nome (busca sequencial)

Objetivo:
Praticar fundamentos como:

Structs
Arrays

Lógica de programação
----------------------
🔹 island.c

Script dedicado ao estudo de algoritmos de busca.

Implementações:
✔ Busca Sequencial

Iterativa
Recursiva

✔ Busca Binária

Iterativa
Recursiva

Características:

Uso de vetor de strings
Funções recursivas
Comparações com strcmp
Saída no terminal

Objetivo:
Entender diferenças entre:

Busca linear vs binária

Iteração vs recursão
----------------------
🔹 ilhaff.c

Versão completa do sistema.

Estruturas utilizadas:

Vetor (lista sequencial)

Lista encadeada

Funcionalidades:

Inserir item
Remover item
Listar itens
Buscar item (sequencial)
Ordenar itens (Bubble Sort)
Buscar item (binária - vetor)

Extras:

Contador de comparações
Menu interativo
Interface organizada

----------------------
🔹 nolibro.c

Script de estudo e comparação de algoritmos de ordenação.

Implementações:

✔ Bubble Sort
✔ Insertion Sort
✔ Selection Sort

Funcionalidades:

Geração de listas:
Ordenada (melhor caso)
Inversa (pior caso)
Aleatória (caso médio)
Ordenação das listas
Impressão formatada

Objetivo:

Entender comportamento dos algoritmos
Comparar desempenho em diferentes cenários
🔹 ilhaff2.c

🧩 Estrutura

typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

⚙️ Funcionalidades

✔ Cadastro de até 20 componentes
✔ Ordenação com múltiplas estratégias:

Bubble Sort → por nome
Insertion Sort → por tipo
Selection Sort → por prioridade

✔ Busca Binária otimizada (por nome)
✔ Contagem de comparações
✔ Medição de tempo com clock()
✔ Exibição completa dos dados
✔ Menu interativo estilo jogo

🧠 Conceitos Aplicados

Modularização de código
Ponteiros e structs
Algoritmos clássicos aplicados
Análise de desempenho real
Tomada de decisão baseada em algoritmo

🎮 Interface (exemplo)

PLANO DE FUGA - CODIGO DA ILHA (NIVEL MESTRE)

Itens na Mochila: 1/20
Status: NAO ORDENADO

1. Adicionar Componente
2. Descartar Componente
3. Listar Componentes
4. Organizar Mochila
5. Busca Binaria (por nome)
0. Sair

🎯 Objetivo

Simular um cenário real onde:

A escolha do algoritmo impacta o desempenho
A ordenação influencia diretamente a busca
O jogador decide a melhor estratégia

🧠 Conceitos Aplicados (Resumo Geral)

📦 Estruturas

Structs
Arrays
Listas encadeadas

🔍 Busca

Sequencial (iterativa e recursiva)
Binária (iterativa e recursiva)

🔄 Ordenação

Bubble Sort
Insertion Sort
Selection Sort

📊 Análise

Comparação de algoritmos
Contagem de operações
Medição de tempo
Diferença entre cenários (melhor, pior, médio)

📊 Comparação de Estruturas

Operação	Vetor	Lista Encadeada
Inserção	O(1)	O(1)
Remoção	O(n)	O(1)*
Busca Sequencial	O(n)	O(n)
Busca Binária	O(log n)	❌ Não aplicável

* Considerando remoção com referência ao nó anterior.

⚙️ Como Compilar e Executar

gcc isla.c -o isla
./isla

gcc island.c -o island
./island

gcc ilhaff.c -o ilhaff
./ilhaff

gcc nolibro.c -o nolibro
./nolibro

gcc ilhaff2.c -o ilhaff2
./ilhaff2

⚠️ Observações Importantes

Busca binária exige ordenação prévia
Lista encadeada não suporta busca binária
Vetor possui limite fixo
Algoritmos simples não escalam bem
O módulo nível mestre adiciona análise de desempenho real

👨‍💻 Autor

Márcio Moraes

Projeto acadêmico com foco na evolução como desenvolvedor e domínio sólido dos fundamentos de programação em C.