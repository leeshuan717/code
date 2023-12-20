#include <Arduino.h>
#include "DHTesp.h"

DHTesp dht;

void setup()
{
  dht.setup(27, DHTesp::AM2302);
}

void loop()
{
  TempAndHumidity data = dht.getTempAndHumidity();

  if (dht.getStatus() != 0)
  {
    Serial.println("DHT sensor error status: " + String(dht.getStatusString()));
  }
  else if (isnan(data.humidity) || isnan(data.temperature))
  {
    Serial.println("Data is NaN!");
  }
  else
  {
    Serial.print("Humidity: ");
    Serial.print(data.humidity);
    Serial.print("%  Temperature: ");
    Serial.println(data.temperature);
  }

  delay(2000);
}
