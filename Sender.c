#include "SerialCommInterface.h"

void writeTo(int fd1, BMSData bmsParam, int *dataLen) {
    dataLen = 0;
    for (int dataIndex = 0; dataIndex < 1/*NUMOFREADINGS*/; dataIndex++) {
        char tempArray[100];
        sprintf(tempArray, "%d %d\n", bmsParam.temp[dataIndex], bmsParam.soc[dataIndex]);
        dataLen += strlen(tempArray);
        write(fd1, tempArray, strlen(tempArray));
       // write(fd1, &bmsParam.temp[dataIndex], sizeof(int));
       // write(fd1, &bmsParam.soc[dataIndex], sizeof(int));
    }
}

int sender(int fd1[]) {
    BMSData bmsParam;
    int dataLen;
    bmsParam = generateSensorBMSData(bmsParam);
    close(fd1[0]);
    writeTo(fd1[1], bmsParam, &dataLen);
    close(fd1[1]);
    return dataLen;
}
