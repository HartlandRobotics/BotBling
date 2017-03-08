#include <Adafruit_DotStar.h>
#include <SPI.h>

#define NUMPIXELS 21

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

int      head  = 0, tail = 2, temp = 0, head2 = 19, tail2 = 21, temp2 = 0, bounce = -1;  
uint32_t color = 0x0000FFFF;      // 'On' color 00(B)(R)(G)
uint32_t color2 = 0x00FF0000;

void loop() {
  
  strip.setPixelColor(head2, color2); 
  strip.setPixelColor(tail2, 0);
  strip.setPixelColor(head, color); 
  strip.setPixelColor(tail, 0);     
  strip.show();                     
  delay(60);                        
  
  if(head > tail) {        
    (++head);                 
  }
  else(--head);

  if(head > tail) {         
    (++tail);                 
  }
  else(--tail);
  
  if((color >>= 0) == 0)          
      color = 0xFFFF00;             
  
  if(head > NUMPIXELS-1) {
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
  
  if((color >>= 0) == 0)          
      color = 0xFF0000;             
  
  if(head2 > NUMPIXELS-1) {
    (temp2 = head2);
    (head2 = tail2);
    (tail2 = temp2);
  }

  if(head2 < 0) {
    (temp2 = head2);
    (head2 = tail2);
    (tail2 = temp2);
  }

}
