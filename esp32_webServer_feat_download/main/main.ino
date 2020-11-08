#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include <SPIFFS.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

//sensor values
float temperature = 1;
float humidity = 1;

//objects
Adafruit_BME280 bme;
TwoWire I2Cone = TwoWire(1);

//define server PORT
AsyncWebServer server(80);

String lastfile = "/a.txt";

void setup()
{
    Serial.begin(115200);
    delay(500);
    startWifi();
    startBME();

    if (!SPIFFS.begin())
    {
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }

    //home page
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/index.html", String(), false);
    });

    //tries to direct send the txt
    server.on("/direct", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/a.txt");
    });

    //send txt as a plain text
    server.on("/plain", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/a.txt", "text/plain");
    });

    //send txt as a file
    server.on("/filehard", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, lastfile, String(), true);
    });

    //send html a downloadable file, test only
    server.on("/file", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/index.html", String(), true);
    });

    server.begin();
}

void loop() {}
