#include <Arduino.h>
#include <DHTesp.h>
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);
DHTesp dht;
void setup()
{
  Serial.begin(9600);
  dht.setup(27, DHTesp::DHT11);
  u8g2.begin();
}

void loop()
{
  delay(dht.getMinimumSamplingPeriod());

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
  u8g2.firstPage();
  u8g2.enableUTF8Print(); // 啟用UTF8文字的功能
  do
  {
    u8g2.setFont(u8g2_font_unifont_t_chinese1); // 使用我們做好的字型
    u8g2.setCursor(0, 14);                      // 使用左下角定位
    u8g2.print("Humidity = " + (String)humidity + "% , ");
    u8g2.setCursor(0, 38);
    u8g2.print("Temperature = " + (String)temperature + "C ");
    u8g2.setCursor(0, 63);
    u8g2.print("李恕安");
  } while (u8g2.nextPage());
  delay(2000);
}
