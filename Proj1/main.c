//]#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

// 64kB stack
#define FIBER_STACK 1024*64
#define MAX_THREAD_NUM 100
sem_t semaphore;

struct c {
 int saldo;
};
typedef struct c conta;
int c1 = 1;
int c2 = 2;
conta from, to;
int valor;

void troca(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// The child thread will execute this function
void* transferencia( void *arg)
{
  sem_wait(&semaphore);
  
  if (from.saldo == 0) {
    sem_post(&semaphore);
    return 0;
  }
  
  if (from.saldo >= valor) { // 2
    from.saldo -= valor;
    to.saldo += valor;
  }
  
  printf("Transferência concluída com sucesso!\n");
  printf("Saldo de c%d: %d\n", c1, from.saldo);
  printf("Saldo de c%d: %d\n", c2, to.saldo);
  sem_post(&semaphore);
  return 0;
}

int main(int argc, char* argv[])
{
  void* stack;
  pid_t pid;
  int i;
  
  // Allocate the stack
  stack = malloc( FIBER_STACK );
  if ( stack == 0 )
  {
  perror("malloc: could not allocate stack");
  exit(1);
  }

  // Initialize Semaphore
  sem_init(&semaphore,0,1);
  
  // Todas as contas começam com saldo 100
  from.saldo = 100;
  to.saldo = 100;
  
  valor = 10;
  int flag = 0;
  int threadNum = MAX_THREAD_NUM;
  
  if (argc > 1) {from.saldo = atoi(argv[1]);}
  if (argc > 2) {to.saldo = atoi(argv[2]);}
  if (argc > 3) {threadNum = atoi(argv[3]);}
  if (argc == 5) {flag = atoi(argv[4]);}
  if (flag == 1) 
  {
    troca(&from.saldo,&to.saldo);
    troca(&c1,&c2);
  }

  if(threadNum > MAX_THREAD_NUM) 
  {
    fprintf(stderr,"Excedeu número máximo de threads\n");
    return -1;
  }

  printf( "Transferindo 10 para a conta c%d\n",c2 );
  
  for (i = 0; i < threadNum; i++) 
  { 
    if (pthread_create( &((pthread_t*)stack)[i], NULL, &transferencia,NULL) != 0) 
    {
      fprintf(stderr,"Falha em criar thread\n");
    }
  }
  for(i = 0; i < threadNum; i++) 
  {
    if (pthread_join(((pthread_t*)stack)[i],NULL) != 0) 
    {
      fprintf(stderr,"Falha em juntar thread\n");
    }
  }
  
  // Free the stack
  free( stack );
  // Free Semaphore
  sem_destroy(&semaphore);
  printf("Transferências concluídas e memória liberada.\n");
  return 0;
}