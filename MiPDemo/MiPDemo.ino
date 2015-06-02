#include "MiP_commands.h"

MiP MyMiP(2);

void setup(){

  MyMiP.init(); //Serial port is configured for 115200
  Serial.print("MiP is Alive!!!");
  delay(100); //Need a delay to let the buffer clear before sending new commands
  delay(1000);
}

void loop() {

MyMiP.playSingleSound(BURP);  //Make burp sound
delay(100);
MyMiP.distanceDrive(4, 0);  //Drive +20 cm and turn 45 degrees
delay(200);
MyMiP.distanceDrive(4, 20);  //Drive +20 cm and turn 45 degrees
delay(200);
MyMiP.distanceDrive(4, -20);  //Drive +20 cm and turn 45 degrees
delay(200);
MyMiP.stop();
delay(100);
//MyMiP.distanceDrive(-4, 0);  //Drive +20 cm and turn 45 degrees
//loop_LEDs();  //built function to blink LED's

//delay(100);

}

void loop_LEDs(){

    MyMiP.setChestLED(255, 0, 0); //Set LED to RED
    delay(200);
    MyMiP.setChestLED(0, 255, 0); //Set LED to GREEN
    delay(200);
    MyMiP.setChestLED(0, 0, 255); //Set LED to BLUE
    delay(200);

}

