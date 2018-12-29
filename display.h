#ifndef DISPLAY_H
#define DISPLAY_H
#include "phase.h"
  int start_display();
  void start_screen();   // 1st screen when start up
  void manual_screen(phase led); // screen at manual mode
  void auto_screen(phase led, phase next_phase, int hour, int minute); // screen at auto mode
  void menu_screen(int menu_pos); // main menu screen
  void phase_select_screen( int phase_pos); // screen when choosing phase to set value
  void phase_setting_screen(phase setting_phase);
  void time_screen(int hour, int minute, int r_value, int g_value); // r-g value from pot res
#endif
