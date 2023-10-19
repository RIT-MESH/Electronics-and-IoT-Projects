#include <WiFi.h>
#include "ThingSpeak.h"
#include "DHT.h"
#define DHTPIN 4 // GPIO 4 Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // DHT type
DHT  dht(DHTPIN, DHTTYPE)
const int moisturePin = A0; // Esp32 is connected to analog input
const int motorPin = 26; //motor pin is connected to pin 26 of Esp32

WiFiClient  client;

unsigned long myChannelNumber = ***********; // Thinkspeak channel number
const char * myWriteAPIKey = "***************"; // channel write API key

// Timer variables
// THE DEFAULT TIMER IS SET TO 10 SECONDS FOR TESTING PURPOSES
// For a final application, check the API call limits per hour/minute to avoid getting blocked/banned
unsigned long lastTime = 0;
unsigned long timerDelay = 10000;

// Variable to hold temperature readings
float temperatureC;
float Humidity;

const char* ssid = "*********";   // WRITE your network SSID (name) 
const char* password = "*********";   //WRITE your network passwor

// for Relay
const int relay = 26;
void setup() {
Serial.begin(115200);
pinMode(relay, OUTPUT);
}
void loop() {
// Normally Open configuration, send LOW signal to let current flow
// (if you're usong Normally Closed configuration send HIGH signal)
digitalWrite(relay, LOW);
Serial.println("Current Flowing");
delay(5000);
// Normally Open configuration, send HIGH signal stop current flow
// (if you're usong Normally Closed configuration send LOW signal)
digitalWrite(relay, HIGH);
Serial.println("Current not Flowing");
delay(5000);
}

// The following section of code will connect our ESP32 board with the local network whose
// network credentials we already specified above.
void setup() {
  Serial.begin(115200); // initialize the baud rate , how many bits transfered per second
  WiFi.begin(ssid, password);
  ThingSpeak.begin(Client); // Initialize thingspeak
  dht.begin();
  pinMode (motorPin, OUTPUT); 
  digitalWrite(motorPin, Low); // initially motor is off
}

void loop() {
  if ((millis() - lastTimer) > timerDelay) {
    // connect or reconnect to WiFi
   
if (WiFi.status () != WL CONNECTED) {
   Serial.print ("Attempting to connect"); 
   while(WiFi.status() != WL_CONNECTED) {
    WiFi.begin (SSID、password);
    delay (5000);
}
Serial.println("\nConnected.");

}

// for temperature and humidity
Delay (2000).
// A temperature or humidity reading takes approximately 250 milliseconds.
// Sensor readings can be "old" by up to 2 seconds (very slow sensor)
float h = dht.readHumidity();
// Read temperature as Celsius (default)
float t = dht.readTemperature();
// Read temperature as Fahrenheit (isFahrenheit = true)
float f = dht.readTemperature(true);
// calculate moisture value from analoge value 12 bit ADC is 4096, for 10 bit it is 1024
int moisture percent (100.00-((analogRead (moisturePin)/4096.00)*100.00)); 
int motorstatus = 0;
Serial.print (F ("Humidity: "));
Serial.print(h);
Serial.print (F("% temperature: "));
Serial.print(t);
Serial.println(F("°C"));
Serial.print(f);
Serial.println(F("F"));
Serial.println(moisturepercentage);

  
// Check if there are any failed reads and exit early (to retry). 
if (isnan(h) || isnan (t) | isnan (f) ||isnan (moisturePercentage))
{
Serial.println (F("Failed to read from sensor!")); -
return;
}
else
{
ThingSpeak.setField (1,t); // Thingspeak feild 1 temperature
ThingSpeak.setField (2, h); // Thingspeak feild 2 humidity
ThingSpeak.setField (3, moisture percent);

  if (moisturePercentage == 0) {
      motorstatus = 1;
      digitalWrite (motorPin, HIGH); // turn on the motor
  }   
  else
  {
    motorstatus=0;
  DigitalWrite (motorPin, LOW); // turn off the motor
  }


ThingSpeak.setField (4, motorstatus);
int x = ThingSpeak.writeFields (myChannel Number, myWriteAPIKey);
if (x == 200) {
Serial.println("Channel updated successfully.");
}
else{
Serial.println("A problem occurred while updating the channel. HTTP error code " + String (x));
}
lastTime = millis();

}

    Serial.print (F("Humidity: "));
    Serial.print (h);
    Serial.print (F(" Temperature: "));
    Serial.print(t);
    Serial.print (F("°C "));
    Serial.print (f);
    Serial.println(F("F"));
    Serial.println(moisture percentage);
  }
}
