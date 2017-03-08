// Simple strand test for Adafruit Dot Star RGB LED strip.
// This is a basic diagnostic tool, NOT a graphics demo...helps confirm
// correct wiring and tests each pixel's ability to display red, green
// and blue and to forward data down the line.  By limiting the number
// and color of LEDs, it's reasonably safe to power a couple meters off
// the Arduino's 5V pin.  DON'T try that with other code!

#include <Adafruit_DotStar.h>
// Because conditional #includes don't work w/Arduino sketches...
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET
//#include <avr/power.h> // ENABLE THIS LINE FOR GEMMA OR TRINKET

#define NUMPIXELS 21 // Number of LEDs in strip

// Here's how to control the LEDs from any two pins:
#define DATAPIN    11
#define CLOCKPIN   13
Adafruit_DotStar strip = Adafruit_DotStar(
  NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);
// The last parameter is optional -- this is the color data order of the
// DotStar strip, which has changed over time in different production runs.
// Your code just uses R,G,B colors, the library then reassigns as needed.
// Default is DOTSTAR_BRG, so change this if you have an earlier strip.

// Hardware SPI is a little faster, but must be wired to specific pins
// (Arduino Uno = pin 11 for data, 13 for clock, other boards are different).
//Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DOTSTAR_BRG);

void setup() {

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif

  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP
}

// Runs 10 LEDs at a time along strip, cycling through red, green and blue.
// This requires about 200 mA for all the 'on' pixels + 1 mA per 'off' pixel.

int      head  = 0, tail = 2, temp = 0, head2 = 19, tail2 = 21, temp2 = 0;  // Index of first 'on' and 'off' pixels
uint32_t color = 0x0000FFFF;      // 'On' color (starts red) 00(B)(R)(G)
uint32_t color2 = 0x00FF0000;

void loop() {
  
  strip.setPixelColor(head2, color2); 
  strip.setPixelColor(tail2, 0);
  strip.setPixelColor(head, color); 
  strip.setPixelColor(tail, 0);     
  strip.show();                     
  delay(60);   


  if(head = head2) {
    color = 0x000000FF;
    color2 = 0x000000FF;
  }
  else {
    color = 0x0000FFFF;
    color2 = 0x00FF0000;
  }
  
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
  
  if(head > NUMPIXELS) {
    (temp = head - 2 );
  }
  
  if(head > NUMPIXELS) {
    (head = tail - 2 );
  }
  
  if(tail > NUMPIXELS) {
    (tail = temp - 2 );
  }

  if(head < -1) {
    (temp = head + 2 );
  }
  
  if(head < -1) {
    (head = tail + 2 );
  }
  
  if(tail < -1) {
    (tail = temp + 2 );
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
  
  if(head2 > NUMPIXELS) {
    (temp2 = head2 - 2 );
  }
  
  if(head2 > NUMPIXELS) {
    (head2 = tail2 - 2 );
  }
  
  if(tail2 > NUMPIXELS) {
    (tail2 = temp2 - 2 );
  }

  if(head2 < -1) {
    (temp2 = head2 + 2 );
  }
  
  if(head2 < -1) {
    (head2 = tail2 + 2 );
  }
  
  if(tail2 < -1) {
    (tail2 = temp2 + 2 );
  }

}
