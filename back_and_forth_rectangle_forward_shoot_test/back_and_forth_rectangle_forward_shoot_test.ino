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
uint32_t yellow = 0x00101000;
uint32_t green = 0x00FF0000;
uint32_t blue = 0x00000010;
uint32_t purple = 0x000080FF;
uint32_t pink = 0x000FFF07;

struct_color color = {blue, yellow, yellow, yellow};  

#define NUMPIXELS 74
#define LONG 22
#define SHORT 15
#define LENGTHs 4
#define LENGTHl 6
#define RANDOM 2
#define FRONT 0

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

int     t2, x2, x, t, set = 0, n = 0, SPEED = 15, head, tail, temp = 0, head2 = SHORT + 8, tail2 = head2 - 4, 
temp2 = 0, head3 = SHORT + LONG, tail3 = head3 - LENGTHs, temp3 = 0, head4 = NUMPIXELS - 9, tail4 = head4 + 4, temp4 = 0;

float  headfloat = 0.5;

void loop() {

  if(FRONT == 0){
  if(set == 0){
  for(n = 0;n < SHORT + 4;n++)
  {
    strip.setPixelColor(n, color.color1);
    strip.show();
  }

  for(n = NUMPIXELS - 4;n < NUMPIXELS;n++)
  {
    strip.setPixelColor(n, color.color1);
    strip.show();
  }  
  set = 1;                       
  }

  if(head >= tail){
  head = (int) (headfloat * SHORT);
  head3 = (int) (headfloat * SHORT + SHORT + LONG);
  tail = head - LENGTHs;
  tail3 = head3 - LENGTHs;
  (headfloat = headfloat + 0.04);
  }
  else{
  head = (int) (headfloat * SHORT);
  head3 = (int) (headfloat * SHORT + SHORT + LONG);
  tail = head + LENGTHs;
  tail3 = head3 + LENGTHs;
  (headfloat = headfloat - 0.04);
  }

  t = t + 1;
  
  if(++head2 >= SHORT + LONG) {
    head2 = SHORT + 4;
    t = 0;
  }

  if(++tail2 >= SHORT + LONG) {
    tail2 = SHORT + 4;
    x = 0;
  }

  if(t >= 4){
    if(x = 0){
      tail2 = SHORT + 4;
      x = 1;
    }
  }

  t2 = t2 + 1;
  
  if(--head4 <= 2 * SHORT + LONG - 1) {
    head4 = NUMPIXELS - 5;
    t2 = 0;
  }

  if(--tail4 <= 2 * SHORT + LONG - 1) {
    tail4 = NUMPIXELS - 5;
    x2 = 0;
  }

  if(t2 >= 4){
    if(x2 = 0){
      tail4 = NUMPIXELS - 5;
      x2 = 1;
    }
  }
  

  if(tail4 >= 2 * SHORT + LONG){
    strip.setPixelColor(tail4, 0);
  }

  if(tail2 <= SHORT + LONG){
    strip.setPixelColor(tail2, 0);
  }
  
  strip.setPixelColor(head3, color.color3);
  strip.setPixelColor(tail3, 0);
  strip.setPixelColor(head2, color.color2); 
  strip.setPixelColor(head4, color.color4);    
  strip.show();                     
  delay(SPEED);  
  
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

  }
  
  else{
    
  if(set == 0){
  for(n = SHORT + LONG - 4;n <= 2 * SHORT + LONG + 4;n++)
  {
    strip.setPixelColor(n, color.color1);
    strip.show();
  }  
  set = 1;                       
  }

  if(head >= tail){
  head = (int) (headfloat * SHORT);
  tail = head - LENGTHs;
  (headfloat = headfloat + 0.04);
  }
  else{
  head = (int) (headfloat * SHORT);
  tail = head + LENGTHs;
  (headfloat = headfloat - 0.04);
  }

  t = t + 1;
  
  if(++head2 >= SHORT + LONG - 4) {
    head2 = SHORT;
    t = 0;
  }

  if(++tail2 >= SHORT + LONG - 4) {
    tail2 = SHORT;
    x = 0;
  }

  if(t >= 4){
    if(x = 0){
      tail2 = SHORT;
      x = 1;
    }
  }

  t2 = t2 + 1;
  
  if(--head4 <= 2 * SHORT + LONG +3) {
    head4 = NUMPIXELS - 1;
    t2 = 0;
  }

  if(--tail4 <= 2 * SHORT + LONG + 3) {
    tail4 = NUMPIXELS - 1;
    x2 = 0;
  }

  if(t2 >= 4){
    if(x2 = 0){
      tail4 = NUMPIXELS - 1;
      x2 = 1;
    }
  }
  

  if(tail4 >= 2 * SHORT + LONG){
    strip.setPixelColor(tail4, 0);
  }

  if(tail2 <= SHORT + LONG){
    strip.setPixelColor(tail2, 0);
  }
  
  strip.setPixelColor(head, color.color3);
  strip.setPixelColor(tail, 0);
  strip.setPixelColor(head2, color.color2); 
  strip.setPixelColor(tail2, 0);
  strip.setPixelColor(head4, color.color4);
  strip.setPixelColor(tail4, 0);     
  strip.show();                     
  delay(SPEED);  
  
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
  
  }
}
