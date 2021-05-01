


// define variables a and b as integers with value of 2
int a = 2;
int b = 2;
//define c as integer, this variable will gain numeric value later
int c;




void setup() 
{
  //initialize serial monitor
  Serial.begin(9600);

}




void loop() 
{

  c = a + b;
  
  //print the value of variable c on next line of serial monitor
  Serial.println(c);

  a = b * c;

  //delay so that sample isn't immediately retaken
  delay(1000);
}
