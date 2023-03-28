
#include <stdio.h>
#include <stdlib.h>


void PreencherVetor(int Vetor[], int r){
  printf("insira um elemento \n");
  int auxiliar=0;
  while(r>=0){
    scanf("%i", &Vetor[auxiliar]);
    auxiliar++;
  } 
  return;
}

void ImprimirVetor(int Vetor[], int r){
  while(r>=0){
    printf("%i", Vetor[r]);
    r--;
  }
  return;
}

void PreencheMatriz(int matriz[][100], int r, int l, int c, int Vetor[]){
  int i, j, auxiliar;
  auxiliar=0;
  for ( i=0; i<l; i++ ){
    for ( j=0; j<c; j++ ){
      matriz[i][j]=Vetor[auxiliar];
      auxiliar++;
    }
  }
  return;
}

void ImprimeMatriz(int matriz[][], int l, int c){
  int i, j;
  for ( i=0; i<l; i++ ){
    for ( j=0; j<c; j++ ){
      printf("%i", matriz[i][j]);
    }
  }
  return;
}


int main(void) {
  int l, c, r;
  printf("Insira o numero de linhas\n");
  scanf("%i", &l);

  printf("insira o numero de colunas\n");
  scanf("%i", &c);

  r=l*c;
  int Vetor[r];
  int matriz[l][c];

  PreencherVetor(Vetor[], r);
  ImprimirVetor(Vetor[], r);
  PreencheMatriz(matriz[][], r, l, c, Vetor[]);
  ImprimeMatriz(matriz[][], l, c);

  
  return 0;
}
