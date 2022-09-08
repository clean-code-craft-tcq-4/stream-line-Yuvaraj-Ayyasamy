#include "SerialCommInterface.h"

void readFrom(int fd1, BMSData bmsParam, int dataLen) {
   // for (int dataIndex = 0; dataIndex < 2/*NUMOFREADINGS*/; dataIndex++) {
        // read(fd1, &bmsParam.temp[dataIndex], sizeof(int));
        // read(fd1, &bmsParam.soc[dataIndex], sizeof(int));
        char tempArray[100];
        read(fd1, tempArray, dataLen);
        printf("%s %d", tempArray, dataLen);
        // printf("%d %d\n", bmsParam.temp[dataIndex], bmsParam.soc[dataIndex]);
    //}
}

void receiver(int fd1[], int dataLen) {
    close(fd1[1]);
    BMSData bmsParam;
    readFrom(fd1[0], bmsParam, dataLen);
    close(fd1[0]);
}
