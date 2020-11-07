#include <Servo.h>
Servo myservo;
unsigned long x,y = 0;
const int stepPiny = 3; 
const int stepPinx = 2; 
const int dirPiny = 6; 
const int dirPinx = 5;
int value = 0;


void moveaxialx(int distancex)
{ 
  for (y =0; y<distancex; y++) //distance = 8 
  {
    for (x=0 ; x<10000; x++)  // 10000pulse axis x move 2cm-0.7s
    {
      digitalWrite(stepPinx,HIGH); 
      delayMicroseconds(35); 
      digitalWrite(stepPinx,LOW); 
      delayMicroseconds(35);    
    }
  }
}
void moveaxialy(int distancey)
{
  for (y=0 ; y< distancey; y++) // distance = 7 
  {
    for (x=0;x<10000;x++)           //10000pulse axis y move 1cm-0.5s
    {
      digitalWrite(stepPiny,HIGH); 
      delayMicroseconds(25); 
      digitalWrite(stepPiny,LOW); 
      delayMicroseconds(25);
    }
  }
}
void penupdw()
{
      for (int pos = 90; pos< 125; pos+=1){
        myservo.write(pos);
        delay(5);
      }
      for (int pos = 124; pos >= 90 ; pos -=1){
        myservo.write(pos);
        delay(5);
      }
}
void setup() {
  Serial.begin(9600);
  // Sets the two pins as Outputs
  pinMode(stepPiny,OUTPUT); 
  pinMode(dirPiny,OUTPUT);
  pinMode(stepPinx,OUTPUT); 
  pinMode(dirPinx,OUTPUT);
  //set up pin servo
  myservo.attach(4);

}
void loop() {
if(Serial.available() > 0)
  {
      value = Serial.read();}
      
          if (value == '3') // x3 on position 1
          {
            digitalWrite(dirPinx,LOW); // axial x go forward
            moveaxialx(8);
            digitalWrite(dirPiny,LOW);// axial y go straight
            moveaxialy(6);
            penupdw(); 
            digitalWrite(dirPinx,HIGH); // aixal x go backward 
            moveaxialx(8);
            digitalWrite(dirPiny,HIGH);
            moveaxialy(6);
            value = 0;
          }
          if (value == '1')
          {
            digitalWrite(dirPinx,LOW);//axial x go forward
            moveaxialx(8);
            digitalWrite(dirPiny,HIGH); //axial y go backward
            moveaxialy(6);
            penupdw();
            digitalWrite(dirPinx,HIGH);//axial x go backward
            moveaxialx(8);
            digitalWrite(dirPiny,LOW); //axial y go reverse
            moveaxialy(6);
            value =0;
          }
          if (value == '4')
          {
            digitalWrite(dirPinx,LOW);//axial x go forward
            moveaxialx(5);
            digitalWrite(dirPiny,HIGH); //axial y go backward
            moveaxialy(6);
            penupdw();
            digitalWrite(dirPinx,HIGH);//axial x go backward
            moveaxialx(5);
            digitalWrite(dirPiny,LOW); //axial y go reverse
            moveaxialy(6);
            value =0;
          }
          if (value == '6')
          {
            digitalWrite(dirPinx,LOW);//axial x go forward
            moveaxialx(5);
            digitalWrite(dirPiny,LOW); //axial y go backward
            moveaxialy(6);
            penupdw();
            digitalWrite(dirPinx,HIGH);//axial x go backward
            moveaxialx(5);
            digitalWrite(dirPiny,HIGH); //axial y go reverse
            moveaxialy(6);
            value =0;
          }
          if (value == '7')
          {
            digitalWrite(dirPinx,LOW);//axial x go forward
            moveaxialx(2);
            digitalWrite(dirPiny,HIGH); //axial y go backward
            moveaxialy(6);
            penupdw();
            digitalWrite(dirPinx,HIGH);//axial x go backward
            moveaxialx(2);
            digitalWrite(dirPiny,LOW); //axial y go reverse
            moveaxialy(6);
            value =0;
          }
          if (value == '9')
          {
            digitalWrite(dirPinx,LOW);//axial x go forward
            moveaxialx(2);
            digitalWrite(dirPiny,LOW); //axial y go backward
            moveaxialy(6);
            penupdw();
            digitalWrite(dirPinx,HIGH);//axial x go backward
            moveaxialx(2);
            digitalWrite(dirPiny,HIGH); //axial y go reverse
            moveaxialy(6);
            value =0;
          }
          if (value == '2')
          {
            digitalWrite(dirPinx,LOW);//axial x go forward
            moveaxialx(8);         
            penupdw();
            digitalWrite(dirPinx,HIGH);//axial x go backward
            moveaxialx(8);
            value =0;
          }
          if (value == '5')
          {
            digitalWrite(dirPinx,LOW);//axial x go forward
            moveaxialx(5);         
            penupdw();
            digitalWrite(dirPinx,HIGH);//axial x go backward
            moveaxialx(5);
            value =0;
          }
          if (value == '8')
          {
            digitalWrite(dirPinx,LOW);//axial x go forward
            moveaxialx(2);         
            penupdw();
            digitalWrite(dirPinx,HIGH);//axial x go backward
            moveaxialx(2);
            value =0;
          }
} 
 
 
