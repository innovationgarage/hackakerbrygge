#include <Adafruit_NeoPixel.h>

static const int NUM_LEDS = 11;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(
                            NUM_LEDS,             // Number of pixels in strip
                            12,                   // Pin number (most are valid)
                            NEO_GRB + NEO_KHZ800  //  pixel type flags, add together as needed:
                            //   NEO_RGB     Pixels are wired for RGB bitstream
                            //   NEO_GRB     Pixels are wired for GRB bitstream
                            //   NEO_KHZ400  400 KHz bitstream (e.g. Old FLORA pixels)
                            //   NEO_KHZ800  800 KHz bitstream (e.g. New FLORA pixels and most WS2811 strips)
                          );

Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(
                             NUM_LEDS,             // Number of pixels in strip
                             11,                   // Pin number (most are valid)
                             NEO_GRB + NEO_KHZ800  //  pixel type flags, add together as needed:
                             //   NEO_RGB     Pixels are wired for RGB bitstream
                             //   NEO_GRB     Pixels are wired for GRB bitstream
                             //   NEO_KHZ400  400 KHz bitstream (e.g. Old FLORA pixels)
                             //   NEO_KHZ800  800 KHz bitstream (e.g. New FLORA pixels and most WS2811 strips)
                           );

void flashAll(byte r, byte g, byte b) {
  // Do a quick test/demo to show that things are working
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, r, g, b);
    strip2.setPixelColor(i, r, g, b);
  }
  strip.show();
  strip2.show();
}

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for port to be ready
  }

  strip.begin();
  strip2.begin();

  strip.show();
  strip2.show();

  flashAll(0, 0, 0);
  Serial.println("READY");
}
byte mode = 0;

void loop() {
  if (Serial.available() > 0)
  {
    flashAll(0, 0, 0);

    mode = Serial.read();
    Serial.print("I received ");
    Serial.println(mode);
  }

  switch (mode)
  {
    case 1:
    case '1':
      strip.setPixelColor(4, abs(-250 + (millis() % 100)), 0, 0);
      strip2.setPixelColor(3, 0.25 * abs(-500 + (millis() % 10000)), 10, 0);
      strip.setPixelColor(1, abs(-250 + (millis() % 500)) / 3, 150, 0);
      strip2.setPixelColor(1, 0.25 * abs(-500 + (millis() % 1000)), 100, 0);
      strip.setPixelColor(11, abs(-250 + (millis() % 500)) / 2, 50, 0);
      strip2.setPixelColor(10, 0.25 * abs(-500 + (millis() % 1000)) / 2, 0, 0);
      break;

    case 2:
    case '2':
      strip.setPixelColor(4, abs(-250 + (millis() % 1000)), 0, 0);
      strip2.setPixelColor(3, 0.25 * abs(-500 + (millis() % 10000)), 10, 0);
      strip.setPixelColor(2, abs(-250 + (millis() % 5000)) / 3, 150, 0);
      strip2.setPixelColor(10, 0.25 * abs(-500 + (millis() % 100)), 100, 0);
      strip.setPixelColor(10, abs(-250 + (millis() % 50)) / 2, 50, 0);
      strip2.setPixelColor(1, 0.25 * abs(-500 + (millis() % 1000)) / 2, 0, 0);
      break;

    case 3:
    case '3':
      strip.setPixelColor(1, abs(-250 + (millis() % 1000)), 0, 0);
      strip2.setPixelColor(1, 0.25 * abs(-500 + (millis() % 10000)), 10, 0);
      strip.setPixelColor(2, abs(-250 + (millis() % 5000)) / 3, 150, 0);
      strip2.setPixelColor(3, 0.25 * abs(-500 + (millis() % 100)), 100, 0);
      strip.setPixelColor(3, abs(-250 + (millis() % 50)) / 2, 50, 0);
      strip2.setPixelColor(4, 0.25 * abs(-500 + (millis() % 1000)) / 2, 0, 0);
      strip.setPixelColor(4, abs(-250 + (millis() % 100)), 0, 0);
      strip2.setPixelColor(5, 0.25 * abs(-500 + (millis() % 10000)), 10, 0);
      strip.setPixelColor(5, abs(-250 + (millis() % 500)) / 3, 150, 0);
      strip2.setPixelColor(11
                           , 0.25 * abs(-500 + (millis() % 1000)), 100, 0);
      strip.setPixelColor(7, abs(-250 + (millis() % 500)) / 2, 50, 0);
      strip2.setPixelColor(10, 0.25 * abs(-500 + (millis() % 1000)) / 2, 0, 0);
      break;

    case 4:
    case '4':
      strip.setPixelColor(1, abs(-250 + (millis() % 20)), 0, 0);
      strip2.setPixelColor(1, 0.25 * abs(-500 + (millis() % 100)), 10, 0);
      strip.setPixelColor(2, abs(-250 + (millis() % 100)) / 3, 150, 0);
      strip2.setPixelColor(3, 0.25 * abs(-500 + (millis() % 200)), 100, 0);
      strip.setPixelColor(3, abs(-250 + (millis() % 50)) / 2, 50, 0);
      strip2.setPixelColor(4, 0.25 * abs(-500 + (millis() % 100)) / 2, 0, 0);
      strip.setPixelColor(4, abs(-250 + (millis() % 100)), 0, 0);
      strip2.setPixelColor(5, 0.25 * abs(-500 + (millis() % 100)), 10, 0);
      strip.setPixelColor(5, abs(-250 + (millis() % 500)) / 3, 150, 0);
      strip.setPixelColor(7, abs(-250 + (millis() % 500)) / 2, 50, 0);
      strip2.setPixelColor(10, 0.25 * abs(-500 + (millis() % 1000)) / 2, 0, 0);
      strip.setPixelColor(4, abs(-250 + (millis() % 100)), 0, 0);
      strip2.setPixelColor(3, 0.25 * abs(-500 + (millis() % 10000)), 10, 0);
      strip.setPixelColor(1, abs(-250 + (millis() % 500)) / 3, 150, 0);
      strip2.setPixelColor(1, 0.25 * abs(-500 + (millis() % 1000)), 100, 0);
      strip.setPixelColor(11, abs(-250 + (millis() % 500)) / 2, 50, 0);
      strip2.setPixelColor(10, 0.25 * abs(-500 + (millis() % 1000)) / 2, 0, 0);
      break;

    case 5:
    case '5':
      strip.setPixelColor(4, abs(-250 + (millis() % 500)), 0, 0);
      strip2.setPixelColor(10, abs(-250 + (millis() % 500)), 0, 0);
      strip2.setPixelColor(3, 0.25 * abs(-500 + (millis() % 1000)), 0, 0);
      break;

    case 6:
    case '6':
      strip.setPixelColor(7, (millis() % 1000) > 500 ? 255 : 0, 0, 0);
      break;

    case 7:
    case '7':
      for (int i = 0; i < 11; i++)
      {

        if (i % 2 == 0)
        {
          strip2.setPixelColor(i, 0, 100 + (millis() % 1280) / 10, 100);
          strip.setPixelColor(i, 0,  100, 100 + (millis() % 1280) / 10);
        }
        else
        {
          strip2.setPixelColor(i, 0, 150 + (millis() % 1000) / 10, 80);
          strip.setPixelColor(i, 0,  80, 150 + (millis() % 1000) / 10);
        }
      }
      break;
  }

  strip.show();
  strip2.show();

}
