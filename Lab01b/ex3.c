#include <stdio.h>
#include <stdlib.h>
int main() {
  int n = 13;
  int c = n/2 + 1;
  int j = 1;
  int e = 0;
  printf("n = %d\n",n);
  
  for(int i = 1; i <= c; i++) {
    
    for(int k = 0; k < e; k++) {
      printf(" ");
    }
    
    for(int k = j; k<=n; k++) {
      printf("%d ",k);
    }
    
    for(int k = 0; k < e; k++) {
      printf(" ");
    }
    printf("\n");
    e+=2;
    j+=1;
    n-=1;
  }
  
}