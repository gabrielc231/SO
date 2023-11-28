#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "queue.c"

int maior(int a, int b)
{
    return (a > b) ? a : b;   
}

int escada(int pessoas[][2], int n) 
{
    int tempo = 0;
    Queue* fila_esq = createQueue(n);
    Queue* fila_dir = createQueue(n);
    for (int i = 0; i < n; i++) {
        if (pessoas[i][1] == 1) { enqueue(fila_esq,pessoas[i][0]); }
        else { enqueue(fila_dir,pessoas[i][0]);}
    }

    while (fila_esq->size && fila_dir->size)
    {
        int esq = front(fila_esq);
        int dir = front(fila_dir);

        if (esq < dir) 
        {
            tempo += 10;
            while (tempo > front(fila_esq) && fila_esq->size) 
            {
                tempo = maior(tempo, front(fila_esq)+10);
                dequeue(fila_esq);
            }    
        }
        else 
        {
            tempo+=10;
            while (tempo > front(fila_dir) && fila_dir->size) 
            {
                tempo = maior(tempo, front(fila_dir)+10);  
                dequeue(fila_dir);
            }
        }
    }
    tempo+=10;
    while (fila_esq->size) 
    {
        tempo = maior(tempo, front(fila_esq)+10);
        dequeue(fila_esq);
    }

    while (fila_dir->size) 
    {
        tempo = maior(tempo, front(fila_dir)+10);
        dequeue(fila_dir);
    }

    deleteQueue(fila_esq);
    deleteQueue(fila_dir);
    return tempo;
}

int main() 
{
    int N;
    
    for (int i = 1; i < 59; i++) {
        char caminho_arq_saida[200] = "./output/E_";
        char caminho_arq_entrada[200] = "./input/E_";
        char n_arq[31];
        char linha_entrada[200]; 
        char linha_saida[200];
        char* temp;
        sprintf(n_arq,"%d",i);
        strcat(caminho_arq_entrada,n_arq);
        strcat(caminho_arq_saida,n_arq);
        FILE* saida = fopen(caminho_arq_saida,"r");
        FILE* entrada = fopen(caminho_arq_entrada,"r");
        N = atoi(fgets(linha_entrada,200,entrada));
        int pessoas[N][2];

        for (int i = 0; i < N; i++) {
            temp = fgets(linha_entrada,200,entrada);
            char* token = strtok(linha_entrada," ");
            pessoas[i][0] = atoi(token);
            pessoas[i][1] = atoi(strtok(NULL," "));
        }

    temp = fgets(linha_saida,200,saida);
    int resultado = escada(pessoas, N);
    int resultado_esperado = atoi(linha_saida);
	printf("Teste %d\n",i);
	printf("%d %d\n\n", resultado, atoi(linha_saida));
    fclose(entrada);
    fclose(saida);

    }


    //int resultado = calcularUltimoMomento(N, pessoas);
    // Imprimir o resultado

    return 0;
}