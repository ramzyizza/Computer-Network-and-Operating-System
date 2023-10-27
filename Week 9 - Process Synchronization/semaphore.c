#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
void *increment();
void *decrement();
int shared = 1;
sem_t semaphore;
int main(){
	sem_init(&semaphore, 0, 1);
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, increment, NULL);
	pthread_create(&thread2, NULL, decrement, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("Final value of the shared variable is %d\n", shared);
}

void *increment() {
	int x;
	printf("Thread 1 trying to decrement the semaphore\n");
	sem_wait(&semaphore);
	printf("Thread 1 can enter its critical section\n");
	x = shared;
	printf("Thread 1 reads the value of the shared variable as: %d\n", x);
	x++;
	printf("Local update by Thread 1: %d\n", x);
	sleep(1);
	shared = x;
	printf("Value of the shared variable updated by Thread 1 is: %d\n",
	shared);
	sem_post(&semaphore);
	printf("Thread 1 increment the semaphore\n");
}
void *decrement() {
	int y;
	printf("Thread 2 trying to decrement the semaphore\n");
	sem_wait(&semaphore);
	printf("Thread 2 can enter its critical section\n");
	y = shared;
	printf("Thread 2 reads the value of the shared variable as: %d\n", y);
	y--;
	printf("Local update by Thread 2: %d\n", y);
	sleep(1);
	shared = y;
	printf("Value of the shared variable updated by Thread 2 is: %d\n",
	shared);
	sem_post(&semaphore);
	printf("Thread 2 increment the semaphore\n");
}
