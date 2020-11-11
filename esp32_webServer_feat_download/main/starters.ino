//just connect to wifi
void startWifi()
{
    WiFi.softAP(ssid, password);
    //WiFi.softAPConfig(local_ip, gateway, subnet);
    Serial.print("IP address: ");
    Serial.println(WiFi.softAPIP());
}

void startRTC()
{
    if (!rtc.begin())
    {
        Serial.println("Couldn't find RTC");
    }
    rtc.adjust(DateTime(__DATE__, __TIME__));
}

void startBME()
{
    bool status_1, status_2;

    // default settings
    // (you can also pass in a Wire library object like &Wire2)
    status_1 = bme.begin(0x76, &I2Cone);
    if (!status_1)
    {
        Serial.println("BME 1 não está funcionando , check os cabos");
    }
    status_2 = bme_2.begin(0x76, &I2Ctwo);
    if (!status_2)
    {
        Serial.println("BME 2 não está funcionando , check os cabos");
    }
}
void startSPIFFS()
{
    if (!SPIFFS.begin())
    {
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }
}