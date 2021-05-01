// include the library code: 
#include <LiquidCrystal.h> 
// initialize the library by associating any needed LCD interface pin 
// with the arduino pin number it is connected to 
const int rs = 12, en = 11, d4 = 2, d5 = 3, d8 = 4, d7 = 5; 
int sensorPin = (A1);
int sensorValue;
LiquidCrystal lcd(rs, en, d4, d5, d8, d7); 
void setup() { 
  pinMode(6, OUTPUT);
 analogWrite(A3, 0); // Set the brightness to its maximum value 
 // set up the LCD's number of columns and rows: 
 lcd.begin(16, 2); 
 // Print a message to the LCD. 
   lcd.setCursor(12, 0); 
 lcd.print("degF"); 
   lcd.setCursor(6, 1); 
 lcd.print("J Hunt :)"); 
 Serial.begin(9600);
} 
void loop() { 
 // set the cursor to column 0, line 1 
 // (note: line 1 is the second row, since counting begins with 0): 
 lcd.setCursor(0, 1); 
 // print the number of seconds since reset: 
 lcd.print(millis() / 1000); 
 sensorValue = analogRead(sensorPin);
  float voltage = sensorValue * 3.3;
     voltage /= 1024.0;
     float tempC = (voltage - 0.5) * 100 ;
      float tempF = (tempC * 9.0 / 5.0) + 32.0;

      if (tempF >= 79) digitalWrite(6, HIGH);
       if (tempF < 79) digitalWrite(6, LOW);

  lcd.setCursor(0, 0); 
 // print the number of seconds since reset: 
 lcd.print(tempF); 
 Serial.println(tempF);
 delay(500);
} 
