#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define SUCCESS         0
#define FAIL            -1
#define MAXSENSORCNT    2
#define NUMOFREADINGS	50
#define SINGLEBMSDATA   8
#define MAXNOOFBMSDATA  (MAXSENSORCNT * NUMOFREADINGS * SINGLEBMSDATA)
#define MIN_TEMP        0
#define MAX_TEMP        45
#define MIN_SOC         20
#define MAX_SOC         80
#define RANDOM_TEMP     (rand()%(MAX_TEMP - MIN_TEMP + 1))
#define RANDOM_SOC      ((rand()%(MAX_SOC - MIN_SOC + 1)) + MIN_SOC)

typedef struct BMSData
{
    int temp[NUMOFREADINGS];
    int soc[NUMOFREADINGS];
}BMSData;

void sender(int fd1[], BMSData bmsParam[]);
void writeTo(int fd1, BMSData bmsParam[]);
void getBMSData(char dataArray[], BMSData bmsParam[]);
void receiver(int fd1[]);
void readFrom(int fd1);
BMSData generateSensorBMSData(BMSData bmsParam);
int commInit();
int pipeInit(int fd1[]);
pid_t createProcess();
int runProcess(pid_t p, BMSData bmsParam[], int fd1[]);
