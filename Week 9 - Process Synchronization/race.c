#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void *increment();
void *decrement();
int shared = 1;
int main(){
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, increment, NULL);
	pthread_create(&thread2, NULL, decrement, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("Final value of the shared variable is %d\n", shared);
}

void *increment() {
	int x;
	x = shared;
	printf("Thread 1 reads the value of the shared variable as: %d\n", x);
	x++;
	printf("Local update by Thread 1: %d\n", x);
	sleep(1);
	shared = x;
	printf("Value of the shared variable updated by Thread 1 is: %d\n", shared);
}

void *decrement() {
	int y;
	y = shared;
	printf("Thread 2 reads the value of the shared variable as: %d\n", y);
	y--;
	printf("Local update by Thread 2: %d\n", y);
	sleep(1);
	shared = y;
	printf("Value of the shared variable updated by Thread 2 is: %d\n", shared);
}
