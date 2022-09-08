#include "SerialCommInterface.h"

int pipeInit(int fd1[]) {
    int retStatus = SUCCESS;
    if (pipe(fd1) == FAIL) {
        fprintf(stderr, "Pipe Failed");
        retStatus = FAIL;
    }
    return retStatus;
}

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

int runProcess(pid_t p) {
    int retStatus = SUCCESS;
    if (p < 0) {
        fprintf(stderr, "fork Failed");
        retStatus = FAIL;
    } else if (p > 0) {
        for (int sensorIndex = 0; sensorIndex < MAXSENSORCNT; sensorIndex++) {
            bmsParam[sensorIndex] = generateSensorBMSData(bmsParam[sensorIndex]);
        }
        sender(fd1, bmsParam);
    } else {
        receiver(fd1);
    }
    return retStatus;
}

int commInit() {
    int retStatus = SUCCESS;
    int fd1[2];
    pid_t p;
    BMSData bmsParam[MAXSENSORCNT];
    retStatus = pipeInit(fd1);
    if (SUCCESS == retStatus) {
        p = createProcess();
        retStatus = runProcess(p);
    }
    return retStatus;
}
