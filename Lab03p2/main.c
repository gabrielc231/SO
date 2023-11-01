#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int thread_count = 4;
double sum = 0.0;
long long n = 1000000;
pthread_mutex_t mutex;

void* thread_sum_original(void* rank) {
    long my_rank = (long) rank;
    double factor;
    long long i;
    long long my_n = n / thread_count;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_first_i + my_n;

    if (my_first_i % 2 == 0) {factor = 1.0;}

    else {factor = -1.0;}

    for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
        sum += factor / (2*i+1);
    }
}

void* thread_sum(void* rank) {
    long my_rank = (long) rank;
    double factor;
    long long i;
    long long my_n = n / thread_count;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_first_i + my_n;

    if (my_first_i % 2 == 0) {factor = 1.0;}

    else {factor = -1.0;}

    for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
        pthread_mutex_lock(&mutex);
        sum += factor / (2*i+1);
        pthread_mutex_unlock(&mutex);
    }
}

int main(void) {
    pthread_t* threads = (pthread_t*) malloc(thread_count * sizeof(threads));
    pthread_mutex_init(&mutex, NULL);
    long arr[4] = {1,2,3,4};
    
    for (int i = 0; i < thread_count; i++) {
        if (pthread_create(&threads[i], NULL, thread_sum, (void*) i) != 0) {
            return 1;
        }
    }

    for (int i = 0; i < thread_count; i++) {
        if (pthread_join(threads[i],NULL)) {
            return 2;
        }
    }
    
    printf("Usando mutex:\n\n");
    printf("pi = %lf\n", 4*sum);
    printf("numero de iteracoes = %lld\n", n);
    printf("numero de threads = %d\n",thread_count);

    sum = 0.0;
    pthread_mutex_destroy(&mutex);
    
    for (int i = 0; i < thread_count; i++) {
        if (pthread_create(&threads[i], NULL, thread_sum_original, (void*) i) != 0) {
            return 1;
        }
    }

    for (int i = 0; i < thread_count; i++) {
        if (pthread_join(threads[i],NULL)) {
            return 2;
        }
    }
    
    printf("\nNão usando mutex:\n\n");
    printf("pi = %lf\n", 4*sum);
    printf("numero de iteracoes = %lld\n", n);
    printf("numero de threads = %d\n",thread_count);

    free(threads);
    return 0;
}