#include <Adafruit_DotStar.h>

#define NUMPIXELS 21

#define DATAPIN    11
#define CLOCKPIN   13

Adafruit_DotStar strip = Adafruit_DotStar(
  NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);



void setup() {

  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif
  
  strip.begin();
  strip.show();

}

void loop() {

  strip.setPixelColor(1,0);
  

}
