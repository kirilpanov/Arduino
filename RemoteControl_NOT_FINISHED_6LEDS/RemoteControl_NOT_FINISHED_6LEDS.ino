#include <IRremote.h>

int RECV_PIN = 11;
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int LED6 = 7;
long on1  = 0x00FFA25D;
long off1 = 0x00FFE01F;
long on2 = 0x00FF629D;
long off2 = 0x00FFA857;
long on3 = 0x00FFE21D;
long off3 = 0x00FF906F;
long on4 = 0x00FF22DD;
long off4 = 0x00FF6897;
long on5 = 0x00FF02FD;
long off5 = 0x00FF9867;
long on6 = 0x00FFC23D;
long off6 = 0x00FFB047;

IRrecv irrecv(RECV_PIN);
decode_results results;

void dump(decode_results *results){

  int count = result->rawlen;

  if(results->decode_type == UNKNOWN){
    Serial.println("Could not decode messege");
    
  }else{
    if(results->decode_type== NEC){
      Serial.println("Decoded NEC: ");
     
    }else if(){
      
    }
  }
}

