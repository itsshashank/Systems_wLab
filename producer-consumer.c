#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#define buffersize 10
pthread_mutex_t mutex;
pthread_t Pro,Con;
sem_t full,empty;
int counter,limit;
int buffer[buffersize];
void initialize(int buff)
{
        pthread_mutex_init(&mutex,NULL);
        sem_init(&full,1,0);
        sem_init(&empty,1,buff/*ersize*/);
        counter=0;
}
void displayBuffer (int a[],int n)
{
	int i;
	printf("Buffer is : ");
	for (i = 0; i < counter; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void write(int item)
{
        buffer[counter++]=item;
}
int read()
{
        return(buffer[--counter]);
}
void * producer (void * param)
{
        int i;
	for (i = 0; i < limit; i++) {
		sem_wait (&empty);
		pthread_mutex_lock(&mutex);
		printf("\nProducer has produced item: %d\n",i);
		write(i);
		displayBuffer (buffer, counter);
		pthread_mutex_unlock(&mutex);
                sleep(1);
		sem_post (&full);
	}
}
void *consumer (void * param)
{
        int i, item;
	for (i = 0; i < limit; i++) {
		sem_wait (&full);
		pthread_mutex_lock(&mutex);
		item=read();
		printf("\nConsumer has consumed item: %d\n",item);
		displayBuffer (buffer, counter);
                sleep(2);
		pthread_mutex_unlock(&mutex);
		sem_post (&empty);
	}
}
int main()
{
        printf("enter the size of buffer to use:");
        int b;
        scanf("%d",&b);
        initialize(b);
        printf ("Enter no. of items to produce : ");
	scanf ("%d", &limit);
        pthread_create (&Pro, NULL, producer, NULL);
	pthread_create (&Con, NULL, consumer, NULL);
        sleep(5);
        pthread_join (Pro, NULL);
	pthread_join (Con, NULL);

	return 0;
}
