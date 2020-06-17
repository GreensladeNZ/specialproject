# LED Panel (CarbMon)
CarbMon consists of an Arduino Nano micro-controller, Co2 sensor and 64x16 LED panel. By default the screen will refresh with the latest reading every 10 seconds. 

## Hardware Requirements

- [Arduino Nano (ATMega 168p/328p based)](https://www.aliexpress.com/wholesale?catId=0&initiative_id=SB_20200617024300&SearchText=Arduino%20Nano)
- [MH-Z19B Carbon Dioxide Sensor](https://www.aliexpress.com/wholesale?catId=0&initiative_id=SB_20200617024414&SearchText=MH-z19B)
- [(64x16) HUB08 Based LED Matrix](https://www.aliexpress.com/item/32616683948.html?spm=a2g0s.9042311.0.0.65934c4ddjg17S)

## Required Arduino Libraries

The device sketch requires the following libraries to be downloaded and installed before compiling;

- https://github.com/adafruit/Adafruit-GFX-Library
- https://github.com/jkairys/HUB08
- https://github.com/crisap94/mhz19


## Device Sketches

**matrixnano_pwm.ino**
Use this sketch if reading sensor value via PWM pin.

**matrixnano_uart.ino**
Use this sketch if reading sensor value via software serial. 

## Power Requirements

The entire unit can be powered through the USB interface on the Arduino board. The power supply must be able to supply at least 150mA with 250mA peaks when taking sensor readings. 

The brightness of the display may dim briefly when the sensor takes a new reading. 

## Wiring
### Connecting the display
Your display will have two HUB08 connectors, be sure to use the INPUT side. 
|Arduino Pin | HUB08 Pin |
|--|--|
| D4 | A |
| D5 | B |
| D6 | C |
| D7 | D |
| D3 | OE |
| D11 | R1 |
| D13 | CLK |
| D2 | LE |
| GND | GND |
| 5V | VCC |

### Connecting the MH-Z19B Sensor
| Arduino Pin | Sensor |
|--|--|
| 5V | Vin |
| GND | GND |
| TX | D10|
| RX | D9 |

If you're running out of I/O on the Arduino you can connect the PWM pin on the sensor to D10 and use the PWM device sketch with the same results. This frees up D9 as you are no longer using a serial connection to communicate. 
