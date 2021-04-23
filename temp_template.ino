


//TMP36 Pin Variables
int sensorPin = A4; //the analog pin the TMP36's Vout (sense) pin is connected to
//the resolution is 10 mV per degree centigrade with a
//500 mV offset to allow for negative temperatures





void setup()
{
  Serial.begin(9600);
  // initializes the serial monitor  
}




void loop()
{
  // define  "reading" as the output read from the pin defined as "sensorPin"
  int reading = analogRead(sensorPin);

  // define the variable used for setting the delay period
  int delayPeriod = 500;

  // float used for values containing decimals. defines voltage variable as the earlier defined reading variable times 3.3
  float voltage = reading * 3.3;

  voltage /= 1024.0;

  // print voltage in serial monitor
  Serial.print(voltage); Serial.println(" volts");

  // print temp celsius in serial monitor after
  float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
  
  //to degrees ((voltage - 500mV) times 100)
  Serial.print(temperatureC); Serial.println(" degrees C");

  // now convert to Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  
  Serial.print(temperatureF); Serial.println(" degrees F");
  // prints converted reading in serial monitor

  delay(2000);                                    
  //delay between readinga
}
