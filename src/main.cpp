#include <Arduino.h>
#include "mindfulness.h"

#define NUM_OF_LEDS 6
extern int ledPins[];
extern int isBreathing;
extern float inhale;

void setup() {
  Serial.begin(9600);

  for (int index = 0; index < NUM_OF_LEDS; index++) {
    pinMode(ledPins[index], OUTPUT);
  }
  
  randomSeed(analogRead(0));
  turnLEDSOff();
  pingPong();
}

void loop() {
  if (isThereLight()) {
    if (!isBreathing) {
      setRandomBreathingPattern();
      isBreathing = 1;
    }
    
    if (inhale) {
      sinePulseNonBlocking();
    }
  }
  else {
    isBreathing = 0;
    turnLEDSOff();
  }
}