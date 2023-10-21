
#include <WiFiClientSecure.h>
#include <PubSubClient.h> // install with Library Manager, I used v2.6.0

const char* ssid = "WarriorsWay_2G"; //Provide your SSID
const char* password = "Success7183!";   
const char* awsEndpoint = "a1cc0nomzey2wg-ats.iot.ap-south-1.amazonaws.com"; //AWS IoT Core--> Settings (Device data endpoint)

// xxxxxxxxxx-certificate.pem.crt
static const char certificate_pem_crt[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAND2GdedUZoh/ltHSpJF4oxQXe3ZMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMTEyMDIxMjU1
MTVaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDfaWMT/6Mugm5DHK/y
//ynPuyor8qJSUZVGD9Soj21ZG6aUJq62f90kNaNUAPeWDtXVOPucBszqCeZPc8p
UMfrdqo/a/UQRSXmJ7YIPR/n9UNCynt3tGjztOHigrFqjPXTb6+Pb+V/fjzsHrbG
CmKmqxLqdS8IMGGeEUOsei00u1HYyW8uPRHBFdsB/DJFqKXxcVjrI16ZycEMzwh/
mqCc4bgq3RJZPlTfi29Vf0Y2gfMdzibq1nNjJ8xYEDH6WzUqDednSAd08w6n7WlX
3nISphMRX7MOwSwpP8tncCjnhxQUw3oZQMeYb6dHmWDbVDxcKlb4pQSPvPxUN19T
KwZLAgMBAAGjYDBeMB8GA1UdIwQYMBaAFGgRry0shViRTBT9AIa4v57eQWiHMB0G
A1UdDgQWBBQxhHRCSGv90NpiLxPUCYh7xCbqcDAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAR8ccR6I39/Xi4c7y9Uwk2KGU
+ecLqZKG4qIlDn1tN0Gj6Ww+uc2GeC9XwIhUbdRYvTVu4dT+qF1f/FcQemOoK2Ll
PnPKq0Wp4wJeNMMC65eJBUP45xCDNPAOmYpj1e34pOZHsVsAS39eecVwPzeyR32N
VjMzVnB1P1yDkknzie6+QIGuwwCAggkiIf00k2X7xloXwDepkHY0owdEu+OyFiHL
k6HCOc0eaZ204M4tz2Ime2G5KE/pTqbipaTzOJMWkDYXctfSCoLuYruLPcMb3y0L
sWy0XN8hJYV07C4m7xQtYYC/yB+ApcUXZIvvoFHMYCN4wjssI2OmuuaoGN+twA==
-----END CERTIFICATE-----
)KEY";

