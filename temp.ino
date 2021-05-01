


int sensorPin = A4;     /*define sensonPin as variable with value of analog pin 4
                          the resolution is 10 mV / degree centigrade with a
                          500 mV offset to allow for negative temperatures*/
                          
float bVolt = 3.3;

void setup()
{
  // initialize serial monitor
  Serial.begin(9600);   
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

  //print the result of previous volatge equation
  Serial.print(voltage); 
  //Label the result as having volts for units
  Serial.println(" volts");
 
  // now print out the temperature
  float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)
  Serial.print(temperatureC); Serial.println(" degrees C");
 
  // now convert to Fahrenheit
  float temperatureF = (temperatureC * 9.0 / bVolt) + 32.0;
  Serial.print(temperatureF); Serial.println(" degrees F");
 
   delay(2000);                                     //waiting a second
}
