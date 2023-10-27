#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int main(){
	int *ptr;
	ptr = (int *) malloc (5 * sizeof(int));
	if(ptr != NULL){
		printf("Memory has been successfully allocated.\n");
		printf("Starting address: %p\n", ptr);
		printf("End address: %p\n", ptr+4);
		free(ptr);
		for(int i=0;i<5;i++){
			ptr[i] = i+1;
		}
		printf("The elements of the array are:\n");
		for(int i=0;i<5;i++){
			printf("%d\n",ptr[i]);
		}
	}
}
