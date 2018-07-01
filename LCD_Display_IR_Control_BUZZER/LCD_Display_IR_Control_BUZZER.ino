#include <IRremote.h>
#include <LiquidCrystal.h>

const int RECV_PIN = 7;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

//const int redPin = 10;
const int buzzer = 8;


void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn(); 
  irrecv.blink13(true);
  lcd.begin(16, 2);
  
//  irrecv.enableIRIn();
//  irrecv.blink13(true);
//  pinMode(redPin, OUTPUT);

    pinMode(buzzer, OUTPUT);
}

void loop(){
  if (irrecv.decode(&results)){
 
        if (results.value == 0XFFFFFFFF)
        results.value = key_value;
        lcd.setCursor(0, 0);
        lcd.clear();
        
        switch(results.value){
          case 0xFFA25D:          
          lcd.print("CH-");
          break;
          case 0xFF629D:
          lcd.print("UP");
          break;
          case 0xFFE21D:
          lcd.print("UP");
          break;
          case 0xFF22DD:
          lcd.print("LEFT");
          break;
          case 0xFF02FD:
          lcd.print("OK");
          break ;  
          case 0xFFC23D:
          lcd.print("RIGHT");
          break ;               
//          case 0xFFE01F:
//          lcd.print("-");
//          break ;  
          case 0xFFA857:
          lcd.print("DOWN");
          break ;  
//          case 0xFF906F:
//          lcd.print("EQ");
//          break ;  
          case 0xFF6897:
          lcd.print("1");
//          
//          digitalWrite(redPin, HIGH);
//          delay(2000);
//          digitalWrite(redPin, LOW);
//          
          break ;  
          case 0xFF9867:
          lcd.print("2");
          digitalWrite(buzzer,HIGH);
          delay(100);
          digitalWrite(buzzer, LOW);
          break ;
          case 0xFFB04F:
          lcd.print("3");
          break ;
          case 0xFF30CF:
          lcd.print("4");
          break ;
          case 0xFF18E7:
          lcd.print("5");
          break ;
          case 0xFF7A85:
          lcd.print("6");
          break ;
          case 0xFF10EF:
          lcd.print("7");
          break ;
          case 0xFF38C7:
          lcd.print("8");
          break ;
          case 0xFF5AA5:
          lcd.print("9");
          break ;
          case 0xFF42BD:
          lcd.print("*");
          break ;
          case 0xFF4AB5:
          lcd.print("0");
          break ;
          case 0xFF52AD:
          lcd.print("#");
          break ;                   
        }
        key_value = results.value;
        irrecv.resume(); 
  }
}

