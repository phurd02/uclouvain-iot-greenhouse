# Backend

This directory contains the configuration files for setting up and deploy the backend services using [Docker](https://www.docker.com/) and [Docker Compose](https://docs.docker.com/compose/). This setup was greatly inspired by [huntabyte\'s tig-stack repository](https://github.com/huntabyte/tig-stack).

## Docker configuration

The [docker-compose.yml](./docker-compose.yml) file defines the Docker containers for the backend services, including Telegraf, InfluxDB, and Grafana.

To start all the backend services, navigate to this directory and run:
```shell
docker-compose up -d
```
You may stop the services at any time by running:
```shell
docker-compose down
```

## Environment Variables

The [.env](./.env) file contains environment variables needed by the Docker services. Make sure to fill out this file with your specific configuration details before running the Docker compose command.

## Telegraf

Telegraf is used to pull data from The Things Network's MQTT broker.

The [telegraf/telegraf.conf](./telegraf/telegraf.conf) file contains the configuration for Telegraf. You need to edit this file to match your specific MQTT broker configuration.

## InfluxDB

InfluxDB is used to store the sensor data.

The [entrypoint.sh](./entrypoint.sh) script initializes the InfluxDB setup.

## Grafana

Grafana is used to visualize the sensor data stored in InfluxDB. Once the Docker containers are running, you can access Grafana at http://localhost:3000 (or replace "localhost" with the IP address of your machine if you're accessing it from another device).





