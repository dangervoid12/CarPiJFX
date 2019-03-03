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
CRGB colors[4];

void setup() { 
      FastLED.addLeds<APA102, DATA_PINa, CLOCK_PIN, RGB>(ledsa, NUM_LEDSa);
       FastLED.addLeds<APA102, DATA_PINb, CLOCK_PIN, RGB>(ledsb, NUM_LEDSb);
      // FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      led_off= CRGB::Black;
      
      colors[0] = CRGB::Red;
      colors[1] = CRGB::Navy;
      colors[2] = CRGB::BlueViolet;
      colors[3] = CRGB::CornflowerBlue;
}
CRGB apaFix(CRGB led){
  int tr = led.red;
  led.red = led.blue;
  led.blue = tr;
  return led;
}


void loop() { 
  
   int i=NUM_LEDSa - 1;
   while(i>0){
      ledsa[i]=apaFix(colors[0]);
      ledsb[i]=apaFix(colors[0]);
      if(i<(NUM_LEDSa -1)){
        ledsa[i+1]=apaFix(led_off);
        ledsb[i+1]=apaFix(led_off);
      }
      if(i==0){
        
      }
      FastLED.show();
      delay(50);
    i--;
   }
   ledsa[1] = apaFix(led_off);
    ledsa[0] = apaFix(colors[0]);
    ledsb[1] = apaFix(led_off);
    ledsb[0] = apaFix(colors[0]);
    FastLED.show();
    delay(50);
    ledsa[0] = apaFix(led_off);
    ledsb[0] = apaFix(led_off);
    FastLED.show();  
}
