
## Lab Activity 1
1. Compile and run the source code listing above and compare your result with your friends. Screenshot your result and answer the following questions.
```c
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
```
a. Is the final result of the shared variable similar to your friends?
	![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/54391f12-172e-41f5-9c24-46af823824fc)

b. Why does this happen?
	![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/771decc9-ab91-437e-a6e8-58e6c6232ba3)

c. Which part of the source code list above is the critical section?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/68151fba-c320-402a-aa6b-59bd000f87db)

## Lab Activity 2
Compile and run the code list above. Screenshot the result and answer the following questions.
1. What is the final value of the shared variable?
`The final result of shared value is 1`
2. Which thread obtains the lock first?
`Thread 1 obtained the lock first and will increment it by 1 (1+1 = 2)`
3. If the other thread first obtains the lock, what will be the final value of the shared variable?
`In the case that thread 2 obtain the lock first and decrement it by 1 (1 – 1 = 0) the final result will still be the same. Since after the thread 2 released the lock and gave it to thread 1, the thread 1 will then read the initial value as 0 and increment it by 1 (0 + 1 = 1)`

![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/62d65c59-a64a-4009-a999-fe69f993b7eb)


## Lab Activity 3
Compile and run the code list above. Screenshot the result and answer the following questions.
```c
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


1. What is the final value of the shared variable?
`The final value of the shared variable is 1`
2. From the final value that you obtained, which thread first obtains access to the shared variable?
`Thread 1 can get the access it first and will increment it by 1`

![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/c4903d44-885e-45e2-ad51-c579dcdc1f77)

## Assignment
1. Create a program that has two threads, threadA and threadB that are trying to access and modify two shared variables, varA and varB. In this case, both threads need to have access to both variables to finish their execution, similar to the deadlock case. Use the semaphore approach to ensure that deadlock does not happen. Take some screenshots and answer the following questions:

```c
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>

void *increment();
void *decrement();

// Initialized 2 shared variables
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
    // Decrement the Semaphore
    int value;
    sem_getvalue(&semaphore, &value);
    printf("\nSemaphore value: %d\n",value);
    printf("Thread 1 trying to decrement the semaphore\n");
    sem_wait(&semaphore);
    sem_getvalue(&semaphore, &value);
    printf("Semaphore Value: %d\n",value);
    // Read the initial value
    printf("Thread 1 can enter its critical section\n");
    a = first;
    b = second;
    printf("Thread 1 reads the value of the first variable as: %d\n", a);
    printf("Thread 1 reads the value of the second variable as: %d\n", b);
    // Critical Section (Increment & Update)
    a++;
    b++;
    printf("Local update by Thread 1 to the first variable: %d\n", a);
    printf("Local update by Thread 1 to the second variable: %d\n", b);
    sleep(1);
    first = a;
    second = b;
    printf("Value of the first variable updated by Thread 1 is: %d\n", a);
    printf("Value of the second variable updated by Thread 1 is: %d\n", b);
    // Increment the Semaphore back
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
    // Decrement the Semaphore
    int value;
    sem_getvalue(&semaphore, &value);
    printf("Semaphore value: %d\n",value);
    printf("Thread 2 trying to decrement the semaphore\n");
    sem_wait(&semaphore);
    sem_getvalue(&semaphore, &value);
    printf("Semaphore Value: %d\n",value);
    // Read the initial value
    printf("Thread 2 can enter its critical section\n");
    a = first;
    b = second;
    printf("Thread 2 reads the value of the first variable as: %d\n", a);
    printf("Thread 2 reads the value of the second variable as: %d\n", b);
    // Critical Section (Decrement & Update)
    a--;
    b--;
    printf("Local update by Thread 2 to the first variable: %d\n", a);
    printf("Local update by Thread 2 to the second variable: %d\n", b);
    sleep(1);
    first = a;
    second = b;
    printf("Value of the first variable updated by Thread 2 is: %d\n", a);
    printf("Value of the second variable updated by Thread 2 is: %d\n", b);
    // Increment the Semaphore back
    sem_getvalue(&semaphore, &value);
    printf("Semaphore Value: %d\n",value);
    sem_post(&semaphore);
    sem_getvalue(&semaphore, &value);
    printf("Semaphore Value: %d\n",value);
    printf("Thread 1 increment the semaphore\n\n\n");
}
```

![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/02f9b701-2def-4c24-b993-57dcee33ba0c)
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/dbd1a0c0-06ab-4ab5-8ed3-d997147f95fe)
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/493acf3d-e02e-495d-a73b-64dc75393c87)

a. Which thread completed first?
`Answer: From the result above, Thread 1 is the first thread that completed, followed by Thread 2 as the last. This happened to avoid deadlock in which Thread 1 will decrement semaphore and must complete all processing of first and second variable. When the process currently happening, Thread 2 must wait. Right after all processes finished on Thread 1, it will increment back the Semaphore and will satisfy the condition of > 0. In this case, Thread 2 will then proceed to its critical section right after Thread 1 and decrement the semaphore with similar concept above. `

b. Illustrate how each thread modifies the semaphore and continues/waiting for their turn.

![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/91b6b949-a33c-4cfe-b7e8-05cc9d804fbf)

`From the illustration above, notice that the initial value of semaphore is set to 1. On the next phase, Thread will decrement it until non-negative (-1). At this state the process of incrementing and decrementing will be start in order (Thread 1 -> Thread 2) until the semaphore is incremented back to 1`