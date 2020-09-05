# Simple LED Movemet Test

This sketch is written to validate the LED strip listed below
 
BTF-LIGHTING WS2811 5m 16.4ft 60LEDs/m 20Pixels/m 300LEDs 100pixels
https://www.amazon.com/gp/product/B01CNL6MNM/

It's addressable chip is WS2811
the LED order a BRG
There is no white (to get white all three must be powered)
There are 100 addressable locations, each address controls 3 leds
totalling 300 LEDS

This sketch addresses the chip using pin 6 as the data pin

And it relies on the FastLED library
https://github.com/FastLED/FastLED


The program sets `leds` locations 0, 1, 2, and 3 to 
Green, Blue, Red, and White respectively, where they are
CRGB data types.

Author(s): Keith Murray
        contact: kmurrayis@gmail.com