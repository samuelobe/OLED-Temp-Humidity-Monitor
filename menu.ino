#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET 4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int index = 1;

void setup()
{
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }

  startupScreen();
  delay(7000);

  updateMenu();
  index = 2;
  delay(3000);
  updateMenu();
  index = 3;
  delay(3000);
  updateMenu();
  index = 4;
  delay(3000);
  updateMenu();
  index = 5;
}

void loop()
{
  
}

void startupScreen()
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 1);
  display.println(F("STARTUP SCREEN!!\n"));
  display.display();
}

void updateMenu()
{
  switch (index)
  {
  case 0:
    index = 1;
    break;
  case 1:
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 1);
    display.println(F("> LINE 1"));
    display.println(F("  LINE 2"));
    display.display();
    break;
  case 2:
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 1);
    display.println(F("  LINE 1"));
    display.println(F("> LINE 2"));
    display.display();
    break;
  case 3:
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 1);
    display.println(F("> LINE 2"));
    display.println(F("  LINE 3"));
    display.display();
    break;
  case 4:
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 1);
    display.println(F("  LINE 2"));
    display.println(F("> LINE 3"));
    display.display();
  }
}
