# ESP32 Real-Time Weather Monitoring System

An IoT-based weather monitoring station using ESP32 with multiple environmental sensors for real-time temperature, humidity, pressure, and rainfall monitoring with Blynk cloud integration.

## Project Overview

This system integrates multiple sensors with ESP32 microcontroller to collect environmental data and transmit it to the Blynk IoT cloud platform for real-time monitoring and analysis.

## Features

- **Real-time Weather Monitoring**: Temperature, humidity, pressure, and rainfall
- **Cloud Integration**: Blynk cloud for remote access
- **Mobile App Dashboard**: User-friendly Blynk app interface
- **Web Dashboard**: Web-based monitoring interface
- **Data Logging**: Historical data storage for trend analysis
- **Wi-Fi Connectivity**: Built-in ESP32 Wi-Fi
- **Low-cost**: Affordable sensors and components

## Hardware Components

| Component | Model | Quantity |
|-----------|-------|----------|
| Microcontroller | ESP32 | 1 |
| Temperature & Humidity | DHT22 | 1 |
| Pressure Sensor | BMP180 | 1 |
| Rain Sensor | Raindrop | 1 |
| Power Supply | 5V 2A | 1 |

## Wiring Diagram

```
DHT22:
  VCC -> 3.3V
  GND -> GND  
  DATA -> GPIO5

BMP180 (I2C):
  VCC -> 3.3V
  GND -> GND
  SCL -> GPIO22
  SDA -> GPIO21

Rain Sensor:
  VCC -> 3.3V
  GND -> GND
  D0 -> GPIO32
  A0 -> GPIO34
```

## Installation & Setup

### 1. Arduino IDE Setup

1. Install Arduino IDE from https://www.arduino.cc/
2. File -> Preferences
3. Add: https://dl.espressif.com/dl/package_esp32_index.json
4. Tools -> Board Manager -> Search & Install ESP32
5. Select Tools -> Board -> ESP32 Dev Module

### 2. Install Libraries

```
Sketch -> Include Library -> Manage Libraries

Search and install:
- DHT sensor library by Adafruit
- Adafruit BMP085 Library
- Blynk by Volodymyr Shymanskyy
```

### 3. Create Blynk Account

1. Go to https://blynk.cloud
2. Sign up and create account
3. Create new device from template
4. Select ESP32 as hardware
5. Copy AUTH TOKEN

### 4. Upload Firmware

1. Update credentials in code:
   - AUTH TOKEN
   - WiFi SSID
   - WiFi Password

2. Connect ESP32 via USB
3. Click Upload
4. Hold BOOT button when upload starts

## Test Results

| Test | Expected | Status |
|------|----------|--------|
| Temperature Accuracy | ±0.5°C | PASS |
| Humidity Accuracy | ±2-5% | PASS |
| Pressure Reading | ~1013 hPa | PASS |
| WiFi Connection | Stable | PASS |
| Data Transmission | Real-time | PASS |

## Sample Data (June 7, 2024)

```
Time | Temp | Humidity | Pressure
-----|------|----------|----------
09:00| 33°C | 87% | 27 hPa
09:30| 34°C | 85% | 26 hPa
10:00| 34°C | 85% | 26 hPa
10:45| 35°C | 82% | 28 hPa
12:00| 36°C | 79% | 29 hPa
14:15| 36°C | 75% | 30 hPa
```

## Applications

- **Agriculture**: Irrigation automation, crop monitoring
- **Smart Home**: HVAC control, weather-based automation
- **Environmental Research**: Climate data collection
- **Disaster Management**: Early warning systems
- **Urban Monitoring**: City-wide weather networks

## Future Enhancements

- Add wind speed/direction sensor
- Home Assistant integration
- Machine learning for prediction
- Solar power module
- LoRaWAN connectivity
- IFTTT integration
- SMS alerts

## Troubleshooting

| Issue | Solution |
|-------|----------|
| WiFi not connecting | Check SSID/password, verify 2.4GHz network |
| No sensor data | Check wiring, verify I2C address |
| Blynk not working | Verify AUTH token, check internet |
| Inaccurate readings | Calibrate sensors, check power supply |

## License

MIT License - Free for educational and commercial use

## Author

**P. Bramham** (2111CS050027)
- B.Tech CSE - IoT Specialization
- Malla Reddy University, Hyderabad

**Project Guided by**: Dr. A. S. N. Murthy

## References

1. Espressif ESP32 Technical Reference
2. Adafruit DHT Sensor Documentation
3. Bosch BMP180 Datasheet
4. Blynk IoT Platform Documentation
5. Arduino IDE Official Docs

---

**Last Updated**: December 2025 | **Version**: 1.0
