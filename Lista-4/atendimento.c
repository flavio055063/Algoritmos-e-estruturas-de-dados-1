#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "atendimento.h"

//criando elemento
struct elemento{
    int dado;
    struct elemento *prox;
};
typedef struct elemento Elemento;

//criando nó descritor
struct descritor{
    Elemento *inicio;
    Elemento *fim;
    int quant;
};

// função para alocar memória do tipo Fila SE
Fila* criar_fila()
{
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicio = NULL;
        fi->fim = NULL;
        fi->quant = 0;
    }
    return fi;
}


// função para liberar memória
int liberar_fila(Fila *fi)
{

  if(fi == NULL){    
    return 0;
  }

  Elemento *atual;

  while(fi->inicio != NULL){    
    atual = fi->inicio;
    fi->inicio = fi->inicio->prox;
    fi->quant--;
    free(atual);
  }

  free(fi);  

  return 1;
}

// função para alocar memória do tipo Elemento
Elemento* criar_elemento()
{
    return (Elemento*) malloc(sizeof(Elemento));
}


// função para inserir elemento no final da fila 
int enfileirar(Fila *fi, int dado)
{
  if(fi == NULL){
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;
  no->prox = NULL;

  // se a fila estiver vazia, insere no início da fila
  if(fi->inicio == NULL){    
    fi->inicio = no;  

  // senão insere elemento no final da fila  
  }else{
    (fi->fim)->prox = no;    
  }

  fi->fim = no;
  fi->quant++;

  return 1;
}

// função para remover elemento do início da fila
int desenfileirar(Fila *fi)
{
  if(fi == NULL){
    return 0;
  }

  // fila vazia, não remove nada
  if(fi->inicio == NULL){
    return 0;
  }

  // remove elemento do início da fila
  Elemento *no;
  no = fi->inicio;
  fi->inicio = fi->inicio->prox;
  fi->quant--;

  // libera Elemento no
  free(no);

  // se a fila ficou vazia
  if(fi->inicio == NULL){
    fi->fim = NULL;
  }

  return 1;
}

// função para consultar o primeiro elemento
int consultar_inicio_fila(Fila *fi, int *dado)
{
  // verifica se a fila foi criada corretamente e se não está vazia
  if(fi == NULL || fi->inicio == NULL){
    return 0;
  }

  // copia o dado do início da fila
  *dado = fi->inicio->dado;

  return 1;
}

// função que devolve o tamanho da fila
int tamanho_fila(Fila *fi)
{
    if(fi == NULL){
        return -1;
    }
    return fi->quant;
}



void imprimirFila(Fila* fila, char letra1, char letra2){

    // verifica se fila existe
    if(fila == NULL){
        printf("\n\nFila nao existe! Tecle enter para continuar...");
        getchar();
        getchar();
        return;
    }

    // imprimir as senhas uma a uma
    Elemento* atual = fila->inicio;

    printf("\n\nFila de senhas:\n");
    while(atual != NULL){

       printf("\n%c%c%d", letra1, letra2, atual->dado);
        
        atual = atual->prox;
    }

    printf("\n\nFim da fila.");
        
    return;
}
