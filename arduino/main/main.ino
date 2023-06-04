
#include <Wire.h>
#include "BME280Sensor.h"
#include "AS7265XSensor.h"
#include "BatteryManager.h"
#include "LoRaWan_APP.h"

// Defining pins
#define SDA 17 // I2C data pin
#define SCL 13 // I2C clock pin
#define BATT_PIN 36 // Battery ADC pin
#define SENSOR_POWER_PIN 21 // Sensor power control pin

// Setting up I2C communication
TwoWire I2Cone = TwoWire(1);

// Constructing sensor and battery manager objects
BME280Sensor bmeSensor(I2Cone); // BME280 sensor object
AS7265XSensor asSensor(I2Cone); // AS7265X sensor object
BatteryManager batteryManager(BATT_PIN); // Battery manager object

// LoRaWAN parameters
/* OTAA para*/
uint8_t devEui[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
uint8_t appEui[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
uint8_t appKey[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

/* ABP para*/
uint8_t nwkSKey[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
uint8_t appSKey[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
uint32_t devAddr =  ( uint32_t )0x00000000;

/*LoraWan channelsmask, default channels 0-7*/ 
uint16_t userChannelsMask[6]={ 0x00FF,0x0000,0x0000,0x0000,0x0000,0x0000 };
LoRaMacRegion_t loraWanRegion = ACTIVE_REGION;
DeviceClass_t  loraWanClass = CLASS_A;
uint32_t appTxDutyCycle = 1500000;
bool overTheAirActivation = true;
bool loraWanAdr = false;
bool isTxConfirmed = true;
uint8_t appPort = 2;
uint8_t confirmedNbTrials = 4;


// Variables to hold sensor data
float temperature = 0;
float humidity = 0;
float pressure = 0;

float spectr_A = 0;
float spectr_B = 0;
float spectr_C = 0;
float spectr_D = 0;
float spectr_E = 0;
float spectr_F = 0;
float spectr_G = 0;
float spectr_H = 0;
float spectr_R = 0;
float spectr_I = 0;
float spectr_S = 0;
float spectr_J = 0;
float spectr_T = 0;
float spectr_U = 0;
float spectr_V = 0;
float spectr_W = 0;
float spectr_K = 0;
float spectr_L = 0;

int batteryPercentage = 0;

static void prepareTxFrame( uint8_t port)
{
    appDataSize = 44;

    int temp = temperature * 100;
    appData[0] = highByte(temp);
    appData[1] = lowByte(temp);

    int hum = humidity * 100;
    appData[2] = highByte(hum);
    appData[3] = lowByte(hum);

    int pres = pressure * 100;
    appData[4] = highByte(pres);
    appData[5] = lowByte(pres);

    int A = spectr_A * 100;
    appData[6] = highByte(A);
    appData[7] = lowByte(A);

    int B = spectr_B * 100;
    appData[8] = highByte(B);
    appData[9] = lowByte(B);

    int C = spectr_C * 100;
    appData[10] = highByte(C);
    appData[11] = lowByte(C);

    int D = spectr_D * 100;
    appData[12] = highByte(D);
    appData[13] = lowByte(D);

    int E = spectr_E * 100;
    appData[14] = highByte(E);
    appData[15] = lowByte(E);

    int F = spectr_F * 100;
    appData[16] = highByte(F);
    appData[17] = lowByte(F);

    int G = spectr_G * 100;
    appData[18] = highByte(G);
    appData[19] = lowByte(G);

    int H = spectr_H * 100;
    appData[20] = highByte(H);
    appData[21] = lowByte(H);

    int R = spectr_R * 100;
    appData[22] = highByte(R);
    appData[23] = lowByte(R);

    int I = spectr_I * 100;
    appData[24] = highByte(I);
    appData[25] = lowByte(I);

    int S = spectr_S * 100;
    appData[26] = highByte(S);
    appData[27] = lowByte(S);

    int J = spectr_J * 100;
    appData[28] = highByte(J);
    appData[29] = lowByte(J);

    int T = spectr_T * 100;
    appData[30] = highByte(T);
    appData[31] = lowByte(T);

    int U = spectr_U * 100;
    appData[32] = highByte(U);
    appData[33] = lowByte(U);

    int V = spectr_V * 100;
    appData[34] = highByte(V);
    appData[35] = lowByte(V);

    int W = spectr_W * 100;
    appData[36] = highByte(W);
    appData[37] = lowByte(W);

    int K = spectr_K * 100;
    appData[38] = highByte(K);
    appData[39] = lowByte(K);

    int L = spectr_L * 100;
    appData[40] = highByte(L);
    appData[41] = lowByte(L);

    appData[42] = highByte(batteryPercentage);
    appData[43] = lowByte(batteryPercentage);
}

void setup() {
  Serial.begin(115200);
  Mcu.begin();
  deviceState = DEVICE_STATE_INIT;
}

void loop() {
  switch( deviceState )
  {
    case DEVICE_STATE_INIT:
    {
#if(LORAWAN_DEVEUI_AUTO)
      LoRaWAN.generateDeveuiByChipID();
#endif
      // Initialize LoRaWAN with the specified class and region
      LoRaWAN.init(loraWanClass,loraWanRegion);
      break;
    }
    case DEVICE_STATE_JOIN:
    {
      // Start the join procedure to connect with the LoRaWAN network
      LoRaWAN.join();
      break;
    }
    case DEVICE_STATE_SEND:
    {
      // Set the sensor power pin as OUTPUT
      pinMode(SENSOR_POWER_PIN, OUTPUT);
      // Power up sensors by setting the power pin to HIGH
      digitalWrite(SENSOR_POWER_PIN, HIGH);
      // Delay to allow sensors to power up
      delay(100);

      // Begin I2C communication
      I2Cone.begin(SDA, SCL, 100000);

      // Initialize BME280 and AS7265X sensors
      bmeSensor.begin();
      asSensor.begin();
      
      // Check if the BME280 sensor is activated, if so, get readings
      if(bmeSensor.isActivated())
        bmeSensor.getReadings(temperature, humidity, pressure);

      // Check if the AS7265X sensor is activated, if so, get readings
      if(asSensor.isActivated())
        asSensor.getReadings(spectr_A, spectr_B, spectr_C, spectr_D, spectr_E, spectr_F, spectr_G, spectr_H, spectr_R, spectr_I, spectr_S, spectr_J, spectr_T, spectr_U, spectr_V, spectr_W, spectr_K, spectr_L);

      // Get the battery percentage from the battery manager
      batteryPercentage = batteryManager.getBatteryPercentage();

      // Power down sensors by setting the power pin to LOW
      digitalWrite(SENSOR_POWER_PIN, LOW);
      delay(10);

      // Prepare the data frame for transmission
      prepareTxFrame( appPort );
      LoRaWAN.send();
      deviceState = DEVICE_STATE_CYCLE;
      break;
    }
    case DEVICE_STATE_CYCLE:
    {
      // Schedule next packet transmission
      txDutyCycleTime = appTxDutyCycle + randr( -APP_TX_DUTYCYCLE_RND, APP_TX_DUTYCYCLE_RND );
      LoRaWAN.cycle(txDutyCycleTime);
      deviceState = DEVICE_STATE_SLEEP;
      break;
    }
    case DEVICE_STATE_SLEEP:
    {
      LoRaWAN.sleep(loraWanClass);
      break;
    }
    default:
    {
      deviceState = DEVICE_STATE_INIT;
      break;
    }
  }
}
