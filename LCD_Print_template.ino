


#include <LiquidCrystal.h>


  /* Initialize LCD. Begin by assigning LCD inputs to
   * Arduino outputs.
  */    
const int rs = 12, en = 11, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int sensorPin = A4;     /*define sensonPin as variable with value of analog pin 4
                          the resolution is 10 mV / degree centigrade with a
                          500 mV offset to allow for negative temperatures*/
                          
float bVolt = 3.3;
 




void setup() 
{
  // Set the brightness: 
  analogWrite(A3, 0); 
  
  // set LCD number of (columns and rows):
  lcd.begin(16, 2);
  
  // Print a message to the LCD:
  lcd.print("Hello, World!");
}




void loop() 
{
    // define reading as the output from the analog pin previously established as sensorPin
  int reading = analogRead(sensorPin);  
 
  // define variable for setting delay time
  int delayPeriod = 500;

  // Define voltage variable as the earlier defined reading variable times 3.3. Float means decimal number. 
  float voltage = reading * bVolt;
 
  voltage /= 1024.0; 

 
  // now print out the temperature
  float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)

 
  // now convert to Fahrenheit
  float temperatureF = (temperatureC * 9.0 / bVolt) + 32.0;

 
  /* set the cursor to column 0, line 1 
   *  (note: line 1 is the second row, counting begins with 0)
  */
  lcd.setCursor(0, 1);
  
  // print the number of seconds since reset:
  lcd.print(temperatureF);

  delay (3000);
}
