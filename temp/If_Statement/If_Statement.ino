int ledPin = 6;
int delayPeriod = 100;

void setup() 
{
  pinMode (ledPin, OUTPUT);
}

void loop() 
{
  digitalWrite(ledPin, HIGH);
  delay(delayPeriod);
  digitalWrite(ledPin, LOW);
  delay(delayPeriod);
  delayPeriod = delayPeriod + 100;
  if (delayPeriod > 3000)
  {
    delayPeriod = 100;
  }
}  
