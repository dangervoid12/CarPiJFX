#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDSa 13
#define NUM_LEDSb 13

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PINa 12
#define DATA_PINb 10
#define CLOCK_PIN 11

// Define the array of leds
CRGB led_off;
CRGB ledsa[NUM_LEDSa];
CRGB ledsb[NUM_LEDSb];
CRGB color1,color2;
#define BRIGHTNESS 100

int curBrightness =255;
int onlyOnce = 0;
void setup() {
      FastLED.addLeds<APA102, DATA_PINa, CLOCK_PIN, RGB>(ledsa, NUM_LEDSa);
      FastLED.addLeds<APA102, DATA_PINb, CLOCK_PIN, RGB>(ledsb, NUM_LEDSb);
      led_off= CRGB::Black;
      
      color1 = CRGB::Red;
      color2 = CRGB::Blue;
