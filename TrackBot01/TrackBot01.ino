
#include <QTRSensors.h>
#include "MiP_commands.h"

MiP MyMiP(2);


#define NUM_SENSORS             4  // number of sensors used
#define NUM_SAMPLES_PER_SENSOR  4  // average 4 analog samples per sensor reading
#define EMITTER_PIN             QTR_NO_EMITTER_PIN  // emitter is controlled by digital pin 2

// sensors 0 through 5 are connected to analog inputs 0 through 5, respectively
QTRSensorsAnalog qtra((unsigned char[]) {1,0,3,2}, 
  NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];

uint8_t i = 0;
uint8_t angle = 0;
uint8_t dist = 0;

unsigned int cutoffs[NUM_SENSORS] = {4, 110, 110, 200};

void setup() {
  // put your setup code here, to run once:
  MyMiP.init(); //Serial port is configured for 115200
  Serial.print("MiP is Alive!!!");
  delay(100); //Need a delay to let the buffer clear

  delay(2000); 
}

void loop() {
  // put your main code here, to run repeatedly:
  
  angle = 0;
  dist = 4;
  
  qtra.read(sensorValues);
  
  // order is 1,0,3,2
  
  // check right most sensor first
  if (sensorValues[2] >= cutoff[2]) {  // in the black
    angle -= 15;
  }
  if (sensorValues[3] >= cutoff[3] {
    if (sensorValues[1] < cutoff[1]) {  // left sensor still on line
      angle -= 15;
    }
    else if (sensorValues[2] < cutoff[2]) {  // right sensor still on line
      angle += 20;
    }
    else {  // backup everything is off the line
      dist = 2;
      angle = 0;
    }
  }
  
}
