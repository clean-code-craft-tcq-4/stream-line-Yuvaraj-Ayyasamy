#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int receiver() {
    FILE* fptr;
    int num = 1234;
    fptr = fopen("test.txt", "w");
    if (NULL == fptr) {
        printf("file can't be opened \n");
    } else {
        printf("content of this file are \n");
        printf("%d",num);
        fscanf(fptr,"%d", &num);
        printf("Value of n=%d", num);
    }
    fclose(fptr);
    return 0;
}
