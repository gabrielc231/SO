#include <stdio.h>

char media(float n1,float n2,float n3,float me){
    float media=(n1 + n2 + n3 + me)/7;
    printf("media %.2f\n",media);
    char nota='E';
    if (media>=9){
        nota='A';
    }
    else if (media>=7.5){
        nota='B';
    }
    else if (media>=6){
        nota='C';
    }
    else if (media>=4){nota='D';}
    return nota;
}

int main() {
  char c = media(6,5,7,9);
  printf("Nota %c\n",c);
}