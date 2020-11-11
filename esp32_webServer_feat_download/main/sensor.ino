void updateSensorValues()
{
    temperature = bme.readTemperature();
    humidity = bme.readHumidity();
}