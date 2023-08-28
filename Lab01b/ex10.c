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

void multMatrixLine(int l,int c, int M[l][c], int mult, int chosenLine) {
  for(int i = 0; i<c; i++) {
    M[chosenLine-1][i]*=mult;
  }
}

void multMatrixColumn(int l, int c, int M[l][c], int mult, int chosenColumn) {
  for(int i = 0; i<c; i++) {
    M[i][chosenColumn-1]*=mult;
  }
}

int main() {
  int n = 3;
  int mult = 2;
  int chosenLine = 2;
  int chosenColumn = 2;
  int M[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  int M_lMult[3][3];
  int M_cMult[3][3];
  matrixcpy(3,3,M_lMult,M);
  matrixcpy(3,3,M_cMult,M);
  multMatrixLine(3,3,M_lMult, mult, chosenLine);
  multMatrixColumn(3,3,M_cMult, mult, chosenColumn);

  
  printf("Matrix:\n");
  printMatrix(3,3,M);
  printf("\nMatrix com apenas a linha %d multiplicada por %d:\n", chosenLine, mult);
  printMatrix(3,3,M_lMult);
  printf("\nMatrix com apenas a coluna %d multiplicada por %d:\n", chosenColumn, mult);
  printMatrix(3,3,M_cMult);
}