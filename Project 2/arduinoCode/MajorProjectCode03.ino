const int LED=3;  //Led to approve that the first event happened 
const long interval=1000;  //interval at which to blink (miliseconds)
const long limit=1000;    //time limit -after which user will get a message 
const int led2=4;         //Led to approve that the second event happened 
const int led3=5;         //Led to approve that the third event happened 
const int speakerPin=8;   //the buzzer pin 
//Speaker  this code will be for the speaker ... we are  not usingit in this project because we don't have a speaker /we are using a buzzer instead
//#include <PCM.h>
//const unsigned char kidsong[] PROGMEM = {
//123, 119, 120, 120, 119, 119, 124, 129, 130, 125, 119, 116, 118, 121, 123, 124, 121, 117, 117, 119, 120, 118, 118, 123, 128, 127, 120, 115, 117, 122, 124, 120, 118, 120, 123, 124, 125, 125, 123, 119, 115, 115, 118, 122, 122, 120, 120, 121, 123, 122, 122, 123, 125, 127, 127, 124, 121, 120, 120, 119, 117, 118, 124, 130, 130, 126, 123, 124, 126, 125, 124, 126, 129, 130, 129, 128, 128, 124};


//Variables that will change:
unsigned long timer=0;
unsigned long myTime;  //checking the time since the programe is started 
int sound=A0;
int temp=A1;
int sensorValue=0;
int counter=0;
int value=160;
int tempValue=0;
int speakerValue=0;


//tones for the buzzer song
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978


#include <BridgeServer.h>
#include <BridgeClient.h>

#include <Bridge.h>
#define BLYNK_PRINT Serial


/* Comment this out to disable prints and save space */
#define BLYNK_PRINT DebugSerial


// You could use a spare Hardware Serial on boards that have it (like Mega)
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX

#include <BlynkSimpleStream.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "OcAygWhp8Y9RuFAECQaKupw-DlOXoLGn";

void setup() {
 
    Blynk.email("jalenoss22@gmail.com", "The kid is awake");
 Blynk.email("jalenoss22@gmail.com", "ESP8266 Alert", "Temperature over 28C!");
  // put your setup code here, to run once:
  //Set the pins as input and output:
  pinMode(sound,INPUT);
  pinMode(LED,OUTPUT);
  pinMode(led2,OUTPUT);
   Bridge.begin();
  pinMode(led3,OUTPUT);
   Blynk.begin(Serial, auth);
  pinMode(tempValue,INPUT);
//  Serial.begin(115200);]
 Serial.begin(9600);
  

}

