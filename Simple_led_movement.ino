#include <FastLED.h>


/* This sketch is written to validate the LED strip listed below
 * 
 * BTF-LIGHTING WS2811 5m 16.4ft 60LEDs/m 20Pixels/m 300LEDs 100pixels
 * https://www.amazon.com/gp/product/B01CNL6MNM/
 * 
 * It's addressable chip is WS2811
 * the LED order a BRG
 * There is no white (to get white all three must be powered)
 * There are 100 addressable locations, each address controls 3 leds
 * totalling 300 LEDS
 * 
 * This sketch addresses the chip using pin 6 as the data pin
 * 
 * And it relies on the FastLED library
 * https://github.com/FastLED/FastLED
 * 
 * 
 * The program sets `leds` locations 0, 1, 2, and 3 to 
 * Green, Blue, Red, and White respectively, where they are
 * CRGB data types.
 * 
 * Author(s): Keith Murray
 *            contact: kmurrayis@gmail.com
 */



#define NUM_LEDS 100
#define DATA_PIN 6
CRGB leds[NUM_LEDS];

void pass_light_down(int start_led, int stop_led, CRGB color, bool forward) {
  /*
   * From start to stop, flicker on and off each led the input CRGB color
   * 
   * If forward is true, for loop will increment up, otherwise it'll go down
   * (This could be simplified by `if (start_led < stop_led)`, however this
   * might increase readability/make it easier to make sure it's moving the 
   * direction the user intends on. 
   */
  int i;
  
  if (forward){
    for (i = start_led; i < stop_led; ++i){
      leds[i] = color;
      FastLED.show();
      delay(30);
      leds[i] = CRGB::Black;
      
    }
  }
  else {
    for (i = start_led; i -- > stop_led; ){
      leds[i] = color;
      FastLED.show();
      delay(30);
      leds[i] = CRGB::Black;
      
    }
  }
}

void pass_light_and_hold(int start_led, int stop_led, CRGB color, bool forward){
  /*
   * Calls pass_light_down and then holds the stop_led-1 at the color
   */
  pass_light_down(start_led, stop_led, color, forward);
  leds[stop_led-1] = color;
  FastLED.show();
}


void setup() { 
  /*
   * Setup FastLED inputs, and initialize the starting arrangement, 
   * and hold for power up
   * 
   * FastLED Inputs:
   *   chip:      WS2811
   *   data pin:  DATA_PIN
   *   led order: BRG
   *   led count: NUM_LEDS
   * 
   */
  LEDS.addLeds<WS2811,DATA_PIN, BRG>(leds, NUM_LEDS);
  leds[3] = CRGB::White; 
  leds[2] = CRGB::Red; 
  leds[1] = CRGB::Blue; 
  leds[0] = CRGB::Green; 
  
  FastLED.show(); 
  delay(500);
}

void loop() {
  /*
   * Send lights down the strip and call them back up the strip
   */
  pass_light_and_hold(3, 100, CRGB::White, true);
  pass_light_and_hold(2, 99, CRGB::Red, true);
  pass_light_and_hold(1, 98, CRGB::Blue, true);
  pass_light_and_hold(0, 97, CRGB::Green, true);

  
  pass_light_and_hold(97, 1, CRGB::Green, false);
  pass_light_and_hold(98, 2, CRGB::Blue, false);
  pass_light_and_hold(99, 3, CRGB::Red, false);
  pass_light_and_hold(100, 4, CRGB::White, false);

}
