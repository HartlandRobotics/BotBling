#include <Adafruit_DotStar.h>

#include <SPI.h>         

struct struct_color {
  uint32_t color1;
  uint32_t color2;
  uint32_t color3;
  uint32_t color4;
};

uint32_t red = 0x0000FF00;
uint32_t orange = 0x0080FF00;  // 'On' color 00(G)(R)(B)
uint32_t yellow = 0x00FFFF00;
uint32_t green = 0x00FF0000;
uint32_t blue = 0x000000FF;
uint32_t purple = 0x000080FF;
uint32_t pink = 0x000FFF07;

struct_color color = {blue, yellow, blue, yellow};  

#define NUMPIXELS 74
#define LONG 22
#define SHORT 15
#define LENGTHs 4
#define LENGTHl 6
#define SPEED 20

#define DATAPIN    11
#define CLOCKPIN   13
Adafruit_DotStar strip = Adafruit_DotStar(
  NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

void setup() {

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); 
#endif

  strip.begin(); 
  strip.show();  
}

int      head = SHORT, tail = head - LENGTHs, temp = 0, head2 = head + 1, tail2 = head2 + LENGTHl, 
temp2 = 0, head3 = 2 * SHORT + LONG, tail3 = head3 - LENGTHs, temp3 = 0, head4 = head3 + 1, tail4 = head4 + LENGTHl, temp4 = 0;

float  headfloat = 0;

void loop() {                      

  for(headfloat = 0; headfloat <= 1; headfloat = headfloat + 0.04){
  head = (int) ((headfloat * 22) + 15);
  tail = head - LENGTHs
  strip.setPixelColor(head, color.color4);
  strip.setPixelColor(tail, 0);
  delay(50);
  strip.show();
  }

}
