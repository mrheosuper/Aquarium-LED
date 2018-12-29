///////////// Constant for displaying
#ifndef CONSTANT_H
  #define CONSTANT_H
  #define disp_i2c              // comment this line if using SPI oled
  #ifdef disp_i2c
    #define disp_reset 4          //display reset pin
    #define disp_addr 0x3c        //display i2c address
  #else
    #define disp_width 128
    #define disp_height 64
    #define disp_mosi
    #define disp_clk
    #define disp_dc
    #define disp_reset
    #define disp_cs
  #endif
  #define VERSION "0x00"
  #define NUM_OF_MENU 3 // NUMBER OF ELEMENT IN MENU
  #define LINE_GAP 10 // gap between each line, pixel
/////////////Constant for caculating
  #define PHASE_AMOUNT 6
  #define PHASE_SIZE 8
////////////constant for interrupt
  #define INTERRUPT_INTERVAL 200   //200ms
#endif 
