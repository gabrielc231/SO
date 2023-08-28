#include <stdio.h>
#include <stdlib.h>

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

int main(void) {
  int M[3][3] = {{5,4,3},{2,1,7},{8,6,9}};
  int n = 3;
  int* tuple = (int*)malloc(sizeof(int)*2);
  tuple[1] = M[0][0];
  tuple[0] = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(tuple[1] > M[i][j]) {
        tuple[1] = M[i][j];
        tuple[0] = i;
      }
    }
  
  }
  tuple[0]+=1;
  printMatrix(n,n,M);
  printf("\nlinha com menor número: %d\n", tuple[0]);
  free(tuple);
  return 0;
}