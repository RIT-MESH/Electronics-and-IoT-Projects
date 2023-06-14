//TMP36 Pin Variables
int sensorPin = 0; //the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade with a
                        //500 mV offset to allow for negative temperatures
                        
const int ledG=2;//Green LED is on pin 2
const int ledY=4;//Yellow LED is on pin 8
const int ledR=5;// Red LED is on pin 9
const int buzzer=8;// Buzzer is on pin 11
const float TempSensorvalue=0; // initialize Temp_Sensor reading 

void setup()
{
  Serial.begin(9600);  //Start the serial connection with the computer
  pinMode(ledG,OUTPUT);
  pinMode(ledY,OUTPUT);
  pinMode(ledR,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.println(" temperature monitor\n");
  delay(1000);//Wait before accessing Sensor//to view the result open the serial monitor 
}
 
void loop()                     // run over and over again
{
 //getting the voltage reading from the temperature sensor
 int reading = analogRead(sensorPin);  
 
 // converting that reading to voltage, for 3.3v arduino use 3.3
 float voltage = reading * 5.0;
 voltage /= 1024.0; 
 
 // print out the voltage
 Serial.print(voltage); Serial.println(" volts");
 
 // now print out the temperature
 float TempSensorvalue = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)

//if (TempSensorvalue>=0.0);// compares reading from Temperature sensor with the threshold value
   if (TempSensorvalue>=0.0 && TempSensorvalue<=40.0)
   { // compares reading from Temperature sensor with the threshold value
  digitalWrite(ledG,HIGH); //turns on led 
  Serial.println("Temperature is normal");
  Serial.print(TempSensorvalue); 
  Serial.println(" degrees C");
  digitalWrite(buzzer, LOW);
  noTone(buzzer);
  delay(1000);    
  }
 else if (TempSensorvalue>=41.0)
   {// compares reading from Temperature sensor with the threshold value
  digitalWrite(ledY,HIGH);//turns on led
  digitalWrite(ledG,LOW);//turns off led
  Serial.println("Temperature is getting high");
   Serial.print(TempSensorvalue); 
  Serial.println(" degrees C");
  digitalWrite(buzzer, LOW);
  noTone(buzzer);
  delay(1000); //stops program for 1 second
}
  else if (TempSensorvalue>=51.0)//compares reading from Temperature sensor with the threshold value
 {
  digitalWrite(ledR,HIGH);//turns on led
  digitalWrite(ledY,LOW);//turns off led
  Serial.println("Temperature is very high");
   Serial.print(TempSensorvalue); 
  Serial.println(" degrees C");
  digitalWrite(buzzer, HIGH);
  tone(buzzer,400, 500); //the buzzer emit sound at 400 MHz for 500 millis
  delay(1000); //stops program for 1 second
 }
 else
  {
  digitalWrite(ledR,LOW);
  digitalWrite(ledG,LOW);
  digitalWrite(ledY,LOW);
  digitalWrite(buzzer, LOW);
  noTone(buzzer);
  Serial.println("Temperature sensor not working");
}
}
