// TAD para Lista Dinâmica Encadeada baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

// definição do struct elemento
typedef struct elemento1{
  int matricula;
  char nome[30];
  float nota;
  struct elemento *prox;
}Elemento1;

typedef struct elemento2{
  int matricula;
  char nome[30];
  float nota;
  struct elemento *prox;
}Elemento2;

// função para alocar memória do tipo Lista
Lista* criar_lista()
{
  Lista *li = (Lista*) malloc(sizeof(Lista));  

  // se a lista foi criada corretamente, indica que ela está vazia
  if(li != NULL){
    *li = NULL;
  } 

  return li;
}


// função para liberar memória
int liberar_lista(Lista *li)
{
  if(li == NULL){    
    return 0;
  }

  // libera todos os nós da lista que foram alocados
  Elemento *no;
  while(*li != NULL){
    no = *li;
    *li = (*li)->prox;
    free(no);
  }

  // libera o ponteiro da lista
  free(li);

  return 1;  
}

// função para obter o tamanho da lista
int tamanho_lista(Lista *li)
{
  // a lista não foi criada corretamente
  if(li == NULL){
    return 0;
  }

  int cont = 0;
  Elemento *no = *li;

  // acrescenta cont até acabar a lista
  while(no != NULL){
    cont++;
    no = no->prox;
  }

  return cont;
}

// função para verificar se a lista está vazia
int lista_vazia(Lista *li)
{
  // verifica se houve problema na criação da lista
  // ou seja, li não é uma lista válida
  if(li == NULL){
    return -1;
  }

  // verifica se a lista foi criada corretamente
  // mas não contém nenhum valor
  if(*li == NULL){
    return 1;
  }

  // se houver elementos, retorna 0
  return 0;
}


// função para verificar se a lista está cheia (não se aplica)
int lista_cheia(Lista *li)
{
  return 0;
}


// função para alocar memória do tipo Elemento
Elemento* criar_elemento()
{
  Elemento *no = (Elemento*) malloc(sizeof(Elemento));  

  return no;
}


// função para inserir elemento no início da lista
int inserir_lista_inicio(Lista *li, int matricula, char nome[30], float nota)
{
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  int copy=0;
  no->matricula = matricula;
  while(copy<=31){
  no->nome[copy] = nome[copy];
  copy++;}
  no->nota = nota;
  no->prox = (*li);

  // insere elemento no início da lista
  *li = no;

  return 1;
}


// função para inserir elemento no final da lista
int inserir_lista_final(Lista *li, int matricula, char nome[30], float nota)
{
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no->matricula = matricula;
  no->nome[29] = nome[30];
  no->nota = nota;
  no->prox = NULL;

  // se a lista estiver vazia, insere no início da lista
  if( (*li) == NULL ){
    *li = no;

  }else{

    // senão percorre a lista até o fim e insere no final
    Elemento *aux;
    aux = *li;

    while(aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = no;
  }

  return 1;
}


// função para remover elemento do meio da lista
int remover_lista_meio(Lista *li, int matricula)
{
  if(li == NULL){
    return 0;
  }

  // lista vazia, não remove nada
  if((*li) == NULL){
    return 0;
  }

  // percorre a lista até achar o elemento e remove
  Elemento *anterior, *atual;
  atual = *li;

  while(atual != NULL && atual->matricula != matricula){
    anterior = atual;
    atual = atual->prox;
  }

  // elemento não foi encontrado
  if(atual == NULL){
    return 0;
  }

  // remove o primeiro elemento
  if(atual == (*li)){
    *li = atual->prox;

  }else{
    anterior->prox = atual->prox;
  }

  //libera Elemento atual
  free(atual);
  return 1;

}

int buscar_lista_posicao(Lista *li, int pos, int *matricula)
{
  // verifica se a lista foi criada corretamente, se não está vazia e se a posição é válida (note que é a posição na lista e não o índice do vetor)
  if(li == NULL || (*li) == NULL || pos <= 0){
    return 0;
  }

  Elemento *no = *li;
  int i = 1;

  while(no != NULL && i < pos){
    no = no->prox;
    i++;
  }

  // posição não existe na lista
  if(no == NULL){
    return 0;
  }

  // copia o dado da posição desejada (parâmetro passado por referência)
  *matricula = no->matricula;

  return 1;
}


int buscar_lista_dado(Lista *li, int matricula, int *pos)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL || (*li) == NULL){
    return 0;
  }

  // procura a posição no vetor onde o dado desejado se encontra
  Elemento *no = *li;
  int i = 1;

  while(no != NULL && no->matricula != matricula){
    no = no->prox;
    i++;
  }
  
  // verifica se elemento não foi encontrado 
  if(no == NULL){ 
    return 0;
  }

  // copia a posição da lista onde o dado foi encontrado (parâmetro passado por referência)
  *pos = i; 

  return 1;
}



//**************************************************************************
// função para imprimir a lista dinâmica
int imprimir_lista(Lista *li)
{
    if(li == NULL || (*li) == NULL){
      return 0;
    }

    Elemento *aux = (*li);

    while(aux->prox != NULL){
      printf("numero de matricula: %d\n", aux->matricula);
      printf("o nome: %s\n", aux->nome);
      printf("a nota eh: %f\n", aux->nota);
      aux = aux->prox;
    }

    printf("numero de matricula: %d\n", aux->matricula);
    printf("o nome: %s\n", aux->nome);
    printf("a nota: %f\n", aux->nota);

    return 1;
}
