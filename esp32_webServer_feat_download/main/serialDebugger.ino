void printValues()
{
  //Serial.print(millis());
  DateTime now = rtc.now();
  Serial.print(now.day(), DEC);
  Serial.print("/");
  Serial.print(now.month(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(":");
  Serial.print(now.minute(), DEC);
  Serial.print(":");
  Serial.println(now.second(), DEC);

  Serial.print("Temperatura 1 = ");
  Serial.print(sht31.readTemperature());
  Serial.print(" *C ");

  Serial.print(" Umidade 1 = ");
  Serial.print(sht31.readHumidity());
  Serial.println(" %");

  delay(1000);
}
