# Arduino

This directory contains the main Arduino sketch, as well as the libraries used in the sketch.

## Main Sketch

The main sketch for the Heltec WiFi LoRa 32 (v2) board is found in the [main](./main/) directory. This sketch controls the board's interaction with the sensors and its transmission of sensor data over LoRaWAN to The Things Network (TTN).

To compile and upload an Arduino sketch, please follow the instructions at https://support.arduino.cc/hc/en-us/articles/4733418441116-Upload-a-sketch-in-Arduino-IDE.

Note that the LoRaWAN device parameters (found in [main.ino](./main/main.ino) lines 24-44) must be modified with your TTN addresses and keys. Depending on your requirements, you may also need to adjust the sleep interval (line 38) and the sensors used. For instructions on obtaining your TTN addresses and keys, see [Adding Devices](https://www.thethingsindustries.com/docs/devices/adding-devices/).


## Libraries

There are several libraries used in the main sketch, some of which are public (see [Arduino IDE Library Manager](https://www.arduino.cc/reference/en/libraries/)) and some of which were custom created for this project. They are found in the [libraries](./libraries/) directory and are listed below:
- [Adafruit_BME280_Library](https://github.com/adafruit/Adafruit_BME280_Library): This library is used to interact with the BME280 sensor for reading humidity, temperature, and pressure.
- [Adafruit_BusIO](https://github.com/adafruit/Adafruit_BusIO): This is a helper library to abstract away I2C & SPI transactions and registers.
- [Adafruit_Unified_Sensor](https://github.com/adafruit/Adafruit_Sensor): This is a unified sensor driver library that provides a common interface for sensor reading.
- [SparkFun_Spectral_Triad_AS7265X](https://github.com/sparkfun/SparkFun_AS7265x_Arduino_Library): This library is used to interact with the AS7265X spectral sensor.
- [BME280Sensor](./libraries/BME280Sensor): This custom library provides a high-level interface for interacting with the BME280 sensor.
- [AS7265XSensor](./libraries/AS7265XSensor): This custom library provides a high-level interface for interacting with the AS7265X spectral sensor.
- [BatteryManager](./libraries/BatteryManager): This custom library is used to manage the board's battery, including monitoring its charge level.


