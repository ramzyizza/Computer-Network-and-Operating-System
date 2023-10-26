#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

struct args {
    char* text;
};

void *createFile(void*content){
    int fileDesc;
    fileDesc = open("hello.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
    write(fileDesc, content, 100);
    pthread_exit(NULL);
}

int main() {
    struct args *String = (struct args *)malloc(sizeof(struct args));
    char content[100] = "Hello Thread\n";
    String->text = content;

    pthread_t t;
    pthread_create(&t, NULL, createFile, content);
    pthread_join(t, NULL);
    return 0;
}
