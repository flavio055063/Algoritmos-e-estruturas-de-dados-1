  
// bibliotecas do sistema
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// bibliotecas do projeto
#include "arvorebinaria.h"

// funcao principal
int main(void) {

  FILE *nomes;
  nomes = fopen("nomes.txt", "r");

  ArvoreBin *raiz;
  int opcao, valor, ok, pos;
  char nome[50];

  raiz = criar_arvore_binaria();

  if(raiz != NULL){
    printf("\n Árvore criada com sucesso!");
  }else{
    printf("\n Árvore não criada!");
  }

  // menu de opções para execuções de operações sobre a lista
  do
  {
    printf("\n LEMBRE DE COLOCAR OS NOMES NO ARQUIVO NOMES.TXT");
    printf("\n\nMenu de opções");
    printf("\n1 - Inserir pontuações");
    printf("\n2 - Mostrar pontuações");
    printf("\n3 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1:

        fscanf(nomes, "%s", nome);

        printf("\n Nome do jogador: %s", nome);
       

        printf("\n Insira a pontuação: ");
        scanf("%d", &valor);

        ok = inserir_arvore_binaria(raiz, valor, nome);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!\n\n Aperte Enter para continuar...");
        }else{
          printf("\n Falha na inserção!\n\nAperte Enter para continuar...");
        }
        getchar();
        getchar();
        system("clear");
        break;

      case 2:

        // imprime percurso em-ordem 
        travessia_simetrica(raiz);
        printf("\n\nAperte Enter para continuar...");
        getchar();
        getchar();
        system("clear");
        break;

      case 3:
        printf("\nFinalizando...");
        break;

      default: 
        printf("\nOpção inválida!\n\nAperte Enter para voltar...");
        getchar();
        getchar();
        system("clear");
        break;
    }

  }while(opcao != 3);

  return 0;
}