
#define NUM_SENSORS             4  // number of sensors used
#define NUM_SAMPLES_PER_SENSOR  4  // average 4 analog samples per sensor reading
#define EMITTER_PIN             QTR_NO_EMITTER_PIN  // emitter is controlled by digital pin 2


unsigned char _pins[4] = {0,1,2,3};

unsigned int sensorValues[NUM_SENSORS];

void setup() {
  // put your setup code here, to run once:
  
  delay(500);
  Serial.begin(9600);
  analogReference(DEFAULT);
  delay(1000);
  
 

}

void loop() {
  // put your main code here, to run repeatedly:
  
  readSensors(sensorValues);
   for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t'); // tab to format the raw data into columns in the Serial monitor
  }
  Serial.println();
  
  delay(250);

}



void readSensors(unsigned int *sensor_values)
{
  uint8_t _numSensors = NUM_SENSORS;
  uint8_t _numSamplesPerSensor = NUM_SAMPLES_PER_SENSOR;
    unsigned char i, j;

   // reset the values
    for(i = 0; i < _numSensors; i++)
        sensor_values[i] = 0;

    for (j = 0; j < _numSamplesPerSensor; j++) 
    {
      analogRead(_pins[3]);
        for (i = 0; i < _numSensors; i++)
        {
          delay(5);
            sensor_values[i] += analogRead(_pins[i]);   // add the conversion result
        }
    }

    // get the rounded average of the readings for each sensor
    for (i = 0; i < _numSensors; i++)
        sensor_values[i] = (sensor_values[i] + (_numSamplesPerSensor >> 1)) /
            _numSamplesPerSensor;
}


