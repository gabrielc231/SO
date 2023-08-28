#include <stdio.h>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printMatrix(int l,int c,int M[l][c]) {
  for(int i = 0; i < l; i++) {
    printf("| ");
    for(int j = 0; j < l; j++) {
      printf("%d ",M[i][j]);
    }
    printf("|");
    printf("\n");
  }
}

void modular(int l, int c,int M[l][c]) {
  for(int i = 0; i < l; i++) {
    for(int j = 0; j < c; j++) {
      if(M[i][j]<0) {M[i][j]*=-1;}
    }
  }
}

int main() {
  int c = 3;
  int l = 3;
  int M[3][3] ={{-1,2,-3},{-4,-5,6},{7,-8,-9}};
  printf("Matrix:\n");
  printMatrix(l,c,M);
  
  modular(l,c,M);
    
  printf("\nMatrix com valores apenas positivo:\n");
  printMatrix(l,c,M);
}