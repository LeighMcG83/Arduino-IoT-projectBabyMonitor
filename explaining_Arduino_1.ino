void setup() {
  // put your setup code here, to run once:
  //tell it that we are working with pin 13 => pinMode(which pin,we are telling the arduno that we want pin 13 as an OUTPUT
  pinMode(13,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //tell the ardino to turn the light on cos we are working with a light in this example so we write => 
  //digitalWrite(what pin we wanna write to,do we wanna turn it on or off , we want it on so we will set it to "HIGH" and high means 5 volts
  //we click on the right arrow at the top of this software to upload the code to our arduino 
  digitalWrite(13,HIGH);

  //we turn the light off by the folllowing code => digitalWrite(13,LOW);  digitalWrite(pinNum,HIGH/LOW);
  //to make the light blink we can write:
  //digitalWrite(13,HIGH); and the right after it
  //digitalWrite(13,LOW); but this will make the arduino turn off and on the light so quick to the extend that we wont be able to see it so we need to add a delay 
  //command which is this =>delay(1000); the time is in miliseconds  so our code will be like this bellow:
  //digitalWrite(13,HIGH);
  //delay(1000);
  //digitalWrite(13,LOW);
  //delay(1000);//1000miliseconds=1 second


  //assignment write a programe to blink fast and see how quickly you can make it blink  where your eyes still see that it is blinking @@@ 
  //next assignment is to make diffrent LEDs blink in diffrent times and repeat..@@@








































  

}
