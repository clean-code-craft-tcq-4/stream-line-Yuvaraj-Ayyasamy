#include "SerialCommInterface.h"

pid_t createProcess() {
    return fork();
}

BMSData generateSensorBMSData(BMSData bmsParam) {
    for (int dataIndex = 0; dataIndex < NUMOFREADINGS; dataIndex++) {
        bmsParam.temp[dataIndex] = (rand()%(MAX_TEMP - MIN_TEMP + 1));
        bmsParam.soc[dataIndex] = (rand()%(MAX_SOC - MIN_SOC + 1)) + MIN_SOC;
        printf("%d %d\n", bmsParam.temp[dataIndex], bmsParam.soc[dataIndex]);
    }
    return bmsParam;
}

int main() {
    int fd1[2];
    pid_t p;
    int dataLen = 0;
    if (pipe(fd1) == -1) {
        fprintf(stderr, "Pipe Failed");
    }
    p = createProcess();
    for (int sensorIndex = 0; sensorIndex < MAXSENSORCNT; sensorIndex++) {
        if (p < 0) {
            fprintf(stderr, "fork Failed");
            break;
        } else if (p > 0) {
            dataLen = sender(fd1);
        } else {
            receiver(fd1, dataLen);
        }
    }
 return 0;
}
