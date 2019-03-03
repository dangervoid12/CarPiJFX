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
CRGB colors[5];
#define MAX_BRIGHTNESS 255      // Thats full on, watch the power!
#define MIN_BRIGHTNESS 5 

boolean dir = false;
int bstep = 5;

 int onlyOnce = 0;
void setup() { 
      FastLED.addLeds<APA102, DATA_PINa, CLOCK_PIN, RGB>(ledsa, NUM_LEDSa);
      FastLED.addLeds<APA102, DATA_PINb, CLOCK_PIN, RGB>(ledsb, NUM_LEDSb);
      
      led_off= CRGB::Black;
      
      colors[0] = CRGB::Red;
      colors[1] = CRGB::Navy;
      colors[2] = CRGB::BlueViolet;
      colors[3] = CRGB::CornflowerBlue;
      colors[4] = CRGB::White;
      //colors[4].red = 0;
      //colors[4].green = 0;
      //colors[4].blue = 153;
      
}
CRGB apaFix(CRGB led){
  int tr = led.red;
  led.red = led.blue;
  led.blue = tr;
  return led;
}
int curB = 0;
void loop() { 

   int i=0;
   while(i<NUM_LEDSa){
      ledsa[i]=apaFix(colors[1]); 
      
      i++;
   }
   i=0;
   while(i<NUM_LEDSb){
      ledsb[i]=apaFix(colors[1]); 
      i++;
   }
   FastLED.setBrightness(curB);
   FastLED.show();
   if(dir == false){ //goes from 0 to max
    if(curB < MAX_BRIGHTNESS){
      curB = curB + bstep;
    }else{
      dir = true;
    }
  }else{
    if(curB > MIN_BRIGHTNESS){
      curB = curB - bstep;
    }else{
      dir = false;
    }
  }
  delay(25);
}
