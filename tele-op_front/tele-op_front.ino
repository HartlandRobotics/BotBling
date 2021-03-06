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

#define SPEED 50
#define NUMPIXELS 74
#define LONG 22
#define SHORT 15
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

int      n = 0, head = SHORT, tail = 0, temp = 0, head2 = LONG + SHORT, tail2 = head, 
temp2 = 0, head3 = 2 * SHORT + LONG, tail3 = SHORT + LONG, temp3 = 0, head4 = NUMPIXELS, tail4 = head3, temp4 = 0;

void loop(){

if(FRONT == 0){
  
for(n = 0;n < SHORT + 4;n++)
  {
    strip.setPixelColor(n, color.color1);
    if(SPEED != 0){
    strip.show();
    delay(SPEED);
    }  
  }

for(n = SHORT + 4;n <= NUMPIXELS - 5;n++)
  {
    strip.setPixelColor(n, color.color2);
    if(SPEED != 0){
    strip.show();
    delay(SPEED);
    }    
  }
  
for(n = NUMPIXELS - 4;n < NUMPIXELS;n++)
  {
    strip.setPixelColor(n, color.color1);
    if(SPEED != 0){
    strip.show();
    delay(SPEED);
    }   
  }  
                         
}

else{
  
  for(n = 0;n < (SHORT + LONG - 4);n++)
  {
    strip.setPixelColor(n, color.color4);
    if(SPEED != 0){
    strip.show();
    delay(SPEED);
    }  
  }

for(n = SHORT + LONG - 4;n < (2 * SHORT + LONG + 4);n++)
  {
    strip.setPixelColor(n, color.color3);
    if(SPEED != 0){
    strip.show();
    delay(SPEED);
    }    
  }
  
for(n = 2 * SHORT + LONG + 4;n <= NUMPIXELS;n++)
  {
    strip.setPixelColor(n, color.color4);
    if(SPEED != 0){
    strip.show();
    delay(SPEED);
    }    
  }
     
}

  strip.show();

}
