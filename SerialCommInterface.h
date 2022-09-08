#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAXSENSORCNT    2
#define NUMOFREADINGS	50
#define MIN_TEMP	0
#define MAX_TEMP	45
#define MIN_SOC		20
#define MAX_SOC		80

typedef struct BMSData
{
    int temp[NUMOFREADINGS];
    int soc[NUMOFREADINGS];
}BMSData;

int sender(int fd1[]);
void receiver(int fd1[], int dataLen);
void writeTo(int fd1, BMSData bmsParam, int *dataLen);
void readFrom(int fd1, BMSData bmsParam, int dataLen);
void generateSensorBMSData(BMSData bmsParam);
