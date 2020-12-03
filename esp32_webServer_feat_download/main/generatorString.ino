String dataline(byte option)
{
  String exportString = "";
  if (option == 0)
  {
    DateTime now = rtc.now();
    exportString += String(now.day());
    exportString += "/";
    exportString += String(now.month());
    exportString += "_";
    exportString += String(now.hour());
    exportString += ":";
    exportString += String(now.minute());
  }
  else if (option == 1)
  {
    exportString += "_T";
    exportString += String(sht31.readTemperature());
  }
  else if (option == 2) {
    exportString += "_H";
    exportString += String(sht31.readHumidity());
    exportString += "\n";
  }
  return exportString;
}
