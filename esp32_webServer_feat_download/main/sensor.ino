void updateSensorValues()
{
  temperature = sht31.readTemperature();
  humidity = sht31.readHumidity();
  Serial.print("T: ");
  Serial.println(temperature);
  Serial.print("H: ");
  Serial.println(humidity);
}
