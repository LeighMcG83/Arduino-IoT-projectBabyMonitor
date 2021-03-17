const int LED=3;  //The number of LED pin
const long interval=1000;  //interval at which to blink (miliseconds)
const long limit=2000;    //time limit -after which user will get a message 
const int led2=4;
const int led3=5;

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
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
//  Serial.begin(115200);
  Serial.begin(9600);

}

void loop() {
sensorValue=0;
delay(1000);
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(sound);
  if(sensorValue>=200){
    Serial.println("Sensor value :");
    Serial.println(sensorValue);
    timer=timer+interval;
    if(timer>=limit){
      counter++;
      timer=0;
    }
  }else{
    Serial.println("Waiting 2 second");
   
    if(sensorValue<200){
       timer=0;
    counter=0;
    }
    Serial.println("Value after else:");
    Serial.println(sensorValue);
    Serial.println(counter);
   
  }

 if(counter==1){
  digitalWrite(LED,HIGH);
  delay(2000);
  digitalWrite(LED,LOW);
 }else if(counter==2){
    digitalWrite(led2,HIGH);
    Serial.println("First Led IsOn");
    //delay(3000);
    digitalWrite(led2,LOW);
    
  }else if(counter>=3){
    digitalWrite(led3,HIGH);
     digitalWrite(led2,HIGH);
    Serial.println("Second Led IsOn");
    delay(5000);
     digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
    counter=0;
    timer=0;
  }
}