int pump1=10;
int pump2=11;

void setup() {
  pinMode(pump1,OUTPUT);
  pinMode(pump2,OUTPUT);

}

void loop() {
  digitalWrite(pump1,HIGH); //pump is stopped
  digitalWrite(pump2,HIGH);
  
  delay(1000); //wait for one second

  digitalWrite(pump1,HIGH); //pump on
  digitalWrite(pump2,LOw);

  delay(5000); //runs for 5 seconds
  //loops over

}
