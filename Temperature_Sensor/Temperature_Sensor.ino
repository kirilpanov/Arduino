const int potPin = 0;
void setup(){
  
  Serial.begin(9600);
  
}
void loop(){
  
  int val;
  int dat;
  
  val = analogRead(0);
  dat = (125 * val) >> 8;
  
  Serial.print("Tep:");
  Serial.print(dat);
  Serial.println("C");
  
//  delay(900000); //15 mins
  delay(60000);
}
