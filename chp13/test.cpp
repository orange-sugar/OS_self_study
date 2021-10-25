#include <cstdio>
#include <cstdlib>

int main (int argc, char *argv[]) {
    printf("location of code: %p", (void *) main);
    printf("location of heap : %p\n", (void *) malloc(1));
    int x = 3;
    printf("location of stack : %p\n", (void *) &x);
    return x;
}