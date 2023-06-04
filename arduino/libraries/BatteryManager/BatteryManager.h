#ifndef BATTERYMANAGER_H
#define BATTERYMANAGER_H

#include "Arduino.h"

class BatteryManager {
  public:
    BatteryManager(int ADC_PIN);
    int getBatteryPercentage();
  
  private:
    float mapAnalogReadToVoltage(int adcValue);
    int calculateBatteryPercentage(float voltage);

    int ADC_PIN;

    static const float MIN_BATTERY_VOLTAGE; 
    static const float MAX_BATTERY_VOLTAGE;
    static const int analogReadValues[];
    static const float voltages[];
};

#endif

