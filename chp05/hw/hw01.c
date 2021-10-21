#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argv, char *argc[]) {
    int i = 400;
    int rc = fork();
    if (0 > rc) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("x in child(%d) is %d\n", (int)getpid(), i);
        i = 20;
        printf("Atfer revising, x in child(%d) is %d\n", (int)getpid(), i);
    } else {
        printf("x in parent(%d) is %d\n", (int)getpid(), i);
        i = 10;
        printf("After revising, x in parent(%d) is %d\n", (int)getpid(), i);
    }
    return 0;
}