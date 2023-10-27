#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
	char *str;
	int x;
	printf("Declare the size of char: ");
	scanf("%d", &x);
	str = (char*) malloc ((x+1) * sizeof(char));
	printf("Memory has been successfully allocated.\n");
	printf("Starting address: %p\n", str);
	printf("End address: %p\n", str+x);
	printf("Enter your string: ");
	for(int i = 0; i < x; i++){
		fgets( str, x + 1, stdin );
	}

	printf("Element contained in the array: \n");
	for(int i = 0; i < x; i++){
		printf("%c ", str[i]);
	}
	printf("\n");
}
