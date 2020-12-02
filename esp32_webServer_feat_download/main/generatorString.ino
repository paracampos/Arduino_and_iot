String dataline()
{
  String exportString = "";
  DateTime now = rtc.now();
  exportString += String(now.hour());
  exportString += ":";
  exportString += String(now.minute());
  //  exportString += "a";
  exportString += String(sht31.readTemperature());
  // exportString += "a";
  //exportString += String(sht31.readHumidity());
  return exportString;
}
