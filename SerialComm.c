#include "SerialCommInterface.h"

pid_t createProcess() {
    return fork();
}

BMSData generateSensorBMSData(BMSData bmsParam) {
    printf("Generated:\n");
    for (int dataIndex = 0; dataIndex < NUMOFREADINGS; dataIndex++) {
        bmsParam.temp[dataIndex] = RANDOM_TEMP;
        bmsParam.soc[dataIndex] = RANDOM_SOC;
        printf("[%d]: %d %d\n", dataIndex, bmsParam.temp[dataIndex], bmsParam.soc[dataIndex]);
    }
    return bmsParam;
}

int main() {
    int fd1[2];
    pid_t p;
    BMSData bmsParam[MAXSENSORCNT];

    if (pipe(fd1) == -1) {
        fprintf(stderr, "Pipe Failed");
    }

    p = createProcess();
    if (p < 0) {
        fprintf(stderr, "fork Failed");
    } else if (p > 0) {
        for (int sensorIndex = 0; sensorIndex < MAXSENSORCNT; sensorIndex++) {
            bmsParam[sensorIndex] = generateSensorBMSData(bmsParam[sensorIndex]);
        }
        sender(fd1, bmsParam);
    } else {
        receiver(fd1);
    }

 return 0;
}
