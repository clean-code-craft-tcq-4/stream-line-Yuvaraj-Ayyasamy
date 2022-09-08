#include "SerialCommInterface.h"

int sender(int fd1[]) {
    char concat_str[100];
    char input_str[100];
    strncpy(input_str, "www.geeks", 10);
    close(fd1[0]);
    write(fd1[1], input_str, strlen(input_str) + 1);
    close(fd1[1]);
    return 0;
}
