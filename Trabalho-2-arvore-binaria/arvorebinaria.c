// TAD para Lista Dinâmica Encadeada Circular

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvorebinaria.h"


// definição do struct elemento
struct no{
  int valor;
  char costura;
  char nome[50];
  struct no *esq;
  struct no *dir;
};

typedef struct no No;

// função para alocar memória
ArvoreBin* criar_arvore_binaria()
{

  ArvoreBin *raiz = (ArvoreBin*) malloc(sizeof(ArvoreBin));  

  if(raiz != NULL){
    *raiz = NULL;
  }

  return raiz;
}

// função para inserção de elementos em uma arvore binaria de busca
 int inserir_arvore_binaria(ArvoreBin *raiz, int valor, char nome[50])
{


  if(raiz == NULL)
    return 0;

  No *novo = (No*) malloc(sizeof(No));
  No *atual, *ant;

  novo->valor = valor;
  strcpy(novo->nome, nome);
  novo->dir = NULL;
  novo->esq = NULL;

  if(*raiz == NULL){

    *raiz = novo;
    novo->costura = 0;

  }else{

    ant = NULL;
    atual = *raiz;

    while(atual != NULL){

      ant = atual;

      if(valor == atual->valor){

        free(novo);
        return 0; 

      }

      if(valor < atual->valor){

        atual = atual->esq;

      }else{

        if(atual->costura == '1'){
          atual = NULL;
        }else{
          atual = atual->dir;
        }

      }
    }

    if(valor < ant->valor){

      ant->esq = novo;
      novo->dir = ant;
      novo->costura = '1';

    }else{

      if(ant->costura == '1'){

        ant->costura = '0';
        novo->costura = '1';
        novo->dir = ant->dir;
        ant->dir = novo;

      } else {

        novo->costura = '0';
        novo->dir = NULL;
        ant->dir = novo;

      }
    }
  }

  return 1;
}

// função para travessia simetrica
void travessia_simetrica(ArvoreBin *raiz)
{
  No *ant, *seg;
  ant = *raiz;
  
  do{
    seg = NULL;

    while(ant != NULL){
      seg = ant;
      ant = ant->esq;
    }

    if(seg != NULL){
    
      printf("\n %s tem a pontuação de: %d", seg->nome, seg->valor);
      ant = seg->dir;
    
      while((seg->costura == '1')&&(ant != NULL)){

          printf("\n %s tem a pontuação de: %d", ant->nome, ant->valor);
          seg = ant;
          ant = ant->dir;

        }
    }

  }while(ant != NULL);

} 