#ifndef BME280Sensor_h
#define BME280Sensor_h

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

class BME280Sensor {
  public:
    BME280Sensor(TwoWire &wire);
    void begin();
    bool isActivated();
    void getReadings(float &temperature, float &humidity, float &pressure);
  private:
    TwoWire &I2Cone;
    Adafruit_BME280 bme;
    bool bmeActivated;
};

#endif

