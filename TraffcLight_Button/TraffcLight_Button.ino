const int buttonPin = 2;
const int ledPinCarsRed = 9;
const int ledPinCarsYellow = 10;
const int ledPinCarsGreen = 11;
const int ledPinHumanRed = 5;
const int ledPinHumanGreen = 6;

int buttonState = 0;

void setup() {
  
  pinMode(ledPinCarsRed, OUTPUT);
  pinMode(ledPinCarsYellow, OUTPUT);
  pinMode(ledPinCarsGreen, OUTPUT);
  pinMode(ledPinHumanRed, OUTPUT);
  pinMode(ledPinHumanGreen, OUTPUT);
  
  pinMode(buttonPin, INPUT);
  
}

void loop() {
  
  buttonState = digitalRead(buttonPin);
  digitalWrite(ledPinHumanRed, HIGH);


  if (buttonState == HIGH) {
    
   // delay(3000);
    
    for(int i = 0; i < 5; i++){
      delay(500);
      digitalWrite(ledPinCarsYellow, HIGH);
      delay(500);
      digitalWrite(ledPinCarsYellow, LOW);
    
    }

    digitalWrite(ledPinCarsRed, HIGH);

    digitalWrite(ledPinHumanRed, LOW);
    digitalWrite(ledPinHumanGreen, HIGH);
    delay(10000);
    digitalWrite(ledPinHumanGreen, LOW);

    digitalWrite(ledPinCarsYellow, HIGH);
    delay(1000);
    digitalWrite(ledPinCarsRed, LOW);
    digitalWrite(ledPinCarsYellow, LOW);

    digitalWrite(ledPinCarsGreen, HIGH);
    delay(5000);
    digitalWrite(ledPinCarsGreen, LOW);

  } else {

    loopCarsTraffic();
  }
}

void loopCarsTraffic(){

  digitalWrite(ledPinCarsRed, HIGH);
  delay(5000);
  digitalWrite(ledPinCarsYellow, HIGH);
  delay(1000);
  
  digitalWrite(ledPinCarsRed, LOW);
  digitalWrite(ledPinCarsYellow, LOW);
  
  digitalWrite(ledPinCarsGreen, HIGH);
  delay(5000);
  digitalWrite(ledPinCarsGreen, LOW);

/*  digitalWrite(ledPinCarsYellow, HIGH);
  delay(1000);
  digitalWrite(ledPinCarsYellow, LOW);
 */ 
}
