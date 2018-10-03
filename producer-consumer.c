#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#define buffersize 10
#define max 20
pthread_mutex_t mutex;
pthread_t tidP[max], tidC[max];
sem_t full, empty;
int counter;
int item;
int buffer[buffersize];
void initialize()
{
        pthread_mutex_init(&mutex, NULL);
        sem_init(&full, 1, 0);
        sem_init(&empty, 1, buffersize);
        counter = 0;
}
void make(/*int item*/)
{
        buffer[counter++] = item;
}
int consume()
{
        return (buffer[--counter]);
}
void *producer(void *param)
{
        int waittime, item, i;
        //item = rand() % 5;
        waittime = rand() % 5;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        printf("\nProducer has produced item: %d\n", item);
        make(/*item*/);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
}
void *consumer(void *param)
{
        int waittime, item;
        waittime = rand() % 5;
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        item = consume();
        printf("\nConsumer has consumed item: %d\n", item);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
}
int main()
{
        int n1, n2, i;
        initialize();
        printf("\nEnter the no of producers: ");
        scanf("%d", &n1);
        printf("\nEnter the no of consumers: ");
        scanf("%d", &n2);
        printf("enter the limit to print:");
        int limit;
        scanf("%d", &limit);
        for (int j = 0; i < limit; j++)
        {
                item = j;
                for (i = 0; i < n1; i++)
                        pthread_create(&tidP[i], NULL, producer, NULL);
                for (i = 0; i < n2; i++)
                        pthread_create(&tidC[i], NULL, consumer, NULL);
        }
        for (i = 0; i < n1; i++)
                pthread_join(tidP[i], NULL);
        for (i = 0; i < n2; i++)
                pthread_join(tidC[i], NULL);
        //ptherad_destroy(&mutex);
        //sleep(5);
        exit(0);
}
