int red = 7;
int yellow = 8;
int blue = 9;
void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  digitalWrite(red, HIGH);
  delay(5000);
  
  digitalWrite(yellow, HIGH);

  for(int i = 0; i < 3; i++){
    delay(500);
    digitalWrite(yellow, HIGH);
    delay(500);
    digitalWrite(yellow, LOW);
    
  }
  
  digitalWrite(red, LOW);
  delay(250);
  digitalWrite(blue, HIGH);
  delay(4000);
  
  for(int i = 0; i < 3; i++){
    digitalWrite(blue, LOW);
    delay(350);
    digitalWrite(blue, HIGH);
    delay(350);
    
  }
  
  delay(150);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, HIGH);
  delay(1500);
  digitalWrite(yellow, LOW);
  
}
