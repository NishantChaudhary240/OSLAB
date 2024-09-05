#include <stdio.h>
#include <stdlib.h>
#define N 5
#define LEFT (i + N - 1) % N
#define RIGHT (i + 1) % N
#define THINKING 0
#define HUNGRY 1
#define EATING 2
typedef int semaphore;
int state[N];
semaphore mutex = 1;
semaphore s[N];

void philosopher(int i);
void take_forks(int i);
void put_forks(int i);
void test(int i);
void think(int i);
void eat(int i);
void down(semaphore *s);
void up(semaphore *s);

int main()
{
    printf("\n\nName: Nishant Chaudhary\nRollno: 19\n\n__________________________________\n\n");
    int i;

    for (i = 0; i < N; i++)
    {
        state[i] = THINKING;
        s[i] = 0;
    }

    for (i = 0; i < N; i++)
    {
        philosopher(i);
    }

    return 0;
}

void philosopher(int i)
{
    think(i);
    take_forks(i);
    eat(i);
    put_forks(i);
}

void take_forks(int i)
{
    down(&mutex);
    state[i] = HUNGRY;
    test(i);
    up(&mutex);
    down(&s[i]);
}
void put_forks(int i)
{
    down(&mutex);
    state[i] = THINKING;
    test(LEFT);
    test(RIGHT);
    up(&mutex);
}
void test(int i)
{
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
    {
        state[i] = EATING;
        up(&s[i]);
    }
}
void think(int i)
{
    printf("Philosopher %d is thinking\n", i);
}

void eat(int i)
{
    printf("Philosopher %d is eating\n", i);
}
void down(semaphore *s)
{
    while (*s <= 0)
        ;
    (*s)--;
}
void up(semaphore *s)
{
    (*s)++;
}
