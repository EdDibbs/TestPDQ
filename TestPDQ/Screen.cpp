#include "Screen.h"


Screen::Screen()
{

}

void Screen::Init()
{
#if defined(ST7735_RST_PIN)        // reset like Adafruit does
  FastPin<ST7735_RST_PIN>::setOutput();
  FastPin<ST7735_RST_PIN>::hi();
  FastPin<ST7735_RST_PIN>::lo();
  delay(1);
  FastPin<ST7735_RST_PIN>::hi();
#endif
  
  //most config is done in PDQ_ST7735_config.h
  tft.begin();
  tft.setRotation(1);
  //tft.fillScreen();
}

int Screen::Width()
{
  return tft.width();
}

int Screen::Height()
{
  return tft.height();
}

void Screen::DrawPixel(short xpos, short ypos, int pixel)
{
  tft.drawPixel(xpos, ypos, pixel);
}

void Screen::Draw(short xpos, short ypos, short width, short height, int* pixels)
{
  for ( int x = 0; x < width; x++)
  {
    for (int y = 0; y < height; y++)
    {
      int index = (y * width) + x;

      int value = pixels[index];

      //because we're using all possible values of a uint16, we need to specify a 
      //color that will denote transparency. In this case, it's the equivalent of
      //magenta. These values will be ignored (not drawn).
      if (value != 0xF81F)
      {
        tft.drawPixel(xpos + x, ypos + y, value);
      }  
    }
  }
}

void Screen::DrawRect(short xpos, short ypos, short width, short height, int color)
{
  tft.fillRect(xpos, ypos, width, height, color);
}



