#include <Adafruit_DotStar.h>

#include <SPI.h>         

struct struct_color {
  uint32_t color1;
  uint32_t color2;
  uint32_t color3;
  uint32_t color4;
};

uint32_t a = 0x0000FF00;
uint32_t b = 0x0080FF00;  // 'On' color 00(G)(R)(B)
uint32_t c = 0x00FFFF00;
uint32_t d = 0x00FF0000;
uint32_t e = 0x000000FF;
uint32_t f = 0x000080FF;
uint32_t color = a;

#define DATAPIN    11
#define CLOCKPIN   13
#define NUMPIXELS 75

Adafruit_DotStar strip = Adafruit_DotStar(
  NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

void setup() {

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); 
#endif

  strip.begin(); 
  strip.show();  
}

int   s = 0, pixel = 0;

void loop() {

  if(s >= 3){
  for(pixel = 0;pixel <= NUMPIXELS; pixel++){
    strip.setPixelColor(pixel, 0);
    s = 0;
  }
  }
 strip.show();

  for(pixel = 0;pixel <= NUMPIXELS; pixel++){
    strip.setPixelColor(random(1-75), random(0x00999999 - 0x00FF00FF));
  }
 strip.show();

 s = s + 1;
 
}
