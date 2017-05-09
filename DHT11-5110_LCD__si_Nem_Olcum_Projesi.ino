#include <SPI.h>

#include "DHT.h"      /

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
// pin 8 - Serial clock out (SCLK)
// pin 9 - Serial data out (DIN)
// pin 10 - Data/Command select (D/C)
// pin 11 - LCD reset (RST)
// pin 4 - LCD chip select (CE)
static PCD8544 lcd = PCD8544(8, 9, 10, 11, 4); 

void setup()
{
  lcd.begin(84, 48);
  dht.begin();
  Serial.begin(9600);  

  lcd.setCursor(10,0);       
  lcd.print("Sicaklik: ");  
  lcd.setCursor(10,4);
  lcd.print("Nem:");
  
}

void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  
  if (isnan(h) || isnan(t) || isnan(f)) {
    return;
  }
  
  lcd.setCursor(21,1);
  lcd.print(t);
  lcd.print(" C");
  Serial.print("Sicaklik: "); Serial.println(t); 
  
  lcd.setCursor(21,3);
  lcd.print(h);
  lcd.print(" %");
  Serial.print("Nem: "); Serial.println(h);

  delay(100);
}
