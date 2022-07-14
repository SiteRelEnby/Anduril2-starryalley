// Wurkkos TS10 (originally used Sofirn SP36-t1616 firmware) config options for Anduril using the Attiny1616
// same as  the  BLF Q8, mostly
#include "cfg-blf-q8-t1616.h"
#undef MODEL_NUMBER
#define MODEL_NUMBER "0714"
// ATTINY: 1616

#ifdef USE_INDICATOR_LED_WHILE_RAMPING
#undef USE_INDICATOR_LED_WHILE_RAMPING
#endif

// voltage readings were a little high with the Q8 value
#undef VOLTAGE_FUDGE_FACTOR
#define VOLTAGE_FUDGE_FACTOR 5  // add 0.25V, not 0.35V

// the high button LED mode on this light uses too much power
// off mode: low (1)
// lockout: blinking (3)
#ifdef INDICATOR_LED_DEFAULT_MODE
#undef INDICATOR_LED_DEFAULT_MODE
#define INDICATOR_LED_DEFAULT_MODE ((3<<2) + 1)
#endif

// don't blink during the ramp; the button LED brightness is sufficient
// to indicate which power channel(s) are being used
#ifdef BLINK_AT_RAMP_MIDDLE
#undef BLINK_AT_RAMP_MIDDLE
#endif
#ifdef BLINK_AT_RAMP_CEIL
#undef BLINK_AT_RAMP_CEIL
#endif

// stop panicking at ~60% power or ~3000 lm
#ifdef THERM_FASTER_LEVEL
#undef THERM_FASTER_LEVEL
#endif
#define THERM_FASTER_LEVEL 130

// candle mode doesn't have thermal throttling. With TS10 it gets hot very fast.
// by raising PWM bits here it not only makes candle mode smoother but also safer to use
#define PWM_TOP_CANDLE 0x3FF // 1023, 10bit PWM, max power is only 25%
#define PWM_TOP_FIREWORK 0xFF // 255, 8bit PWM, max power is 100%
