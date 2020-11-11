void printValues()
{
    Serial.print(millis());
    DateTime now = rtc.now();
    Serial.print(now.day(), DEC);
    Serial.print("/n");
    Serial.print(now.month(), DEC);
    Serial.print(" ");
    Serial.print(now.hour(), DEC);
    Serial.print(":");
    Serial.print(now.minute(), DEC);
    Serial.print(":");
    Serial.println(now.second(), DEC);

    Serial.print("Temperatura 1 = ");
    Serial.print(bme.readTemperature());
    Serial.print(" *C ");

    Serial.print(" Humidade 1 = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");

    Serial.print("Temperatura 2 = ");
    Serial.print(bme_2.readTemperature());
    Serial.print(" *C ");

    Serial.print(" Humidade 2 = ");
    Serial.print(bme_2.readHumidity());
    Serial.println(" %");

    delay(1000);
}
