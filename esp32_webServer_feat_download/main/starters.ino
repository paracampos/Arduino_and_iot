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

void startSHT31()
{
  // default settings
  // (you can also pass in a Wire library object like &Wire2)
  if (!sht31.begin(0x44))
    Serial.println("SHT31_A não está funcionando , check os cabos");
}

void startSPIFFS()
{
  if (!SPIFFS.begin())
  {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
}
