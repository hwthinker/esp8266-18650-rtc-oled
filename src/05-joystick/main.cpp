#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define LEFT_btn 0
#define RIGHT_btn 1 // WARNING Tidak bisa digunakan karena akan reset
#define UP_btn 12
#define DN_btn 13
#define TOP_btn 14
#define LED_BUILTIN 2

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

bool debounce(int pin)
{
  bool state = digitalRead(pin);
  delay(50);                        // Delay debounce untuk mencegah bouncing
  return state == digitalRead(pin); // Pastikan state stabil
}

void setup()
{
  Serial.begin(115200);
  pinMode(UP_btn, INPUT_PULLUP);
  pinMode(DN_btn, INPUT_PULLUP);
  pinMode(LEFT_btn, INPUT_PULLUP);
  // pinMode(RIGHT_btn, INPUT_PULLUP);
  pinMode(TOP_btn, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

  Wire.begin(5, 4);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Test");
  display.setCursor(0, 20);
  display.println("Joystick");
  display.setCursor(0, 30);
  display.println("move");
  display.setCursor(0, 40);
  display.println("joystick");
  display.setCursor(0, 50);
  display.println("or pressed");
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop()
{

  if (!digitalRead(UP_btn))
  {
    delay(20);
    if (!digitalRead(UP_btn))
    {
      while (!digitalRead(UP_btn))
        ;
      Serial.println(F("UP_btn"));
      display.clearDisplay();
      display.setCursor(0, 30);
      display.println("UP_btn Press");
      display.display();
    }
  }

  if (!digitalRead(DN_btn))
  {
    delay(20);
    if (!digitalRead(DN_btn))
    {
      while (!digitalRead(DN_btn))
        ;
      Serial.println(F("DN_btn"));
      display.clearDisplay();
      display.setCursor(0, 30);
      display.println("DN_btn Press");
      display.display();
      delay(50);
    }
  }

  if (!digitalRead(LEFT_btn))
  {
    delay(20);
    if (!digitalRead(LEFT_btn))
    {
      while (!digitalRead(LEFT_btn))
        ;
      Serial.println(F("LEFT_btn"));
      display.clearDisplay();
      display.setCursor(0, 30);
      display.println("LEFT_btn Press");
      display.display();
      delay(50);
    }
  }

  if (!digitalRead(TOP_btn))
  {
    delay(20);
    if (!digitalRead(TOP_btn))
    {
      while (!digitalRead(TOP_btn))
        ;
      Serial.println(F("TOP_btn"));
      display.clearDisplay();
      display.setCursor(0, 30);
      display.println("TOP_btn Press");
      display.display();
      delay(50);
    }
  }
}