#include "SerialCommInterface.h"

int receiver(int fd1[]) {
    close(fd1[1]);
    char concat_str[100];
    read(fd1[0], concat_str, 100);
    printf("Concatenated string %s\n", concat_str);
    close(fd1[0]);
    return 0;
}
