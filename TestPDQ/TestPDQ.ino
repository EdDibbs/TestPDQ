#include <Arduino.h>
#include <PDQ_FastPin.h>
#include "PDQ_ST7735_config.h"
#include <PDQ_ST7735.h>
#include <SPI.h>
#include <PDQ_GFX.h>
#include "Screen.h"

PDQ_ST7735 tft; //static
//namespace{
  
  void _ScreenBegin()
  {
    tft.begin();
    tft.setAddrWindow(0, 0, tft.width()-1, tft.height()-1);
    tft.fillScreen(0x00);
  }

  void _SetRotation(int rot)
  {
    tft.setRotation(rot);
  }
  
  void _DrawPixel(uint16_t xpos, uint16_t ypos, uint16_t color)    {
      tft.drawPixel(xpos, ypos, color);
    }

  void _FillRect(uint16_t xpos, uint16_t ypos, uint16_t width, uint16_t height, uint16_t color){
    tft.fillRect(xpos, ypos, width, height, color);
    }

  int _ScreenWidth()
  {
    return tft.width();
  }

  int _ScreenHeight()
  {
    return tft.height();
  }

  void _FillScreen(uint16_t color)
  {
    tft.fillScreen(color);
  }
//}
void setup() {
  // put your setup code here, to run once:
  Screen::Instance().Init();  
}

void loop() {
  // put your main code here, to run repeatedly:
  int width = _ScreenWidth();
  int height = _ScreenHeight();

  testScreen();
  delay(500);
}


void testScreen()
{
  int32_t  w = tft.width();
  int32_t h = tft.height();
  _FillScreen(0x00);
  
  for (uint16_t y = 0; y < h; y++)
  {
    for (uint16_t x = 0; x < w; x++)
    {
      Screen::Instance().DrawPixel(x, y, (x+y % 0xFFFF));
    }
  }  
}
