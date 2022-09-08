#include "SerialCommInterface.h"

void writeTo(int fd1, BMSData bmsParam) {
    dataLen = 0;
    for (int dataIndex = 0; dataIndex < 2/*NUMOFREADINGS*/; dataIndex++) {
        char tempArray[100];
        sprintf(tempArray, "%d %d\n", bmsParam.temp[dataIndex], bmsParam.soc[dataIndex]);
        //dataLen += strlen(tempArray);
        write(fd1, tempArray, strlen(tempArray));
        printf("sender: %s\n", tempArray);
       // write(fd1, &bmsParam.temp[dataIndex], sizeof(int));
       // write(fd1, &bmsParam.soc[dataIndex], sizeof(int));
    }
}

void sender(int fd1[]) {
    BMSData bmsParam;
    //int dataLen;
    bmsParam = generateSensorBMSData(bmsParam);
    close(fd1[0]);
    writeTo(fd1[1], bmsParam);
    close(fd1[1]);
    //return dataLen;
}
