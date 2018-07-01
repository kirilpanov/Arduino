const int buzzer = 11;

void setup() {
  pinMode(buzzer, OUTPUT);

}

void loop() {
  char i;
  char j;

  while(1){
    for(i = 0; i < 80; i++){
      digitalWrite(buzzer, HIGH);
      delay(1);
      digitalWrite(buzzer, LOW);
      delay(1);
      
    }

    for(j = 0; j < 100; j++){
      digitalWrite(buzzer, HIGH);
      digitalWrite(buzzer, LOW);
      delay(2);
      
    }
  }
}
