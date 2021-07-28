#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>

void main()
{   int size;
    char *c = (char *) calloc(100, sizeof(char));

    // File open system call
    int fileDescriptor = open("file.txt", O_RDONLY | O_CREAT);
    if (fileDescriptor < 0) {
        perror("File open or creation failed\n");
        exit(1);
    }
    printf("File creation or opening successful\n");
    printf("fd = %d \n", fileDescriptor);

    // Write System Call
    size = write(fileDescriptor, "Hello World in C!", strlen("Hello World in C!"));
    printf("Called write(%d, \"Hello World in C!\", %d). It returned %d \n", fileDescriptor, strlen("Hello World in C!\n"), size);

    // Read System Call
    size = read(fileDescriptor, c, 10);
    printf("Called read(%d, c, 10). It returned that %d bytes were read.\n", fileDescriptor, size);
    c[size] = '\0';
    printf("Those bytes are as follows: %s\n", c);

    // File close system Call
    printf("Closing the file \n");
    if (close(fileDescriptor) < 0)
    {
        perror("c1");
        exit(1);
    }
    printf("File Closed Successfully \n");
}