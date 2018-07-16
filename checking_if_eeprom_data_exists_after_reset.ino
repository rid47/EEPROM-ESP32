#define EEPROM_SIZE 64
#include "EEPROM.h"

int addr = 0;
char did[10]={'0'};
char uid[10]={'0'};


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);


  Serial.println("\nInitializing EEPROM library\n");
  if (!EEPROM.begin(EEPROM_SIZE)) 
  {
    Serial.println("Failed to initialise EEPROM");
    Serial.println("Restarting...");
    delay(1000);
    ESP.restart();
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  readfromEEPROM();
  delay(1000);

}


void readfromEEPROM()
{

  memset(did,0,sizeof(did));
  memset(uid,0,sizeof(uid));
 
  
  for(int i=0;i<10;++i){


    did[i]=char(EEPROM.read(0x00+i));
    
    
  }

  Serial.print("did:");
  Serial.println(did);

  for(int j=0;j<10;++j){

       
      uid[j]=char(EEPROM.read(0x0A+j));
    
  }

  Serial.print("uid:");
  Serial.println(uid);
  }            
     
            
 
