#include "application.h"
PRODUCT_ID(PLATFORM_ID);
PRODUCT_VERSION(2);
//SYSTEM_MODE(AUTOMATIC);
SYSTEM_MODE(MANUAL);


int LED_PIN1 = D6; 
int LED_PIN2 = D7; 

int photoresistor = A0;

int power = A5;

int analogvalue, bgLight; 

int isOn = 0;


void setup() {
  Serial.begin(9600);
  
    pinMode(LED_PIN1,OUTPUT); // Our LED pin is output (lighting up the LED)
    pinMode(LED_PIN2,OUTPUT); // Our LED pin is output (lighting up the LED)
    pinMode(photoresistor,INPUT);  // Our photoresistor pin is input (reading the photoresistor)
    pinMode(power,OUTPUT); // The pin powering the photoresistor is output (sending out consistent power)

    digitalWrite(power,HIGH);

    bgLight = analogRead(photoresistor);

    //    Particle.function("led",ledToggle);

}

void ledToggle(void) {

  //Serial.print("isOn==");
  //Serial.println(isOn,DEC);
  digitalWrite(LED_PIN1,!isOn);
  isOn = !isOn;

}

// Next is the loop function...

void loop() {

    // check to see what the value of the photoresistor is and store it in the int variable analogvalue
    analogvalue = analogRead(photoresistor);
    Serial.println(analogvalue,DEC);

    // if light level < 100 of background found at beginning
    if (bgLight - analogvalue > 100) {
      digitalWrite(LED_PIN2,HIGH);
      ledToggle();
    } else {
      digitalWrite(LED_PIN1,LOW);
      digitalWrite(LED_PIN2,LOW);
    }
    delay(500);

}


