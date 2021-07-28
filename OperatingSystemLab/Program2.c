#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void forkSystemCall() {
    // Child process returns value zero
    if (fork() == 0) {
        printf("I'm the child process");
    } else {
        printf("I'm the parent process");
    }
}

void main() {
    // Calling method to show fork system call
    forkSystemCall();
}