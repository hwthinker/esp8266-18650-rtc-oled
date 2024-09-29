#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RTClib.h>
#include <ESP8266WiFi.h>
#include <EasyNTPClient.h>
#include <WiFiUdp.h>
#include <SPI.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Edit lines 13 and 14 with name and password of specific wireless network
const char *ssid     = "your-wifi";  // Name of the wireless network ESP8266 will connect with
const char *password = "your-password";  // Password for wireless network
DateTime now;   //Variable to hold current time in UNIX seconds
WiFiUDP udp;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
// Declaration for the RTC IC
RTC_PCF8563 rtc;
// Declaration for NTP Client
EasyNTPClient ntpClient(udp, "pool.ntp.org", 25200); // EST = 25200 seconds in jakarta indonesia time zone

void setup() {
  Serial.begin(115200);

  // Connect ESP8266 to wireless network of choice
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Begin OLED communication
  Wire.begin(5,4);  // OLED SDA = GPIO5 SCL = GPIO4
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  // Get current time from NTP server
  now = ntpClient.getUnixTime() + 1;  // Get current time from ntp server
  Wire.begin(0,2);  // RTC SDA = 0 SCL = 2
  rtc.begin();
  rtc.start();
  rtc.adjust(now);  // load current time into PCF8563 RTC
  WiFi.disconnect(); // Disconnect ESP8266 from wireless network; not needed anymore

}

void loop() {
  Wire.begin(5,4);  //OLED SDA = GPIO5 SCL = GPIO4

  delay(1000); // Effectively update time display every second
  display.clearDisplay();

  // Write out date and time to OLED display
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10, 0);
  display.print(now.year());
  display.print('/');
  display.print(now.month());
  display.print('/');
  display.println(now.day());
  display.setCursor(14,30);
  display.print(now.hour());
  display.print(':');
  if (now.minute() < 10){  // Add a padding 0 if minutes in single digits
    display.print('0');
    display.print(now.minute());
  }
  else {
    display.print(now.minute());
  }
  display.print(':');
  if (now.second() < 10){  // Add a padding 0 if seconds in single digits
    display.print('0');
    display.println(now.second());
  }
  else {
    display.println(now.second());
  }
  
  display.display();

  Wire.begin(0,2);  // RTC SDA = 0 SCL = 2

  now = rtc.now();  // get latest time from PCF8563 RTC
}