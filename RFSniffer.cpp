#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int pin = 2;
    
    if (wiringPiSetup() == -1) return 0;
    RCSwitch mySwitch = RCSwitch();
    mySwitch.enableReceive(pin);
    
    while(1) {
        if (mySwitch.available()) {
            int value = mySwitch.getReceivedValue();

            if (value == 0) {
                printf("unknown encoding");
            } else {
                printf("received [%i] with pulse [%i]\n", mySwitch.getReceivedValue(), mySwitch.getReceivedDelay());
            }

            mySwitch.resetAvailable();
        }
        
        usleep(100); 
    }
}