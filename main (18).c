#include <stdio.h>
#include <stdlib.h>
//////////////////////////////////////
//criação da struct cadastro ALUNO;//
////////////////////////////////////

typedef struct cadastro{
    int matricula;
    char nome [50];
    int dianasc;
    int mesnasc;
    int anonasc;
    float nota;
}cadastro;


///////////////////////////////////////////////////
// função para preencher as informações do aluno//
/////////////////////////////////////////////////

void preencher(cadastro *aluno){
    printf("Matricula: ");
    scanf("%i", &aluno->matricula);
    printf("Nome:");
    gets(aluno->nome);
    printf("A data de nascimento:\n ");
    scanf("%i\n", &aluno->dianasc);
    scanf("%i\n", &aluno->mesnasc);
    scanf("%i\n", &aluno->anonasc);
    scanf("%f", &aluno->nota);
  return;
}


///////////////////////////////////////////////
// função para imprimir informações do aluno//
/////////////////////////////////////////////

void imprimir(cadastro *aluno){
    printf("Matricula: %i\n Nome: %s\n Data de nascimento: %i/%i/%i\n Nota: %f", aluno->matricula, aluno->nome, aluno->dianasc, aluno->mesnasc, aluno->anonasc, aluno->nota);
  return;
}




int main(void) {
    printf("Insira o numero de alunos:");
    int qtd;
    scanf("%i", &qtd);

    cadastro *aluno=NULL;
    aluno = (cadastro*) malloc(qtd * sizeof(cadastro));

    int i;
    for (i=0; i<qtd; i++){
      preencher(&aluno[i]);
    }


   
    imprimir(&aluno);





    return 0;
}