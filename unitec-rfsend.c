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

void pulse(char codeString[], int pin) {
  int i, h;

  for (h = 0; h < 5; h++) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(shortPulse);
    digitalWrite(pin, LOW);
    delayMicroseconds(5 * shortPulse);

    for (i = 0; i < strlen(codeString); i++){
      sendBit(codeString[i] - '0', pin);
    }
  }
}

int main (int argc, char **argv) {
  wiringPiSetup();

  int pin = atoi(argv[2]);
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);

  int h;
  for (h = 0; h < 3; h++) {
    pulse(argv[1], pin);
    delayMicroseconds(5 * longPulse);
  }

  return 0;
}
