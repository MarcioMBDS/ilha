🎒 Mochila de Sobrevivência — Código da Ilha

Projeto desenvolvido em linguagem C com foco no aprendizado de estruturas de dados, algoritmos de busca e ordenação, demonstrando evolução prática ao longo de diferentes versões do sistema.

---

📁 Estrutura do Projeto

📦 ilha  
┣ 📜 isla.c  
┣ 📜 island.c  
┣ 📜 ilhaff.c  
┣ 📜 nolibro.c  
┣ 📜 README.md  

---

📄 Descrição dos Arquivos

🔹 isla.c  
Primeira versão do sistema de mochila.

Implementa um inventário simples utilizando vetor (lista sequencial).

Funcionalidades:
- Inserir item  
- Remover item  
- Listar itens  
- Buscar item por nome (busca sequencial)  

Objetivo:
Praticar fundamentos como:
- Structs  
- Arrays  
- Lógica de programação  

---

🔹 island.c  
Script dedicado ao estudo de algoritmos de busca.

Implementações:
✔ Busca Sequencial  
- Iterativa  
- Recursiva  

✔ Busca Binária  
- Iterativa  
- Recursiva  

Características:
- Uso de vetor de strings  
- Funções auxiliares recursivas  
- Comparações com strcmp  
- Impressão de resultados no terminal  

Objetivo:
Entender diferenças entre:
- Busca linear vs binária  
- Iteração vs recursão  

---

🔹 ilhaff.c  
Versão final e completa do sistema.

Estruturas utilizadas:
- Vetor (lista sequencial)  
- Lista encadeada  

Funcionalidades:
- Inserir item  
- Remover item  
- Listar itens  
- Buscar item (sequencial)  
- Ordenar itens (Bubble Sort)  
- Buscar item (binária - vetor)  

Extras:
- Contador de comparações  
- Menu interativo  
- Interface organizada no terminal  

---

🔹 nolibro.c  
Script desenvolvido para estudo e comparação de algoritmos de ordenação simples.

Implementações:
✔ Bubble Sort  
✔ Insertion Sort  
✔ Selection Sort  

Funcionalidades:
- Geração de listas de teste:
  - Lista já ordenada (melhor caso)
  - Lista em ordem inversa (pior caso)
  - Lista aleatória (caso médio)
- Ordenação completa das listas
- Impressão formatada dos resultados no terminal

Conceitos aplicados:
- Uso de função auxiliar de troca (ponteiros)
- Comparação entre algoritmos clássicos
- Análise prática de comportamento dos algoritmos

Objetivo:
Entender na prática:
- Diferença de desempenho entre algoritmos
- Impacto do tipo de entrada (melhor, pior e médio caso)
- Funcionamento interno de algoritmos de ordenação

---

🧠 Conceitos Aplicados

- Structs em C  
- Arrays (vetores)  
- Ponteiros  
- Alocação dinâmica (malloc / free)  
- Listas encadeadas  

Algoritmos:

🔍 Busca:
- Busca sequencial (iterativa e recursiva)  
- Busca binária (iterativa e recursiva)  

🔄 Ordenação:
- Bubble Sort  
- Insertion Sort  
- Selection Sort  

📊 Análise:
- Comparação de desempenho  
- Diferença entre cenários de entrada  

---

📊 Comparação de Estruturas

| Operação            | Vetor | Lista Encadeada |
|--------------------|------|-----------------|
| Inserção           | O(1) | O(1)            |
| Remoção            | O(n) | O(1)*           |
| Busca Sequencial   | O(n) | O(n)            |
| Busca Binária      | O(log n) | ❌ Não aplicável |

\* Considerando remoção no início ou com referência ao nó anterior.

---

🖥️ Interface (ilhaff.c)

MOCHILA DE SOBREVIVENCIA - CODIGO DA ILHA

Itens na Mochila: X/10

1. Adicionar Item (Loot)  
2. Remover Item  
3. Listar Itens  
4. Buscar (Sequencial)  
5. Ordenar (Vetor)  
6. Buscar (Binária)  
7. Lista Encadeada  
0. Sair  

---

📊 Saída do Script de Ordenação (nolibro.c)

--- GERANDO LISTAS DE ENTRADA ---

Original - Ordenada   : [ 1 2 3 4 5 6 7 8 9 10 ]  
Original - Inversa    : [ 10 9 8 7 6 5 4 3 2 1 ]  
Original - Aleatoria  : [ 85 54 76 4 48 43 85 73 55 83 ]  

======== 1. BUBBLE SORT ========  
======== 2. INSERTION SORT ========  
======== 3. SELECTION SORT ========  

⚙️ Como Compilar e Executar

gcc isla.c -o isla
./isla

gcc island.c -o island
./island

gcc ilhaff.c -o ilhaff
./ilhaff

gcc nolibro.c -o nolibro
./nolibro

⚠️ Observações Importantes

A busca binária exige ordenação prévia
A lista encadeada não suporta busca binária
O vetor possui limite fixo (MAX_ITENS)
A lista encadeada cresce dinamicamente
O arquivo island.c é demonstrativo
Os algoritmos de ordenação simples não são eficientes para grandes volumes

🎯 Aprendizados

Este projeto demonstra:

Evolução de um sistema simples para um sistema completo
Diferença entre estruturas estáticas e dinâmicas
Impacto da escolha de estrutura no desempenho
Aplicação prática de algoritmos clássicos
Comparação entre métodos de ordenação
Análise de cenários (melhor, pior e caso médio)

👨‍💻 Autor
Márcio Moraes

Projeto acadêmico desenvolvido com foco na evolução como desenvolvedor e domínio dos fundamentos de programação em C.