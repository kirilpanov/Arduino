#include <IRremote.h> //добавяне на библютека за инфраред управление
#include <LiquidCrystal.h> //добавяне на библютека за LCD 

//инициализиране на константи пинове
const byte RECV_PIN = 7;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

const byte redPin = 10;
const byte bluePin = 9;
const byte buzzer = 8;


void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn(); 
  irrecv.blink13(true); //пин 13 светва при получаване на сигнал от дистанционото
  lcd.begin(16, 2); //инициализация на дисплея 2 реда 16 колони
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(redPin, OUTPUT); //инициализация на червен диод
  pinMode(bluePin, OUTPUT); //инициализация на червен диод
  pinMode(buzzer, OUTPUT); //инициализация на бъзера
  
}

void loop(){
 
  if (irrecv.decode(&results)){
    if (results.value == 0XFFFFFFFF)
    results.value = key_value;
    lcd.setCursor(0, 0);
    lcd.clear();
    
    
    switch(results.value){
        
      case 0xFF629D: // бутон нагоре
      lcd.print("You have pressed UP");
      break;
        
      case 0xFF22DD: // бутон наляво
      lcd.print("You have pressed LEFT");
      break;
        
      case 0xFF02FD: //бутон ОК
      lcd.print("You have pressed OK");
      break;  
        
      case 0xFFC23D: //бутон надясно
      lcd.print("You have pressed RIGHT");
      break;
        
      case 0xFFA857: //бутон надолу
      lcd.print("You have pressed DOWN");
      break; 
        
      case 0xFF6897: //бутон 1
      lcd.print("Pressed buton: 1");      
      digitalWrite(redPin, HIGH);
      delay(500);
      digitalWrite(redPin, LOW);
      break;  
        
      case 0xFF9867: //бутон 2
      lcd.print("Pressed buton: 2");
      digitalWrite(buzzer,HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      break;
        
      case 0xFFB04F: //бутон 3
      lcd.print("Pressed buton: 3");
      digitalWrite(bluePin, HIGH);
      delay(500);
      digitalWrite(bluePin, LOW);
      break;
        
      case 0xFF30CF: //бутон 4
      lcd.print("Pressed buton: 4");
      break;
        
      case 0xFF18E7: //бутон 5
      lcd.print("Pressed buton: 5");
      break;
          
      case 0xFF7A85: //бутон 6
      lcd.print("Pressed buton: 6");
      break;
          
      case 0xFF10EF: //бутон 7
      lcd.print("Pressed buton: 7");
      break;
          
      case 0xFF38C7: //бутон 8
      lcd.print("Pressed buton: 8");
      break;
          
      case 0xFF5AA5: //бутон 9
      lcd.print("Pressed buton: 9");
      break;
        
      case 0xFF42BD: //бутон *
      lcd.print("Pressed buton: *");
      break;
          
      case 0xFF4AB5: //бутон 0
      lcd.print("Pressed buton: 0");
      break;
          
      case 0xFF52AD: //бутон №
      lcd.print("Pressed buton: #");
      break;

      default:
      lcd.print("Press any key");
      break;
        
      }
        
    key_value = results.value;
    irrecv.resume(); //рестартиране на инфрачетеца
    
  }
}

