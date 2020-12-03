#include "WiFi.h"
#include <Wire.h>
#include "ESPAsyncWebServer.h"
#include "Adafruit_SHT31.h"
#include <SPIFFS.h>
#include "FS.h"
#include <Adafruit_Sensor.h>
#include "RTClib.h"

#define uS_TO_S_FACTOR 1000000
#define TIME_TO_SLEEP 10

RTC_DS3231 rtc;
Adafruit_SHT31 sht31 = Adafruit_SHT31();
AsyncWebServer server(80);

String lastfile = "/a.txt";
String dataline();
//bool print_wakeup_reason();
bool modo = false;

//sensor values
float temperature = 1;
float humidity = 1;

void setup()
{
  Serial.begin(9600);
  startSPIFFS();
  modo = !print_wakeup_reason();

  if (modo)
  {
    startRTC();
    startSHT31();
    deleteFile(SPIFFS, "/a.txt");
    writeFile(SPIFFS, "/a.txt", "Start");
  }
  else
  {
    startWifi();
    delay(2000);
    //home page
    server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
      request->send(SPIFFS, "/index.html", String(), false);
    });
    //tries to direct send the txt
    server.on("/direct", HTTP_GET, [](AsyncWebServerRequest * request) {
      request->send(SPIFFS, "/b.txt");
    });
    //send txt as a file
    server.on("/filehard", HTTP_GET, [](AsyncWebServerRequest * request) {
      request->send(SPIFFS, lastfile, String(), true);
    });
    server.begin();
  }
}

void loop()
{
  if (modo)
  {
    printValues();
    //delay(3000);
    for (byte i = 0; i <= 2; i++)
    {
      String buf = dataline(i);
      char __dataFileName[sizeof(buf)];
      buf.toCharArray(__dataFileName, sizeof(__dataFileName));
      appendFile(SPIFFS, "/a.txt", __dataFileName);
    }
    //startSleep();
  }

  //if (millis() >= 30000)
  //  startSleep();
}
