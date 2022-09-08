#include "SerialCommInterface.h"

void readFrom(int fd1) {
   // for (int dataIndex = 0; dataIndex < 2/*NUMOFREADINGS*/; dataIndex++) {
        // read(fd1, &bmsParam.temp[dataIndex], sizeof(int));
        // read(fd1, &bmsParam.soc[dataIndex], sizeof(int));
        char tempArray[100];
        read(fd1, tempArray, 6);
        printf("receiver: %s", tempArray);
        // printf("%d %d\n", bmsParam.temp[dataIndex], bmsParam.soc[dataIndex]);
    //}
}

void receiver(int fd1[]) {
    close(fd1[1]);
    //BMSData bmsParam;
    readFrom(fd1[0]);
    //readFrom(fd1[0], bmsParam);
    close(fd1[0]);
}
