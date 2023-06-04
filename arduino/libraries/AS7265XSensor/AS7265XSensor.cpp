#include "AS7265XSensor.h"

AS7265XSensor::AS7265XSensor(TwoWire &wire): I2Cone(wire) {
}

void AS7265XSensor::begin() {
  bool status = spectral.begin(I2Cone);
  if (!status) {
    spectralActivated = false;
  } else {
    spectralActivated = true;
  }
}

bool AS7265XSensor::isActivated() {
  return spectralActivated;
}

void AS7265XSensor::getReadings(float &spectr_A, float &spectr_B, float &spectr_C, float &spectr_D, float &spectr_E, float &spectr_F, float &spectr_G, float &spectr_H, float &spectr_R, float &spectr_I, float &spectr_S, float &spectr_J, float &spectr_T, float &spectr_U, float &spectr_V, float &spectr_W, float &spectr_K, float &spectr_L) {
  spectral.takeMeasurements();

  spectr_A = spectral.getCalibratedA();
  spectr_B = spectral.getCalibratedB();
  spectr_C = spectral.getCalibratedC();
  spectr_D = spectral.getCalibratedD();
  spectr_E = spectral.getCalibratedE();
  spectr_F = spectral.getCalibratedF();
  spectr_G = spectral.getCalibratedG();
  spectr_H = spectral.getCalibratedH();
  spectr_R = spectral.getCalibratedR();
  spectr_I = spectral.getCalibratedI();
  spectr_S = spectral.getCalibratedS();
  spectr_J = spectral.getCalibratedJ();
  spectr_T = spectral.getCalibratedT();
  spectr_U = spectral.getCalibratedU();
  spectr_V = spectral.getCalibratedV();
  spectr_W = spectral.getCalibratedW();
  spectr_K = spectral.getCalibratedK();
  spectr_L = spectral.getCalibratedL();
}

