#include "SerialCommInterface.h"

void readFrom(BMSData bmsParam) {
    for (int dataIndex = 0; dataIndex < NUMOFREADINGS; dataIndex++) {
        read(fd1[1], bmsParam.temperature[dataIndex], int);
        read(fd1[1], bmsParam.soc[dataIndex], int);
        printf("%d %d\n", bmsParam.temperature[dataIndex], bmsParam.soc[dataIndex]);
    }
}

int receiver(int fd1[]) {
    close(fd1[1]);
    //BMSData bmsParam[MAXSENSORCNT];
    BMSData bmsParam;
    //char concat_str[100];
    //read(fd1[0], concat_str, 100);
    //printf("Concatenated string %s\n", concat_str);
    //for (int sensorIndex = 0; sensorIndex < MAXSENSORCNT; sensorIndex++) {
        readFrom(bmsParam);
    //}
    close(fd1[0]);
    return 0;
}
