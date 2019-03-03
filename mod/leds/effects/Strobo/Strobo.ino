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
int minB = 0;
int maxB = 255;// Thats full on, watch the power!

 int speed = 50;


void setup() { 
      // Uncomment/edit one of the following lines for your leds arrangement.
      // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  	  // FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
      // FastLED.addLeds<APA104, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<GW6205, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<GW6205_400, DATA_PIN, RGB>(leds, NUM_LEDS);
      
      // FastLED.addLeds<WS2801, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<P9813, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<APA102, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<DOTSTAR, RGB>(leds, NUM_LEDS);

      // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
       FastLED.addLeds<APA102, DATA_PINa, CLOCK_PIN, RGB>(ledsa, NUM_LEDSa);
       FastLED.addLeds<APA102, DATA_PINb, CLOCK_PIN, RGB>(ledsb, NUM_LEDSb);
      // FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
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
/*
CRGB apaFixAll(CRGB leds[],int arraySize){
  //int ledsSize = sizeof(leds)/sizeof(int);
  int i=0;
  while(i < arraySize){
    //CRGB led = leds[i];
    leds[i] = apaFix(leds[i]);
    i++;
  }
  return leds;
}*/
int dir = 0;
int curC = 4;
void loop() { 
 if(dir == 0){
   int i=0;
   while(i<NUM_LEDSa){
      ledsa[i]=apaFix(colors[curC]); 
      i++;
   }
   i=0;
   while(i<NUM_LEDSb){
      ledsb[i]=apaFix(colors[curC]); 
      i++;
   }
   dir++;
 }else{
  int i=0;
   while(i<NUM_LEDSa){
      ledsa[i]=apaFix(led_off); 
      i++;
   }
   i=0;
   while(i<NUM_LEDSb){
      ledsb[i]=apaFix(led_off); 
      i++;
   }
   dir = 0;
 }
   FastLED.setBrightness(maxB);
   FastLED.show();
 /*if(curC <4){
  curC++;
 }else{
  curC = 0;
 }*/
 delay(speed);
}
