#include "SerialCommInterface.h"

void writeTo(int fd1, BMSData bmsParam[]) {
    char dataArray[1000];
    memset(dataArray, '\0', sizeof(dataArray));
    for (int sensorIndex = 0; sensorIndex < MAXSENSORCNT; sensorIndex++) {
    for (int dataIndex = 0; dataIndex < NUMOFREADINGS; dataIndex++) {
        char tempArray[10];
        memset(tempArray, '\0', sizeof(tempArray));
        sprintf(tempArray, "%d %d\n", bmsParam[sensorIndex].temp[dataIndex], bmsParam[sensorIndex].soc[dataIndex]);
        strcat(dataArray, tempArray);
    }
    }
    printf("sender: \n%s", dataArray);
    write(fd1, dataArray, strlen(dataArray));
}

void sender(int fd1[], BMSData bmsParam) {
    close(fd1[0]);
    writeTo(fd1[1], bmsParam);
    close(fd1[1]);
}
