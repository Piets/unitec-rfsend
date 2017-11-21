#include <wiringPi.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pin = 0;
int i, h;

int shortPulse = 475;
int longPulse = 975;

void sendBit(int bit) {
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

void pulse(char codeString[], int amount) {
  for (h = 0; h < amount; h++) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(shortPulse);
    digitalWrite(pin, LOW);
    delayMicroseconds(5 * shortPulse);

    for (i = 0; i < strlen(codeString); i++){
      sendBit(codeString[i] - '0');
    }
  }
}

int main (int argc, char **argv)
{
  wiringPiSetup();

  pinMode (pin, OUTPUT);
  digitalWrite(pin, LOW);

  pulse(argv[1], 10);

  return 0;
}
