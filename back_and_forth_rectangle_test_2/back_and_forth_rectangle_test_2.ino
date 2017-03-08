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
uint32_t yellow = 0x00202000;
uint32_t green = 0x00FF0000;
uint32_t blue = 0x00000020;
uint32_t purple = 0x000080FF;
uint32_t pink = 0x000FFF07;

struct_color color = {blue, yellow, blue, yellow};  

#define NUMPIXELS 74
#define LONG 22
#define SHORT 15
#define LENGTHs 4
#define LENGTHl 6
#define RANDOM 2

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

int      SPEED = 15, head, tail, temp = 0, head2 = head + 1, tail2 = head2 + LENGTHl, 
temp2 = 0, head3 = SHORT + LONG, tail3 = head3 - LENGTHs, temp3 = 0, head4 = head3 + 1, tail4 = head4 + LENGTHl, temp4 = 0;

float  headfloat = 0;

void loop() {

  if(head >= tail){
  (headfloat = headfloat + 0.04);
  head = (int) (headfloat * SHORT);
  head2 = (int) ((1 - headfloat) * LONG + SHORT + 1);
  head3 = (int) (headfloat * SHORT + SHORT + LONG - 1);
  head4 = (int) ((1 - headfloat) * LONG + 2 * SHORT + LONG + 1);
  tail = head - LENGTHs;
  tail2 = head2 + LENGTHl;
  tail3 = head3 - LENGTHs;
  tail4 = head4 + LENGTHl;
  }
  
  else{
  (headfloat = headfloat - 0.04);
  head = (int) (headfloat * SHORT);
  head2 = (int) ((1 - headfloat) * LONG + SHORT - 1);
  head3 = (int) (headfloat * SHORT + SHORT + LONG + 1);
  head4 = (int) ((1 - headfloat) * LONG + 2 * SHORT + LONG - 1);
  tail = head + LENGTHs;
  tail2 = head2 - LENGTHl;
  tail3 = head3 + LENGTHs;
  tail4 = head4 - LENGTHl;
  }
    
  if(headfloat >= 1) {
    (temp = head);
    (head = tail);
    (tail = temp);
    headfloat = 1 - ((float) LENGTHs/(float) SHORT);
  }

  if(headfloat <= 0) {
    (temp = head);
    (head = tail);
    (tail = temp);
    headfloat = (float) LENGTHs/(float) SHORT;
  } 
  
  if((color.color1 >>= 0) == 0)          
      color.color1 = 0xFFFF00;             
  
  if((color.color1 >>= 0) == 0)          
      color.color1 = 0xFF0000;             
   
  if((color.color1 >>= 0) == 0)          
      color.color1 = 0xFF0000;             

  if((color.color1 >>= 0) == 0)          
      color.color1 = 0xFF0000;             

  strip.setPixelColor(head, color.color1); 
  strip.setPixelColor(tail, 0);
  strip.setPixelColor(head3, color.color3);
  strip.setPixelColor(tail3, 0);
  strip.setPixelColor(head2, color.color2); 
  strip.setPixelColor(tail2, 0);
  strip.setPixelColor(head4, color.color4);
  strip.setPixelColor(tail4, 0);     
  strip.show();                     
  delay(SPEED);
  
}
