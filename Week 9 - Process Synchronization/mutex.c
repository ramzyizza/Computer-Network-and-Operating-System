#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void *increment();
void *decrement();
int shared = 1;
pthread_mutex_t lock;
int main(){
	pthread_mutex_init(&lock, NULL);
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, increment, NULL);
	pthread_create(&thread2, NULL, decrement, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("Final value of the shared variable is %d\n", shared);
}

void *increment() {
	int x;
	printf("Thread 1 trying to acquire the lock\n");
	pthread_mutex_lock(&lock);
	printf("Thread 1 acquired the lock\n");
	x = shared;
	printf("Thread 1 reads the value of the shared variable as: %d\n", x);
	x++;
	printf("Local update by Thread 1: %d\n", x);
	sleep(1);
	shared = x;
	printf("Value of the shared variable updated by Thread 1 is: %d\n", shared);
	pthread_mutex_unlock(&lock);
	printf("Thread 1 released the lock\n");
}

void *decrement() {
	int y;
	printf("Thread 2 trying to acquire the lock\n");
	pthread_mutex_lock(&lock);
	printf("Thread 2 acquired the lock\n");
	y = shared;
	printf("Thread 2 reads the value of the shared variable as: %d\n", y);
	y--;
	printf("Local update by Thread 2: %d\n", y);
	sleep(1);
	shared = y;
	printf("Value of the shared variable updated by Thread 2 is: %d\n", shared);
	pthread_mutex_unlock(&lock);
	printf("Thread 2 released the lock\n");
}
