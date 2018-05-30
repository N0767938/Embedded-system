//TRANSMITTER BOARD CODE
#define trigPin  2   //DEFINES TRIGGER PIN
#define echoPin  3   //DEFINES ECHO PIN

//int LDR = A0;        //INITIALISING LIGHT DEPENDANT RESISTOR PIN
//unsigned int sensorValue = 0 ;        //INITIALISING A VARIABLE TO STORE LDR VALUE

 int duration;
 unsigned int distance;                //INITIALISING TWO VARIABLES TO STORE DURATION OF ECHO SIGNAL AND DISTANCE OF OBJECT


void setup()            //SETTING UP/DECLARING OF EITHER OUTPUT OR INPUT AND SERIAL MONITORS

{
 // pinMode(LDR,INPUT);
  pinMode(trigPin, OUTPUT);           //DECLARE TRIGGERPIN AS OUTPUT PIN
  pinMode(echoPin, INPUT);            //DECLARE ECHOPIN AS INPUT PIN
  Serial1.begin(9600);  //BEGENING OF THE ZIGBEE CHANNEL
}

void loop()             //STARTING ARDUINO LOOP
{
     //start front distance computing
 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW); 
 float distance = pulseIn(echoPin, HIGH)/58; // return 0 if no high pulse in 1sec
 Serial.print("Front Distance: ");
 Serial.print(distance);
 Serial.println("cm");
 delay(500);

  if(distance > 0 && distance <10)
    {
    Serial1.write(0); //print distance
    Serial.println(0);
    }
    if(distance >= 10 && distance <20)
    {
    Serial1.write(1); //print distance
    Serial.println(1);
    }

    if(distance >= 20 && distance <30)
    {
    Serial1.write(2); //print distance
    Serial.println(2);
    }
    if(distance >= 30 && distance <40)
    {
    Serial1.write(3); //print distance
    Serial.println(3);
    }

    if(distance >= 40 && distance <50)
    {
    Serial1.write(4); //print distance
    Serial.println(4);
    }
    if(distance >= 50 && distance <60)
    {
    Serial1.write(5); //print distance
    Serial.println(5);
    }
    if(distance >= 60 && distance <70)
    {
    Serial1.write(6); //print distance
    Serial.println(6);
    }
    if(distance >= 70 && distance <80)
    {
    Serial1.write(7); //print distance
    Serial.println(7);
    }
    if(distance >= 80 && distance <90)
    {
    Serial1.write(8); //print distance
    Serial.println(8);
    }
    if(distance >= 90 && distance <100)
    {
    Serial1.write(9); //print distance
    Serial.println(9);
    }
    if(distance >= 100 && distance <110)
    {
    Serial1.write(10); //print distance
    Serial.println(10);
    }
    if(distance >= 110 && distance <120)
    {
    Serial1.write(11); //print distance
    Serial.println(11);
    }
    if(distance >= 120 && distance <130)
    {
    Serial1.write(12); //print distance
    Serial.println(12);
    }

    if(distance >= 130 && distance <140)
    {
    Serial1.write(13); //print distance
    Serial.println(13);
    }
    if(distance >= 140 && distance <150)
    {
    Serial1.write(14); //print distance
    Serial.println(14);
    }
    if(distance >= 150 && distance <160)
    {
    Serial1.write(15); //print distance
    Serial.println(15);
    }
    if(distance >= 160)
    {
    Serial1.write(16); //print distance
    Serial.println(16);
    }

}                        //END OF LOOP
