#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* ptr;
    int num = 1234;
    ptr = fopen("test.txt", "w");
    if (NULL == ptr) {
        printf("file can't be opened \n");
    } else {
        printf("content of this file are \n");
        printf(fptr,"%d",num);
        fscanf(fptr,"%d", &num);
        printf("Value of n=%d", num);
    }
    fclose(ptr);
    return 0;
}
