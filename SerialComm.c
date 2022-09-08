#include "SerialCommInterface.h"

pid_t createProcess() {
    return fork();
}

void generateSensorBMSData(BMSData bmsParam){
    //for (int sensorIndex = 0; sensorIndex < MAXSENSORCNT; sensorIndex++) {
	    for (int dataIndex = 0; dataIndex < NUMOFREADINGS; dataIndex++) {
            bmsParam.temperature[dataIndex] = (rand()%(MAX_TEMP - MIN_TEMP + 1));
		    bmsParam.soc[dataIndex] = (rand()%(MAX_SOC - MIN_SOC + 1)) + MIN_SOC;
		    //bmsParam[sensorIndex].temperature[dataIndex] = (rand()%(MAX_TEMP - MIN_TEMP + 1));
		    //bmsParam[sensorIndex].soc[dataIndex] = (rand()%(MAX_SOC - MIN_SOC + 1)) + MIN_SOC;
	    }
    //}
}

int main() {
    int fd1[2];
    pid_t p;
    if (pipe(fd1) == -1) {
        fprintf(stderr, "Pipe Failed");
    }
    p = createProcess();
    for (int sensorIndex = 0; sensorIndex < MAXSENSORCNT; sensorIndex++) {
        if (p < 0) {
            fprintf(stderr, "fork Failed");
            break;
        } else if (p > 0) {
            sender(fd1);
        } else {
            receiver(fd1);
        }
    }
 return 0;
}
