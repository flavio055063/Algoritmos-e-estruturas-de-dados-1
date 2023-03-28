
// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "listaEncadeada.h"

// funcao principal
int main(void) {

  // no início a lista está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da lista
  Lista *li = NULL;
  int opcao, matricula, ok, pos;
  char nome[30];
  float nota;

  // menu de opções para execuções de operações sobre a lista
  do
  {
    printf("\n\nMenu de opções");
    printf("\n1 - Criar lista");
    printf("\n2 - Liberar lista");
    printf("\n3 - Inserir elemento no início");
    printf("\n4 - Inserir elemento no final");
    printf("\n5 - concatenar 2 listas");
    printf("\n6 - inverter uma lista");
    printf("\n8 - Remover elemento (qualquer)");
    printf("\n9 - Buscar elemento pela posição");
    printf("\n10 - Buscar elemento pelo dado");
    printf("\n11 - Imprimir lista");
    printf("\n12 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1:

        // criar lista
        li = criar_lista();

        if(li != NULL){
          printf("\n Lista criada com sucesso!");
        }else{
          printf("\n Lista não criada!");
        }
        break;


      case 2:

        // liberar lista
        ok = liberar_lista(li);

        if(ok){
          printf("\n Lista liberada com sucesso!");
        }else{
          printf("\n Lista não liberada!");
        }
        break;

      case 3:

        // inserir elemento no início
        printf("\nmatricula: ");
        scanf("%d", &matricula);
        printf("nome: ");
        scanf("%s", nome);
        printf("nota: ");
        scanf("%f", &nota);
        ok = inserir_lista_inicio(li, matricula, &nome[30], nota);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 4:

        // inserir elemento no final
        printf("\nmatricula: ");
        scanf("%d", &matricula);
        printf("nome: ");
        scanf("%s", &nome[30]);
        printf("nota: ");
        scanf("%f", &nota);
        ok = inserir_lista_final(li, matricula, &nome[30], nota);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

       case 5:



       break;

      case 8:

        // remover elemento do meio
        printf("\n Número a ser removido: ");
        scanf("%d", &matricula);

        ok = remover_lista_meio(li, matricula);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 9:

        // busca elemento pela posicao
        printf("\n Posição do elemento a ser buscado: ");
        scanf("%d", &pos);

        ok = buscar_lista_posicao(li, pos, &matricula);

        if(ok){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento da %dª posição: ", pos);
          printf("%d", matricula);
        }else{
          printf("\n Posição não existe!");
        }

        break;

      case 10:

        // busca elemento pelo dado
        printf("\n matricula do aluno p buscar: ");
        scanf("%d", &matricula);

        ok = buscar_lista_dado(li, matricula, &pos);

        if(ok){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento da %dª posição: ", pos);
          printf("%d", matricula);
        }else{
          printf("\n Elemento não encontrado!");
        }

        break;

      case 11:

        // imprime a lista
        printf("\n Lista encadeada: ");
        ok = imprimir_lista(li);

        if(!ok){
          printf("\n Lista não encontrada!");
        }

        break;

      case 12:

        // libera memória e finaliza programa
        liberar_lista(li);
        printf("\nFinalizando...");
        break;

      case 13:
      
      break;

      case 14:
      break;


      case 15:
      break;
      default:
        printf("\nOpção inválida!");
        break;
    }

  }while(opcao != 12);

  return 0;
}

