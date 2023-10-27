#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(){
int *ptr;
ptr = (int *) malloc (5 * sizeof(int));
	if(ptr != NULL){
		printf("Memory has been successfully allocated.\n");
		printf("Starting address: %p\n", ptr);
		printf("End address: %p\n", ptr+4);

		for(int i=0;i<5;i++){
			ptr[i] = i+1;
		}

		//ptr = realloc(ptr, 10 * sizeof(int));
		printf("Successfully realocated the pointer\n");

		for(int i=5;i<10;i++){
			ptr[i] = i+1;
		}
		printf("The elements of the array are:\n");

		for(int i=0;i<10;i++){
			printf("%d\n",ptr[i]);
		}
	}
}
