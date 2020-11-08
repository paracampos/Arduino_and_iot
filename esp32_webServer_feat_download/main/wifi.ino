//just connect to wifi
void startWifi()
{
    WiFi.softAP(ssid, password);
    //WiFi.softAPConfig(local_ip, gateway, subnet);
    Serial.print("IP address: ");
    Serial.println(WiFi.softAPIP());
}
