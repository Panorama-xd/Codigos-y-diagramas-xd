#include <Adafruit_NeoPixel.h>

#define PIN 3
#define NUMPIX 64

Adafruit_NeoPixel pixel = Adafruit_NeoPixel (NUMPIX,PIN,NEO_RGB + NEO_KHZ800);

void setup() {
  pixel.begin();
}

void loop() {
  pixel.clear();

  for(int i = 0;i<8;i++) {
    pixel.setPixelColor(i,pixel.Color(20,0,0));
    pixel.show();
    delay(250);
  }
  for(int i = 8;i<16;i++) {
    pixel.setPixelColor(i,pixel.Color(0,20,0));
    pixel.show();
    delay(250);
  }
  for(int i = 16;i<24;i++) {
    pixel.setPixelColor(i,pixel.Color(0,0,20));
    pixel.show();
    delay(250);
  }
  for(int i = 24;i<32;i++) {
    pixel.setPixelColor(i,pixel.Color(20,20,20));
    pixel.show();
    delay(250);
  }
  for(int i = 32;i<60;i++) {
    pixel.setPixelColor(i,pixel.Color(20,20,0));
    pixel.show();
    delay(250);
  }
  for(int i = 40;i<48;i++) {
    pixel.setPixelColor(i,pixel.Color(20,0,20));
    pixel.show();
    delay(250);
  }
  for(int i = 48;i<56;i++) {
    pixel.setPixelColor(i,pixel.Color(0,20,20));
    pixel.show();
    delay(250);
  }
}
  
