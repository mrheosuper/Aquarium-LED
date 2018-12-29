#include "gpio.h"
#include <Arduino.h>
void start_gpio()
{
  pinMode(r_pot,INPUT);
  pinMode(g_pot,INPUT);
  pinMode(b_pot,INPUT);
  pinMode(w_pot,INPUT);
  pinMode(r_pin,OUTPUT);
  pinMode(g_pin,OUTPUT);
  pinMode(b_pin,OUTPUT);
  pinMode(w_pin,OUTPUT);
  pinMode(mode_switch,INPUT_PULLUP);
  pinMode(select_pin,INPUT_PULLUP);
  pinMode(enter_pin,INPUT_PULLUP);
}
