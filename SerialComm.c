#include "SerialCommInterface.h"

pid_t createProcess() {
    return fork();
}

int main()
{
    int fd1[2];
    pid_t p;
    if (pipe(fd1) == -1) {
        fprintf(stderr, "Pipe Failed");
    }
    p = createProcess();
    for (int index=0; index<10; index++) {
    if (p < 0) {
        fprintf(stderr, "fork Failed");
        break;
    } else if (p > 0) {
        sender(fd1);
        wait(NULL);
    } else {
        receiver(fd1);
        exit(0);
    }
    }
 return 0;
}
