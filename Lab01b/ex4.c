#include <stdio.h>
#include <string.h>

int main() {
  char* n1 = "Carla";
  char* n2 = "Roberto";

  if(strcmp(n1,n2)<=0) {
    printf("%s, %s\n",n1,n2);
  }

  else {
    printf("%s, %s\n",n2,n1);
  }
}