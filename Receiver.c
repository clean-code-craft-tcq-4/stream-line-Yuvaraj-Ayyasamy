#include "SerialCommInterface.h"

void readFrom(int fd1) {
    char dataArray[800];
    memset(dataArray, '\0', sizeof(dataArray));
    read(fd1, dataArray, 800);
    printf("receiver:\n%s", dataArray);
}

void receiver(int fd1[]) {
    close(fd1[1]);
    readFrom(fd1[0]);
    close(fd1[0]);
}
