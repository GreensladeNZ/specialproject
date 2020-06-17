
# Iceberg
![Iceberg](https://i.imgur.com/Mgnwihm.jpg)
The Iceberg consists of an Arduino Nano micro-controller, Co2 sensor and RGB LED. The enclosure changes colour depending on the air quality. 

## Hardware Requirements

- [Arduino Nano (ATMega 168p/328p based)](https://www.aliexpress.com/wholesale?catId=0&initiative_id=SB_20200617024300&SearchText=Arduino%20Nano)
- [MH-Z19B Carbon Dioxide Sensor](https://www.aliexpress.com/wholesale?catId=0&initiative_id=SB_20200617024414&SearchText=MH-z19B)
- [Common Annode RGB LED](https://www.aliexpress.com/wholesale?catId=0&initiative_id=SB_20200617033856&SearchText=Common%20Anode%20RGB%20LED)

## Required Arduino Libraries

The device sketch requires the following libraries to be downloaded and installed before compiling;

- https://github.com/crisap94/mhz19


## Power Requirements

The entire unit can be powered through the USB interface on the Arduino board. The power supply must be able to supply at least 100mA with 150mA peaks when taking sensor readings. 

The brightness of the LED may dim briefly when the sensor takes a new reading. 

## Wiring
### Connecting the RGB LED
|Arduino Pin | LED |
|--|--|
| VCC | 5V |
| R | D11 |
| G | D10 |
| B | D9 |

### Connecting the MH-Z19B Sensor
| Arduino Pin | Sensor |
|--|--|
| 5V | Vin |
| GND | GND |
| TX | D5|
| RX | D6 |
# Printing 3D Models
**base.stl** - 100% infill, non-transparent or dark material.
**basebottom.stl** - 100% infill, any material.
**iceberg.stl** - 0% infill, with white/transparent material.

# Assembly
![3D Model of assembled iceberg](https://i.imgur.com/SOvHJho.png)Standard superglue should be enough to hold everything together, and is compatible with most 3D printed plastics like ABS and PLA. Securing the light source inside the Iceberg model will vary depending on the type of LED you have and how many you choose to use. 

Try to keep the CO2 sensor as close to the ventilation holes as possible, this will help to give real-time and accurate figures when readings are taken. 

![Added weights](https://i.imgur.com/7aDDEvX.jpg)Alone, the iceberg print and electronics don't weigh very much and may be prone to excessive tipping/sliding on a smooth desk surface. In my case I added some extra weigh to the base by gluing three dead AA batteries in place next to the electronics. This provided stability to the base. 

# Behavior
Upon powerup, the Iceberg will gently strobe a purple colour as the sensor warms up. When ready it will transition to a green colour and then any subsequent colour changes are based on the air quality of the room. 

|CO2 Level (ppm)| Colour |
|--|--|
| <1000| Green |
|1000~2000|Yellow|
|2000>|Red|

A new reading is taken every 5 seconds. 

Breathing on the sensor will is a good way to test it's functionality. The sensor should transition to a yellow or red colour soon after being exposed to high levels of CO2, it may take some time for it to transition back to lower levels. 
