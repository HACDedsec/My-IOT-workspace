#include <FastLED.h>

#define LED_PIN     1
#define NUM_LEDS    60

CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

}

void loop() {

  for (int i = 0; i <= 59; i++) {
    leds[i] = CRGB ( 0, 0, 255);
    FastLED.show();
    delay(40);
  }
  for (int i = 59; i >= 0; i--) {
    leds[i] = CRGB ( 255, 0, 0);
    FastLED.show();
    delay(40);
  }

  
   for (int i = 0; i <= 59; i++) {
    leds[i] = CRGB ( 170, 0, 255);
    FastLED.show();
    delay(40);
  }


   for (int i = 0; i <= 59; i++) {
    leds[i] = CRGB ( 155, 100,0 );
    FastLED.show();
    delay(40);
  }
}
