#define trig 7
#define echo 6
#define buzzer 10
void setup() {
pinMode(9,OUTPUT);
pinMode(8,OUTPUT);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(buzzer,OUTPUT);
digitalWrite(9,HIGH);
digitalWrite(8,LOW);
}
void loop() 
{ long duration,distance;
digitalWrite(trig,LOW);
delay(2);
digitalWrite(trig,HIGH);
delay(5);
digitalWrite(trig,LOW);
duration = pulseIn(echo,HIGH);
distance = (duration/2)*0.0343;
digitalWrite(buzzer,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
if (distance < 30)//Cambiando este valor regulas la ditancia del sensor
{
digitalWrite(buzzer,HIGH);
digitalWrite(8,LOW);
digitalWrite(9,HIGH);
delay(50);
}
else
{
digitalWrite(buzzer,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
}
} 