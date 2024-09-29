#include <Arduino.h>
#define LED_Board 16
#define LED_ESP 2
void setup()
{
  pinMode(LED_ESP, OUTPUT);
  pinMode(LED_Board, OUTPUT);
}

void loop()
{
  digitalWrite(LED_ESP, HIGH);
  delay(500);
  digitalWrite(LED_ESP, LOW);
  delay(500);
  digitalWrite(LED_Board, HIGH);
  delay(500);
  digitalWrite(LED_Board, LOW);
  delay(500);
}