## Lab Activity 1
Modify the above program by adding the function “sleep(10000)”. You may need to import the unistd.h library. Then compile the program and run it in the background. Identify the process id of this program and check the value of /proc//maps file.
```c
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
        for(int i=0;i<5;i++){
            ptr[i] = i+1;
        }
        printf("The elements of the array are:\n");
        for(int i=0;i<5;i++){
            printf("%d\n",ptr[i]);
        }
    }
    sleep(10000);
}
```

1. Add sleep(10000) at the end of the program
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/6605b145-952e-4f5e-8351-f027d3571da8)

2. What does it mean in terms of memory allocation?
`In terms of memory allocation, if we put our running program in the background, we could observe that by using the method above, it will put both of our starting address (0x55ed96c8a2a0) and end address (0x55ed96c8a2b0) at address 55ed96c8a exactly on the [heap] which depicted on the image above.
`
## Lab Activity 2
Modify the realloc.c by commenting on the realloc function and its corresponding message printing. Then compile and run the realloc.c again.
```c
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
        printf("Successfully reallocated the pointer\n");

        for(int i=5;i<10;i++){
            ptr[i] = i+1;
        }
        printf("The elements of the array are:\n");

        for(int i=0;i<10;i++){
            printf("%d\n",ptr[i]);
        }
    }
}
```

1. What is the result?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/1c1e3e85-92d7-4b59-8b30-9d5376d2de87)

2. Why does that happen?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/9807cb3a-5e19-436a-b037-ce0cada5f656)

## Lab Activity 3
Compile the changes that you made and run the program. free.c program, Add free(ptr); before the for loops
```c
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
        free(ptr);  // Note: Using 'ptr' after 'free()' is undefined behavior.
        for(int i=0;i<5;i++){
            ptr[i] = i+1;  // Here, 'ptr' is being accessed after 'free()', which should generally be avoided.
        }
        printf("The elements of the array are:\n");
        for(int i=0;i<5;i++){
            printf("%d\n",ptr[i]);
        }
    }
}
```

1. What is the result?

![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/cad418f3-8afc-491b-afb9-ce5d9a133449)

2. Can the pointer still be used to store and print values? Why?

![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/fb4970e6-b8c6-4333-add5-d626d446b643)

## Assignment
1. Write a program that declares a variable of any type. Print the memory address of the variable and find out in which segment the variable is stored in the virtual address space. Explain why the variable is stored there!

```c
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
        printf("The address of each element is:\n");
        for(int i=0;i<3;i++){
            printf("%p\n",(void*)&ptr[i]);
        }
        sleep(10000);  // This will pause the program for a long duration
    }
}
```

![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/7683a63a-cc71-44bd-880e-66f831a7377b)
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/a4c4dc6e-b6ac-4804-8846-4b427451ea34)

2. Write a program that accepts and displays a string value. The string should be stored in an array of characters allocated using the malloc function. First, the program accepts the length of string that needs to be stored as an input. Then, the program accepts the string to be displayed. Finally, the program displays the inputted string. You may use scanf and printf functions for this purpose.
```c
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
```
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/8161794b-329a-43c5-99ce-aa3e5fa69a76)
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/0c3a0d7b-03f2-428c-aa2f-69198af520b3)
