void setup() {
  
  pinMode(13, OUTPUT);
  
}

void loop() {
  
  digitalWrite(13, HIGH);
  delayMicroseconds(100);
  digitalWrite(13, LOW);
  delayMicroseconds(4000);      // to lower brightness
  
}
