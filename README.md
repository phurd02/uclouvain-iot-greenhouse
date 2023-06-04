# IoT based greenhouse monitoring
UCLouvain master's thesis, 2023\
Pierre-Yves HURD\
Supervised by Pr. Yves Deville & Pr. Ramin Sadre

This repository contains the software components of the **IoT based greenhouse monitoring** project, my master's thesis at UCLouvain. The project is designed to monitor data from a greenhouse using a Heltec WiFi LoRa 32 (v2) board, sending the data over LoRaWAN to The Things Network (TTN). The backend collects the data from TTN's MQTT broker via a Telegraf agent, stores it in InfluxDB, and visualizes it on Grafana.

## Repository Structure

The repository is organized as follows:
- [arduino](./arduino/): This folder contains the Arduino sketch that runs on the Heltec WiFi LoRa 32 board, as well as the libraries used by the sketch. Check the [README](./arduino/README.md) in this folder for more details.
- [backend](./backend/): This folder contains Docker configurations for the Telegraf, InfluxDB, and Grafana services, as well as some setup scripts. Check the [README](./backend/README.md) in this folder for more details.
- [payload_formatter](./payload_formatter/): This folder contains a JavaScript payload formatter to use with The Things Network. Check the [README](./payload_formatter/README.md) in this folder for more details.

## Getting Started

- Clone this repository to your local machine
- Follow the instructions in each folder's README to set up the Arduino board and the backend services
- Modify the necessary parameters in the .env file and the Arduino sketch to fit your specific setup
- Start the backend services
- Power up your device (the board connected with the sensors). Verify that it's functioning correctly and transmitting data

