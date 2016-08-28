//SONIC PI RUN/STOP CONTROLLER
//Juneau Projects
//N.B. Make sure you are using an Arduino Leonardo
#include <Keyboard.h>


//Sensor1
const int sensorPin1 = A0;    // select the input pin for the potentiometer
int prevSensorValue1 = 0;  // variable to store the value coming from the sensor
int sensorValue1 = 0;  // variable to store the value coming from the sensor
boolean triggered1 = false;
boolean takeTriggerTime1 = false;
//the time when the sensor outputs a low impulse
long unsigned int lowIn1;


//Sensor2
const int sensorPin2 = A1;    // select the input pin for the potentiometer
int prevSensorValue2 = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0;  // variable to store the value coming from the sensor
boolean triggered2 = false;
boolean takeTriggerTime2 = false;
//the time when the sensor outputs a low impulse
long unsigned int lowIn2;


//Sensor3
const int sensorPin3 = A2;    // select the input pin for the potentiometer
int prevSensorValue3 = 0;  // variable to store the value coming from the sensor
int sensorValue3 = 0;  // variable to store the value coming from the sensor
boolean triggered3 = false;
boolean takeTriggerTime3 = false;
//the time when the sensor outputs a low impulse
long unsigned int lowIn3;


//the amount of milliseconds the sensor has to be low 
//before we assume all motion has stopped
long unsigned int pause = 2000;  

char ctrlKey = KEY_LEFT_ALT; //if you are using this code with a mac you will need to change KEY_LEFT_CTRL
// to KEY_LEFT_GUI
char del = KEY_BACKSPACE;




void setup() {
  delay(3000);
  Keyboard.begin();

  
  Keyboard.press('r');
  Keyboard.press('e');
  Keyboard.press('a');
  Keyboard.press('d');
  Keyboard.press('y');
  Keyboard.releaseAll();
}

void loop() {
  // read the value from the sensor:
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  sensorValue3 = analogRead(sensorPin3);
  
  if(prevSensorValue1==0){
    prevSensorValue1=sensorValue1;
  }

  if(prevSensorValue2==0){
    prevSensorValue2=sensorValue2;
  }

  if(prevSensorValue3==0){
    prevSensorValue3=sensorValue3;
  }
  
   if (abs(sensorValue1 - prevSensorValue1)>100) {
      if(!triggered1){
        triggered1=true;
        Keyboard.press(ctrlKey);
        Keyboard.press('a');
        Keyboard.releaseAll();
        Keyboard.press(del);
        delay (1);
        Keyboard.releaseAll();
        delay (1);
        Keyboard.println("button1");
        delay (1);
        Keyboard.press(ctrlKey);
        Keyboard.press('r');
        delay (1); 
        Keyboard.releaseAll();
        takeTriggerTime1 = true;
      }
  }

  if (abs(sensorValue2 - prevSensorValue2)>100) {
      if(!triggered2){
        triggered2=true;
        Keyboard.press(ctrlKey);
        Keyboard.press('a');
        Keyboard.releaseAll();
        Keyboard.press(del);
        delay (1);
        Keyboard.releaseAll();
        delay (1);
        Keyboard.println("button2");
        delay (1);
        Keyboard.press(ctrlKey);
        Keyboard.press('r');
        delay (1); 
        Keyboard.releaseAll();
        takeTriggerTime2 = true;
      }
  }

  if (abs(sensorValue3 - prevSensorValue3)>100) {
      if(!triggered3){
        triggered3=true;
        Keyboard.press(ctrlKey);
        Keyboard.press('a');
        Keyboard.releaseAll();
        Keyboard.press(del);
        delay (1);
        Keyboard.releaseAll();
        delay (1);
        Keyboard.println("button3");
        delay (1);
        Keyboard.press(ctrlKey);
        Keyboard.press('r');
        delay (1); 
        Keyboard.releaseAll();
        takeTriggerTime3 = true;
      }
  }

  if(takeTriggerTime1){
    lowIn1 = millis();          //save the time of the transition from high to LOW
    takeTriggerTime1 = false;       //make sure this is only done at the start of a LOW phase
  }

  if(takeTriggerTime2){
    lowIn2 = millis();          //save the time of the transition from high to LOW
    takeTriggerTime2 = false;       //make sure this is only done at the start of a LOW phase
  }

  if(takeTriggerTime3){
    lowIn3 = millis();          //save the time of the transition from high to LOW
    takeTriggerTime3 = false;       //make sure this is only done at the start of a LOW phase
  }

    //if the sensor is low for more than the given pause, 
   //we assume that no more motion is going to happen
   if(triggered1 && millis() - lowIn1 > pause){  
    triggered1=false;
   }

   if(triggered2 && millis() - lowIn2 > pause){  
    triggered2=false;
   }

   if(triggered3 && millis() - lowIn3 > pause){  
    triggered3=false;
   }
  
  prevSensorValue1=sensorValue1;
  prevSensorValue2=sensorValue2;
  prevSensorValue3=sensorValue3;
  delay(10);
  
  //Keyboard.releaseAll();
  //delay(10);
//if you find your buttons are triggering erratically then uncomment the two lines above
}

