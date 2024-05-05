#include <ESP32Ping.h>
#include <ping.h>#include <Arduino.h>
#include <PromLokiTransport.h>
#include <PrometheusArduino.h>
#include <DHT.h>
#include "certificates.h"
#include "config.h"
byte dat[5];
int sensorPin = 32;
int pin1= 33;
int pin2= 25;
int pin3=26;
int value = 0;
/*
// Prometheus client and transport
PromLokiTransport transport;
PromClient client(transport);// Create a write request for 3 series (when changing update buffers used to serialize the data)
WriteRequest req(1, 1537);// Define a TimeSeries which can hold up to 5 samples, has a name of `temperature/humidity/...` and uses the above labels of which there are 2
TimeSeries ts1(5, "temperature_celsius", "{monitoring_type=\"room_comfort\",board_type=\"esp32_devkit1\",room=\"bedroom\"}");int loopCounter = 0;// Function to set up Prometheus client
void setupClient() {
 // Serial.println("Setting up client...");  uint8_t serialTimeout;
  while (!Serial && serialTimeout < 50) {
    delay(100);
    serialTimeout++;
  }  // Configure and start the transport layer
  transport.setUseTls(true);
  transport.setCerts(grafanaCert, strlen(grafanaCert));
  transport.setWifiSsid(WIFI_SSID);
  transport.setWifiPass(WIFI_PASSWORD);
 // transport.setDebug(Serial);  // Remove this line to disable debug logging of the client.
  if (!transport.begin()) {
     // Serial.println(transport.errmsg);
      while (true) {};
  }  // Configure the client
  client.setUrl(GC_PROM_URL);
  client.setPath((char*)GC_PROM_PATH);
  client.setPort(GC_PORT);
  client.setUser(GC_PROM_USER);
  client.setPass(GC_PROM_PASS);
  client.setDebug(Serial);  // Remove this line to disable debug logging of the client.
  if (!client.begin()) {
     // Serial.println(client.errmsg);
      while (true) {};
  }  // Add our TimeSeries to the WriteRequest
  req.addTimeSeries(ts1);  req.setDebug(Serial);  // Remove this line to disable debug logging of the write request serialization and compression.
}*/
// ========== MAIN FUNCTIONS: SETUP & LOOP ==========
// SETUP: Function called at boot to initialize the system
void setup() {
  // Start the serial output at 115,200 baud
  Serial.begin(115200);
pinMode(pin1, OUTPUT);
pinMode(pin2, OUTPUT);
pinMode(pin3, OUTPUT);
  // Set up client
  //setupClient();  pinMode(sensorPin, INPUT);
  // Start the DHT sensor
}// LOOP: Function called in a loop to read from sensors and send them do databases
void loop() {
    bool ret = Ping.ping("www.googhghcf7t6le.com");
/*Serial.print("Ping result");
Serial.print(ret);*/
  int64_t time;
 // time = transport.getTimeMillis();
  value = analogRead(sensorPin);
  //Serial.println("value:");
  Serial.println(value); // light intensity
                // high values for bright environment
                // low values for dark environment  // Read temperature and humidity  // Check if any reads failed and exit early (to try again)
                delay(1000);
    /*  if (loopCounter >= 5) {
    //Send
    loopCounter = 0;*/
  /*  PromClient::SendResult res = client.send(req);
    if (!res == PromClient::SendResult::SUCCESS) {
           // Serial.println(client.errmsg);
    }    // Reset batches after a succesful send.
    ts1.resetSamples();  } else {
    if (!ts1.addSample(time, value)) {
     // Serial.println(ts1.errmsg);
    }    loopCounter++;
  }
  // wait INTERVAL seconds and then do it again
  delay(INTERVAL * 1000);
  */
}