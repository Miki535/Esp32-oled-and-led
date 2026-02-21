#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define LED_GREEN 23

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  pinMode(LED_GREEN, OUTPUT);

  Serial.begin(115200);
  
  Wire.begin(19, 18); //sda gpio19 || scl gpio18

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);

}

void loop() {
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 8);
  display.println("Hello, Hardware Developer!");

  digitalWrite(LED_GREEN, HIGH);
  display.setCursor(0, 25);
  display.println("Green led: ON");
  display.display();      
  delay(1000);

  display.clearDisplay();
  display.setCursor(0, 8);
  display.println("Hello, Hardware Developer!");
  digitalWrite(LED_GREEN, LOW);
  display.setCursor(0, 25);
  display.println("Green led: OFF");
  display.display();      
  delay(1000);
}