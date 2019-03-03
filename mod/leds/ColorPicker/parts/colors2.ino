}
CRGB apaFix(CRGB led){
  int tr = led.red;
  led.red = led.blue;
  led.blue = tr;
  return led;
}

void loop() { 
 if(onlyOnce == 0){
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
   FastLED.setBrightness(BRIGHTNESS);
   FastLED.show();
   onlyOnce++;
 }
}
