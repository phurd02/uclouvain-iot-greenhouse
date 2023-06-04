#include "BME280Sensor.h"

BME280Sensor::BME280Sensor(TwoWire &wire): I2Cone(wire) {
}

void BME280Sensor::begin() {
  bool status = bme.begin(0x76, &I2Cone);
  if (!status) {
    bmeActivated = false;
  } else {
    bmeActivated = true;
  }
}

bool BME280Sensor::isActivated() {
  return bmeActivated;
}

void BME280Sensor::getReadings(float &temperature, float &humidity, float &pressure) {
  temperature = bme.readTemperature();
  humidity = bme.readHumidity();
  pressure = bme.readPressure() / 100.0F;
}

