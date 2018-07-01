#include <IRremote.h> // добавяне на библютека за инфраред управление
#include <LiquidCrystal.h> // добавяне на библютека за LCD 

const byte redPin = 10; // инициализация за червен диод на дигитален пин 10
const byte whitePin = 9; // инициализация за бял диод на дигитален пин 9
const byte greenPin = 6; // инициализация за зелен диод на дигитален пин 6
const byte buzzer = 8; // инициализация за бъзер на дигитален пин 8
const byte RECV_PIN = 7; // инициализация за инфраприемник на дигитален пин 7
const int temperaturePin = 0; // инициализация за темрературен датчик на аналогов пин 0

// инициализиране на дисплея и инфраконтрола
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

// инициализиране на мелодия 1
int numTones = 10;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
// mid C C# D D# E F F# G G# A
int statePin = LOW;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn(); 
  irrecv.blink13(true); //пин 13 светва при получаване на сигнал от дистанционото
  lcd.begin(16, 2); //инициализация на дисплея 16 колони 2 реда 
  pinMode(whitePin, OUTPUT); //инициализация на бял диод
  pinMode(greenPin, OUTPUT); //инициализация на зелен диод
  pinMode(redPin, OUTPUT); //инициализация на червен диод
  pinMode(buzzer, OUTPUT); //инициализация на бъзер

}

void loop(){

  // формула за изчисляване на температурата
  int val = analogRead(0);
  int dat = (125 * val) >> 8;
  
  if (irrecv.decode(&results)){
    if (results.value == 0XFFFFFFFF)
    results.value = key_value;
    lcd.setCursor(0, 0);
    lcd.clear();
    
    // switch-case операторът в зависимост от получената информация за натиснат бутон, изпълнява съответно действие
    switch(results.value){

      case 0xFF6897: // бутон 1 -> изобразява Българското знаме
      lcd.print("Pressed button:1");
      lcd.setCursor(0, 1); // премества курсора на вторият ред на LCD
      lcd.print("Bulgarian Flag");
          
      digitalWrite(whitePin, HIGH);
      digitalWrite(greenPin, HIGH);
      digitalWrite(redPin, HIGH);
      delay(2000);
      digitalWrite(whitePin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(redPin, LOW);
      break;  
        
      case 0xFF9867: // бутон 2 -> бъзера издава звук в продължение на 0,1 секунда
      lcd.print("Pressed button:2");
      lcd.setCursor(0, 1);
      lcd.print("Buzzer beep");
      
      digitalWrite(buzzer,HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      break;
        
      case 0xFFB04F: // бутон 3 -> показва моментната температура
      lcd.print("Pressed button:3");
      lcd.setCursor(0, 1);
      lcd.print("Temp: ");
      lcd.print(dat);
      lcd.print("C");
      delay(1000);
      break;
        
      case 0xFF30CF: // бутон 4 -> няма функция все още
      lcd.print("Pressed button:4");
      lcd.setCursor(0, 1);
      lcd.print("No function here");
      //TODO: FUTURE FUNCTION HERE
      break;
        
      case 0xFF18E7: // бутон 5 -> изпълнява кратка мелодия със светомузика
      lcd.print("Pressed button:5");
      lcd.setCursor(0, 1);
      lcd.print("Melody 1");

//      for(int i = 0; i < numTones; i++){
//        tone(buzzer, tones[i]);
//        delay(500);
//      }
//      noTone(buzzer);
//tone(buzzer, 1000,500);
        
      break;
          
      case 0xFF7A85: // бутон 6 -> изпълнява кратка мелодия със светомузика
      lcd.print("Pressed button:6");
      lcd.setCursor(0, 1);
      lcd.print("Playing Melody 2");
      
      break;
          
      case 0xFF10EF: // бутон 7 -> включва бели LED светлини
      lcd.print("Pressed button:7");
      lcd.setCursor(0, 1);
      lcd.print("White LEDs On");
          
      digitalWrite(whitePin, HIGH);
      delay(1000);
      digitalWrite(whitePin, LOW);
      break;
          
      case 0xFF38C7: // бутон 8 -> включва зелени LED светлини
      lcd.print("Pressed button:8");
      lcd.setCursor(0, 1);
      lcd.print("Green LEDs On");
          
      digitalWrite(greenPin, HIGH);
      delay(1000);
      digitalWrite(greenPin, LOW);
      break;
          
      case 0xFF5AA5: // бутон 9 -> включва червени LED светлини
      lcd.print("Pressed button:9");
      lcd.setCursor(0, 1);
      lcd.print("Red LEDs On");
          
      digitalWrite(redPin, HIGH);
      delay(1000);
      digitalWrite(redPin, LOW);
      break;

      case 0xFF4AB5: // бутон 0 -> няма функция все още
      lcd.print("Pressed button:0");
      lcd.setCursor(0, 1);
      lcd.print("No function here");
      //TODO: FUTURE FUNCTION HERE
      break;

      default:
      lcd.print("Press another");
      lcd.setCursor(0, 1);
      lcd.print("key");
      break;
        
      }
        
    key_value = results.value;
    irrecv.resume(); // рестартиране на инфрачетеца
    
  }
}
        //при всяко завъртане на цикъка диодат светва или изгасва; светва при нота, изгасва при празно място/пауза/
        //statePin = !statePin;
        //digitalWrite(redPin, statePin);

