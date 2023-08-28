#include <stdio.h>

typedef struct dados_pessoa {
  int idade;
  float peso;
  float altura;
} Dados_pessoa;

void imprimePessoa(char nome[], Dados_pessoa dado) {
  printf("Nome: %s \nidade: %d anos \npeso: %.2f kg \naltura: %.2f m\n",nome,dado.idade,dado.peso,dado.altura);
}

int main() {
  char nomes[3][20] = {{"Roberto"},{"Lúcia"},{"Amélia"}};

  Dados_pessoa dados[3];
  dados[0].idade = 30;
  dados[0].peso = 80.2;
  dados[0].altura = 1.80;

  dados[1].idade = 25;
  dados[1].peso = 69.5;
  dados[1].altura = 1.68;

  dados[2].idade = 50;
  dados[2].peso = 75.7;
  dados[2].altura = 1.64;

  for(int i = 0; i < 3; i++) {
    imprimePessoa(nomes[i],dados[i]);
    printf("\n");
  }
  
}