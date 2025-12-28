#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL3rVuErzt"
#define BLYNK_TEMPLATE_NAME "Weather"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Arduino.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>

// Pin Definitions
#define DHTPIN 5
#define DHTTYPE DHT22
#define RAIN_DIGITAL_PIN 32
#define RAIN_ANALOG_PIN 34

// Sensor Objects
DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP085 bmp;

// Variables
float temperature = 0;
float humidity = 0;
float pressure = 0;
float mbar = 0;
int raindropDigitalValue = 0;
int raindropAnalogValue = 0;

// Blynk Credentials
char auth[] = "RFODgVUqsnLXBaDbDGBz5sDtdwfvVOUu";
char ssid[] = "Bramham";
char pass[] = "987654321";

BlynkTimer timer;

void sendSensor() {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT!");
    return;
  }
  
  pressure = bmp.readPressure();
  mbar = pressure / 100.0;
  float mappedPressure = map(mbar, 900, 1050, 0, 100);
  
  raindropDigitalValue = digitalRead(RAIN_DIGITAL_PIN);
  raindropAnalogValue = analogRead(RAIN_ANALOG_PIN);
  
  Blynk.virtualWrite(V1, temperature);
  Blynk.virtualWrite(V2, humidity);
  Blynk.virtualWrite(V3, mappedPressure);
  Blynk.virtualWrite(V4, raindropDigitalValue);
  Blynk.virtualWrite(V5, raindropAnalogValue);
}

void setup() {
  Serial.begin(115200);
  
  if (!bmp.begin()) {
    Serial.println("Could not find BMP180!");
    while (1);
  }
  
  dht.begin();
  pinMode(RAIN_DIGITAL_PIN, INPUT);
  
  delay(1000);
  Blynk.begin(auth, ssid, pass);
  delay(1000);
  
  timer.setInterval(1000L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
