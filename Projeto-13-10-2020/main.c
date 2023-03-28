#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

int main(int argc, char const *argv[]) {

  int op=0, ok=0, m=0, a=0, c=0, idade;
  char nome[15], snome[15], email[30], telef[15], sexo[10];
  Lista *li;
  li = NULL;

  //Cria a lista
  li = criarlista();

  printf("1 - Cadastrar\n2 - Imprimir lista\n3 - Limpar lista\n4 - Buscar cliente\n5 - Sair\n\nOpção : ");
  scanf("%i", &op);

  while (0 > op || op > 5){
    system("clear");
    printf("Opção inválida !\n\n");
    printf("1 - Cadastrar\n2 - Imprimir lista\n3 - Limpar lista\n4 - Buscar cliente\n5 - Sair\n\nOpção : ");
    scanf("%i", &op);
  }

  while (op != 5){

    if (op == 1){  
      op1(li, a, nome, snome, idade, email, sexo, telef);

      system("clear");
      printf("1 - Cadastrar\n2 - Imprimir lista\n3 - Limpar lista\n4 - Buscar cliente\n5 - Sair\n\nOpção : ");
      scanf("%i", &op);
    }

    if (op == 2){
      op2(li, m);
      
      system("clear");
      printf("1 - Cadastrar\n2 - Imprimir lista\n3 - Limpar lista\n4 - Buscar cliente\n5 - Sair\n\nOpção : ");
      scanf("%i", &op);
    }

    if (op == 3){
      op3(li, ok, m);

      system("clear");
      printf("1 - Cadastrar\n2 - Imprimir lista\n3 - Limpar lista\n4 - Buscar cliente\n5 - Sair\n\nOpção : ");
      scanf("%i", &op);
    }

    if (op == 4){
      buscar(li, a, m, c, nome, snome, idade, email, sexo, telef);
      printf("1 - Cadastrar\n2 - Imprimir lista\n3 - Limpar lista\n4 - Buscar cliente\n5 - Sair\n\nOpção : ");
      scanf("%i", &op);
    }
  } 
  return 0;
}