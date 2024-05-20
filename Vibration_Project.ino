#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const int sensorPin = A3;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600); 
  lcd.init(); 
  lcd.backlight();
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(sensorPin); 
  
  float minFreq = 100.0;
  float maxFreq = 1000.0;
  float frequency = map(sensorValue, 0, 1023, minFreq, maxFreq);
  
  Serial.println(frequency);
  
  lcd.setCursor(0, 0);
  lcd.print("Frequency: "); 
  lcd.print(frequency); 
  
  delay(400); 
}
