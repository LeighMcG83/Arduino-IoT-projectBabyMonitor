/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
  
  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe
      
  modified by Leigh McGuinness on 05/02/21
  
*/

int LEDpin = 4;                   // Assign LEDpin to D3


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
}
// the loop routine runs over and over again forever:
void loop() {
  
  int sensorValue = analogRead(A0);   // read the input on analog pin 0
  
  
  if (sensorValue > 500){             // check if pin A0 is greater thsn 500
    digitalWrite(LEDpin, HIGH);       // turn the LED on @ high voltage
    delay(500);                       // 1/2 second pause
    digitalWrite(LEDpin, LOW);        // Turn off the LED
  }
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}
