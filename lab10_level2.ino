// C++ code
// Emre YILMAZ
// 03.08.2021

#include <Servo.h>

Servo myservo;

int degree = 0;
int button1 = 9; // button 1 is set to pin 9
int button2 = 10; // button2 is set to pin 10

void setup()
{
  myservo.attach(4);
  myservo.write(0); // at the begining i set the position for 0 degree
  Serial.begin(9600);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  
}

void loop()
{
  
  if(digitalRead(button1)==HIGH){ // it will increase the position 45 degree
    Serial.println("1");
    degree += 45;
    if(degree > 180){ // if the degree is 180 and we press the button 1 the degree's value will be 225
      // and if we press the button 2 it will decrease it to 180 and we have to press again to get it to position 135 degree
      // this code block will prevent that error
      degree = 180; 
    }
    Serial.println(degree);
    myservo.write(degree);
    delay(500);
    
  }
  if(digitalRead(button2)== HIGH){ // it will decrease the position 45 degree
    Serial.println("2");
    degree -= 45;
    if(degree < 0){ // if the degree is 0 and we press the button 2 the degree's value will be -45
      // and if we press the button 1 it will increase it to 0 and we have to press again to get it to position 45 degree
      // this code block will prevent that error
      degree = 0; 
    }
    Serial.println(degree);
    myservo.write(degree);
    delay(500);
  }
  
}










