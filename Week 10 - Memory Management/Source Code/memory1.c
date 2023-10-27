#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(){
	char *ptr;
	ptr = (char *) malloc (3 * sizeof(char));
	if(ptr != NULL){
		printf("Memory has been successfully allocated.\n");
		printf("Starting address: %p\n", ptr);
		printf("End address: %p\n", ptr+2);
		for(int i=0;i<3;i++){
			ptr[i] = i+1;
		}
		printf("The address of each elements are:\n");
		for(int i=0;i<3;i++){
			printf("%p\n",(void*)&ptr[i]);
		}
		sleep(10000);
	}
}
