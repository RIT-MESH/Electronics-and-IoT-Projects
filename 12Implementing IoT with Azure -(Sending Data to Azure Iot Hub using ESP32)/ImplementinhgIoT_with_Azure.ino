#include <WiFi.h>
#include "DHT.h"
#include "AzureIotHub.h"
#include "Esp32MQTTClient.h"
#define INTERVAL 2000 // interval for message delay
#define DEVICE_ID "ESP32DEVICELIVE" // this wiil have to be created on Azure platform
#define MESSAGE_MAX_LEN 256 // maximum length of message
#define DHTPIN 4 // DHTvpin is connected to GPIO D4 of ESP32
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "**********";
const char* password = "**************";

int messageCount = 1;

// Device primary connectipon string got from Azure platform
static const char* connectionString = "HostName=ESP32DEMODAY13LIVE.azure-devices.net;DeviceId=ESP32DEVICELIVE;SharedAccessKey=oR7lS6Amqn3GW0rbpsBBWz+quZ4nqFyjLpMdIVZYHEk=";

//Message data, device ID then Message ID it will be incremented like 1,2,3,4...and so on, then 
//temperature and humidity values
const char *messageData = "{\"deviceId\":\"%s\", \"messageId\":%d, \"Temperature\":%f, \"Humidity\":%f}";

static bool hasWifi = false; // when WiFi is connected this value will become True
static bool messageSending = true;
static uint64_t send_interval_ms;
static void InitWifi() //to initialize the WiFi

{
  Serial.println("Connecting...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  hasWifi = true;
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

static void SendConfirmationCallback(IOTHUB_CLIENT_CONFIRMATION_RESULT result)
{
  if (result == IOTHUB_CLIENT_CONFIRMATION_OK)
  {
    Serial.println("Send Confirmation Callback finished.");
  }
}

void setup()
{
  
  Serial.begin(115200);
  Serial.println(F("DHT11 test!"));
  dht.begin();
  Serial.println("ESP32 Device");
  Serial.println("Initializing...");
  Serial.println(" > WiFi");
  hasWifi = false;
  InitWifi();
  
  if (!hasWifi) //if False
  {
    return;
  }
  // if True it print the IOT hub and processed further
  Serial.println(" > IoT Hub");
  Esp32MQTTClient_Init((const uint8_t*)connectionString);
  Esp32MQTTClient_SetSendConfirmationCallback(SendConfirmationCallback); //This api is typically used to force reconnection upon a specific event. 
  send_interval_ms = millis();
}

void loop()
{
  if (hasWifi) //If WiFi is True it enters the loop
  {
    if (messageSending && 
        (int)(millis() - send_interval_ms) >= INTERVAL)
    {
      char messagePayload[MESSAGE_MAX_LEN];// previously set message length
      float temperature = dht.readTemperature();
      float humidity = dht.readHumidity();
      snprintf(messagePayload,MESSAGE_MAX_LEN,messageData, DEVICE_ID, messageCount++, temperature,humidity); // formats and stores a series of characters and values.
      Serial.println(messagePayload);
      //Generate the event and send event instance message to IoT hub
      EVENT_INSTANCE* message = Esp32MQTTClient_Event_Generate(messagePayload, MESSAGE);
      Esp32MQTTClient_SendEventInstance(message);
      send_interval_ms = millis();
    }
  }
  delay(10);
}