// xxxxxxxxxx-private.pem.key
static const char private_pem_key[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEA32ljE/+jLoJuQxyv8v/8pz7sqK/KiUlGVRg/UqI9tWRumlCa
utn/dJDWjVAD3lg7V1Tj7nAbM6gnmT3PKVDH63aqP2v1EEUl5ie2CD0f5/VDQsp7
d7Ro87Th4oKxaoz102+vj2/lf3487B62xgpipqsS6nUvCDBhnhFDrHotNLtR2Mlv
Lj0RwRXbAfwyRail8XFY6yNemcnBDM8If5qgnOG4Kt0SWT5U34tvVX9GNoHzHc4m
6tZzYyfMWBAx+ls1Kg3nZ0gHdPMOp+1pV95yEqYTEV+zDsEsKT/LZ3Ao54cUFMN6
GUDHmG+nR5lg21Q8XCpW+KUEj7z8VDdfUysGSwIDAQABAoIBABhmtFGc3D/aMxzV
Z0pNN1U1BDgwaxivjiUBLvlhiwfi3kmwgBXkdYhPwX9Ru/pu/Jw/Q13plK8BsMGG
BLhogE1xeorOycdrJgaLU9B2jKOTIDONVgrvA3+KxBkvWR1gJAFh83ThLdnM+e54
NFJRFBFMIhbFkct9LUxMam3OMl3N24h2zCwit5AOoz6l/wEdKpOgW9+zeB9G7ghQ
aWQcomjHggPtcbNQX7xVAGzCj4yDDAF81iRZkbF4lMkpWDqs031Xyze4mCp3NIfF
zT3PU9niLJvR34k/vo6wK1lSWqCmWiIoaGDfiR38y7dviOqazzEmYNvtZlZub/nq
MYR7ZRECgYEA+oJTXvFyuDjdE7MWHxec5KQR6oewxTG4Zqs5C/URjLSIBjMKR5TU
67kAcKQG49aAuoknZLEh5quvyKWQjlbIGu9hDmEkiczRD7cfNk/ueEHaWC52ofBU
6o5199KlbcCJB+3iUqumIFK+XZKas1j2XOCcuYOdldOwbrgdxPZ5UT8CgYEA5E8C
qlkDJ29AUGHPMsF1sxx8Rmbnje9u79S7DHknNVUTkahNnptsYJ0KAI++wdO3Yp7H
Pu2uUz4A+2i/iSw6QiLPcoqLWqQ4on20V2GdFitHPe0xegLEYtmQdZx0wXuA/OXp
kz9BvnboO3bvW60B5RA0WOwK/98kSTdPe/A5e/UCgYEA0UXgmhdAzA+M+LEKUO0r
/4HlCbVTglkYAIUXwhp4D8CdRfiLpOL7wPSrHm6Y5utCXRLJGwAzHv3cetV9Xru2
rXG+9gFHQesd13AWngvGXyY8XqBqMLySY+ShPmf2FSrcDwi2onOM88HMEGWx4RP3
s/1cUEpYclsHMGeVTv7MuIcCgYAe27cGg0Vz3QuaUb4JpDBeZyk88se1XXlnHR+z
DeUIxlkAxPjIyUUawd8KOGOWGyGcSM2xabq4MZc8Y+oPhlTRf5b+ak9vjubAv7DS
ZrUuu+bDLf4T+a/FlJZ77wuw4xqKFCE/77rZHYVCFE9B2t54sXoB0tWhw+1JoBo0
LEH4yQKBgQC+cpZAXTMI+MUJaCQAESKOj+2xu2GvYELh37d+SeFRcQgLQO/g0ti9
+KhgytqBMjHzoNjHag3PdT/lwM4k0naek9ra3C8vEr/e9iohw25oEVKGSvREFjTr
03pBzGLVlFXNd5bom/Aq6CVEqNcIGHh83nZZu5/RzE9bBBwCyCTOiA==
-----END RSA PRIVATE KEY-----
)KEY";

/* root CA found at:
  https://www.amazontrust.com/repository/AmazonRootCA1.pem
  fungible between regions, I dont care if you use mine below or paste in your own.
*/
static const char rootCA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";


WiFiClientSecure wiFiClient;
void msgReceived(char* topic, byte* payload, unsigned int len);
PubSubClient pubSubClient(awsEndpoint, 8883, msgReceived, wiFiClient); 

void setup() {
  Serial.begin(115200); delay(50); Serial.println();
  Serial.println("ESP32 AWS IoT Example");
  Serial.printf("SDK version: %s\n", ESP.getSdkVersion());

  Serial.print("Connecting to "); Serial.print(ssid);
  WiFi.begin(ssid, password);
  WiFi.waitForConnectResult();
  Serial.print(", WiFi connected, IP address: "); Serial.println(WiFi.localIP());

  wiFiClient.setCACert(rootCA);
  wiFiClient.setCertificate(certificate_pem_crt);
  wiFiClient.setPrivateKey(private_pem_key);
}

unsigned long lastPublish;
int msgCount;

void loop() {

  pubSubCheckConnect();

   //If you need to increase buffer size, you need to change MQTT_MAX_PACKET_SIZE in PubSubClient.h
   char fakeData[128];

  float var1 =  random(55,77); //fake number range, adjust as you like
  float var2 =  random(77,99);
  sprintf(fakeData,  "{\"uptime\":%lu,\"temp\":%f,\"humid\":%f}", millis() / 1000, var1, var2);


  if (millis() - lastPublish > 10000) {
  boolean rc = pubSubClient.publish("outTopic", fakeData);
    Serial.print("Published, rc="); Serial.print( (rc ? "OK: " : "FAILED: ") );
    Serial.println(fakeData);
    lastPublish = millis();

    
  }
}

void msgReceived(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message received on "); Serial.print(topic); Serial.print(": ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void pubSubCheckConnect() {
  if ( ! pubSubClient.connected()) {
    Serial.print("PubSubClient connecting to: "); Serial.print(awsEndpoint);
    while ( ! pubSubClient.connected()) {
      Serial.print(".");
      pubSubClient.connect("ESPthingXXXX");
      delay(1000);
    }
    Serial.println(" connected");
    pubSubClient.subscribe("inTopic");
  }
  pubSubClient.loop();
}
