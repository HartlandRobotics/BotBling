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

void loop() {
 
  strip.setPixelColor(head4, color.color4);
  strip.setPixelColor(tail4, 0);
  strip.setPixelColor(head3, color.color3);
  strip.setPixelColor(tail3, 0);
  strip.setPixelColor(head2, color.color2); 
  strip.setPixelColor(tail2, 0);
  strip.setPixelColor(head, color.color1); 
  strip.setPixelColor(tail, 0);     
  strip.show();                     
  delay(SPEED);                        
  
  if(head > tail) {        
    (++head);              
  }
  else(--head);
      

  if(head > tail) {
    (++tail);
  }

  else(--tail);
  
  if((color.color1 >>= 0) == 0)          
      color.color1 = 0xFFFF00;             
  
  if(head > SHORT - 1) {
    (temp = head);
    (head = tail);
    (tail = temp);
  }

  if(head < 0) {
    (temp = head);
    (head = tail);
    (tail = temp);
  }
  
  if(head2 > tail2) {        
    (++head2);              
  }
  else(--head2);
      

  if(head2 > tail2) {
    (++tail2);
  }

  else(--tail2);
  
  if((color.color1 >>= 0) == 0)          
      color.color1 = 0xFF0000;             
  
  if(head2 > SHORT + LONG - 1) {
    (temp2 = head2);
    (head2 = tail2);
    (tail2 = temp2);
  }

  if(head2 < SHORT) {
    (temp2 = head2);
    (head2 = tail2);
    (tail2 = temp2);
  }

  if(head3 > tail3) {        
    (++head3);              
  }
  else(--head3);
      

  if(head3 > tail3) {
    (++tail3);
  }

  else(--tail3);
  
  if((color.color1 >>= 0) == 0)          
      color.color1 = 0xFF0000;             
  
  if(head3 > SHORT * 2 + LONG - 1) {
    (temp3 = head3);
    (head3 = tail3);
    (tail3 = temp3);
  }

  if(head3 < SHORT + LONG) {
    (temp3 = head3);
    (head3 = tail3);
    (tail3 = temp3);
  }

  if(head4 > tail4) {        
    (++head4);              
  }
  else(--head4);
      

  if(head4 > tail4) {
    (++tail4);
  }

  else(--tail4);
  
  if((color.color1 >>= 0) == 0)          
      color.color1 = 0xFF0000;             
  
  if(head4 > NUMPIXELS - 1) {
    (temp4 = head4);
    (head4 = tail4);
    (tail4 = temp4);
  }

  if(head4 < SHORT * 2 + LONG) {
    (temp4 = head4);
    (head4 = tail4);
    (tail4 = temp4);
  }
  
}
