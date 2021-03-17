const int LED=3;  //The number of LED pin
const long interval=1000;  //interval at which to blink (miliseconds)
const long limit=2000;    //time limit -after which user will get a message 

//Variables that will change:
unsigned long timer=0;
int sound=A0;
int sensorValue=0;
int counter=0;
int value=200;


void setup() {
  // put your setup code here, to run once:
  //Set the pins as input and output:
  pinMode(sound,INPUT);
  pinMode(LED,OUTPUT);
//  Serial.begin(115200);
  Serial.begin(9600);

}

void loop() {
sensorValue=0;
delay(1000);
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(sound);

  if(sensorValue>=value){

    timer=timer+interval;
    Serial.println(sensorValue); 
    Serial.println(timer);
   
    if(timer>=limit){
      counter++;
      Serial.println("Counter incremented");
    }
    
    if(counter>=2){
      digitalWrite(LED,OUTPUT);  
       Serial.println("The LED is ON now");       //If timer is over limit say this...
       counter=0;
    }
    if(counter>=3){
      
    }
}else{
  timer=0;
   delay(2000);
    
    if(sensorValue<value){
        Serial.println(sensorValue);
      timer=0;
      counter=0;
   
    digitalWrite(LED,LOW);
    Serial.println("The LED is OFF ");
   
    }
   
    
  }}
