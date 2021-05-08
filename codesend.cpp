#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int pin = 0;
    int pulse = 0;
    int code = atoi(argv[1]);
    if (argc >= 3) pulse = atoi(argv[2]);
    
    if (wiringPiSetup() == -1) return 1;
    printf("sending code [%d]\n", code);
    RCSwitch mySwitch = RCSwitch();
    if (pulse != 0) mySwitch.setPulseLength(pulse);
    mySwitch.enableTransmit(pin);
    
    mySwitch.send(code, 24);
    
    return 0;
}