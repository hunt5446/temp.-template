


#include <LiquidCrystal.h>


  /* Initialize LCD. Begin by assigning LCD inputs to
   * Arduino outputs.
  */    
const int rs = 12, en = 11, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);




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

}
