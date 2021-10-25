#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
//    //for q1-3
//    int *p = NULL;
//    free(p);

//    //for q5
//    int *data = (int *)malloc(sizeof(int)*100);
//    data[100] = 0;

//    //for q6
//    int *data = (int *)malloc(sizeof(int)*100);
//    free(data);
//    printf("%d\n", data[0]);
//
    int *data = (int *)malloc(sizeof(int)*100);
    free(data+2);   
    printf("%d\n", data[0]);
    return 0;    
}
