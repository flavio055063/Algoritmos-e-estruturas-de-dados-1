
#ifndef _LISTA_ENCADEADA
#define _LISTA_ENCADEADA

//typedef struct elemento* Lista;
typedef struct elemento* Lista;

// funções para alocar e desalocar memória
Lista* criar_lista();
int liberar_lista(Lista *li);	

// funções para obter informações da lista
int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);
int lista_cheia(Lista *li);

// funções para inserção de elementos da lista
int inserir_lista_inicio(Lista *li, int matricula, char nome[30], float nota);
int inserir_lista_final(Lista *li, int matricula, char nome[30], float nota);

// funções para remoção de elementos da lista
int remover_lista_inicio(Lista *li);
int remover_lista_final(Lista *li);
int remover_lista_meio(Lista *li, int matricula);

// funções para buscar elementos na lista
int buscar_lista_posicao(Lista *li, int pos, int *matricula);
int buscar_lista_dado(Lista *li, int matricula, int *pos);

int imprimir_lista(Lista *li);

#endif



