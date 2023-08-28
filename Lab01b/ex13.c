#include <stdio.h>

int remover(char st[],int target,int n){
  for(int i=target;i<n;i++){
    st[target]=st[target+1];
  }
  for (int i=0;i<n;i++){
    printf("%c",st[i]);
  }
  printf("\n");
  return 0;
}

int main(void) {
 
  char st[]="ches";
  remover(st,2,3);
  return 0;
}