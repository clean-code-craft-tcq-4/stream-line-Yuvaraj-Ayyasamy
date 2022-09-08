#include "SerialCommInterface.h"
void writeTo(BMSData bmsParam) {
    for (int dataIndex = 0; dataIndex < NUMOFREADINGS; dataIndex++) {
        write(fd1[1], bmsParam.temperature[dataIndex], int);
        write(fd1[1], bmsParam.soc[dataIndex], int);
    }
}

int sender(int fd1[]) {
    //char concat_str[100];
    //char input_str[100];
    //BMSData bmsParam[MAXSENSORCNT];
    BMSData bmsParam;
    //for (int sensorIndex = 0; sensorIndex < MAXSENSORCNT; sensorIndex++) {
        generateSensorBMSData(bmsParam);
    //}
    //strncpy(input_str, "www.geeks", 10);
    close(fd1[0]);
    //for (int sensorIndex = 0; sensorIndex < MAXSENSORCNT; sensorIndex++) {
        writeTo(bmsParam);
    //}
    close(fd1[1]);
    return 0;
}
