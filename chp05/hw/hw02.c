#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF 32

int main() {
    const char *file = "a.txt";
    int fd = open(file, O_WRONLY); //, S_IRWXU
    
    int rc = fork();
    if (0 > rc) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        char ms_child_wt[] = "child \n";
        write(fd, ms_child_wt, strlen(ms_child_wt));

        // char ms_child_rd[BUF];
        // memset(ms_child_rd, 0, sizeof(ms_child_rd)/sizeof(char));
        // ssize_t n = read(fd, ms_child_rd, strlen(ms_child_rd));
        // if (n < 0) fprintf(stderr, "child read failed\n");
        // else printf("message from child: %s\n", ms_child_rd);
    } else {
        char ms_parent_wt[] = "parent \n";
        write(fd, ms_parent_wt, strlen(ms_parent_wt));

        // char ms_parent_rd[BUF];
        // memset(ms_parent_rd, 0, sizeof(ms_parent_rd)/sizeof(char));
        // ssize_t n = read(fd, ms_parent_rd, sizeof(ms_parent_rd));
        // // write(fd, ms_parent_rd, sizeof(ms_parent_rd));
        // if (n < 0) fprintf(stderr, "parent read failed\n");
        // else printf("message from parent: %s\n", ms_parent_rd);
    }
    return 0;
}