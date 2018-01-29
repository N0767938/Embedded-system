
int sensorPin = A0;            
unsigned int sensorValue = 0;  

void setup()
{

  Serial.begin(9600);        
}

void loop()
{
  
  sensorValue = analogRead(sensorPin);     
  Serial.print(sensorValue);
  Serial.print("\n");
  delay(500);
if (sensorValue < 15)
{
  for (int inka = 0; inka < 5; inka++)
  {
  digitalWrite(5, HIGH);
  delay(300);
  digitalWrite(5, LOW);
  delay(300);
  }
}
}

