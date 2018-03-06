#define ECHOPIN 3
#define TRIGPIN 2

int LDR = A0;  // Select the input pin for LDR
unsigned int sensorValue = 0; // Variable to store the value coming from the sensor
int Red = 4; // Red led is connected to digital pin 4
int Yellow = 5; // Yellow led is connected to digital pin 5
int Green = 6; // Green led is connected to digital pin 6
int buzzer = 9; // Buzzer is connected to digital pin 9


char inVal ='R';

void setup() 
{
  // initialize the digital pin as output.
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LDR, OUTPUT);
  Serial.begin(9600);
 }

void loop() 
{
   // the loop would runs continuously:
  
  while (Serial.available()>0)
    inVal=Serial.read();

  if(inVal == 'R') // this represent the Regular mode
    {
       // preforming Rrgular mode function
       
       digitalWrite(buzzer,LOW);
       noTone(buzzer); 
        
       digitalWrite(Red,HIGH);
       delay(2000);
       digitalWrite(Red,LOW);

       digitalWrite(Yellow,HIGH);
       delay(1000);
       digitalWrite(Yellow,LOW);

       digitalWrite(Green,HIGH);
       delay(2000);
       digitalWrite(Green,LOW);

       digitalWrite(Green,HIGH);
       delay(1000);
       digitalWrite(Green,LOW);

       digitalWrite(Yellow,HIGH);
       delay(1000);
       digitalWrite(Yellow,LOW);



       }
     
    else if (inVal == 'P') // preforming the pedestrian mode function
    {

       digitalWrite(TRIGPIN, LOW);
       delayMicroseconds(2);
       digitalWrite(TRIGPIN, HIGH);
       delayMicroseconds(10);
       digitalWrite(TRIGPIN, LOW);
       float distance = pulseIn(ECHOPIN, HIGH)/58.00; // return 0 if no high pulse in 1sec
       Serial.print("Distance:");
       Serial.print(distance);
       Serial.println("cm");
       delay(200);
       if(distance<10)
       {
        digitalWrite(buzzer, HIGH);
        tone(buzzer,500);
        for (int i=0; i<10; i++)
        {
          digitalWrite(Yellow,HIGH);  // Trun ON Yellow LED
          delay(100);
          digitalWrite(Yellow,LOW);  // Trun OFF Yellow LED
          delay(100);
         
       
        }
       }
       if(distance>=10)
       {
        digitalWrite(buzzer,LOW);
        noTone(buzzer);
        digitalWrite(Red,HIGH);
       delay(2000);
       digitalWrite(Red,LOW);

       digitalWrite(Yellow,HIGH);
       delay(1000);
       digitalWrite(Yellow,LOW);

       digitalWrite(Green,HIGH);
       delay(2000);
       digitalWrite(Green,LOW);

       digitalWrite(Yellow,HIGH);
       delay(1000);
       digitalWrite(Yellow,LOW);
       } 
      }
     
    else if(inVal == 'N') // preforming the night mode
    {

        sensorValue = analogRead(LDR);// read the value from the sensor
        Serial.print("LightValue:");
        Serial.println(sensorValue);  //prints the values coming from the sensor on the screen

        digitalWrite(TRIGPIN, LOW);
        delayMicroseconds(2);
        digitalWrite(TRIGPIN, HIGH);
        delayMicroseconds(10);
        digitalWrite(TRIGPIN, LOW);
        float distance = pulseIn(ECHOPIN, HIGH)/58.00;
        Serial.print("Distance:");
        Serial.print(distance);
        Serial.println("cm");
        delay(200);
        
        if(sensorValue<10)
        {
          
         if (distance <10){
         digitalWrite(Green,HIGH); 
         digitalWrite(Red,LOW);         
        }
        else
        {
          digitalWrite(Red,HIGH);
          digitalWrite(Green,LOW);
        }
        }
        else
        {
         digitalWrite(Red,HIGH);
       delay(2000);
       digitalWrite(Red,LOW);

       digitalWrite(Yellow,HIGH);
       delay(1000);
       digitalWrite(Yellow,LOW);

       digitalWrite(Green,HIGH);
       delay(2000);
       digitalWrite(Green,LOW);

       digitalWrite(Yellow,HIGH);
       delay(1000);
       digitalWrite(Yellow,LOW);
        }
       
      }
    
  }




  
