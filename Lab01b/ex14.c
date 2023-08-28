#include <stdio.h>

void insere(char* st, char c, int pos) {
  st[pos] = c; 
}

int main() {
  char str[100] = "hello";
  insere(str,'i',1);
  puts(str);
}