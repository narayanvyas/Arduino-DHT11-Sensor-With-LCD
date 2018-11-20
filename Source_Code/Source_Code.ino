/*  DHT11 Sensor With LCD
 *   
 *  GitHub URL - https://github.com/narayanvyas/Arduino-DHT11-Sensor-With-LCD
 * 
 *  Developed By Web Dev Fusion
 *  URL - https://www.webdevfusion.com
 *  
 * Components
 * ----------
 *  - Arduino Uno
 *  - 10KOhm potentiometer
 *  - DHT11
 *  - 16x2 LCD Screen
 *  - 4.7k Resistor
 *  - jumper wires
 *  - Breadboard
 *  
 *  Libraries
 *  ---------
 *  - LiquidCrystal (comes with Arduino IDE)
 *  - Unified Sensor - https://github.com/adafruit/Adafruit_Sensor
 *
 * Connections
 * -----------
 *  LCD screen    |    Arduino Uno
 *  -----------------------------
 *      1  (Vss)  |      GND
 *      2  (Vdd)  |      5V
 *      3  (VO)   |      Potentiometer
 *      4  (RS)   |      12
 *      5  (RW)   |      GND
 *      6  (E)    |      11
 *      7  (D0)   |      Not connected
 *      8  (D1)   |      Not connected
 *      9  (D2)   |      Not connected
 *      10 (D3)   |      Not connected
 *      11 (D4)   |      5
 *      12 (D5)   |      4
 *      13 (D6)   |      3
 *      14 (D7)   |      2
 *      15 (A)    |      5V
 *      16 (K)    |      GND
 *      
 *      DHT       |    Arduino Uno
 *  -----------------------------
 *      1         |      5V  (Left Pin Number 1)
 *      2         |      13 (Digital Pin 13 On Arduino)
 *      3         |      Unplugged
 *      4         |      GND
 *      
 * For the potentiometer, connect the middle pin
 * to pin 3 (V0) of the display. The other two, connect
 * to 5V and GND. It doesn't matter which pin goes to
 * 5V and to GND.
 * 
 * For the DHT22:
 * 
 *  * Hold the sensor so that the grill is towards you. Here are the connections
 * 
 *     -----------
 *     | - |  -  |
 *     | - |  -  |
 *     | - |  -  |
 *     | - |  -  |
 *     -----------
 *     |  |  |  |
 *     |  |  |  |
 *     |  |  |  |
 *     |  |  |  |
 *    5V  2     GND
 *      data
 * 
 * Other information
 * -----------------
 *  For information on the LiquidCrystal library: https://www.arduino.cc/en/Reference/LiquidCrystal
 * 
 */

#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 13     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11  (AM2302)
DHT dht(DHTPIN, DHTTYPE);

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("DHT11 Sensor");
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  delay(500);
  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Waiting...");
    lcd.setCursor(0, 1);
    lcd.print("from DHT");

  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print(" *C");
    lcd.setCursor(0, 1);
    lcd.print("Hum: ");
    lcd.print(h);
    lcd.print(" %");
    delay(5000);
  }
}
