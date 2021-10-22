#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd[2] = {0, 0};
    int result = pipe(fd);
    if (result < 0) {
        printf("fail to create pipe\n");
        return 0;
    }

    int rc1 = fork();
    if (rc1 < 0) {
        fprintf(stderr, "1-fork failed\n");
        exit(1);
    } else if (rc1 == 0) {
        close(fd[0]);
        char* msg = "Hello world from child1\n";
        write(fd[1], msg, strlen(msg));
        close(fd[1]);
        printf("child1 says something\n");
        return 0;
    }

    int rc2 = fork();
    if (rc2 < 0) {
        fprintf(stderr, "2-fork failed\n");
        exit(1);
    } else if (rc2 == 0) {
        waitpid(rc1, NULL, 0);
        close(fd[1]);
        char buf[1024];
        int len = (int)read(fd[0], buf, 1024);
        if (len > 0) {
            buf[len] = '\0';
            printf("child2 reads something: %s\n", buf);
        } 
        return 0;
    }

    waitpid(rc1, NULL, 0);
    waitpid(rc2, NULL, 0);
    return 0;
}