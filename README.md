🧠 Estruturas de Dados e Algoritmos em C

Projeto desenvolvido em linguagem C com foco em prática de lógica de programação, estruturas de dados e algoritmos clássicos.

Este repositório reúne implementações de algoritmos de busca e um sistema de gerenciamento de inventário (estilo jogo), consolidando conceitos fundamentais da programação em C.

📌 Objetivo

Aplicar na prática conceitos essenciais como:

Algoritmos de busca (sequencial e binária)

Manipulação de arrays e strings

Uso de structs

Recursividade

Organização de código

Entrada e saída de dados

🚀 Projetos Incluídos
🔍 1. Algoritmos de Busca em Lista

Simula buscas em uma lista de compras utilizando diferentes abordagens.

Funcionalidades:

Busca Sequencial Iterativa

Busca Sequencial Recursiva

Busca Binária Iterativa

Busca Binária Recursiva

Retorno do índice do item encontrado

Tratamento de item inexistente

Conceitos aplicados:

strcmp para comparação de strings

Recursividade

Análise de eficiência entre algoritmos

🎒 2. Sistema de Inventário (Mochila)

Sistema interativo via terminal para gerenciamento de itens.

Funcionalidades:

➕ Inserir item

➖ Remover item

📋 Listar itens

🔎 Buscar item

🧾 Exibição automática após operações

Estrutura do Item:
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;
Conceitos aplicados:

Structs

Vetores estáticos

Busca sequencial

Manipulação de dados em memória

Menu interativo com switch

🛠️ Tecnologias Utilizadas

Linguagem C

Bibliotecas padrão:

stdio.h

stdlib.h

string.h

▶️ Como Executar
🔹 Compilar (exemplo)
gcc busca.c -o busca
gcc inventario.c -o inventario

🔹 Executar
./busca
./inventario

📋 Exemplo de Uso

Busca:
[Sequencial Iterativa] Buscando por "leite"...
-> Item encontrado no indice 5
Inventário:

===== INVENTARIO =====
1. Inserir item
2. Remover item
3. Listar itens
4. Buscar item

🧠 Aprendizados

Durante o desenvolvimento, foram reforçados:

Diferença entre algoritmos iterativos e recursivos

Importância de consistência na nomenclatura

Manipulação de memória em C

Estruturação de programas maiores

Criação de menus interativos no terminal

👨‍💻 Autor

Márcio Moraes
🎓 Estudante de Engenharia de Software
💻 Foco em Back-end (Node.js | TypeScript | C | Ruby on Rails)

⭐ Observação

Este projeto é educacional e representa minha evolução prática em programação.

Sugestões, melhorias e feedbacks são sempre bem-vindos!