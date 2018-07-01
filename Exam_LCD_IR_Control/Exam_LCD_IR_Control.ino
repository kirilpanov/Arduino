/*  
 *  Проект на Кирил Богомилов Панов  -  kokololo@softuni.bg
 *  Курс - Arduino Basics April 2018
 *  Exam - 17.06.2018
 *  
 *   Програма за извършване на различни функции, чрез дистанционно упрвавление, използвайки
 *   инфраред сигнал. С вграден дисплей за изписване на функциите и стойностите към тях.
 *   Кодът включва използването на 7 бутона от дистанционно, като в бъдеще може да се 
 *   добавят още функции.
 *   
 *   http://z3t0.github.io/Arduino-IRremote/ -> линк за библиотека на IRremote
 */

/*
 *  Чрез код IR_Remote_SetUp попучаваме данните от сигналите на дистанционното при натиснат бутнон<>
 *  в шеснайсетичен формат; от него вече знаем номера на сигнала и можем да му добавим функция
 */

 
#include <IRremote.h> // добавяне на библютека за инфраред управление
#include <LiquidCrystal.h> // добавяне на библютека за LCD 

const byte redPin = 10; // деклариране за червен диод на дигитален пин 10
const byte whitePin = 9; // деклариране за бял диод на дигитален пин 9
const byte greenPin = 6; // деклариране за зелен диод на дигитален пин 6
const byte buzzer = 8; // деклариране за бъзер на дигитален пин 8
const byte RECV_PIN = 7; // деклариране за инфраприемник на дигитален пин 7
const byte temperaturePin = 0; // деклариране за темрературен датчик на аналогов пин 0

// деклариране на дисплея и инфраконтрола
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

// деклариране на мелодия 
int length = 15; // броят ноти
char notes[] = "ccggaagffeeddc "; // празно място -> почивка/спиране 
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;
int statePin = LOW; // деклариране на LED за светомузика с начално състояние изгасен

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn(); 
  irrecv.blink13(true); //пин 13 светва при получаване на сигнал от дистанционото
  lcd.begin(16, 2); //инициализация на дисплея 16 колони 2 реда 
  pinMode(whitePin, OUTPUT); //инициализация на бял диод
  pinMode(greenPin, OUTPUT); //инициализация на зелен диод
  pinMode(redPin, OUTPUT); //инициализация на червен диод
  pinMode(buzzer, OUTPUT); //инициализация на бъзер
  lcd.print("Press any key");

}

void loop(){
      
  // формула за изчисляване на температурата
  int val = analogRead(0);
  int dat = (125 * val) >> 8;

  // получаване и запиване на сигнала от дистанционното за натиснат бутон
  if (irrecv.decode(&results)){
    if (results.value == 0XFFFFFFFF) // 0XFFFFFFFF -> дефолт-на стойност при задържане предишният 
                                     // сингал за натиснат бутон за презаписване и изпълнение на негова функция
                                     // за да не се преизпълнява цялата програма наново -> пести памет и време
    results.value = key_value;
    lcd.setCursor(0, 0);
    lcd.clear();
    
    // switch-case операторът в зависимост от получената информация за натиснат бутон, изпълнява съответно действие
    switch(results.value){

      case 0xFF6897: // бутон 1 -> изобразява Българското знамеза 2 секунда
      lcd.print("Pressed button:1");
      lcd.setCursor(0, 1); // премества курсора на вторият ред на LCD
      lcd.print("Bulgarian Flag");
      Serial.println("Pressed button:1");
      Serial.println("Bugldarian Flag");
         
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
      Serial.println("Pressed button:2");
      Serial.println("Buzzer beep");
      
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
      Serial.println("Pressed button:3");
      Serial.print("Temp");
      Serial.print(dat);
      Serial.print("C");
      
      delay(1000);
      break;
        
      case 0xFF30CF: // бутон 4 -> няма функция все още
      lcd.print("Pressed button:4");
      lcd.setCursor(0, 1);
      lcd.print("No function here");
      Serial.println("Pressed button:4");
      Serial.println("NO function here");
      //TODO: FUTURE FUNCTION HERE
      break;
        
      case 0xFF18E7: // бутон 5 -> изпълнява кратка мелодия без светомузика
      lcd.print("Pressed button:5");
      lcd.setCursor(0, 1);
      lcd.print("Melody");
      Serial.println("Pressed button:5");
      Serial.println("Melody");
      
      for (int i = 0; i < length; i++) {
        if (notes[i] == ' ') {
          delay(beats[i] * tempo); // ако е празно място в моментния char - паузирай
        } else {
           playNote(notes[i], beats[i] * tempo); // ако не -> продължи изпълнението
        }
         
        delay(tempo / 10); // пауза между нотите
      } 
      
      break;
          
      case 0xFF7A85: // бутон 6 -> изпълнява кратка мелодия със светомузика
      lcd.print("Pressed button:6");
      lcd.setCursor(0, 1);
      lcd.print("Melody with LEDs");
      Serial.println("Pressed button:6");
      Serial.println("Melody with LEDs");
      
      for (int i = 0; i < length; i++) {
        //при всяко завъртане на цикъка диодат светва или изгасва; светва при нота, изгасва при празно място/пауза/
        statePin = !statePin;
        digitalWrite(redPin, statePin);
        if (notes[i] == ' ') {
          delay(beats[i] * tempo); // ако е празно място в моментния char -> паузирай
        } else {
           playNote(notes[i], beats[i] * tempo); // ако не -> продължи изпълнението
        }
         
        delay(tempo / 10); // пауза между нотите
      }  
      digitalWrite(redPin, LOW);
      break;
          
      case 0xFF10EF: // бутон 7 -> включва бели LED светлини за 1 секунда
      lcd.print("Pressed button:7");
      lcd.setCursor(0, 1);
      lcd.print("White LEDs On");
      Serial.println("Pressed button:7");
      Serial.println("White LEDs On");
          
      digitalWrite(whitePin, HIGH);
      delay(1000);
      digitalWrite(whitePin, LOW);
      break;
          
      case 0xFF38C7: // бутон 8 -> включва зелени LED светлини за 1 секунда
      lcd.print("Pressed button:8");
      lcd.setCursor(0, 1);
      lcd.print("Green LEDs On");
      Serial.println("Pressed button:8");
      Serial.println("Green LEDs On");
          
      digitalWrite(greenPin, HIGH);
      delay(1000);
      digitalWrite(greenPin, LOW);
      break;
          
      case 0xFF5AA5: // бутон 9 -> включва червени LED светлини за 1 секунда
      lcd.print("Pressed button:9");
      lcd.setCursor(0, 1);
      lcd.print("Red LEDs On");
      Serial.println("Pressed button:9");
      Serial.println("Red LEDs On");
          
      digitalWrite(redPin, HIGH);
      delay(1000);
      digitalWrite(redPin, LOW);
      break;

      case 0xFF4AB5: // бутон 0 -> няма функция все още
      lcd.print("Pressed button:0");
      lcd.setCursor(0, 1);
      lcd.print("No function here");
      Serial.println("Pressed button:0");
      Serial.println("No function here");
      //TODO: FUTURE FUNCTION HERE
      break;

      default:
      lcd.print("Press another");
      lcd.setCursor(0, 1);
      lcd.print("key");
      Serial.println("Press another key");
      break;
        
      }
        
    key_value = results.value;
    irrecv.resume(); // рестартиране на инфрачетеца
    
  }
}

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(buzzer, HIGH);
    delayMicroseconds(tone);
    digitalWrite(buzzer, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

  // play the tone corresponding to the note name
  // изпълнява нотата съответстваща на буквата
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

