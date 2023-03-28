// TAD para Árvore Dinâmica Encadeada

#ifndef _ARVORE_BIN_DE
#define _ARVORE_BIN_DE

// definição do tipo abstrato
typedef struct no* ArvoreBin;

FILE *nomes;

// funções para alocar e desalocar memória
ArvoreBin* criar_arvore_binaria();
// função para inserção de elementos da arvore binaria
int inserir_arvore_binaria(ArvoreBin *raiz, int valor, char nome[50]);

// funções para percorrer a arvore binaria
void travessia_simetrica(ArvoreBin *raiz);

#endif