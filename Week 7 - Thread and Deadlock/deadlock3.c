#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *function1();
void *function2();
void *function3();
pthread_mutex_t resourceA;
pthread_mutex_t resourceB;
pthread_mutex_t resourceC;

int main() {

 	pthread_mutex_init(&resourceA,NULL);
 	pthread_mutex_init(&resourceB,NULL);
	pthread_mutex_init(&resourceC,NULL);

	pthread_t one, two, three;

	//create thread
	pthread_create(&one, NULL, function1, NULL);
	pthread_create(&two, NULL, function2, NULL);
	pthread_create(&three, NULL, function3, NULL);
	pthread_join(one, NULL);
	pthread_join(two, NULL);
	pthread_join(three, NULL);
	printf("Thread joined\n");
}

void *function1() {
 	pthread_mutex_lock(&resourceA);
 	printf("Thread ONE acquired Resource A\n");
 	sleep(1);

 	pthread_mutex_lock(&resourceB);
 	printf("Thread ONE acquired Resource B\n");

 	pthread_mutex_unlock(&resourceB);
 	printf("Thread ONE released Resource B\n");

 	pthread_mutex_unlock(&resourceA);
 	printf("Thread ONE released Resource A\n");
}


void *function2() {
 	pthread_mutex_lock(&resourceB);
 	printf("Thread TWO acquired Resource B\n");
 	sleep(1);

 	pthread_mutex_lock(&resourceC);
 	printf("Thread TWO acquired Resource C\n");

 	pthread_mutex_unlock(&resourceC);
 	printf("Thread TWO released Resource C\n");

 	pthread_mutex_unlock(&resourceB);
 	printf("Thread TWO released Resource B\n");
}

void *function3() {
 	pthread_mutex_lock(&resourceC);
 	printf("Thread THREE acquired Resource C\n");
 	sleep(1);

 	pthread_mutex_lock(&resourceA);
 	printf("Thread THREE acquired Resource A\n");

 	pthread_mutex_unlock(&resourceA);
 	printf("Thread THREE released Resource A\n");

 	pthread_mutex_unlock(&resourceC);
 	printf("Thread THREE released Resource C\n");
}
