const int potpin=0;
const int ledpin=11;

int val=0;

void setup(){
  
  pinMode(ledpin,OUTPUT);
  Serial.begin(9600);
  
}

void loop(){
  
  val=analogRead(potpin);
  Serial.println(val);
  analogWrite(ledpin,val);
  delay(100);
  
}
