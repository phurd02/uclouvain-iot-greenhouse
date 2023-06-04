#ifndef AS7265XSensor_h
#define AS7265XSensor_h

#include <Wire.h>
#include "SparkFun_AS7265X.h"

class AS7265XSensor {
  public:
    AS7265XSensor(TwoWire &wire);
    void begin();
    bool isActivated();
    void getReadings(float &spectr_A, float &spectr_B, float &spectr_C, float &spectr_D, float &spectr_E, float &spectr_F, float &spectr_G, float &spectr_H, float &spectr_R, float &spectr_I, float &spectr_S, float &spectr_J, float &spectr_T, float &spectr_U, float &spectr_V, float &spectr_W, float &spectr_K, float &spectr_L);
  private:
    TwoWire &I2Cone;
    AS7265X spectral;
    bool spectralActivated;
};

#endif

