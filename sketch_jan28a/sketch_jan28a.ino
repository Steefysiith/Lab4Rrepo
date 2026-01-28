#include <U8x8lib.h>
#include <DHT.h>
DHT dht(3, DHT11);
U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);
double tempValue;
double humidLevel;

void setup() {
dht.begin();
u8x8.begin();
u8x8.setFlipMode(1);
u8x8.clear();
tempValue = dht.readTemperature();
humidLevel = dht.readHumidity();
}
void loop() {
u8x8.setFont(u8x8_font_chroma48medium8_r);
u8x8.setCursor(0, 0);
u8x8.print("Humidity: ");
u8x8.println(humidLevel);
u8x8.print("Temp: ");
u8x8.println(tempValue);

}

