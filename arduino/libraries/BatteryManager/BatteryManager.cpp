#include "BatteryManager.h"

const float BatteryManager::MIN_BATTERY_VOLTAGE = 3.0;
const float BatteryManager::MAX_BATTERY_VOLTAGE = 4.2;
const int BatteryManager::analogReadValues[6] = {2352, 2250, 2082, 1959, 1851, 1631};
const float BatteryManager::voltages[6] = {4.2, 4.0, 3.7, 3.5, 3.35, 3.0};

BatteryManager::BatteryManager(int ADC_PIN)
: ADC_PIN(ADC_PIN) {}

int BatteryManager::getBatteryPercentage() {
  int adcValue = analogRead(ADC_PIN);
  float voltage = mapAnalogReadToVoltage(adcValue);

  return calculateBatteryPercentage(voltage);
}

float BatteryManager::mapAnalogReadToVoltage(int adcValue) {
  for (int i = 0; i < 6 - 1; i++) {
    if (adcValue <= analogReadValues[i] && adcValue >= analogReadValues[i + 1]) {
      float voltageDiff = voltages[i] - voltages[i + 1];
      float adcDiff = analogReadValues[i] - analogReadValues[i + 1];
      float slope = voltageDiff / adcDiff;
      float offset = voltages[i] - slope * analogReadValues[i];
      return adcValue * slope + offset;
    }
  }
  return 0.0;
}

int BatteryManager::calculateBatteryPercentage(float voltage) {
  if (voltage <= MIN_BATTERY_VOLTAGE) {
    return 0;
  } else if (voltage >= MAX_BATTERY_VOLTAGE) {
    return 100;
  } else {
    return (int)((voltage - MIN_BATTERY_VOLTAGE) * 100 / (MAX_BATTERY_VOLTAGE - MIN_BATTERY_VOLTAGE));
  }
}

