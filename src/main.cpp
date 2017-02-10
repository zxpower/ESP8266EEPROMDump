#include "main.h"

void setup() {
  String EEPROMcontents;
  Serial.begin(115200);
  EEPROM.begin(512);
  delay(10);
  Serial.println();
  Serial.println();
  Serial.println("EEPROM Dump");
  Serial.println("-----------");
  delay(1000);
  EEPROMcontents = readEEPROM();
  Serial.println("EEPROM contents below:");
  Serial.println(EEPROMcontents);
  Serial.println("-----------");
}

void loop() {
  
}

String readEEPROM(void) {
  EEPROM.begin(EEPROM_SIZE);
	byte ch;
	String returnString = "";
	for (int i = 0; i < EEPROM_SIZE; i++){
		ch = EEPROM.read(i);
		if( !isalpha(ch) && !isdigit(ch) ){
			returnString += '\0';
		} else {
      returnString += char(ch);
    }
	}
	EEPROM.end();
  return returnString;
}
