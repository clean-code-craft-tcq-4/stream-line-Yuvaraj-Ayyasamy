#include "SerialCommInterface.h"

pid_t createProcess() {
    return fork();
}

BMSData generateSensorBMSData(BMSData bmsParam) {
    int dataIndex = 0;
  //  for (int dataIndex = 0; dataIndex < 2/*NUMOFREADINGS*/; dataIndex++) {
        bmsParam.temp[dataIndex] = (rand()%(MAX_TEMP - MIN_TEMP + 1));
        bmsParam.soc[dataIndex] = (rand()%(MAX_SOC - MIN_SOC + 1)) + MIN_SOC;
        printf("[%d]: %d %d\n", dataIndex, bmsParam.temp[dataIndex], bmsParam.soc[dataIndex]);
    dataIndex++;
   // }
    return bmsParam;
}

int main() {
    int fd1[2];
    pid_t p;
    //int dataLen = 0;
    if (pipe(fd1) == -1) {
        fprintf(stderr, "Pipe Failed");
    }
    p = createProcess();
   // for (int sensorIndex = 0; sensorIndex < MAXSENSORCNT; sensorIndex++) {
        for (int dataIndex = 0; dataIndex < NUMOFREADINGS; dataIndex++) {
            if (p < 0) {
                fprintf(stderr, "fork Failed");
                break;
            } else if (p > 0) {
                sender(fd1);
            } else {
                receiver(fd1);
            }
        }
   // }
 return 0;
}
