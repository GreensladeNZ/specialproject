#include "MHZ19.h"

const int rx_pin = 5; //Serial rx pin no
const int tx_pin = 6; //Serial tx pin no

MHZ19 *mhz19_uart = new MHZ19(rx_pin,tx_pin);

int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;

int smooth = 2;
int state = 1;
int ppm;

/* State Table:
 * Green = 1
 * Blue = 2
 * Red = 3
 */

void setup() {
  Serial.begin(115200);
  
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);

  mhz19_uart->begin(rx_pin, tx_pin);
  mhz19_uart->setAutoCalibration(false);
  
  warming();
  warming();
  warming();
  delay(1000);
  blackToGreen();
}
void loop() {
  measurement_t m = mhz19_uart->getMeasurement();
  ppm = m.co2_ppm;
  
  Serial.print("PPM: ");
  Serial.println(ppm);
  Serial.print("State: ");
  Serial.println(state);
  Serial.println("");

  if(ppm <= 1000)   // If below green threshold
  {
    if (state != 1)
    {
      if (state == 2)
      {
        yellowToGreen();
      }

      else
      {
        redToYellow();
        delay(500);
        yellowToGreen();
      }
      RGB_color(255, 0, 255); // green
    }
    state = 1;
  }

  else if((ppm > 1000) && (ppm < 2000))
  {
    if (state != 2)
    {
      if (state == 1)
      {
        greenToYellow();
      }
      
      else
      {
        redToYellow();
      }
      RGB_color(0, 0, 255); // yellow
    }
    state = 2;
  }

  else if(ppm >= 2000)
  {
    if (state != 3)
    {
      if (state == 1)
      {
        greenToYellow();
        delay(500);
        yellowToRed();
      }
      
      else
      {
        yellowToRed();
      }
      RGB_color(0, 255, 255); // red
    }
    state = 3;
  }

  delay(5000);
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
{
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}

void demo()
{
  RGB_color(255, 0, 255); // green
  delay(2000);
  
  greenToYellow();
  
  RGB_color(0, 0, 255); // yellow
  delay(2000);
  
  yellowToRed();

  RGB_color(0, 255, 255); // red
  delay(2000);

  redToYellow();
  
  RGB_color(0, 0, 255); // yellow
  delay(2000);

  yellowToGreen();
}

void greenToYellow()
{
  int maxi = 255;
  
  for(int i=0; i<=255; i++)
  {
    delay(smooth);
    maxi--;
    RGB_color(maxi, 0, 255); 
  }
}

void yellowToRed()
{
  int maxi = 0;
  
  for(int i=0; i<=255; i++)
  {
    delay(smooth);
    maxi++;
    RGB_color(0, maxi, 255);
  }
}

void redToYellow()
{
  int maxi = 0;
  
  for(int i=0; i<=255; i++)
  {
    delay(smooth);
    maxi--;
    RGB_color(0, maxi, 255); 
  }
}

void yellowToGreen()
{
  int maxi = 0;
  
  for(int i=0; i<=255; i++)
  {
    delay(smooth);
    maxi++;
    RGB_color(maxi, 0, 255); 
  }
}

void blackToGreen()
{
  for(int i=255; i>=0; i--)
  {
    delay(smooth);
    RGB_color(255, i, 255); 
  }
}

void warming() // Cycles purple light once
{
  for(int i=255; i>=0; i--)
  {
    RGB_color(i, 255, i);
    delay(10);
  }
  for(int i=0; i<=255; i++)
  {
    RGB_color(i, 255, i);
    delay(10);
  }
}
