#ifndef PHASE_H
  #define PHASE_H
  #include "constant.h"
  typedef struct {
    int16_t r_value;
    int16_t g_value;
    int16_t b_value;
    int16_t w_value;
    } phase;
    extern phase RGB[PHASE_AMOUNT];
    extern phase current_phase;
#endif
