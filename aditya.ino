#include <Servo.h>

char btvalue=0;
int pump1=10;
int pump2=11;
Servo myservo;

void setup() {
  pinMode(pump1,OUTPUT);
  pinMode(pump2,OUTPUT);
  myservo.attach(7);
  myservo.write(90);
  Serial.begin(9600);
}

int food=0;
int water=0;

void loop() {
  digitalWrite(pump1,HIGH);
  digitalWrite(pump2,HIGH);

  int i=0;
  while (i!=5){
    if(Serial.available() > 0){
      btvalue= Serial.read();
      if(btvalue == 'w'){
        water=1;
      } else if(btvalue == 'f'){ 
        food=1;
      }
    }

    if (water==1){
      digitalWrite(pump1,HIGH);
      digitalWrite(pump2,LOW);
      delay(20000);
      digitalWrite(pump1,HIGH);
      digitalWrite(pump2,HIGH);
      water=0;
    }
    if (food==1){
      myservo.write(180);
      delay(2000);
      myservo.write(90);
      delay(100);
      food=0;
    }

  }
}
