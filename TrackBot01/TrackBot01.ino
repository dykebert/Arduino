
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
int angle = 0;
int dist = 0;

unsigned int cutoffs[NUM_SENSORS] = {155, 4, 300, 155};

void setup() {
  // put your setup code here, to run once:
  MyMiP.init(); //Serial port is configured for 115200
  Serial.print("MiP is Alive!!!");
  delay(100); //Need a delay to let the buffer clear

  delay(2000); 
  MyMiP.playSingleSound(BURP);  //Make burp sound
  delay(100);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  angle = 0;
  dist = 4;
  
  qtra.read(sensorValues);
  
  // order is 1,0,3,2
  
  if (sensorValues[0] < cutoffs[0] && sensorValues[3] < cutoffs[3]) {  // on the line
    angle = 0;
  }
  else {
    if (sensorValues[0] >= cutoffs[0] && sensorValues[3] >= cutoffs[3]) {  // off the line so backup
      dist = -2;
      angle = 0;
    }
    else if (sensorValues[2] >= cutoffs[2] && sensorValues[0] >= cutoffs[0]) {  // 2 left sensors are off the line
        angle = 30;
    }
    else if (sensorValues[2] >= cutoffs[2] && sensorValues[3] >= cutoffs[3]) {  // 2 right sensors are off the line
        angle = -20;
    }
      else if (sensorValues[3] >= cutoffs[3]) {  // right sensor is in the black
        angle = -15;
    }
      else if (sensorValues[0] >= cutoffs[0]) {  // left sensor is in the black
        angle = 15;
    }
 
   }
//  Serial.print(dist);
  //Serial.print('\t');
  //Serial.println(angle);
  MyMiP.distanceDrive(dist, angle); 
  delay(100);
  MyMiP.stop();
  delay(100);
}
