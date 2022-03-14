#include <Wire.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1022.2)

Adafruit_BME280 bme;

void setup() {
  Serial.begin(9600);

  if (!bme.begin(0x77)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

void loop() {

  Serial.print(bme.readTemperature());
  Serial.print(" ");
  Serial.print(bme.readPressure() / 100.0F );
  Serial.print(" ");
  Serial.print(bme.readHumidity());
  Serial.print(" ");
  Serial.println(bme.readAltitude(SEALEVELPRESSURE_HPA));

  delay(5000);
}
  
