#include "SerialCommInterface.h"

void writeTo(int fd1, BMSData bmsParam) {
 //   static int dataIndex = 0;
    char dataArray[1000];
    for (int dataIndex = 0; dataIndex < NUMOFREADINGS; dataIndex++) {
        char tempArray[10];
        sprintf(tempArray, "%d %d\n", bmsParam.temp[dataIndex], bmsParam.soc[dataIndex]);
        //dataLen += strlen(tempArray);
       // write(fd1, dataArray, strlen(dataArray));
        //printf("sender:[%d] %s\n", dataIndex, dataArray);
        strcat(dataArray, tempArray);
       // write(fd1, &bmsParam.temp[dataIndex], sizeof(int));
       // write(fd1, &bmsParam.soc[dataIndex], sizeof(int));
    }
    printf("sender: %s\n", dataArray);
    write(fd1, dataArray, strlen(dataArray));
}

void sender(int fd1[], BMSData bmsParam) {
    //BMSData bmsParam;
    //int dataLen;
    //bmsParam = generateSensorBMSData(bmsParam);
    close(fd1[0]);
    writeTo(fd1[1], bmsParam);
    close(fd1[1]);
    //return dataLen;
}
