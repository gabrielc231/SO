#include <stdio.h>

int asoma_matris1a2b(int M[][4],int n){
  for(int i=0;i<=n;i++){
      M[1][i]=M[0][i]+M[1][i];
      printf("%d ",M[1][i]);
  }
  printf("\n");

  return 0;
}
int bmult_matris1a2b(int M[][4],int n){
  for(int i=0;i<=n;i++){
      M[1][i]=M[0][i]*M[1][i];
      printf("%d ",M[1][i]);
  }
  printf("\n");

  return 0;
}

int main(void) {
  int matriz[3][4] = {{10, 20, 30, 40},{50, 60, 70, 80},{90, 11, 22, 33}};
  asoma_matris1a2b(matriz,3);
  bmult_matris1a2b(matriz,3);
  return 0;
}