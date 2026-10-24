// Q1: Create a process and display process IDs
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Child process ID: %d\n", (int)getpid());
        printf("Parent process ID: %d\n", (int)getppid());
    } else {
        printf("Parent process ID: %d\n", (int)getpid());
        printf("Created child process ID: %d\n", (int)pid);
        wait(NULL);
    }
    return 0;
}
