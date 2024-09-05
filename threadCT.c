#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
void *threadFunction(void *arg)
{
    int id = *((int *)arg);
    printf("Thread %d: Started\n", id);

    sleep(2);

    printf("Thread %d: Finished\n", id);
    pthread_exit(NULL);
}
int main()
{
    pthread_t thread1, thread2;
    int id1 = 1, id2 = 2;
    printf("\n\nName: Anurag Bhattarai\nRollno: 04\n\n");

    if (pthread_create(&thread1, NULL, threadFunction, &id1) != 0)
    {
        fprintf(stderr, "Error creating thread 1\n");
        return 1;
    }

    if (pthread_create(&thread2, NULL, threadFunction, &id2) != 0)
    {
        fprintf(stderr, "Error creating thread 2\n");
        return 1;
    }
    if (pthread_join(thread1, NULL) != 0)
    {
        fprintf(stderr, "Error joining thread 1\n");
        return 1;
    }
    if (pthread_join(thread2, NULL) != 0)
    {
        fprintf(stderr, "Error joining thread 2\n");
        return 1;
    }
    printf("Main thread: All threads have finished\n");
    return 0;
}
