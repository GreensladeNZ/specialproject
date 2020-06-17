#include "HUB08.h"
#include "MHZ19.h"

#include <Fonts/TomThumb.h>

#define WIDTH   64
#define HEIGHT  16

// Sensor pwm
const int pwmpin = 10;

// LEDMatrix(a, b, c, d, oe, r1, stb, clk);
#define A 4
#define B 5
#define C 6
#define D 7
#define OE 3
#define R1 11
#define STB 2
#define CLK 13

// Create panel and sensor obj
HUB08 matrix(A, B, C, D, OE, R1, STB, CLK);
MHZ19 *mhz19_pwm = new MHZ19(pwmpin);

static uint32_t lastCountTime = 0;

void setup()
{
  matrix.begin();

  // Start screen
  matrix.clearDisplay();
  matrix.setFont(&TomThumb);
  
  matrix.setTextSize(2);
  matrix.setTextColor(WHITE);
  matrix.setCursor(0, 16);
  matrix.println("CarbMon");
  matrix.setTextSize(1);
  matrix.setCursor(52, 6);
  matrix.println("v2");
}


void loop()
{
    matrix.scan();

    if ((millis() - lastCountTime) > 10000) {
        lastCountTime = millis();
        
        int co2ppm = (mhz19_pwm->getPpmPwm() * 2.5);
        matrix.clearDisplay();

        matrix.setTextSize(1);
        matrix.setTextColor(WHITE);
        matrix.setCursor(0, 5);
        matrix.println("CO2 Levels");
        matrix.setTextSize(2);
        matrix.setCursor(16, 16);
        matrix.println(co2ppm);
        matrix.setTextSize(1);
        matrix.setCursor(48, 14);
        matrix.println("ppm");
    }
}
