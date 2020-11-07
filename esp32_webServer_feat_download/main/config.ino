//access point config
const char *ssid = "alcoolgel";    //netwok name
const char *password = "12345678"; //netwok password

IPAddress local_ip(192, 168, 1, 7);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

//BME280 i2c PINS
#define SDA 21
#define SCL 22