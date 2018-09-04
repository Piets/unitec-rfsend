#include <wiringPi.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int shortPulse = 450;
int longPulse = 950;

void sendBit(int bit, int pin) {
    if (bit == 0) {
        digitalWrite(pin, HIGH);
        delayMicroseconds(longPulse);
        digitalWrite(pin, LOW);
        delayMicroseconds(shortPulse);
    } else if (bit == 1) {
        digitalWrite(pin, HIGH);
        delayMicroseconds(shortPulse);
        digitalWrite(pin, LOW);
        delayMicroseconds(longPulse);
    }
}

void sendCommand(char codeString[], int pin) {
    int i, h;

    for (h = 0; h < 5; h++) {
        // Send Header
        digitalWrite(pin, HIGH);
        delayMicroseconds(shortPulse);
        digitalWrite(pin, LOW);
        delayMicroseconds(5 * shortPulse);

        // Send Command
        for (i = 0; i < strlen(codeString); i++){
            sendBit(codeString[i] - '0', pin);
        }
    }
}

int main (int argc, char **argv) {
    if (wiringPiSetup() == -1) {
        return -1;
    }
    piHiPri(99);

    // Load Parameters
    // <COMMAND> <PIN>
    char *codeString = argv[1];
    int pin = atoi(argv[2]);

    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);

    int i;
    for (i = 0; i < 4; i++) {
        sendCommand(codeString, pin);
        delay(10);
    }

    return 0;
}
