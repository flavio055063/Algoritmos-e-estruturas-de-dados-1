#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

typedef struct cadastro{

  char nome[15];
  char snome[15];
  int idade;
  char email[30];
  char sexo[10];
  char telef[15];
  struct cadastro *prox;

}cadastro;

//Criar lista
Lista* criarlista(){
  
  Lista *li = (Lista*) malloc(sizeof(Lista));  

  if(li != NULL){
    *li = NULL;
  } 

  return li;
}

//Liberar lista
int liberar_lista(Lista *li){
  
  if(li == NULL){    
    return 0;
  }

  cadastro *no;
  while(*li != NULL){
    no = *li;
    *li = (*li)->prox;
    free(no);
  }

  free(li);

  return 1;  
}

//Para alocar memória do tipo cadastro
cadastro* criar_elemento(){

  cadastro *no = (cadastro*) malloc(sizeof(cadastro));  

  return no;
}

//Cadastrar novo cliente
void cadastrarcliente(Lista *li, char nome[15], char snome[15], int idade, char email[30], char sexo[10], char telef[15]){
  if(li == NULL){
    //return 0;
  }

  // cria um elemento novo
  cadastro *no;
  no = criar_elemento();

  if(no == NULL){
    //return 0;
  }

  // atribui valores aos dados do novo cliente
  strcpy(no->nome, nome);
  strcpy(no->snome, snome);
  no->idade = idade;
  strcpy(no->email, email);
  strcpy(no->sexo, sexo);
  strcpy(no->telef, telef);
  no->prox = NULL;

  // se a lista estiver vazia, insere no início da lista
  if( (*li) == NULL ){
    *li = no;

  }else{

    // senão percorre a lista até o fim e insere no final
    cadastro *aux;
    aux = *li;

    while(aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = no;
  }

  //return 1;
}

//Opção 1
void op1(Lista *li, int a, char nome[15], char snome[15], int idade, char email[30], char sexo[10], char telef[15]){
  
  system("clear");
  printf("Digite o primeiro nome do cliente : ");
  scanf("%s", nome);
  printf("Digite o sobrenome do cliente : ");
  scanf("%s", snome);
  printf("Digite a idade do cliente : ");
  scanf("%i", &idade);
  printf("Digite o E-Mail do cliente : ");
  scanf("%s", email);
  printf("Digite o Sexo do cliente (Masculino/Feminino) : ");
  scanf("%s", sexo);
  printf("Digite o telefone do cliente (apenas números) : ");
  scanf("%s", telef);
  system("clear");
  printf("Os dados inseridos estão corretos ?\n\nCliente : %s %s \nIdade : %d   \nE-Mail : %s   \nSexo : %s   \nTelefone : %s\n\n", nome, snome, idade, email, sexo, telef);

  printf("1 - Confirmar cadastro\n2 - Corrigir dados\nOpção : ");
  scanf("%i", &a);
  
  while (a != 1 && a != 2){
    system ("clear");
    printf("Os dados inseridos estão corretos ?\n\nCliente : %s %s \nIdade : %d   \nE-Mail : %s   \nSexo : %s   \nTelefone : %s\n\n", nome, snome, idade, email, sexo, telef);

    printf("1 - Confirmar cadastro\n2 - Corrigir dados\nOpção : ");
    scanf("%i", &a);
    }
  if (a == 1){
    cadastrarcliente(li, nome, snome, idade, email, sexo, telef);
  }
  while (a == 2){
    system("clear");
    printf("Digite o primeiro nome do cliente : ");
    scanf("%s", nome);
    printf("Digite o sobrenome do cliente : ");
    scanf("%s", snome);
    printf("Digite a idade do cliente : ");
    scanf("%i", &idade);
    printf("Digite o E-Mail do cliente : ");
    scanf("%s", email);
    printf("Digite o Sexo do cliente (Masculino/Feminino) : ");
    scanf("%s", sexo);
    printf("Digite o telefone do cliente (apenas números) : ");
    scanf("%s", telef);
    system("clear");
    printf("Os dados inseridos estão corretos ?\n\nCliente : %s %s \nIdade : %d   \nE-Mail : %s   \nSexo : %s   \nTelefone : %s\n\n", nome, snome, idade, email, sexo, telef);

    printf("1 - Confirmar cadastro\n2 - Corrigir dados\nOpção : ");
    scanf("%i", &a);

    while (a != 1 && a != 2){
      system("clear");
      printf("Os dados inseridos estão corretos ?\n\nCliente : %s %s \nIdade : %d   \nE-Mail : %s   \nSexo : %s   \nTelefone : %s\n\n", nome, snome, idade, email, sexo, telef);

      printf("1 - Confirmar cadastro\n2 - Corrigir dados\nOpção : ");
      scanf("%i", &a);
    }

    if (a == 1){
      cadastrarcliente(li, nome, snome, idade, email, sexo, telef);
    }
  }
}

//Opção 2
void op2(Lista *li, int m){
  
  if(li == NULL || (*li) == NULL){
    system("clear");
    printf("Lista não encontrada !\n\n");
    
    printf("Insira 1 para voltar ao menu : ");
    scanf("%i", &m);
    while (m != 1){
      printf("Insira 1 para voltar ao menu : ");
      scanf("%i", &m);
    }
  }
  else {
    system("clear");
    printf("\n Lista dos clientes: ");
    imprimirlista(li);

    printf("Insira 1 para voltar ao menu : ");
    scanf("%i", &m);
    while (m != 1){
      printf("Insira 1 para voltar ao menu : ");
      scanf("%i", &m);
    }
  }

}

//Opção 3
void op3(Lista *li, int ok, int m){
  ok = liberar_lista(li);
  m = 0;

  if (ok == 0 ){
    printf("Lista já está vazia\n\n");
  }
  else{
    printf("Lista esvaziada\n\n");
  }
  printf("Insira 1 para voltar ao menu : ");
  scanf("%i", &m);
  while (m != 1){
    printf("Insira 1 para voltar ao menu : ");
    scanf("%i", &m);
  }
}

//Imprimir lista
void imprimirlista(Lista *li){

  cadastro *aux = (*li);

  printf("\n\n----------------------------------------------------------------\n");

  while(aux->prox != NULL){
    printf("\nCliente : %s %s \nIdade : %d   \nE-Mail : %s   \nSexo : %s   \nTelefone : %s\n\n", aux->nome, aux->snome, aux->idade, aux->email, aux->sexo, aux->telef);
    aux = aux->prox;
  }

  printf("\nCliente : %s %s \nIdade : %d   \nE-Mail : %s   \nSexo : %s   \nTelefone : %s\n\n", aux->nome, aux->snome, aux->idade, aux->email, aux->sexo, aux->telef);
  printf("----------------------------------------------------------------\n\n");

}


void buscar(Lista *li, int a, int m, int c, char nome[15], char snome[15], int idade, char email[30], char sexo[10], char telef[15]){

  if(li == NULL || (*li) == NULL){
    system("clear");
    printf("Ainda não há clientes na lista !\n\n");
    printf("Insira 1 para voltar ao menu : ");
    scanf("%i", &m);
    while (m != 1){
      printf("Insira 1 para voltar ao menu : ");
      scanf("%i", &m);
    }
    system("clear");
  }
  else{
    cadastro *aux = (*li);
    m = 0;a = 0;

    system("clear");
    printf("Como deseja fazer a busca ?\n\n1 - Nome\n2 - Idade\n3 - E-Mail\n4 - Sexo\n5 - Telefone\n6 - Voltar ao menu principal\n");
    printf("Opção : ");
    scanf("%i", &a);

    while (a != 6){
      
      if (a == 1){
      
        c = 0;
        a = 6;
        system("clear");
        printf("Digite o primeiro nome do cliente : ");
        scanf("%s", nome);
        printf("Digite o sobrenome do cliente : ");
        scanf("%s", snome);
        strcpy(nome, nome);
        strcpy(snome, snome);
        printf("\nClientes encontrados : \n");
        printf("----------------------------------------------------------------\n");
      
        while(aux->prox != NULL){
          if(strcmp (nome,aux->nome) == 0 && strcmp (snome,aux->snome) == 0){
            printf("\nCliente : %s %s \nIdade : %d   \nE-Mail : %s   \nSexo : %s   \nTelefone : %s\n\n", aux->nome, aux->snome, aux->idade, aux->email, aux->sexo, aux->telef);
            c++;
          }
          aux = aux->prox;
        }
        if(strcmp (nome,aux->nome) == 0 && strcmp (snome,aux->snome) == 0){
          printf("\nCliente : %s %s \nIdade : %d   \nE-Mail : %s   \nSexo : %s   \nTelefone : %s\n\n", aux->nome, aux->snome, aux->idade, aux->email, aux->sexo, aux->telef);
          printf("----------------------------------------------------------------\n\n");
          c++;
        }
        if (c == 0){
          printf("\nNenhum cliente encontrado.\n\n");
          printf("----------------------------------------------------------------\n\n");
        }
      }

      if (a == 2){
        
        c = 0;
        a = 6;
        system("clear");
        printf("Digite a idade do cliente : ");
        scanf("%i", &idade);
        printf("\nClientes encontrados : \n");
        printf("----------------------------------------------------------------\n");

        while(aux->prox != NULL){
          if(idade == aux->idade){
            printf("\nCliente : %s %s \nIdade : %d   \nE-Mail : %s   \nSexo : %s   \nTelefone : %s\n\n", aux->nome, aux->snome, aux->idade, aux->email, aux->sexo, aux->telef);
            c++;
          }
          aux = aux->prox;
        }
        if(idade == aux->idade){
          printf("\nCliente : %s %s \nIdade : %d   \nE-Mail : %s   \nSexo : %s   \nTelefone : %s\n\n", aux->nome, aux->snome, aux->idade, aux->email, aux->sexo, aux->telef);
          printf("----------------------------------------------------------------\n\n");
          c++;
        }
        if (c == 0){
          printf("\nNenhum cliente encontrado.\n\n");
          printf("----------------------------------------------------------------\n\n");
        }
      }
      
      if (a == 3){
      
        c = 0;
        a = 6;
        system("clear");
        printf("Digite o E-Mail do cliente : ");
        scanf("%s", email);
        strcpy(email, email);
        printf("\nClientes encontrados : \n");
        printf("----------------------------------------------------------------\n");
      
        while(aux->prox != NULL){
          if(strcmp (email,aux->email) == 0){
            printf("\nCliente : %s %s \nIdade : %d   \nE-Mail : %s   \nSexo : %s   \nTelefone : %s\n\n", aux->nome, aux->snome, aux->idade, aux->email, aux->sexo, aux->telef);
            c++;
          }
          aux = aux->prox;
        }
        if(strcmp (email,aux->email) == 0){
          printf("\nCliente : %s %s \nIdade : %d   \nE-Mail : %s   \nSexo : %s   \nTelefone : %s\n\n", aux->nome, aux->snome, aux->idade, aux->email, aux->sexo, aux->telef);
          printf("----------------------------------------------------------------\n\n");
          c++;
        }
        if (c == 0){
          printf("\nNenhum cliente encontrado.\n\n");
          printf("----------------------------------------------------------------\n\n");
        }
      }

      if (a == 4){
      
        c = 0;
        a = 6;
        system("clear");
        printf("Digite o sexo do cliente (Masculino/Feminino) : ");
        scanf("%s", sexo);
        strcpy(sexo, sexo);
        printf("\nClientes encontrados : \n");
        printf("----------------------------------------------------------------\n");
      
        while(aux->prox != NULL){
          if(strcmp (sexo,aux->sexo) == 0){
            printf("\nCliente : %s %s \nIdade : %d   \nE-Mail : %s   \nSexo : %s   \nTelefone : %s\n\n", aux->nome, aux->snome, aux->idade, aux->email, aux->sexo, aux->telef);
            c++;
          }
          aux = aux->prox;
        }
        if(strcmp (sexo,aux->sexo) == 0){
          printf("\nCliente : %s %s \nIdade : %d   \nE-Mail : %s   \nSexo : %s   \nTelefone : %s\n\n", aux->nome, aux->snome, aux->idade, aux->email, aux->sexo, aux->telef);
          printf("----------------------------------------------------------------\n\n");
          c++;
        }
        if (c == 0){
          printf("\nNenhum cliente encontrado.\n\n");
          printf("----------------------------------------------------------------\n\n");
        }
      }

      if (a == 5){
      
        c = 0;
        a = 6;
        system("clear");
        printf("Digite o telefone do cliente : ");
        scanf("%s", telef);
        strcpy(telef, telef);
        printf("\nClientes encontrados : \n");
        printf("----------------------------------------------------------------\n");
      
        while(aux->prox != NULL){
          if(strcmp (telef,aux->telef) == 0){
            printf("\nCliente : %s %s \nIdade : %d   \nE-Mail : %s   \nSexo : %s   \nTelefone : %s\n\n", aux->nome, aux->snome, aux->idade, aux->email, aux->sexo, aux->telef);
            c++;
          }
          aux = aux->prox;
        }
        if(strcmp (telef,aux->telef) == 0){
          printf("\nCliente : %s %s \nIdade : %d   \nE-Mail : %s   \nSexo : %s   \nTelefone : %s\n\n", aux->nome, aux->snome, aux->idade, aux->email, aux->sexo, aux->telef);
          printf("----------------------------------------------------------------\n\n");
          c++;
        }
        if (c == 0){
          printf("\nNenhum cliente encontrado.\n\n");
          printf("----------------------------------------------------------------\n\n");
        }
      }

      printf("Insira 1 para voltar ao menu : ");
      scanf("%i", &m);
      while (m != 1){
        printf("Insira 1 para voltar ao menu : ");
        scanf("%i", &m);
      }

    }
    system("clear");
  }
}
