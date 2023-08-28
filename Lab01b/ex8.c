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

void transpose(int l, int c,int M[l][c]) {
  for(int i = 0; i < l; i++) {
    for(int j = i; j < c; j++) {
      swap(&M[i][j],&M[j][i]);
    }
  }
}

int main() {
  int c = 3;
  int l = 3;
  int M[3][3] ={{1,2,3},{4,5,6},{7,8,9}};
  printf("Matrix:\n");
  printMatrix(l,c,M);
  
  transpose(l,c,M);
    
  printf("\nMatrix Transposta:\n");
  printMatrix(l,c,M);
}