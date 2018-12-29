#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <gfxfont.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#ifndef disp_i2c 
  #include <SPI.h>
#endif
#include "constant.h"
#include "display.h"
#include "phase.h"
#ifdef disp_i2c 
Adafruit_SSD1306 display(disp_reset);
#else
Adafruit_SSD1306 display(disp_width,disp_height,
  disp_mosi, disp_clk, disp_dc,disp_reset,disp_cs);
#endif
/////////////menu_screen_text
const char * menu_text[NUM_OF_MENU]={"PHASE_SETTING", "TIME_SETTING", "RETURN"};
////////////////////////////////////
void SetCurPri(int x, int y, __FlashStringHelper* text);  
/////////////////////intial_display
int start_display()
{
  #ifdef disp_i2c
    if(display.begin(SSD1306_SWITCHCAPVCC, disp_addr))
  #else
    if(display.begin(SSD1306_SWITCHCAPVCC))
  #endif
    {
      display.clearDisplay();
      display.display();
      display.setTextSize(0);
      display.setTextColor(WHITE);
      return 1;
    }
    else return 0;
}
////////////////////main_screen
void start_screen()
{
  display.clearDisplay();
  SetCurPri(0,0,F("Aquarium Light"));
  SetCurPri(0,LINE_GAP,F("Version:"));
  display.print(F(VERSION));
  display.display();
}
/////////////////// manual_screen
void manual_screen(phase led)
{
  display.clearDisplay();
  SetCurPri(0,0, F("Manual Mode"));
  SetCurPri(0,LINE_GAP, F("R Led: "));
  display.print(led.r_value);
  SetCurPri(0,2*LINE_GAP, F("G Led: "));
  display.print(led.g_value);
  SetCurPri(0,3*LINE_GAP, F("B Led: "));
  display.print(led.b_value);
  SetCurPri(0,4*LINE_GAP, F("W Led: "));
  display.print(led.w_value);
  display.display();
}
///////////////////auto_screen
void auto_screen(phase led, phase next_phase, int hour, int minute)
{
  display.clearDisplay();
  SetCurPri(0,0,F("Auto Mode"));
  display.setCursor(0,LINE_GAP);
  display.print(hour); display.print(F(":")); display.print(minute); // print time on screen
  SetCurPri(0,2*LINE_GAP,F("R Led:"));
  display.print(led.r_value);display.print(F("->"));display.print(next_phase.r_value); // show current and next value of red led
  SetCurPri(0,3*LINE_GAP,F("G Led:"));
  display.print(led.g_value);display.print(F("->"));display.print(next_phase.g_value);
  SetCurPri(0,4*LINE_GAP,F("B Led:"));
  display.print(led.b_value);display.print(F("->"));display.print(next_phase.b_value);
  SetCurPri(0,5*LINE_GAP,F("W Led:"));
  display.print(led.w_value);display.print(F("->"));display.print(next_phase.w_value);
}
////////////////////menu_screen
void menu_screen(int menu_pos)
{
  display.clearDisplay();
  for(int i=0;i<NUM_OF_MENU;i++)
  {
    display.setCursor(8,i*LINE_GAP); display.print(menu_text[i]);
  }
}
/////////////quick function to setcursor and print
void SetCurPri(int x, int y,const __FlashStringHelper* text)        // Set Cursor and Print
{
  display.setCursor(x,y);
  display.print(text);
}
