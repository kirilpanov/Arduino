void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(11, HIGH);
  delay(1500);
  digitalWrite(11, LOW);
  delay(500);
  digitalWrite(10, HIGH);
  delay(1500);
  digitalWrite(10, LOW);
  delay(500);
  digitalWrite(9, HIGH);
  delay(1500);
  digitalWrite(9, LOW);
  delay(500);
}
