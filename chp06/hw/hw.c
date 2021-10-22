#include <bits/types/struct_timeval.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    double time_use = 0;
    struct timeval start;
    struct timeval end;

    gettimeofday(&start, NULL);
    printf("start.tv_sec:%ld\n", start.tv_sec);
    printf("start.tv_usec:%ld\n", start.tv_usec);

    int i = 100000000;
    while(i--);

    gettimeofday(&end, NULL);
    printf("start.tv_sec:%ld\n", start.tv_sec);
    printf("start.tv_usec:%ld\n", start.tv_usec);

    time_use = (end.tv_sec-start.tv_sec)*1.0+(end.tv_usec-start.tv_usec)*1.0/1000000;
    printf("time_use is %.10f\n",time_use);

    return 0;
}