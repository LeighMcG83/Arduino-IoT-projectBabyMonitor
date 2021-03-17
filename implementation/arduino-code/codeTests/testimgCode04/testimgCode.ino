
 int PIEZO_PIN = A0;

void setup() {
    Serial.begin(9600);
   
}
 
void loop() {

  
     int sensorState = analogRead(PIEZO_PIN);
    Serial.println(sensorState);
    
    delay(300);

}
