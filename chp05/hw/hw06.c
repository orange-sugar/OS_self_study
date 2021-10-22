#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("%d", (int)wait(NULL));
        printf("child running\n");
    } else {
        // int pid = (int)wait(NULL);
        int pid = (int)waitpid(-1, NULL, 0);
        printf("wait and child(%d) ended\n", pid);
    }
    return 0;
}