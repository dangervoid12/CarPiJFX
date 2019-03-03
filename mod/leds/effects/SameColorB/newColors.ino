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
//#define BRIGHTNESS 100
#define MAX_BRIGHTNESS 255      // Thats full on, watch the power!
#define MIN_BRIGHTNESS 10 
int curBmin, curBmax;
int curStep;

boolean dir = false;
int onlyOnce = 0;
void setup() {
      FastLED.addLeds<APA102, DATA_PINa, CLOCK_PIN, RGB>(ledsa, NUM_LEDSa);
      FastLED.addLeds<APA102, DATA_PINb, CLOCK_PIN, RGB>(ledsb, NUM_LEDSb);
      led_off= CRGB::Black;
      
      curStep = 5;
      curBmin = 100;
      curBmax = 100;
      color1 = CRGB::Red;
      color2 = CRGB::Blue;
color1 = 0xff0000;
 color2 = 0xff0000;
 curBmin = 31;
 curBmax = 148;
 curStep = 5;
}
CRGB apaFix(CRGB led){
  int tr = led.red;
  led.red = led.blue;
  led.blue = tr;
  return led;
}
int curB = curBmin;
void loop() { 

   int i=0;
   while(i<NUM_LEDSa){
      ledsa[i]=apaFix(color1); 
      
      i++;
   }
   i=0;
   while(i<NUM_LEDSb){
      ledsb[i]=apaFix(color2); 
      i++;
   }
   FastLED.setBrightness(curB);
   FastLED.show();
   if(dir == false){ //goes from 0 to max
    if(curB < curBmax){
      curB = curB + curStep;
    }else{
      dir = true;
    }
  }else{
    if(curB > curBmin){
      curB = curB - curStep;
    }else{
      dir = false;
    }
  }
  delay(25);
}

