#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>

void *increment();
void *decrement();
//Initialized 2 shared variables
int first = 1;
int second = 2;
sem_t semaphore;

int main(){
	sem_init(&semaphore, 0, 1);
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, increment, NULL);
	pthread_create(&thread2, NULL, decrement, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("\nFinal value of the first variable is %d\n", first);
	printf("Final value of the second variable is %d\n", second);
}

void *increment() {
	int a;
	int b;
	//Decrement the Semaphore
	int value;
	sem_getvalue(&semaphore, &value);
    	printf("\nSemaphore value: %d\n",value);
	printf("Thread 1 trying to decrement the semaphore\n");
	sem_wait(&semaphore);
	sem_getvalue(&semaphore, &value);
	printf("Semaphore Value: %d\n",value);
	//Read the initial value
	printf("Thread 1 can enter its critical section\n");
	a = first;
	b = second;
	printf("Thread 1 reads the value of the first variable as: %d\n", a);
	printf("Thread 1 reads the value of the second variable as: %d\n", b);
	//Critical Section (Increment & Update)
	a++;
	b++;
	printf("Local update by Thread 1 to the first variable: %d\n", a);
	printf("Local update by Thread 1 to the second variable: %d\n", b);
	sleep(1);
	first = a;
	second = b;
	printf("Value of the first variable updated by Thread 1 is: %d\n", a);
        printf("Value of the second variable updated by Thread 1 is: %d\n", b);
	//Increment the Semaphore back
	sem_getvalue(&semaphore, &value);
	printf("Semaphore Value: %d\n",value);
	sem_post(&semaphore);
	sem_getvalue(&semaphore, &value);
	printf("Semaphore Value: %d\n",value);
	printf("Thread 1 increment the semaphore\n\n\n");
}

void *decrement() {
        int a;
        int b;
        //Decrement the Semaphore
	int value;
        sem_getvalue(&semaphore, &value);
        printf("Semaphore value: %d\n",value);
        printf("Thread 2 trying to decrement the semaphore\n");
        sem_wait(&semaphore);
	sem_getvalue(&semaphore, &value);
	printf("Semaphore Value: %d\n",value);
        //Read the initial value
        printf("Thread 2 can enter its critical section\n");
        a = first;
        b = second;
        printf("Thread 2 reads the value of the first variable as: %d\n", a);
        printf("Thread 2 reads the value of the second variable as: %d\n", b);
        //Critical Section (Decrement & Update)
        a--;
        b--;
        printf("Local update by Thread 2 to the first variable: %d\n", a);
        printf("Local update by Thread 2 to the second variable: %d\n", b);
        sleep(1);
        first = a;
        second = b;
        printf("Value of the first variable updated by Thread 2 is: %d\n", a);
        printf("Value of the second variable updated by Thread 2 is: %d\n", b);
        //Increment the Semaphore back
	sem_getvalue(&semaphore, &value);
	printf("Semaphore Value: %d\n",value);
        sem_post(&semaphore);
	sem_getvalue(&semaphore, &value);
	printf("Semaphore Value: %d\n",value);
        printf("Thread 1 increment the semaphore\n\n\n");
}
