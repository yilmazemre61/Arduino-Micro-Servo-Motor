// C++ code
// Emre YILMAZ
// 03.08.2021

// LIBRARY
#include <Servo.h>

Servo myservo;

int degree;

// BUTTONS
int button1 = 5; // button 1 is set to pin 5
int button2 = 6; // button 2 is set to pin 6

// LED
int redLed = 9; // red led is set to pin 9
int blueLed = 10; // blue led is set to pin 10
int greenLed = 11; // green led is set to pin 11

// Delay Time
int dt1 = 500;
int dt2 = 375;

void setup()
{
  myservo.attach(4);
  myservo.write(0); // at the begining I set the position for 0 degree
  Serial.begin(9600);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop()
{
  // button 1
  
  if(digitalRead(button1) == HIGH){
    Serial.print("Button : ");
    Serial.println("1");
    degree += 45; // Each time we press the button 1, degree will be increased by 45
    Serial.print("Degree : ");
    Serial.println(degree);

    if(degree == 45){ // sets the position for 45 degree and turns on the red led
      myservo.write(degree);
      digitalWrite(redLed, HIGH);
      digitalWrite(blueLed, LOW);
      digitalWrite(greenLed, LOW);
      delay(dt1);
    }else if(degree == 90){ // sets the position for 90 degree and turns on the blue led
      myservo.write(degree);
      digitalWrite(blueLed, HIGH);
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, LOW);
      delay(dt1);
    }else if(degree == 135){ // sets the position for 135 degree and turns on the green
      myservo.write(degree);
      digitalWrite(greenLed, HIGH);
      digitalWrite(blueLed, LOW);
      digitalWrite(redLed, LOW);
      delay(dt1);
    }else if(degree == 180){ // sets the position for 180 degree and turns on the purple
      myservo.write(degree);
      digitalWrite(redLed, HIGH);
      digitalWrite(blueLed, HIGH);
      digitalWrite(greenLed, LOW);
      delay(dt1);
    }
    if(degree == 225){ // if the position is at the 180 degree and we press the button 1 
      // it will set the degree for position 0 and tunr on all the colors consecutively 
      degree = 0;
      myservo.write(degree);
      digitalWrite(redLed, HIGH);
      digitalWrite(blueLed, LOW);
      digitalWrite(greenLed, LOW);
      delay(dt2);
      digitalWrite(blueLed, HIGH);
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, LOW);
      delay(dt2);
      digitalWrite(greenLed, HIGH);
      digitalWrite(blueLed, LOW);
      digitalWrite(redLed, LOW);
      delay(dt2);
      digitalWrite(redLed, HIGH);
      digitalWrite(blueLed, HIGH);
      digitalWrite(greenLed, LOW);
      delay(dt2);
      Serial.print("Degree : ");
      Serial.println(degree);
    }
  }
 
  // button 2
  
  if(digitalRead(button2) == HIGH){
    Serial.print("Button : ");
    Serial.println("2");
    degree -= 45; // Each time we press the button 1, degree will be decreased by 45
    Serial.print("Degree : ");
    Serial.println(degree);

    if(degree == 0){ // sets the position for 0 degree and turns on the purple
      myservo.write(degree);
      digitalWrite(redLed, HIGH);
      digitalWrite(blueLed, HIGH);
      digitalWrite(greenLed, LOW);
      delay(dt1);
    }else if(degree == 45){ // sets the position for 45 degree and turns on the red led
      myservo.write(degree);
      digitalWrite(redLed, HIGH);
      digitalWrite(blueLed, LOW);
      digitalWrite(greenLed, LOW);
      delay(dt1);
    }else if(degree == 90){ // sets the position for 90 degree and turns on the blue led
      myservo.write(degree);
      digitalWrite(blueLed, HIGH);
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, LOW);
      delay(dt1);
    }else if(degree == 135){ // sets the position for 135 degree and turns on the green led
      myservo.write(degree);
      digitalWrite(greenLed, HIGH);
      digitalWrite(blueLed, LOW);
      digitalWrite(redLed, LOW);
      delay(dt1);
    }
    // there will be no position for 180 degree for button1
    if(degree == -45){ // if the position is at the 0 degree and we press the button 2
      // it will set the for the position 180 and turn on all the colors consecutively
      degree = 180;
      myservo.write(degree);
      myservo.write(degree);
      digitalWrite(redLed, HIGH);
      digitalWrite(blueLed, LOW);
      digitalWrite(greenLed, LOW);
      delay(dt2);
      digitalWrite(blueLed, HIGH);
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, LOW);
      delay(dt2);
      digitalWrite(greenLed, HIGH);
      digitalWrite(blueLed, LOW);
      digitalWrite(redLed, LOW);
      delay(dt2);
      digitalWrite(redLed, HIGH);
      digitalWrite(blueLed, HIGH);
      digitalWrite(greenLed, LOW);
      delay(dt2);
      Serial.print("Degree : ");
      Serial.println(degree);
    }
  }
  

}


  
  
  
  
  
