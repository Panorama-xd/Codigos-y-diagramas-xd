#include <Servo.h>
Servo servo1;
Servo servo2;
int eje1=90;
int eje2=90;
void setup(){  
  servo1.attach(7);
  servo2.attach(6);
  servo1.write(90);
  servo2.write(90);
}
void loop(){
  //SERVO 1
  if (analogRead(0)<200 && eje1<180){
    eje1++;
    servo1.write(eje1);
  }
  if (analogRead(0)>700 && eje1>0){
    eje1--;
    servo1.write(eje1);
  }
  //SERVO 2
  if (analogRead(1)<200 && eje2<180){
    eje2++;
    servo2.write(eje2);
  }
  if (analogRead(1)>700 && eje2>0){
    eje2--;
    servo2.write(eje2);
  }
  delay(15);
}