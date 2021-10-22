#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // close(STDOUT_FILENO);
        // open("./hw04.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
        char *myargs[3];
        myargs[0] = strdup("ls");
        myargs[1] = strdup(".");
        myargs[2] = NULL;
        char *envp[] = {"PATH=/bin:/usr/bin", "TERM=console", NULL};
        // execl("/bin/ls", "ls", NULL);
        // execv("/bin/ls", myargs);
        // execle("/bin/ls", "ls", NULL, envp);
        // execve("/bin/ls", myargs, envp);
        // execve(myargs[0], myargs, NULL);
        execvp(myargs[0], myargs);
    } else {
        
    }
    return 0;
}