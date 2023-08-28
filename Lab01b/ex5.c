#include <stdio.h>

void matrixcpy(int l, int c, int cpy[l][c], int orig[l][c]) {
  for(int i = 0; i < l; i++) {
    for(int j = 0; j < c; j++) {
      cpy[i][j] = orig[i][j];
    }
  }
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

int main() {
  int n = 3;
  int mult = 2;
  int M[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  int M_lMult[3][3];
  int M_cMult[3][3];
  matrixcpy(3,3,M_lMult,M);
  matrixcpy(3,3,M_cMult,M);

  for(int i = 0; i<n; i++) {
    M_lMult[0][i]*=mult;
    M_cMult[i][0]*=mult;
  }
  printf("Matrix:\n");
  printMatrix(3,3,M);
  printf("\nMatrix com apenas a linha 1 multiplicada por %d:\n", mult);
  printMatrix(3,3,M_lMult);
  printf("\nMatrix com apenas a coluna 1 multiplicada por %d:\n", mult);
  printMatrix(3,3,M_cMult);
}