const int LED=3;  //The number of LED pin
const long interval=1000;  //interval at which to blink (miliseconds)
const long limit=3000;    //time limit -after which user will get a message 

//Variables that will change:
unsigned long timer=0;
int ledState=LOW;
int light=A0;
int sensorValue=0;
int counter=0;


void setup() {
  // put your setup code here, to run once:
  //Set the pins as input and output:
  pinMode(light,INPUT);
  pinMode(LED,OUTPUT);
//  Serial.begin(115200);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(light);


  if(sensorValue>=100){

    timer=timer+interval;
    Serial.println(timer);
    if(timer>=limit){
      counter++;
      Serial.println("The child cried for 4 seconds|counter:");
      Serial.println(counter);//If timer is over limit say this...
    }
    
    if(counter>=2){
      digitalWrite(LED,OUTPUT);  
       Serial.println("The LED is ON now");       //If timer is over limit say this...
       
    }

//      if(counter==3){
//      digitalWrite(LED,OUTPUT);  
//       Serial.println("The LED is on now");       //If timer is over limit say this...
//    }
 
    
 



}else{
   delay(2000);
    if(sensorValue<100){
      timer=0;
      counter=0;
    digitalWrite(LED,LOW);
    Serial.println("The LED is OFF ");
    Serial.println(timer);
    Serial.println(counter);
    Serial.println(sensorValue);
    }
    
  }}
