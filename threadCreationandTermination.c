#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 5

void *PrintHello(void *threadid) {
    long tid = (long)threadid;
    printf("Hello! I am thread #%ld\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    long t;

    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        int rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);

        if (rc) {
            printf("Error: Unable to create thread %d\n", rc);
            return -1;
        }
    }

    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("All threads have finished.\n");
    return 0;
}
