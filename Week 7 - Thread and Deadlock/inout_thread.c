#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
struct arg_struct
{
	int a;
	int b;
	int sum;
};

void *addition(void *arguments){
	struct arg_struct *args = arguments;
	args -> sum = args -> a + args -> b;
	pthread_exit(NULL);
}

int main(){
	pthread_t t;
	struct arg_struct args;
	args.a = 10;
	args.b = 5;
	pthread_create(&t, NULL, addition, &args);
	pthread_join(t, NULL);
	printf("%d + %d = %d\n", args.a, args.b, args.sum);
}
