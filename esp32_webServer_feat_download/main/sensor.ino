void startBME()
{
    I2Cone.begin(SDA, SCL, 100000);
    bool status1 = bme.begin(0x76, &I2Cone);
    if (!status1)
    {
        Serial.println("BME ERROR");
    }
}

void updateSensorValues()
{
    temperature = bme.readTemperature();
    humidity = bme.readHumidity();
}