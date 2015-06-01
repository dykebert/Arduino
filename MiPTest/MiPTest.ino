



void setup()
{
//Setup Serial1 for correct baud rate
Serial.begin(9600);
Serial1.begin(115200);

Serial.println("Hello!!");

int numBytes = -1;
//Send init command
//Serial1.write(0xFF);
//delay(30); // delay in between reads for stability

if (Serial1) {
  Serial.println("MIP READY");
}
else {
  Serial.println("No No No");
}
Serial.println("Sending 0x14");
byte inByte;
Serial1.write(0x14);
numBytes = Serial1.available();
Serial.print("Bytes available = ");
Serial.println(numBytes);
delay(30);
numBytes = Serial1.available();
Serial.print("Bytes available = ");
Serial.println(numBytes);
delay(30);
numBytes = Serial1.available();
Serial.print("Bytes available = ");
Serial.println(numBytes);
byte buffer2[5];
if (Serial1.available()) {
     Serial1.readBytes(buffer2,5);
}

  for (int i = 0; i < sizeof(buffer2) - 1; i++){
    Serial.print("buffer 2 ");
    Serial.print(i);
    Serial.print(" = ");
    Serial.print(buffer2[i], HEX);
    Serial.print(" (");
    Serial.print(buffer2[1]);
    Serial.println(")");
  }
Serial.println();
Serial.println("Sending 0x83");
Serial1.write(0x83);
numBytes = Serial1.available();
Serial.print("Bytes available = ");
Serial.println(numBytes);
delay(30);
numBytes = Serial1.available();
Serial.print("Bytes available = ");
Serial.println(numBytes);

byte buffer1[6];
if (Serial1.available()) {
     Serial1.readBytes(buffer1,6);
}

int ndx=0;
  for (int i = 0; i < sizeof(buffer1) - 1; i++){
    Serial.print("buffer ");
    Serial.print(i);
    Serial.print(" = ");
    Serial.print(buffer1[i], HEX);
    Serial.print(" (");
    Serial.print(buffer1[1]);
    Serial.println(")");

  }
//Send command to blink chest green
Serial1.write(0x84);
Serial1.write(0xFF);
Serial1.write(0x01);
Serial1.write(0x01);
//Serial1.write(0x01);
//Serial1.write(0x10);
delay(30000);

//Send command to sleep
Serial1.write(0xFA);
Serial.println("DONE");
}

void loop() // run over and over
{
 
}

