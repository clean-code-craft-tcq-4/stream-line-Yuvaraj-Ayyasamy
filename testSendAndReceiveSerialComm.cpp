#include "SerialCommInterface.h"
#include <cassert.h>

void testgenerateSensorBMSData() {
    BMSData bmsParam;
    int index=0;
    for (; index<NUMOFREADINGS; index++) {
        bmsParam.temp[index] = 0;
        bmsParam.soc[index] = 0;
    }
    bmsParam = generateSensorBMSData(bmsParam);
    for (index=0; index<NUMOFREADINGS; index++) {
        assert((bmsParam.temp[index] != 0) && (bmsParam.soc[index] != 0));
    }
}

void testcreateProcess() {
    assert(createProcess() >= SUCCESS);
}

void testpipeInit() {
    int fd1[2];
    assert(pipeInit(fd1) == SUCCESS);
}

void testcommInit() {
    assert(commInit() == SUCCESS);
}

int main() {
    testgenerateSensorBMSData();
    testcreateProcess();
    testpipeInit();
    testcommInit();
    return 0;
}
