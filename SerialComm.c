#include "SerialCommInterface.h"

pid_t createProcess() {
    return fork();
}

int main()
{
    int fd1[2];
    //char input_str[100];
    pid_t p;
 
    if (pipe(fd1) == -1) {
        fprintf(stderr, "Pipe Failed");
    }
    //strncpy(input_str, "www.geeks", 10);
    p = createProcess();
    if (p < 0) {
        fprintf(stderr, "fork Failed");
    } else if (p > 0) {
        /*char concat_str[100];
        close(fd1[0]);
        write(fd1[1], input_str, strlen(input_str) + 1);
        close(fd1[1]);*/
        sender(fd1);
        wait(NULL);
    } else {
        /*close(fd1[1]);
        char concat_str[100];
        read(fd1[0], concat_str, 100);
        printf("Concatenated string %s\n", concat_str);
        close(fd1[0]);*/
        receiver(fd1);
        exit(0);
    }
 return 0;
}
