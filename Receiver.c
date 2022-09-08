#include "SerialCommInterface.h"

void readFrom(int fd1) {
    char dataArray[500];
    read(fd1, dataArray, 350);
    printf("receiver: %s", dataArray);
}

void receiver(int fd1[]) {
    close(fd1[1]);
    readFrom(fd1[0]);
    close(fd1[0]);
}
