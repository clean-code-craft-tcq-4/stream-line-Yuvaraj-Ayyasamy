#include "SerialCommInterface.h"

void getBMSData(char dataArray[], BMSData bmsParam[]) {
    memset(dataArray, '\0', sizeof(dataArray));
    for (int sensorIndex = 0; sensorIndex < MAXSENSORCNT; sensorIndex++) {
        for (int dataIndex = 0; dataIndex < NUMOFREADINGS; dataIndex++) {
            char tempArray[NUMOFREADINGS];
            memset(tempArray, '\0', sizeof(tempArray));
            sprintf(tempArray, "%d %d\n", bmsParam[sensorIndex].temp[dataIndex], bmsParam[sensorIndex].soc[dataIndex]);
            strcat(dataArray, tempArray);
        }
    }
    printf("sender: \n%s", dataArray);
}

void writeTo(int fd1, BMSData bmsParam[]) {
    char dataArray[MAXNOOFBMSDATA];
    getBMSData(dataArray, bmsParam);
    write(fd1, dataArray, strlen(dataArray));
}

void sender(int fd1[], BMSData bmsParam[]) {
    close(fd1[0]);
    writeTo(fd1[1], bmsParam);
    close(fd1[1]);
}
