#include "SerialCommInterface.h"
void writeTo(int fd1, BMSData bmsParam) {
    for (int dataIndex = 0; dataIndex < NUMOFREADINGS; dataIndex++) {
        write(fd1, bmsParam.temp[dataIndex], sizeof(int));
        write(fd1, bmsParam.soc[dataIndex], sizeof(int));
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
        writeTo(fd1[1], bmsParam);
    //}
    close(fd1[1]);
    return 0;
}
