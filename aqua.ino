#include "constant.h"
#include "phase.h"
#include "gpio.h"
#include "display.h"
enum interrupt_event { SELECT, MENU};
void interrupt_handle();
//////////////////main
void setup()
{
  Serial.begin(115200);
  Serial.println(F("Serial debugging Aquarium Light"));
  Serial.println(VERSION);
  start_gpio();
  if(!start_display())
  {
    Serial.println(F("Fail Starting Display"));
    while(1);
  }
}
//////////////////main loop
void loop()
{}
void interrupt_handle()
{
  
}
