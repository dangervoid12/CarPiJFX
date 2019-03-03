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