void loop() {
  // Initialize the client library
Blynk.run();
digitalWrite(led2,HIGH);
Blynk.notify("KID IS AWAKE");
 sensorValue=0;
 delay(1000);
  sensorValue=analogRead(sound);   //Reading the sound sensor
   Blynk.virtualWrite(V1, sensorValue);
  tempValue=analogRead(temp);     //Reading the sound sensor
  Blynk.virtualWrite(V2,  tempValue);
  if(sensorValue>=95){    
    Blynk.notify("KID IS AWAKE, LULLABY ON!");//Checking if sensor value is greater than 200
    Serial.println("Sensor value :");
    Serial.println(sensorValue);
    timer=timer+interval;     //if the sensor value is >200 it will add an interval which is equal to 1000
    if(timer>=limit){
      counter++;
      timer=0;
    }
  }else{
    Serial.println("Waiting 2 seconds");
   delay(2000);
    if(sensorValue<95){
       timer=0;
    counter=0;
    Serial.println("All off now");
    
    digitalWrite(led3,LOW);
      digitalWrite(LED,LOW);
    }
  }

 if(counter==1){                                      //Event 1
  digitalWrite(LED,HIGH);
  Serial.println("Event 1 now");
Blynk.virtualWrite(V2,  tempValue);
   Blynk.virtualWrite(V1, sensorValue);
 }else if(counter==2){                                //Event 2
    
Blynk.virtualWrite(V2,  tempValue);
   Blynk.virtualWrite(V1, sensorValue);
Serial.println("event 2 now");
 Blynk.notify("Kid is awake ,Lights on!");
    if(sensorValue>=value){
      counter++;
    }else{ //////////Working here
    
      digitalWrite(led3,LOW);
      counter=0;
        timer=0;
    }
 
  }else if(counter>=3){   
    GameOfThrones();//Event 3
    digitalWrite(led3,HIGH);
     Blynk.notify("Kid is awake ,Lullaby is on!");
    Serial.println("Event 3 now"); 
    Blynk.virtualWrite(V2,  tempValue);
   Blynk.virtualWrite(V1, sensorValue);
   
    delay(2000);
    if(sensorValue<value){
      
      digitalWrite(led3,LOW);
      Serial.println(tempValue);
       counter=0;
        timer=0;
    }

  }}//End of loop


  //Methods 
  void GameOfThrones()
  {
    for(int i=0; i<4; i++)
    {
    tone(speakerPin, NOTE_G4);
    delay(500);
    noTone(speakerPin);
    tone(speakerPin, NOTE_C4);
    delay(500);
    noTone(speakerPin);
    tone(speakerPin, NOTE_DS4);
    delay(250);
    noTone(speakerPin);
    tone(speakerPin, NOTE_F4);
    delay(250);
    noTone(speakerPin);
    }
    for(int i=0; i<4; i++)
    {
    tone(speakerPin, NOTE_G4);
    delay(500);
    noTone(speakerPin);
    tone(speakerPin, NOTE_C4);
    delay(500);
    noTone(speakerPin);
    tone(speakerPin, NOTE_E4);
    delay(250);
    noTone(speakerPin);
    tone(speakerPin, NOTE_F4);
    delay(250);
    noTone(speakerPin);
    }
        tone(speakerPin, NOTE_G4);
        delay(500);
        noTone(speakerPin);
        tone(speakerPin, NOTE_C4);
        delay(500);
        tone(speakerPin, NOTE_DS4);
        delay(250);
        noTone(speakerPin);
        tone(speakerPin, NOTE_F4);
        delay(250);
        noTone(speakerPin);
        tone(speakerPin, NOTE_D4);
        delay(500);
        noTone(speakerPin);
    for(int i=0; i<3; i++)
    {
    tone(speakerPin, NOTE_G3);
    delay(500);
    noTone(speakerPin);
    tone(speakerPin, NOTE_AS3);
    delay(250);
    noTone(speakerPin);
    tone(speakerPin, NOTE_C4);
    delay(250);
    noTone(speakerPin);
    tone(speakerPin, NOTE_D4);
    delay(500);
    noTone(speakerPin);
    }//
        tone(speakerPin, NOTE_G3);
        delay(500);
        noTone(speakerPin);
        tone(speakerPin, NOTE_AS3);
        delay(250);
        noTone(speakerPin);
        tone(speakerPin, NOTE_C4);
        delay(250);
        noTone(speakerPin);
        tone(speakerPin, NOTE_D4);
        delay(1000);
        noTone(speakerPin);
        
        tone(speakerPin, NOTE_F4);
        delay(1000);
        noTone(speakerPin);
        tone(speakerPin, NOTE_AS3);
        delay(1000);
        noTone(speakerPin);
        tone(speakerPin, NOTE_DS4);
        delay(250);
        noTone(speakerPin);
        tone(speakerPin, NOTE_D4);
        delay(250);
        noTone(speakerPin);
        tone(speakerPin, NOTE_F4);
        delay(1000);
        noTone(speakerPin);
        tone(speakerPin, NOTE_AS3);
        delay(1000);
        noTone(speakerPin);
        tone(speakerPin, NOTE_DS4);
        delay(250);
        noTone(speakerPin);
        tone(speakerPin, NOTE_D4);
        delay(250);
        noTone(speakerPin);
        tone(speakerPin, NOTE_C4);
        delay(500);
        noTone(speakerPin);
  
    }//End of GameOfThrones Method
